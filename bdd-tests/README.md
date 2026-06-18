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

2. Run the Behave suite from this folder:

```bash
behave
```

The Behave hooks compile the harness automatically before the first scenario.
