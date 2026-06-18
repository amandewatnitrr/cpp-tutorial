from html import escape
from pathlib import Path
import subprocess
from collections import OrderedDict
import hashlib
import time


def _status_name(status):
        name = getattr(status, "name", None)
        if name:
                return name.lower()
        return str(status).lower()


def _status_label(status):
        name = _status_name(status)
        if name == "passed":
                return "Passed"
        if name == "failed":
                return "Failed"
        if name == "skipped":
                return "Skipped"
        return name.title()


def _status_class(status):
        name = _status_name(status)
        if name == "passed":
                return "passed"
        if name == "failed":
                return "failed"
        if name == "skipped":
                return "skipped"
        return "unknown"


def _format_duration(seconds):
        seconds = float(seconds)
        if seconds >= 1.0:
            return f"{seconds:.3f}s"
        if seconds >= 0.001:
            return f"{seconds * 1000.0:.3f}ms"
        return f"{seconds * 1000000.0:.1f}us"


def _display_text(value):
    text = value if isinstance(value, str) else str(value)
    return escape(text).replace("-&gt;", " &rarr; ")


def _compute_file_hash(path):
    sha = hashlib.sha256()
    sha.update(Path(path).read_bytes())
    return sha.hexdigest()


def _check_report_tampered(report_path):
    hash_path = Path(report_path).parent / ".behave-report.sha256"
    if not report_path.exists() or not hash_path.exists():
        return False
    stored = hash_path.read_text(encoding="utf-8").strip()
    current = _compute_file_hash(report_path)
    return current != stored


def _store_report_hash(report_path):
    hash_path = Path(report_path).parent / ".behave-report.sha256"
    hash_path.write_text(_compute_file_hash(report_path), encoding="utf-8")


def _check_readme_tampered(readme_path):
    hash_path = Path(readme_path).parent / "build" / ".behave-readme.sha256"
    if not Path(readme_path).exists() or not hash_path.exists():
        return False
    stored = hash_path.read_text(encoding="utf-8").strip()
    current = _compute_file_hash(readme_path)
    return current != stored


def _store_readme_hash(readme_path):
    hash_path = Path(readme_path).parent / "build" / ".behave-readme.sha256"
    hash_path.write_text(_compute_file_hash(readme_path), encoding="utf-8")


def _build_readme_summary_block(scenario_results, total_duration, tamper_warning=False, readme_tampered=False):
    passed = sum(1 for item in scenario_results if _status_name(item["status"]) == "passed")
    failed = sum(1 for item in scenario_results if _status_name(item["status"]) == "failed")
    skipped = sum(1 for item in scenario_results if _status_name(item["status"]) == "skipped")
    generated_at = time.strftime("%Y-%m-%d %H:%M:%S UTC", time.gmtime())
    tamper_line = (
        "- \u26a0\ufe0f **Previous report was manually modified** \u2014 content may not reflect actual results.\n"
        if tamper_warning
        else ""
    )
    readme_tamper_line = (
        "- \u270f\ufe0f **README was manually edited outside a Behave run** \u2014 this section has been restored by Behave.\n"
        if readme_tampered
        else ""
    )

    return (
        "<!-- BEGIN:behave-report-summary -->\n"
        + tamper_line
        + readme_tamper_line
        + "Open the latest generated report here:\n\n"
        "- [build/behave-report.html](build/behave-report.html)\n\n"
        "Latest local run summary (auto-updated after each Behave run):\n\n"
        f"- Passed: {passed}\n"
        f"- Failed: {failed}\n"
        f"- Skipped: {skipped}\n"
        f"- Total test time: {_format_duration(total_duration)}\n"
        f"- Generated at: {generated_at}\n\n"
        "If the link is missing, run `behave` once from this folder to generate the report.\n"
        "<!-- END:behave-report-summary -->"
    )


def _update_readme_with_latest_report(root, scenario_results, total_duration, tamper_warning=False, readme_tampered=False):
    readme_path = root / "README.md"
    if not readme_path.exists():
        return

    begin_marker = "<!-- BEGIN:behave-report-summary -->"
    end_marker = "<!-- END:behave-report-summary -->"
    summary_block = _build_readme_summary_block(scenario_results, total_duration, tamper_warning, readme_tampered)

    content = readme_path.read_text(encoding="utf-8")
    has_markers = begin_marker in content and end_marker in content

    if has_markers:
        start_index = content.index(begin_marker)
        end_index = content.index(end_marker) + len(end_marker)
        updated = content[:start_index] + summary_block + content[end_index:]
    else:
        section = "\n\n## Latest Behave report\n\n" + summary_block + "\n"
        updated = content.rstrip() + section

    readme_path.write_text(updated, encoding="utf-8")


def _write_html_report(report_path, scenario_results, tamper_warning=False):
        passed = sum(1 for item in scenario_results if _status_name(item["status"]) == "passed")
        failed = sum(1 for item in scenario_results if _status_name(item["status"]) == "failed")
        skipped = sum(1 for item in scenario_results if _status_name(item["status"]) == "skipped")
        total_duration = sum(float(item.get("duration", 0.0)) for item in scenario_results)
        failed_results = [item for item in scenario_results if _status_name(item["status"]) == "failed"]
        tamper_banner_html = (
            '<div class="tamper-banner">'
            "\u26a0\ufe0f <strong>Warning:</strong> The previous version of this report was manually "
            "modified in a code editor. The content below reflects the latest genuine Behave run."
            "</div>"
        ) if tamper_warning else ""

        grouped = OrderedDict()
        for result in scenario_results:
                grouped.setdefault(result["feature"], []).append(result)

        sections = []
        for feature_name, feature_results in grouped.items():
                feature_passed = sum(1 for item in feature_results if _status_name(item["status"]) == "passed")
                feature_failed = sum(1 for item in feature_results if _status_name(item["status"]) == "failed")
                feature_skipped = sum(1 for item in feature_results if _status_name(item["status"]) == "skipped")
                feature_duration = sum(float(item.get("duration", 0.0)) for item in feature_results)
                feature_state = "passed"
                if feature_failed:
                        feature_state = "failed"
                elif feature_skipped and not feature_passed:
                        feature_state = "skipped"

                scenario_cards = []
                for result in feature_results:
                        scenario_cards.append(
                                f"""
                                <article class="card {_status_class(result['status'])}">
                                    <div class="card-top">
                                        <div>
                                            <h2>{escape(result['name'])}</h2>
                                        </div>
                                        <span class="card-meta">
                                            <span class="badge {_status_class(result['status'])}">{_status_label(result['status'])}</span>
                                            <span class="badge duration">{_format_duration(result.get('duration', 0.0))}</span>
                                        </span>
                                    </div>
                                    <div class="kv"><span class="k">Input</span><pre>{_display_text(result.get('input', ''))}</pre></div>
                                    <div class="kv"><span class="k">Expected</span><pre>{_display_text(result.get('expected', ''))}</pre></div>
                                    <div class="kv"><span class="k">Actual</span><pre>{_display_text(result.get('actual', ''))}</pre></div>
                                    <p class="detail">{escape(result.get('detail', ''))}</p>
                                </article>
                                """
                        )

                sections.append(
                        f"""
                        <details class="feature-section">
                            <summary class="feature-summary">
                                <div>
                                    <p class="feature">{escape(feature_name)}</p>
                                    <h2>{len(feature_results)} test{'s' if len(feature_results) != 1 else ''}</h2>
                                    <p class="feature-stats">{feature_passed} passed · {feature_failed} failed · {feature_skipped} skipped · {_format_duration(feature_duration)}</p>
                                </div>
                                <span class="summary-pill">
                                    <span class="badge {feature_state}">{len(feature_results)} scenario{'s' if len(feature_results) != 1 else ''}</span>
                                    <span class="toggle-icon" aria-hidden="true"></span>
                                </span>
                            </summary>
                            <div class="feature-items">
                                {''.join(scenario_cards)}
                            </div>
                        </details>
                        """
                )

        failed_cards = []
        for result in failed_results:
                detail_text = result.get("detail", "").strip() or "No explicit error message was captured."
                failed_cards.append(
                        f"""
                        <article class="failed-item">
                            <div class="failed-item-top">
                                <div>
                                    <p class="feature">{escape(result.get('feature', 'Feature'))}</p>
                                    <h3>{escape(result.get('name', 'Scenario'))}</h3>
                                </div>
                                <span class="badge failed">Failed</span>
                            </div>
                            <p class="failed-reason"><strong>Reason:</strong> {escape(detail_text)}</p>
                            <div class="kv"><span class="k">Input</span><pre>{_display_text(result.get('input', ''))}</pre></div>
                            <div class="kv"><span class="k">Expected</span><pre>{_display_text(result.get('expected', ''))}</pre></div>
                            <div class="kv"><span class="k">Actual</span><pre>{_display_text(result.get('actual', ''))}</pre></div>
                        </article>
                        """
                )

        failed_section = f"""
        <section class="failed-overview">
            <div class="failed-overview-top">
                <h2>Failed Tests</h2>
                <span class="badge failed">{len(failed_results)} failed</span>
            </div>
            {''.join(failed_cards) if failed_cards else '<p class="failed-empty">No failed scenarios in this run.</p>'}
        </section>
        """

        html = f"""<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Behave Test Report</title>
    <style>
        :root {{
            color-scheme: dark;
            --bg: #0b1020;
            --panel: rgba(14, 20, 39, 0.86);
            --panel-border: rgba(255, 255, 255, 0.08);
            --text: #e7ecff;
            --muted: #9aa7c7;
            --passed: #34d399;
            --failed: #fb7185;
            --skipped: #fbbf24;
            --shadow: 0 24px 60px rgba(0, 0, 0, 0.35);
        }}

        * {{ box-sizing: border-box; }}

        body {{
            margin: 0;
            min-height: 100vh;
            font-family: Inter, ui-sans-serif, system-ui, -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
            background:
                radial-gradient(circle at top left, rgba(96, 165, 250, 0.18), transparent 28%),
                radial-gradient(circle at right, rgba(52, 211, 153, 0.16), transparent 24%),
                linear-gradient(160deg, #060913 0%, #0b1020 55%, #070a12 100%);
            color: var(--text);
            padding: 32px;
        }}

        .shell {{
            max-width: 1100px;
            margin: 0 auto;
        }}

        .hero {{
            background: var(--panel);
            border: 1px solid var(--panel-border);
            border-radius: 28px;
            padding: 28px;
            box-shadow: var(--shadow);
            backdrop-filter: blur(16px);
        }}

        .eyebrow {{
            text-transform: uppercase;
            letter-spacing: 0.18em;
            font-size: 12px;
            color: var(--muted);
            margin: 0 0 10px;
        }}

        h1 {{
            margin: 0;
            font-size: clamp(2rem, 5vw, 3.5rem);
            line-height: 1.05;
        }}

        .summary {{
            display: grid;
            grid-template-columns: repeat(3, minmax(0, 1fr));
            gap: 16px;
            margin-top: 24px;
        }}

        .metric {{
            padding: 18px;
            border-radius: 22px;
            background: rgba(255, 255, 255, 0.04);
            border: 1px solid rgba(255, 255, 255, 0.06);
        }}

        .metric .label {{
            display: block;
            color: var(--muted);
            font-size: 13px;
            margin-bottom: 8px;
        }}

        .metric .value {{
            display: block;
            font-size: 34px;
            font-weight: 700;
        }}

        .value.passed {{ color: var(--passed); }}
        .value.failed {{ color: var(--failed); }}
        .value.skipped {{ color: var(--skipped); }}

        .report-duration {{
            margin: 18px 0 0;
            color: var(--muted);
            font-size: 14px;
            text-align: center;
        }}

        .grid {{
            margin-top: 24px;
            display: flex;
            flex-direction: column;
            gap: 16px;
        }}

        .failed-overview {{
            margin-top: 20px;
            background: var(--panel);
            border: 1px solid rgba(251, 113, 133, 0.35);
            border-radius: 24px;
            padding: 20px;
            box-shadow: var(--shadow);
            backdrop-filter: blur(16px);
        }}

        .failed-overview-top {{
            display: flex;
            justify-content: space-between;
            align-items: center;
            gap: 12px;
            margin-bottom: 12px;
        }}

        .failed-overview-top h2 {{
            margin: 0;
            font-size: 24px;
        }}

        .failed-empty {{
            margin: 0;
            color: var(--muted);
        }}

        .failed-item {{
            border: 1px solid rgba(251, 113, 133, 0.3);
            background: rgba(251, 113, 133, 0.08);
            border-radius: 20px;
            padding: 16px;
            margin-top: 12px;
        }}

        .failed-item-top {{
            display: flex;
            justify-content: space-between;
            align-items: start;
            gap: 10px;
        }}

        .failed-item h3 {{
            margin: 0;
            font-size: 18px;
        }}

        .failed-reason {{
            margin: 12px 0 0;
            color: var(--text);
            line-height: 1.5;
            white-space: pre-wrap;
        }}

        .feature-section {{
            width: 100%;
            background: var(--panel);
            border: 1px solid var(--panel-border);
            border-radius: 24px;
            box-shadow: var(--shadow);
            backdrop-filter: blur(16px);
            overflow: hidden;
        }}

        .feature-section[open] {{
            border-color: rgba(255, 255, 255, 0.14);
        }}

        .feature-summary {{
            list-style: none;
            cursor: pointer;
            display: flex;
            justify-content: space-between;
            align-items: center;
            gap: 16px;
            padding: 22px 24px;
        }}

        .feature-summary::-webkit-details-marker {{
            display: none;
        }}

        .feature-summary h2 {{
            font-size: 24px;
            margin-top: 2px;
        }}

        .summary-pill {{
            display: inline-flex;
            align-items: center;
            gap: 12px;
            flex-wrap: wrap;
            justify-content: flex-end;
        }}

        .toggle-hint {{
            color: var(--muted);
            font-size: 12px;
            text-transform: uppercase;
            letter-spacing: 0.12em;
        }}

        .toggle-icon {{
            width: 32px;
            height: 32px;
            display: inline-flex;
            align-items: center;
            justify-content: center;
            border-radius: 999px;
            border: 1px solid rgba(255, 255, 255, 0.14);
            background: rgba(255, 255, 255, 0.06);
            color: var(--text);
            font-size: 18px;
            line-height: 1;
            transition: transform 0.2s ease, background 0.2s ease, border-color 0.2s ease;
        }}

        .toggle-icon::before {{
            content: "⌄";
            transform: translateY(-2px);
        }}

        .feature-section[open] .toggle-icon {{
            transform: rotate(180deg);
            background: rgba(52, 211, 153, 0.12);
            border-color: rgba(52, 211, 153, 0.25);
        }}

        .feature-stats {{
            margin: 8px 0 0;
            color: var(--muted);
            font-size: 14px;
        }}

        .feature-items {{
            display: flex;
            flex-direction: column;
            gap: 16px;
            margin: 0;
            padding: 0 24px 24px;
        }}

        .card {{
            width: 100%;
            background: rgba(255, 255, 255, 0.04);
            border: 1px solid var(--panel-border);
            border-radius: 22px;
            padding: 20px;
        }}

        .card.passed {{ border-color: rgba(52, 211, 153, 0.25); }}
        .card.failed {{ border-color: rgba(251, 113, 133, 0.3); }}
        .card.skipped {{ border-color: rgba(251, 191, 36, 0.28); }}

        .card-top {{
            display: flex;
            gap: 16px;
            justify-content: space-between;
            align-items: start;
        }}

        .card-meta {{
            display: inline-flex;
            align-items: center;
            gap: 8px;
            flex-wrap: wrap;
            justify-content: flex-end;
        }}

        .feature {{
            margin: 0 0 6px;
            color: var(--muted);
            font-size: 13px;
            text-transform: uppercase;
            letter-spacing: 0.08em;
        }}

        h2 {{
            margin: 0;
            font-size: 20px;
        }}

        .badge {{
            display: inline-flex;
            align-items: center;
            border-radius: 999px;
            padding: 8px 12px;
            font-size: 12px;
            font-weight: 700;
            letter-spacing: 0.05em;
            text-transform: uppercase;
        }}

        .badge.passed {{ background: rgba(52, 211, 153, 0.15); color: var(--passed); }}
        .badge.failed {{ background: rgba(251, 113, 133, 0.15); color: var(--failed); }}
        .badge.skipped {{ background: rgba(251, 191, 36, 0.15); color: var(--skipped); }}
        .badge.unknown {{ background: rgba(255, 255, 255, 0.08); color: var(--muted); }}
        .badge.duration {{ background: rgba(96, 165, 250, 0.14); color: #93c5fd; }}

        .detail {{
            margin: 14px 0 0;
            color: var(--muted);
            line-height: 1.6;
            white-space: pre-wrap;
        }}

        .kv {{
            margin-top: 12px;
            padding: 14px;
            border-radius: 18px;
            background: rgba(255, 255, 255, 0.04);
            border: 1px solid rgba(255, 255, 255, 0.06);
        }}

        .kv .k {{
            display: block;
            margin-bottom: 8px;
            color: var(--muted);
            font-size: 12px;
            text-transform: uppercase;
            letter-spacing: 0.12em;
        }}

        .kv pre {{
            margin: 0;
            white-space: pre-wrap;
            word-break: break-word;
            color: var(--text);
            font: inherit;
        }}

        .empty {{
            margin-top: 24px;
            padding: 24px;
            border-radius: 22px;
            background: rgba(255, 255, 255, 0.04);
            border: 1px dashed rgba(255, 255, 255, 0.1);
            color: var(--muted);
        }}

        .tamper-banner {{
            background: rgba(251, 191, 36, 0.12);
            border: 1px solid rgba(251, 191, 36, 0.45);
            border-radius: 16px;
            padding: 16px 20px;
            margin-bottom: 20px;
            color: #fbbf24;
            font-size: 15px;
            line-height: 1.5;
        }}

        @media (max-width: 720px) {{
            body {{ padding: 16px; }}
            .summary {{ grid-template-columns: 1fr; }}
            .card-top {{ flex-direction: column; }}
            .feature-summary {{ flex-direction: column; align-items: flex-start; }}
            .summary-pill {{ justify-content: flex-start; }}
            .toggle-icon {{ align-self: flex-start; }}
        }}
    </style>
</head>
<body>
    <main class="shell">
        {tamper_banner_html}
        <section class="hero">
            <p class="eyebrow">Behave BDD Report</p>
            <h1>Test results for cpp-tutorial</h1>
            <div class="summary">
                <div class="metric">
                    <span class="label">Passed</span>
                    <span class="value passed">{passed}</span>
                </div>
                <div class="metric">
                    <span class="label">Failed</span>
                    <span class="value failed">{failed}</span>
                </div>
                <div class="metric">
                    <span class="label">Skipped</span>
                    <span class="value skipped">{skipped}</span>
                </div>
            </div>
            <p class="report-duration">Total test time: {_format_duration(total_duration)}</p>
        </section>

        {failed_section}

        <section class="grid">
            {''.join(sections) if sections else '<div class="empty">No scenarios were executed.</div>'}
        </section>
    </main>
</body>
</html>
"""

        report_path.write_text(html, encoding="utf-8")


def before_all(context):
    root = Path(__file__).resolve().parents[1]
    source = root / "cpp" / "bddtesting.cpp"
    output = root / "build" / "bddtesting"
    report_path = root / "build" / "behave-report.html"
    include_dir = root / "cpp" / "include"

    output.parent.mkdir(parents=True, exist_ok=True)
    context.scenario_results = []
    context.feature_durations = {}
    context.run_started = time.perf_counter()
    context.behave_report_path = report_path
    context.report_tampered = _check_report_tampered(report_path)
    context.readme_tampered = _check_readme_tampered(root / "README.md")

    command = [
        "c++",
        "-std=c++17",
        "-Wall",
        "-Wextra",
        "-Wno-sign-compare",
        "-Wno-unused-parameter",
        "-Wno-vla-cxx-extension",
        "-Wno-return-type",
        "-Wno-unused-variable",
        "-Wno-unused-but-set-variable",
        "-I",
        str(include_dir),
        str(source),
        "-o",
        str(output),
    ]

    subprocess.run(command, check=True, cwd=root)
    context.bddtesting = output


def before_feature(context, feature):
    feature._started_at = time.perf_counter()


def after_feature(context, feature):
    context.feature_durations[feature.name] = time.perf_counter() - getattr(feature, "_started_at", time.perf_counter())


def before_scenario(context, scenario):
    scenario._started_at = time.perf_counter()


def after_scenario(context, scenario):
    detail = ""
    if getattr(scenario, "error_message", None):
        detail = str(scenario.error_message)

    elapsed = time.perf_counter() - getattr(scenario, "_started_at", time.perf_counter())

    context.scenario_results.append(
        {
            "name": scenario.name,
            "feature": scenario.feature.name if scenario.feature else "Feature",
            "status": scenario.status,
            "detail": detail,
            "input": getattr(context, "last_test_input", ""),
            "expected": getattr(context, "expected_output", ""),
            "actual": getattr(context, "actual_output", ""),
            "duration": elapsed,
        }
    )


def after_all(context):
    total_duration = time.perf_counter() - getattr(context, "run_started", time.perf_counter())
    for item in context.scenario_results:
        item["feature_duration"] = context.feature_durations.get(item["feature"], 0.0)
    context.total_duration = total_duration
    tampered = getattr(context, "report_tampered", False)
    readme_tampered = getattr(context, "readme_tampered", False)
    _write_html_report(context.behave_report_path, getattr(context, "scenario_results", []), tampered)
    _store_report_hash(context.behave_report_path)
    root = Path(__file__).resolve().parents[1]
    _update_readme_with_latest_report(root, getattr(context, "scenario_results", []), total_duration, tampered, readme_tampered)
    _store_readme_hash(root / "README.md")
