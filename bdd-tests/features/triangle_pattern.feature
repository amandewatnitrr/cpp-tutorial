Feature: triangle patterns

  Scenario: prints a left base star triangle
    Given the bddtesting harness is built
    When I run "lbstar" with input:
      """
      3
      """
    Then the harness output should be:
      """
      *
      * *
      * * *
      """

  Scenario: prints a right base star triangle
    Given the bddtesting harness is built
    When I run "rbstar" with input:
      """
      3
      """
    Then the harness output should be:
      """
        *
       **
      ***
      """

  Scenario: prints the mirrored left triangle
    Given the bddtesting harness is built
    When I run "lastar" with input:
      """
      3
      """
    Then the harness output should be:
      """

      * * *
      * *
      *
      """

  Scenario: prints an equilateral triangle pattern
    Given the bddtesting harness is built
    When I run "equilateral_triangle_pattern" with input:
      """
      3
      """
    Then the harness output should be:
      """
      <sp><sp><sp>*
      <sp><sp>* *
      <sp>* * *
      """

  Scenario: prints a diamond pattern
    Given the bddtesting harness is built
    When I run "diamond_pattern" with input:
      """
      3
      """
    Then the harness output should be:
      """
         *
        ***
       *****
        ***
         *
      """

  Scenario: prints a left base triangle pattern
    Given the bddtesting harness is built
    When I run "left_base_triangle_pattern" with input:
      """
      3
      """
    Then the harness output should be:
      """

      *
      * *
      * * *
      * *
      *
      """

  Scenario: prints a right base triangle pattern
    Given the bddtesting harness is built
    When I run "right_base_triangle_pattern" with input:
      """
      3
      """
    Then the harness output should be:
      """

         *
        **
       ***
        **
         *
      """

  Scenario: prints Pascal triangle
    Given the bddtesting harness is built
    When I run "pascal_triangle" with input:
      """
      3
      """
    Then the harness output should be:
      """
      1 
      1 1 
      1 2 1 
      1 3 3 1 
      """