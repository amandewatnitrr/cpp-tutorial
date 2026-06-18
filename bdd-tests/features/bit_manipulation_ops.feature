Feature: bit manipulation operations

  Scenario: gets the bit value at index i
    Given the bddtesting harness is built
    When I run bit function "getbit" with input:
      """
      5 2
      """
    Then the bit harness output should be:
      """
      1
      """

  Scenario: sets the bit at index i
    Given the bddtesting harness is built
    When I run bit function "setbit" with input:
      """
      5 1
      """
    Then the bit harness output should be:
      """
      7
      """

  Scenario: clears the bit at index i
    Given the bddtesting harness is built
    When I run bit function "clearbit" with input:
      """
      7 1
      """
    Then the bit harness output should be:
      """
      5
      """

  Scenario: updates the bit at index i to target value
    Given the bddtesting harness is built
    When I run bit function "updatebit" with input:
      """
      5 0 0
      """
    Then the bit harness output should be:
      """
      4
      """

  Scenario: prints binary representation of a number
    Given the bddtesting harness is built
    When I run bit function "binary_representation_of_number" with input:
      """
      10
      """
    Then the bit harness output should be:
      """
      1010
      """

  Scenario: counts zeros and ones in binary representation
    Given the bddtesting harness is built
    When I run bit function "count0s1s_in_binary_represent_of_number" with input:
      """
      10
      """
    Then the bit harness output should be:
      """
      2 2
      """

  Scenario: computes ones complement of a number
    Given the bddtesting harness is built
    When I run bit function "onescomplement" with input:
      """
      10
      """
    Then the bit harness output should be:
      """
      5
      """
