import subprocess

from behave import then, when


def _run_array_harness(context, function_name, input_text):
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


@when('I run array input with data:')
def step_run_array_input(context):
    _run_array_harness(context, "array_input", context.text or "")


@when('I run array function "{function_name}" with data:')
def step_run_array_function(context, function_name):
    _run_array_harness(context, function_name, context.text or "")


@then('the array harness output should be:')
def step_validate_output(context):
    expected = (context.text or "").rstrip("\n")
    context.expected_output = expected

    def normalize(text):
        return "\n".join(line.rstrip() for line in text.splitlines())

    actual = normalize(context.actual_output)
    expected_normalized = normalize(expected)
    assert actual == expected_normalized, f"Expected {expected!r}, got {context.actual_output!r}"
