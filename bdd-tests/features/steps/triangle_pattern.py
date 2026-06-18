from pathlib import Path
from textwrap import dedent
import subprocess

from behave import given, then, when


@given("the bddtesting harness is built")
def step_harness_is_built(context):
    assert hasattr(context, "bddtesting")
    assert Path(context.bddtesting).exists()


@when('I run "{function_name}" with input:')
def step_run_harness(context, function_name):
    input_text = dedent(context.text or "")
    context.last_test_input = input_text.rstrip("\n")

    try:
        result = subprocess.run(
            [str(context.bddtesting), function_name],
            input=input_text,
            text=True,
            capture_output=True,
            check=True,
        )
        context.actual_output = result.stdout
    except subprocess.CalledProcessError as error:
        context.actual_output = error.stdout or ""
        raise


@then('the harness output should be:')
def step_validate_output(context):
    expected = dedent(context.text or "").rstrip("\n").replace("<sp>", " ")
    context.expected_output = expected

    def normalize(text):
        return "\n".join(line.rstrip() for line in text.splitlines())

    actual = normalize(context.actual_output)
    expected_normalized = normalize(expected)
    assert actual == expected_normalized, f"Expected {expected!r}, got {context.actual_output!r}"
