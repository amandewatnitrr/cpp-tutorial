Feature: mathematical operations

  Scenario: computes gcd of two numbers
    Given the bddtesting harness is built
    When I run math function "gcd" with input:
      """
      12 18
      """
    Then the math harness output should be:
      """
      6
      """

  Scenario: finds gcd of an array of numbers
    Given the bddtesting harness is built
    When I run math function "find_gcd" with input:
      """
      3
      12 18 24
      """
    Then the math harness output should be:
      """
      6
      """

  Scenario: finds lcm of an array of numbers
    Given the bddtesting harness is built
    When I run math function "find_lcm" with input:
      """
      3
      4 6 8
      """
    Then the math harness output should be:
      """
      24
      """

  Scenario: checks armstrong number
    Given the bddtesting harness is built
    When I run math function "check_armstrong" with input:
      """
      153
      """
    Then the math harness output should be:
      """
      1
      """

  Scenario: counts digits in a number
    Given the bddtesting harness is built
    When I run math function "count_digits" with input:
      """
      1000
      """
    Then the math harness output should be:
      """
      4
      """

  Scenario: checks even number
    Given the bddtesting harness is built
    When I run math function "isEven" with input:
      """
      10
      """
    Then the math harness output should be:
      """
      1
      """

  Scenario: checks odd number
    Given the bddtesting harness is built
    When I run math function "isOdd" with input:
      """
      11
      """
    Then the math harness output should be:
      """
      1
      """

  Scenario: computes shorter angle between hour and minute hand
    Given the bddtesting harness is built
    When I run math function "shorter_angle_bw_hour_and_minute" with input:
      """
      3 30
      """
    Then the math harness output should be:
      """
      75
      """

  Scenario: checks perfect number
    Given the bddtesting harness is built
    When I run math function "isperfectnumber" with input:
      """
      28
      """
    Then the math harness output should be:
      """
      1
      """

  Scenario: checks two numbers are the same
    Given the bddtesting harness is built
    When I run math function "check_2_numbers_same" with input:
      """
      42 42
      """
    Then the math harness output should be:
      """
      1
      """

  Scenario: prints divisors of a natural number
    Given the bddtesting harness is built
    When I run math function "divisor_of_natural_number" with input:
      """
      12
      """
    Then the math harness output should be:
      """
      1 2 3 4 6 12
      """

  Scenario: computes nth fibonacci term
    Given the bddtesting harness is built
    When I run math function "fibonaci_nth_term" with input:
      """
      7
      """
    Then the math harness output should be:
      """
      13
      """

  Scenario: computes binomial coefficient
    Given the bddtesting harness is built
    When I run math function "binomoal_coeff" with input:
      """
      5 2
      """
    Then the math harness output should be:
      """
      10
      """

  Scenario: adds numbers without plus or minus
    Given the bddtesting harness is built
    When I run math function "add_2_numbers_without_plus_minus" with input:
      """
      6 5
      """
    Then the math harness output should be:
      """
      11
      """
