Feature: array questions

  Scenario: copies input values into a 1D array
    Given the bddtesting harness is built
    When I run array input with data:
      """
      5
      3 8 13 21 34
      """
    Then the array harness output should be:
      """
      3 8 13 21 34
      """

  Scenario: prints all subarrays of an array
    Given the bddtesting harness is built
    When I run array function "subarray_of_array" with data:
      """
      3
      1 2 3
      """
    Then the array harness output should be:
      """
      1
      1 2
      1 2 3
      2
      2 3
      3
      """

  Scenario: traverses and prints an array
    Given the bddtesting harness is built
    When I run array function "array_traversal" with data:
      """
      3
      4 6 8
      """
    Then the array harness output should be:
      """
      4 6 8
      """

  Scenario: inserts an element at a given position
    Given the bddtesting harness is built
    When I run array function "insert_in_array_at_pos" with data:
      """
      4
      3 99
      10 20 30 40
      """
    Then the array harness output should be:
      """
      10 10 99 30 40
      """

  Scenario: quick sorts an array
    Given the bddtesting harness is built
    When I run array function "quicksort_array" with data:
      """
      6
      5 3 8 6 2 7
      """
    Then the array harness output should be:
      """
      2 3 5 6 7 8
      """

  Scenario: gets pivot index for partitioned quicksort array
    Given the bddtesting harness is built
    When I run array function "pivot_quicksort_array" with data:
      """
      5
      4 3 2 1 5
      """
    Then the array harness output should be:
      """
      4
      4 3 2 1 5
      """

  Scenario: checks if an array is sorted using iteration
    Given the bddtesting harness is built
    When I run array function "check_array_sorted" with data:
      """
      5
      1 2 3 4 5
      """
    Then the array harness output should be:
      """
      1
      """

  Scenario: checks if an array is sorted using recursion
    Given the bddtesting harness is built
    When I run array function "check_if_array_sorted" with data:
      """
      5
      1 3 5 7 9
      """
    Then the array harness output should be:
      """
      1
      """

  Scenario: checks if an array is sorted even if rotated
    Given the bddtesting harness is built
    When I run array function "check_if_array_sorted_even_if_rotated" with data:
      """
      5
      3 4 5 1 2
      """
    Then the array harness output should be:
      """
      1
      """

  Scenario: reverses an array
    Given the bddtesting harness is built
    When I run array function "reverse_array" with data:
      """
      5
      1 2 3 4 5
      """
    Then the array harness output should be:
      """
      5 4 3 2 1
      """

  Scenario: finds second smallest and second largest values
    Given the bddtesting harness is built
    When I run array function "second_largest_and_smallest_element_in_array" with data:
      """
      6
      7 1 9 3 5 2
      """
    Then the array harness output should be:
      """
      2 7
      """

  Scenario: rotates an array to the right by k positions
    Given the bddtesting harness is built
    When I run array function "rotate_array_k_times_right" with data:
      """
      5
      2
      1 2 3 4 5
      """
    Then the array harness output should be:
      """
      4 5 1 2 3
      """

  Scenario: computes union of two arrays
    Given the bddtesting harness is built
    When I run array function "union_of_array" with data:
      """
      4 5
      1 2 3 4
      3 4 5 6 7
      """
    Then the array harness output should be:
      """
      1 2 3 4 5 6 7
      """

  Scenario: finds a missing number in range 1 to n
    Given the bddtesting harness is built
    When I run array function "find_missing_number_N" with data:
      """
      4
      1 2 4 0
      """
    Then the array harness output should be:
      """
      3
      """

  Scenario: prints distinct elements from an array
    Given the bddtesting harness is built
    When I run array function "distinct_elements_in_array" with data:
      """
      8
      4 2 4 3 2 1 1 5
      """
    Then the array harness output should be:
      """
      1 2 3 4 5
      """

  Scenario: finds longest subarray with sum k
    Given the bddtesting harness is built
    When I run array function "longest_subarray_sum_k" with data:
      """
      6 6
      1 2 3 1 1 1
      """
    Then the array harness output should be:
      """
      4
      """

  Scenario: prints next lexicographic permutation of input vector
    Given the bddtesting harness is built
    When I run array function "lexicographic_greater_permutation_main" with data:
      """
      3
      1 2 3
      """
    Then the array harness output should be:
      """
      1 3 2
      """

  Scenario: finds leaders in an array
    Given the bddtesting harness is built
    When I run array function "leaders_in_array" with data:
      """
      6
      16 17 4 3 5 2
      """
    Then the array harness output should be:
      """
      2 5 17
      """

  Scenario: performs linear search in an array
    Given the bddtesting harness is built
    When I run array function "linear_search_array" with data:
      """
      5 21
      3 8 13 21 34
      """
    Then the array harness output should be:
      """
      1
      """

  Scenario: counts all subarrays having sum k
    Given the bddtesting harness is built
    When I run array function "count_all_subarray_sum_k" with data:
      """
      5 3
      1 2 1 1 1
      """
    Then the array harness output should be:
      """
      3
      """

  Scenario: finds maximum product subarray
    Given the bddtesting harness is built
    When I run array function "max_product_subarray" with data:
      """
      4
      2 3 -2 4
      """
    Then the array harness output should be:
      """
      6
      """

  Scenario: finds first and last occurrences in unsorted array
    Given the bddtesting harness is built
    When I run array function "first_and_last_occurance_of_ele_unsorted_array" with data:
      """
      5 1
      4 1 2 1 3
      """
    Then the array harness output should be:
      """
      2 4
      """

  Scenario: removes duplicates from sorted array values
    Given the bddtesting harness is built
    When I run array function "remove_duplicates_from_sorted_array" with data:
      """
      8
      1 1 2 2 3 4 4 5
      """
    Then the array harness output should be:
      """
      1 2 3 4 5
      """

  Scenario: prints frequency of each number in an array
    Given the bddtesting harness is built
    When I run array function "frequency_of_number_in_array" with data:
      """
      7
      4 4 2 1 2 2 1
      """
    Then the array harness output should be:
      """
      1 2
      2 3
      4 2
      """

  Scenario: moves all zeros to the right of array
    Given the bddtesting harness is built
    When I run array function "move_all_the_zeros_to_right_array" with data:
      """
      7
      0 1 0 3 12 0 5
      """
    Then the array harness output should be:
      """
      1 3 12 5 0 0 0
      """

  Scenario: counts maximum consecutive ones in array
    Given the bddtesting harness is built
    When I run array function "count_max_consc_1s_array" with data:
      """
      6
      1 1 0 1 1 1
      """
    Then the array harness output should be:
      """
      3
      """

  Scenario: rearranges array elements by sign and sorted order
    Given the bddtesting harness is built
    When I run array function "rearrange_elements_by_sign_sorted" with data:
      """
      6
      3 -1 -2 4 -5 6
      """
    Then the array harness output should be:
      """
      3 -5 4 -2 6 -1
      """

  Scenario: counts subarrays with xor k
    Given the bddtesting harness is built
    When I run array function "subarrays_with_xor_k" with data:
      """
      5 6
      4 2 2 6 4
      """
    Then the array harness output should be:
      """
      4
      """

  Scenario: counts inversions in an array
    Given the bddtesting harness is built
    When I run array function "count_inversions_in_array" with data:
      """
      5
      3 1 2 5 4
      """
    Then the array harness output should be:
      """
      3
      """

  Scenario: counts inversions using merge sort recursion
    Given the bddtesting harness is built
    When I run array function "count_inversions_in_array_mergesort" with data:
      """
      5
      3 1 2 5 4
      """
    Then the array harness output should be:
      """
      3
      """

  Scenario: merges two sorted parts and counts split inversions
    Given the bddtesting harness is built
    When I run array function "count_inversions_in_array_merge" with data:
      """
      5 0 2 4
      1 3 5 2 4
      """
    Then the array harness output should be:
      """
      3
      1 2 3 4 5
      """
