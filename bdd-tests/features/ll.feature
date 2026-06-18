Feature: linked list operations

  Scenario: inserts nodes at head in linked list
    Given the bddtesting harness is built
    When I run linked list function "ll_insertathead" with input:
      """
      4
      1 2 3 4
      """
    Then the linked list harness output should be:
      """
      4->3->2->1->NULL
      """

  Scenario: inserts nodes at tail in linked list
    Given the bddtesting harness is built
    When I run linked list function "ll_insertattail" with input:
      """
      4
      1 2 3 4
      """
    Then the linked list harness output should be:
      """
      1->2->3->4->NULL
      """

  Scenario: searches an element in linked list
    Given the bddtesting harness is built
    When I run linked list function "ll_search" with input:
      """
      5
      10 20 30 40 50
      30
      """
    Then the linked list harness output should be:
      """
      1
      """

  Scenario: deletes a node by value in linked list
    Given the bddtesting harness is built
    When I run linked list function "ll_deletee" with input:
      """
      5
      10 20 30 40 50
      30
      """
    Then the linked list harness output should be:
      """
      10->20->40->50->NULL
      """

  Scenario: returns linked list length
    Given the bddtesting harness is built
    When I run linked list function "ll_length" with input:
      """
      5
      2 4 6 8 10
      """
    Then the linked list harness output should be:
      """
      5
      """

  Scenario: reverses the linked list
    Given the bddtesting harness is built
    When I run linked list function "ll_reverse" with input:
      """
      4
      11 22 33 44
      """
    Then the linked list harness output should be:
      """
      44->33->22->11->NULL
      """

  Scenario: reverses linked list in groups of k nodes
    Given the bddtesting harness is built
    When I run linked list function "ll_reverseknodes" with input:
      """
      5
      1 2 3 4 5
      2
      """
    Then the linked list harness output should be:
      """
      2->1->4->3->5->NULL
      """

  Scenario: detects a cycle in linked list
    Given the bddtesting harness is built
    When I run linked list function "ll_detectcycle" with input:
      """
      5
      1 2 3 4 5
      2
      """
    Then the linked list harness output should be:
      """
      1
      """

  Scenario: removes cycle and prints linked list
    Given the bddtesting harness is built
    When I run linked list function "ll_deletecycle" with input:
      """
      5
      1 2 3 4 5
      2
      """
    Then the linked list harness output should be:
      """
      1->2->3->4->5->NULL
      """

  Scenario: bubble sorts linked list
    Given the bddtesting harness is built
    When I run linked list function "ll_bubblesort" with input:
      """
      5
      4 2 5 1 3
      """
    Then the linked list harness output should be:
      """
      1->2->3->4->5->NULL
      """

  Scenario: adds two numbers represented by linked lists
    Given the bddtesting harness is built
    When I run linked list function "ll_addtwonumbers" with input:
      """
      3
      2 4 3
      3
      5 6 4
      """
    Then the linked list harness output should be:
      """
      7->0->8->NULL
      """
