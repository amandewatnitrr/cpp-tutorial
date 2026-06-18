# Behave BDD Test Suite for cpp-tutorial

This folder contains the Behave-based acceptance suite for [CPP/test.cpp](../CPP/test.cpp), executed through a shared C++ harness without modifying the source file.

## At a glance

| Area | Details |
| --- | --- |
| Target source | [CPP/test.cpp](../CPP/test.cpp) |
| Test framework | Behave (`behave==1.2.6`) |
| Harness entry | `bdd-tests/cpp/bddtesting.cpp` |
| Live report | [build/behave-report.html](build/behave-report.html) |

## Coverage notes

- The suite started with `array_input(int *v, int n)` and expanded to broader C++ function behaviors through a shared harness.
- The bridge header allows additional wrappers to be added without repeating include shims.

## Run locally

1. Install dependencies:

```bash
python3 -m pip install -r requirements.txt
```

1. Run the full suite:

```bash
behave
```

The Behave hooks compile the harness automatically before scenarios execute.

## Latest Behave report

<!-- BEGIN:behave-report-summary -->
### Report dashboard

![Passed](https://img.shields.io/badge/Passed-90-22c55e?style=for-the-badge) ![Failed](https://img.shields.io/badge/Failed-0-ef4444?style=for-the-badge) ![Skipped](https://img.shields.io/badge/Skipped-0-f59e0b?style=for-the-badge)

[Open latest HTML report](build/behave-report.html)

| Metric | Value |
| --- | --- |
| Passed | **90** |
| Failed | **0** |
| Skipped | **0** |
| Total test time | **2.047s** |
| Generated at | `2026-06-18 23:56:12 UTC` |

Regenerate this dashboard:
Run `behave` from `bdd-tests/` to refresh both this summary and the HTML report.

If the link is missing, run `behave` once from this folder to generate the report.
<!-- END:behave-report-summary -->