# Behave BDD tests for cpp-tutorial

This folder contains a small Behave setup that exercises functions from [CPP/test.cpp](../CPP/test.cpp) without modifying that file.

## Current coverage

The first scenario validates `array_input(int *v, int n)` by compiling a tiny wrapper executable and checking that the values read from standard input are copied into the array in the same order.

The wrapper uses a shared bridge header so future harnesses can call other functions from [CPP/test.cpp](../CPP/test.cpp) directly without repeating the include shim.

## Run

1. Install the Python dependency:

```bash
python3 -m pip install -r requirements.txt
```

1. Run the Behave suite from this folder:

```bash
behave --no-capture 2>&1
```

The Behave hooks compile the harness automatically before the first scenario.

## Latest Behave report

<!-- BEGIN:behave-report-summary -->
- ✏️ **README was manually edited outside a Behave run** — this section has been restored by Behave.
Open the latest generated report here:

- [build/behave-report.html](build/behave-report.html)

Latest local run summary (auto-updated after each Behave run):

- Passed: 90
- Failed: 0
- Skipped: 0
- Total test time: 2.131s
- Generated at: 2026-06-18 23:42:48 UTC

If the link is missing, run `behave` once from this folder to generate the report.
<!-- END:behave-report-summary -->

<!-- manual edit test -->