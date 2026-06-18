Feature: string operations

  Scenario: reads a full line using input_string
    Given the bddtesting harness is built
    When I run string function "input_string" with input:
      """
      hello world from behave
      """
    Then the string harness output should be:
      """
      hello world from behave
      """

  Scenario: prints a full string using print_string
    Given the bddtesting harness is built
    When I run string function "print_string" with input:
      """
      copilot string test
      """
    Then the string harness output should be:
      """
      copilot string test
      """

  Scenario: prints each character using print_string_by_char
    Given the bddtesting harness is built
    When I run string function "print_string_by_char" with input:
      """
      hello
      """
    Then the string harness output should be:
      """
      hello
      """
