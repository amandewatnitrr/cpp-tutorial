Feature: sorting algorithms

  Scenario: finds an element using binary search
    Given the bddtesting harness is built
    When I run sorting function "binarysearch" with input:
      """
      5
      1 3 5 7 9
      7
      """
    Then the sorting harness output should be:
      """
      4
      """

  Scenario: sorts values using bubble sort
    Given the bddtesting harness is built
    When I run sorting function "bubblesort" with input:
      """
      5
      5 1 4 2 8
      """
    Then the sorting harness output should be:
      """
      1 2 4 5 8
      """

  Scenario: sorts values using insertion sort
    Given the bddtesting harness is built
    When I run sorting function "insertionsort" with input:
      """
      5
      9 5 1 4 3
      """
    Then the sorting harness output should be:
      """
      1 3 4 5 9
      """

  Scenario: sorts values using selection sort
    Given the bddtesting harness is built
    When I run sorting function "selectionsort" with input:
      """
      5
      64 25 12 22 11
      """
    Then the sorting harness output should be:
      """
      11 12 22 25 64
      """

  Scenario: merges two sorted halves
    Given the bddtesting harness is built
    When I run sorting function "merge" with input:
      """
      6
      1 3 5 2 4 6
      0 2 5
      """
    Then the sorting harness output should be:
      """
      1 2 3 4 5 6
      """

  Scenario: sorts values using merge sort
    Given the bddtesting harness is built
    When I run sorting function "mergesort" with input:
      """
      5
      9 4 6 2 7
      """
    Then the sorting harness output should be:
      """
      2 4 6 7 9
      """

  Scenario: sorts values using quick sort
    Given the bddtesting harness is built
    When I run sorting function "quicksort" with input:
      """
      6
      10 7 8 9 1 5
      """
    Then the sorting harness output should be:
      """
      1 5 7 8 9 10
      """

  Scenario: swaps two quicksort positions
    Given the bddtesting harness is built
    When I run sorting function "swap_quicksort" with input:
      """
      4
      1 2 3 4
      1 3
      """
    Then the sorting harness output should be:
      """
      1 4 3 2
      """

  Scenario: partitions quicksort around the pivot
    Given the bddtesting harness is built
    When I run sorting function "partition_quicksort" with input:
      """
      7
      10 80 30 90 40 50 70
      0 6
      """
    Then the sorting harness output should be:
      """
      4
      10 30 40 50 70 90 80
      """

  Scenario: performs dutch national flag sort
    Given the bddtesting harness is built
    When I run sorting function "dnfsort" with input:
      """
      4
      0 0 1 2
      """
    Then the sorting harness output should be:
      """
      0 0 1 2
      """

  Scenario: produces wave sorted output
    Given the bddtesting harness is built
    When I run sorting function "wavesort" with input:
      """
      6
      1 2 3 4 5 6
      """
    Then the sorting harness output should be:
      """
      2 1 4 3 6 5
      """
