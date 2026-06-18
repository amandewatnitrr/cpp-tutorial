Feature: 2D array matrix operations

  Scenario: reads and prints a matrix
    Given the bddtesting harness is built
    When I run 2d array function "matrix_input" with input:
      """
      2 3
      1 2 3
      4 5 6
      """
    Then the 2d array harness output should be:
      """
      1 2 3
      4 5 6
      """

  Scenario: prints a matrix directly
    Given the bddtesting harness is built
    When I run 2d array function "print_matrix" with input:
      """
      2 2
      7 8
      9 10
      """
    Then the 2d array harness output should be:
      """
      7 8
      9 10
      """

  Scenario: sets matrix row and column to zero for first zero occurrence
    Given the bddtesting harness is built
    When I run 2d array function "set_matrix_zero" with input:
      """
      3 3
      1 2 3
      4 0 6
      7 8 9
      """
    Then the 2d array harness output should be:
      """
      1 0 3
      0 0 0
      7 0 9
      """

  Scenario: rotates a square matrix clockwise
    Given the bddtesting harness is built
    When I run 2d array function "rotate_matrix_clockwise" with input:
      """
      3 3
      1 2 3
      4 5 6
      7 8 9
      """
    Then the 2d array harness output should be:
      """
      7 4 1
      8 5 2
      9 6 3
      """

  Scenario: prints spiral traversal of matrix
    Given the bddtesting harness is built
    When I run 2d array function "spiral_traversal_matrix" with input:
      """
      3 3
      1 2 3
      4 5 6
      7 8 9
      """
    Then the 2d array harness output should be:
      """
      1 2 3 6 9 8 7 4 5
      """
