import subprocess

from behave import then, when


@when('I run string function "{function_name}" with input:')
def step_run_string_harness(context, function_name):
    input_text = context.text or ""
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


@then('the string harness output should be:')
def step_validate_string_output(context):
    expected = (context.text or "").rstrip("\n")
    context.expected_output = expected

    def normalize(text):
        return "\n".join(line.rstrip() for line in text.splitlines())

    actual = normalize(context.actual_output)
    expected_normalized = normalize(expected)
    assert actual == expected_normalized, f"Expected {expected!r}, got {context.actual_output!r}"
