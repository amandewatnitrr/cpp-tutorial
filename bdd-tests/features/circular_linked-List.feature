Feature: circular linked list operations

  Scenario: inserts nodes at head in circular linked list
    Given the bddtesting harness is built
    When I run circular linked list function "cll_insertathead" with input:
      """
      4
      1 2 3 4
      5
      """
    Then the circular linked list harness output should be:
      """
      5 1 2 3 4
      """

  Scenario: inserts nodes at tail in circular linked list
    Given the bddtesting harness is built
    When I run circular linked list function "cll_insertattail" with input:
      """
      4
      1 2 3 4
      5
      """
    Then the circular linked list harness output should be:
      """
      1 2 3 4 5
      """

  Scenario: deletes the head node in circular linked list
    Given the bddtesting harness is built
    When I run circular linked list function "cll_deleteathead" with input:
      """
      4
      1 2 3 4
      """
    Then the circular linked list harness output should be:
      """
      2 3 4
      """

  Scenario: deletes a node by position in circular linked list
    Given the bddtesting harness is built
    When I run circular linked list function "cll_deletee" with input:
      """
      5
      1 2 3 4 5
      3
      """
    Then the circular linked list harness output should be:
      """
      1 2 4 5
      """

  Scenario: displays a circular linked list
    Given the bddtesting harness is built
    When I run circular linked list function "cll_display" with input:
      """
      3
      7 8 9
      """
    Then the circular linked list harness output should be:
      """
      7 8 9
      """