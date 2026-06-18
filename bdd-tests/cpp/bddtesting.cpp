#include "test_bridge.hpp"

static int run_array_input()
{
    int n = 0;

    if (!(cin >> n))
    {
        return 1;
    }

    int *values = new int[n];
    array_input(values, n);

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }

        cout << values[i];
    }

    cout << '\n';

    delete[] values;
    return 0;
}

static void print_int_array(const int *values, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }
        cout << values[i];
    }
    cout << '\n';
}

static void print_int_vector(const vector<int> &values)
{
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }
        cout << values[i];
    }
    cout << '\n';
}

static int run_subarray_of_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    subarray_of_array(values, n);
    delete[] values;
    return 0;
}

static int run_array_traversal()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    array_traversal(values, n);
    cout << '\n';
    delete[] values;
    return 0;
}

static int run_insert_in_array_at_pos()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int pos = 0;
    int val = 0;
    if (!(cin >> pos >> val))
    {
        return 1;
    }

    int *values = new int[n + 1];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int size = n;
    insert_in_array(values, size, pos, val);
    print_int_array(values, size);

    delete[] values;
    return 0;
}

static int run_quicksort_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    quicksort_array(values, n, 0, n - 1);
    print_int_array(values, n);
    delete[] values;
    return 0;
}

static int run_pivot_quicksort_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    int pivot = pivot_quicksort_array(values, n, 0, n - 1);
    cout << pivot << '\n';
    print_int_array(values, n);
    delete[] values;
    return 0;
}

static int run_check_array_sorted()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << check_array_sorted(values, n) << '\n';
    delete[] values;
    return 0;
}

static int run_check_if_array_sorted()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << check_if_array_sorted(values, n) << '\n';
    delete[] values;
    return 0;
}

static int run_check_if_array_sorted_even_if_rotated()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << check_if_array_sorted_even_if_rotated(values, n) << '\n';
    delete[] values;
    return 0;
}

static int run_reverse_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    reverse_array(values, n);
    print_int_array(values, n);
    delete[] values;
    return 0;
}

static int run_second_largest_and_smallest_element_in_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    second_largest_and_smallest_element_in_array(values, n);
    cout << '\n';
    delete[] values;
    return 0;
}

static int run_rotate_array_k_times_right()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int k = 0;
    if (!(cin >> k))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    rotate_array_k_times_right(values, n, k);
    print_int_array(values, n);
    delete[] values;
    return 0;
}

static int run_union_of_array()
{
    int an = 0;
    int bn = 0;
    if (!(cin >> an >> bn))
    {
        return 1;
    }

    int *a = new int[an];
    int *b = new int[bn];

    for (int i = 0; i < an; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < bn; ++i)
    {
        cin >> b[i];
    }

    vector<int> result = union_of_array(a, b, an, bn);
    print_int_vector(result);

    delete[] a;
    delete[] b;
    return 0;
}

static int run_find_missing_number_N()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << find_missing_number_N(values, n) << '\n';
    delete[] values;
    return 0;
}

static int run_distinct_elements_in_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    distinct_elements_in_array(values, n);
    cout << '\n';
    delete[] values;
    return 0;
}

static int run_longest_subarray_sum_k()
{
    int n = 0;
    int k = 0;
    if (!(cin >> n >> k))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << longest_subarray_sum_k(values, n, k) << '\n';
    delete[] values;
    return 0;
}

static int run_lexicographic_greater_permutation_main()
{
    lexicographic_greater_permutation_main();
    cout << '\n';
    return 0;
}

static int run_leaders_in_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    vector<int> result = leaders_in_array(values, n);
    print_int_vector(result);
    delete[] values;
    return 0;
}

static int run_linear_search_array()
{
    int n = 0;
    int key = 0;
    if (!(cin >> n >> key))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << linear_search_array(values, n, key) << '\n';
    delete[] values;
    return 0;
}

static int run_count_all_subarray_sum_k()
{
    int n = 0;
    int k = 0;
    if (!(cin >> n >> k))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << count_all_subarray_sum_k(values, n, k) << '\n';
    delete[] values;
    return 0;
}

static int run_max_product_subarray()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << max_product_subarray(values, n) << '\n';
    delete[] values;
    return 0;
}

static int run_first_and_last_occurance_of_ele_unsorted_array()
{
    int n = 0;
    int key = 0;
    if (!(cin >> n >> key))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    vector<int> ans;
    vector<int> result = first_and_last_occurance_of_ele_unsorted_array(values, key, 0, n, ans);
    print_int_vector(result);
    delete[] values;
    return 0;
}

static int run_remove_duplicates_from_sorted_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    remove_duplicates_from_sorted_array(values);
    print_int_vector(values);
    return 0;
}

static int run_frequency_of_number_in_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    frequency_of_number_in_array(values, n);
    delete[] values;
    return 0;
}

static int run_move_all_the_zeros_to_right_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    move_all_the_zeros_to_right_array(values, n);
    print_int_array(values, n);
    delete[] values;
    return 0;
}

static int run_count_max_consc_1s_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << count_max_consc_1s_array(values, n) << '\n';
    delete[] values;
    return 0;
}

static int run_rearrange_elements_by_sign_sorted()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    rearrange_elements_by_sign_sorted(values, n);
    print_int_array(values, n);
    delete[] values;
    return 0;
}

static int run_subarrays_with_xor_k()
{
    int n = 0;
    int k = 0;
    if (!(cin >> n >> k))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << subarrays_with_xor_k(values, n, k) << '\n';
    delete[] values;
    return 0;
}

static int run_count_inversions_in_array()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << count_inversions_in_array(values, n) << '\n';
    delete[] values;
    return 0;
}

static int run_count_inversions_in_array_mergesort()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << count_inversions_in_array_mergesort(values, 0, n - 1) << '\n';
    delete[] values;
    return 0;
}

static int run_count_inversions_in_array_merge()
{
    int n = 0;
    int l = 0;
    int m = 0;
    int e = 0;
    if (!(cin >> n >> l >> m >> e))
    {
        return 1;
    }
    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    cout << count_inversions_in_array_merge(values, l, m, e) << '\n';
    print_int_array(values, n);
    delete[] values;
    return 0;
}

static int run_input_string()
{
    string value;
    cin >> ws;
    input_string(value);
    cout << value << '\n';
    return 0;
}

static int run_print_string()
{
    string value;
    cin >> ws;
    getline(cin, value);
    print_string(value);
    cout << '\n';
    return 0;
}

static int run_print_string_by_char()
{
    string value;
    cin >> ws;
    getline(cin, value);
    print_string_by_char(value);
    cout << '\n';
    return 0;
}

static int run_lbstar()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    lbstar(n);
    return 0;
}

static int run_rbstar()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    rbstar(n);
    return 0;
}

static int run_lastar()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    lastar(n);
    return 0;
}

static int run_equilateral_triangle_pattern()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    equilateral_triangle_pattern(n);
    return 0;
}

static int run_diamond_pattern()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    diamond_pattern(n);
    return 0;
}

static int run_left_base_triangle_pattern()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    left_base_triangle_pattern(n);
    return 0;
}

static int run_right_base_triangle_pattern()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    right_base_triangle_pattern(n);
    return 0;
}

static int run_pascal_triangle()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    pascal_triangle(n);
    return 0;
}

template <typename Fn>
static int run_single_int(Fn fn)
{
    int value = 0;
    if (!(cin >> value))
    {
        return 1;
    }

    cout << fn(value) << '\n';
    return 0;
}

template <typename Fn>
static int run_two_ints(Fn fn)
{
    int first = 0;
    int second = 0;
    if (!(cin >> first >> second))
    {
        return 1;
    }

    cout << fn(first, second) << '\n';
    return 0;
}

template <typename Fn>
static int run_int_array(Fn fn)
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    cout << fn(values, n) << '\n';
    delete[] values;
    return 0;
}

template <typename Fn>
static int run_divisors(Fn fn)
{
    long long value = 0;
    if (!(cin >> value))
    {
        return 1;
    }

    fn(value);
    cout << '\n';
    return 0;
}

template <typename Fn>
static int run_vector_input_sort(Fn fn)
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    fn(values);

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }

        cout << values[i];
    }

    cout << '\n';
    return 0;
}

template <typename Fn>
static int run_binary_search(Fn fn)
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int target = 0;
    if (!(cin >> target))
    {
        return 1;
    }

    cout << fn(values, target) << '\n';
    return 0;
}

template <typename Fn>
static int run_dnfsort(Fn fn)
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    int *values = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    fn(values, n);

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }

        cout << values[i];
    }

    cout << '\n';
    delete[] values;
    return 0;
}

template <typename Fn>
static int run_wavesort(Fn fn)
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    fn(values.data(), n);

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }

        cout << values[i];
    }

    cout << '\n';
    return 0;
}

template <typename Fn>
static int run_merge(Fn fn)
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int b = 0;
    int mid = 0;
    int e = 0;
    if (!(cin >> b >> mid >> e))
    {
        return 1;
    }

    fn(values, b, mid, e);

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }

        cout << values[i];
    }

    cout << '\n';
    return 0;
}

template <typename Fn>
static int run_swap_quicksort(Fn fn)
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int x = 0;
    int y = 0;
    if (!(cin >> x >> y))
    {
        return 1;
    }

    fn(values, x, y);

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }

        cout << values[i];
    }

    cout << '\n';
    return 0;
}

template <typename Fn>
static int run_partition_quicksort(Fn fn)
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int b = 0;
    int e = 0;
    if (!(cin >> b >> e))
    {
        return 1;
    }

    int pivotIndex = fn(values, b, e);
    cout << pivotIndex << '\n';
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            cout << ' ';
        }

        cout << values[i];
    }

    cout << '\n';
    return 0;
}

static int run_getbit()
{
    int n = 0;
    int i = 0;
    if (!(cin >> n >> i))
    {
        return 1;
    }
    cout << getbit(n, i) << '\n';
    return 0;
}

static int run_setbit()
{
    int n = 0;
    int i = 0;
    if (!(cin >> n >> i))
    {
        return 1;
    }
    cout << setbit(n, i) << '\n';
    return 0;
}

static int run_clearbit()
{
    int n = 0;
    int i = 0;
    if (!(cin >> n >> i))
    {
        return 1;
    }
    cout << clearbit(n, i) << '\n';
    return 0;
}

static int run_updatebit()
{
    int n = 0;
    int i = 0;
    int value = 0;
    if (!(cin >> n >> i >> value))
    {
        return 1;
    }
    cout << updatebit(n, i, value) << '\n';
    return 0;
}

static int run_binary_representation_of_number()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    binary_representation_of_number(n);
    cout << '\n';
    return 0;
}

static int run_count0s1s_in_binary_represent_of_number()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    vector<int> counts = count0s1s_in_binary_represent_of_number(n);
    print_int_vector(counts);
    return 0;
}

static int run_onescomplement()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }
    cout << onescomplement(n) << '\n';
    return 0;
}

static bool read_linked_list(llnode *&head)
{
    int n = 0;
    if (!(cin >> n))
    {
        return false;
    }

    head = nullptr;
    for (int i = 0; i < n; ++i)
    {
        int value = 0;
        if (!(cin >> value))
        {
            return false;
        }
        ll_insertattail(head, value);
    }

    return true;
}

static void print_linked_list_pointers(llnode *head)
{
    llnode *current = head;
    while (current != nullptr)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL\n";
}

static void free_linked_list(llnode *head)
{
    while (head != nullptr)
    {
        llnode *next = head->next;
        delete head;
        head = next;
    }
}

static int run_ll_insertathead()
{
    int n = 0;
    if (!(cin >> n))
    {
        return 1;
    }

    llnode *head = nullptr;
    for (int i = 0; i < n; ++i)
    {
        int value = 0;
        if (!(cin >> value))
        {
            free_linked_list(head);
            return 1;
        }
        ll_insertathead(head, value);
    }

    print_linked_list_pointers(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_insertattail()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    print_linked_list_pointers(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_display()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    print_linked_list_pointers(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_search()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    int key = 0;
    if (!(cin >> key))
    {
        free_linked_list(head);
        return 1;
    }

    cout << ll_search(head, key) << '\n';
    free_linked_list(head);
    return 0;
}

static int run_ll_deletee()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    int value = 0;
    if (!(cin >> value))
    {
        free_linked_list(head);
        return 1;
    }

    ll_deletee(head, value);
    print_linked_list_pointers(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_length()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    cout << ll_length(head) << '\n';
    free_linked_list(head);
    return 0;
}

static int run_ll_reverse()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    ll_reverse(head);
    print_linked_list_pointers(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_reverseknodes()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    int k = 0;
    if (!(cin >> k))
    {
        free_linked_list(head);
        return 1;
    }

    head = ll_reverseknodes(head, k);
    print_linked_list_pointers(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_makecycle()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    int pos = 0;
    if (!(cin >> pos))
    {
        free_linked_list(head);
        return 1;
    }

    ll_makecycle(head, pos);
    cout << ll_detectcycle(head) << '\n';
    ll_deletecycle(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_detectcycle()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    int pos = 0;
    if (!(cin >> pos))
    {
        free_linked_list(head);
        return 1;
    }

    ll_makecycle(head, pos);
    cout << ll_detectcycle(head) << '\n';
    ll_deletecycle(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_deletecycle()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    int pos = 0;
    if (!(cin >> pos))
    {
        free_linked_list(head);
        return 1;
    }

    ll_makecycle(head, pos);
    ll_deletecycle(head);
    print_linked_list_pointers(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_bubblesort()
{
    llnode *head = nullptr;
    if (!read_linked_list(head))
    {
        return 1;
    }

    ll_bubblesort(head);
    print_linked_list_pointers(head);
    free_linked_list(head);
    return 0;
}

static int run_ll_addtwonumbers()
{
    llnode *first = nullptr;
    if (!read_linked_list(first))
    {
        return 1;
    }

    llnode *second = nullptr;
    if (!read_linked_list(second))
    {
        free_linked_list(first);
        return 1;
    }

    llnode *first_cursor = first;
    llnode *second_cursor = second;
    llnode *result = ll_addtwonumbers(first_cursor, second_cursor);
    print_linked_list_pointers(result);

    free_linked_list(first);
    free_linked_list(second);
    free_linked_list(result);
    return 0;
}

static int **read_matrix(int rows, int cols)
{
    return matrix_input(rows, cols);
}

static void free_matrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

static int run_matrix_input()
{
    int rows = 0;
    int cols = 0;
    if (!(cin >> rows >> cols))
    {
        return 1;
    }

    int **matrix = read_matrix(rows, cols);
    print_matrix(matrix, rows, cols);
    free_matrix(matrix, rows);
    return 0;
}

static int run_print_matrix()
{
    int rows = 0;
    int cols = 0;
    if (!(cin >> rows >> cols))
    {
        return 1;
    }

    int **matrix = read_matrix(rows, cols);
    print_matrix(matrix, rows, cols);
    free_matrix(matrix, rows);
    return 0;
}

static int run_set_matrix_zero()
{
    int rows = 0;
    int cols = 0;
    if (!(cin >> rows >> cols))
    {
        return 1;
    }

    int **matrix = read_matrix(rows, cols);
    set_matrix_zero(matrix, rows, cols);
    print_matrix(matrix, rows, cols);
    free_matrix(matrix, rows);
    return 0;
}

static int run_rotate_matrix_clockwise()
{
    int rows = 0;
    int cols = 0;
    if (!(cin >> rows >> cols))
    {
        return 1;
    }

    int **matrix = read_matrix(rows, cols);
    rotate_matrix_clockwise(matrix, rows, cols);
    print_matrix(matrix, rows, cols);
    free_matrix(matrix, rows);
    return 0;
}

static int run_spiral_traversal_matrix()
{
    int rows = 0;
    int cols = 0;
    if (!(cin >> rows >> cols))
    {
        return 1;
    }

    int **matrix = read_matrix(rows, cols);
    spiral_traversal_matrix(matrix, rows, cols);
    cout << '\n';
    free_matrix(matrix, rows);
    return 0;
}

int main(int argc, char **argv)
{
    string function_name = (argc > 1) ? argv[1] : "array_input";

    if (function_name == "array_input")
    {
        return run_array_input();
    }

    if (function_name == "subarray_of_array")
    {
        return run_subarray_of_array();
    }

    if (function_name == "array_traversal")
    {
        return run_array_traversal();
    }

    if (function_name == "insert_in_array_at_pos")
    {
        return run_insert_in_array_at_pos();
    }

    if (function_name == "quicksort_array")
    {
        return run_quicksort_array();
    }

    if (function_name == "pivot_quicksort_array")
    {
        return run_pivot_quicksort_array();
    }

    if (function_name == "check_array_sorted")
    {
        return run_check_array_sorted();
    }

    if (function_name == "check_if_array_sorted")
    {
        return run_check_if_array_sorted();
    }

    if (function_name == "check_if_array_sorted_even_if_rotated")
    {
        return run_check_if_array_sorted_even_if_rotated();
    }

    if (function_name == "reverse_array")
    {
        return run_reverse_array();
    }

    if (function_name == "second_largest_and_smallest_element_in_array")
    {
        return run_second_largest_and_smallest_element_in_array();
    }

    if (function_name == "rotate_array_k_times_right")
    {
        return run_rotate_array_k_times_right();
    }

    if (function_name == "union_of_array")
    {
        return run_union_of_array();
    }

    if (function_name == "find_missing_number_N")
    {
        return run_find_missing_number_N();
    }

    if (function_name == "distinct_elements_in_array")
    {
        return run_distinct_elements_in_array();
    }

    if (function_name == "longest_subarray_sum_k")
    {
        return run_longest_subarray_sum_k();
    }

    if (function_name == "lexicographic_greater_permutation_main")
    {
        return run_lexicographic_greater_permutation_main();
    }

    if (function_name == "leaders_in_array")
    {
        return run_leaders_in_array();
    }

    if (function_name == "linear_search_array")
    {
        return run_linear_search_array();
    }

    if (function_name == "count_all_subarray_sum_k")
    {
        return run_count_all_subarray_sum_k();
    }

    if (function_name == "max_product_subarray")
    {
        return run_max_product_subarray();
    }

    if (function_name == "first_and_last_occurance_of_ele_unsorted_array")
    {
        return run_first_and_last_occurance_of_ele_unsorted_array();
    }

    if (function_name == "remove_duplicates_from_sorted_array")
    {
        return run_remove_duplicates_from_sorted_array();
    }

    if (function_name == "frequency_of_number_in_array")
    {
        return run_frequency_of_number_in_array();
    }

    if (function_name == "move_all_the_zeros_to_right_array")
    {
        return run_move_all_the_zeros_to_right_array();
    }

    if (function_name == "count_max_consc_1s_array")
    {
        return run_count_max_consc_1s_array();
    }

    if (function_name == "rearrange_elements_by_sign_sorted")
    {
        return run_rearrange_elements_by_sign_sorted();
    }

    if (function_name == "subarrays_with_xor_k")
    {
        return run_subarrays_with_xor_k();
    }

    if (function_name == "count_inversions_in_array")
    {
        return run_count_inversions_in_array();
    }

    if (function_name == "count_inversions_in_array_mergesort")
    {
        return run_count_inversions_in_array_mergesort();
    }

    if (function_name == "count_inversions_in_array_merge")
    {
        return run_count_inversions_in_array_merge();
    }

    if (function_name == "input_string")
    {
        return run_input_string();
    }

    if (function_name == "print_string")
    {
        return run_print_string();
    }

    if (function_name == "print_string_by_char")
    {
        return run_print_string_by_char();
    }

    if (function_name == "getbit")
    {
        return run_getbit();
    }

    if (function_name == "setbit")
    {
        return run_setbit();
    }

    if (function_name == "clearbit")
    {
        return run_clearbit();
    }

    if (function_name == "updatebit")
    {
        return run_updatebit();
    }

    if (function_name == "binary_representation_of_number")
    {
        return run_binary_representation_of_number();
    }

    if (function_name == "count0s1s_in_binary_represent_of_number")
    {
        return run_count0s1s_in_binary_represent_of_number();
    }

    if (function_name == "onescomplement")
    {
        return run_onescomplement();
    }

    if (function_name == "matrix_input")
    {
        return run_matrix_input();
    }

    if (function_name == "print_matrix")
    {
        return run_print_matrix();
    }

    if (function_name == "set_matrix_zero")
    {
        return run_set_matrix_zero();
    }

    if (function_name == "rotate_matrix_clockwise")
    {
        return run_rotate_matrix_clockwise();
    }

    if (function_name == "spiral_traversal_matrix")
    {
        return run_spiral_traversal_matrix();
    }

    if (function_name == "ll_insertathead")
    {
        return run_ll_insertathead();
    }

    if (function_name == "ll_insertattail")
    {
        return run_ll_insertattail();
    }

    if (function_name == "ll_display")
    {
        return run_ll_display();
    }

    if (function_name == "ll_search")
    {
        return run_ll_search();
    }

    if (function_name == "ll_deletee")
    {
        return run_ll_deletee();
    }

    if (function_name == "ll_length")
    {
        return run_ll_length();
    }

    if (function_name == "ll_reverse")
    {
        return run_ll_reverse();
    }

    if (function_name == "ll_reverseknodes")
    {
        return run_ll_reverseknodes();
    }

    if (function_name == "ll_makecycle")
    {
        return run_ll_makecycle();
    }

    if (function_name == "ll_detectcycle")
    {
        return run_ll_detectcycle();
    }

    if (function_name == "ll_deletecycle")
    {
        return run_ll_deletecycle();
    }

    if (function_name == "ll_bubblesort")
    {
        return run_ll_bubblesort();
    }

    if (function_name == "ll_addtwonumbers")
    {
        return run_ll_addtwonumbers();
    }

    if (function_name == "lbstar")
    {
        return run_lbstar();
    }

    if (function_name == "rbstar")
    {
        return run_rbstar();
    }

    if (function_name == "lastar")
    {
        return run_lastar();
    }

    if (function_name == "equilateral_triangle_pattern")
    {
        return run_equilateral_triangle_pattern();
    }

    if (function_name == "diamond_pattern")
    {
        return run_diamond_pattern();
    }

    if (function_name == "left_base_triangle_pattern")
    {
        return run_left_base_triangle_pattern();
    }

    if (function_name == "right_base_triangle_pattern")
    {
        return run_right_base_triangle_pattern();
    }

    if (function_name == "pascal_triangle")
    {
        return run_pascal_triangle();
    }

    if (function_name == "gcd")
    {
        return run_two_ints([](int a, int b) { return gcd(a, b); });
    }

    if (function_name == "find_gcd")
    {
        return run_int_array(find_gcd);
    }

    if (function_name == "find_lcm")
    {
        return run_int_array(find_lcm);
    }

    if (function_name == "check_armstrong")
    {
        return run_single_int(check_armstrong);
    }

    if (function_name == "count_digits")
    {
        return run_single_int(count_digits);
    }

    if (function_name == "isEven")
    {
        return run_single_int(isEven);
    }

    if (function_name == "isOdd")
    {
        return run_single_int(isOdd);
    }

    if (function_name == "shorter_angle_bw_hour_and_minute")
    {
        return run_two_ints(shorter_angle_bw_hour_and_minute);
    }

    if (function_name == "isperfectnumber")
    {
        return run_single_int(isperfectnumber);
    }

    if (function_name == "check_2_numbers_same")
    {
        return run_two_ints(check_2_numbers_same);
    }

    if (function_name == "divisor_of_natural_number")
    {
        return run_divisors(divisor_of_natural_number);
    }

    if (function_name == "fibonaci_nth_term")
    {
        return run_single_int(fibonaci_nth_term);
    }

    if (function_name == "binomoal_coeff")
    {
        return run_two_ints(binomoal_coeff);
    }

    if (function_name == "add_2_numbers_without_plus_minus")
    {
        return run_two_ints(add_2_numbers_without_plus_minus);
    }

    if (function_name == "binarysearch")
    {
        return run_binary_search(static_cast<int (*)(vector<int> &, int)>(binarysearch));
    }

    if (function_name == "bubblesort")
    {
        return run_vector_input_sort(bubblesort);
    }

    if (function_name == "insertionsort")
    {
        return run_vector_input_sort(insertionsort);
    }

    if (function_name == "selectionsort")
    {
        return run_vector_input_sort(selectionsort);
    }

    if (function_name == "mergesort")
    {
        return run_vector_input_sort([](vector<int> &values) {
            if (!values.empty())
            {
                mergesort(values, 0, static_cast<int>(values.size()) - 1);
            }
        });
    }

    if (function_name == "quicksort")
    {
        return run_vector_input_sort([](vector<int> &values) {
            if (!values.empty())
            {
                quicksort(values, 0, static_cast<int>(values.size()) - 1);
            }
        });
    }

    if (function_name == "dnfsort")
    {
        return run_dnfsort([](int *values, int n) { dnfsort(values, n); });
    }

    if (function_name == "wavesort")
    {
        return run_wavesort(wavesort);
    }

    if (function_name == "merge")
    {
        return run_merge([](vector<int> &values, int b, int mid, int e) {
            merge(values, b, mid, e);
        });
    }

    if (function_name == "swap_quicksort")
    {
        return run_swap_quicksort(swap_quicksort);
    }

    if (function_name == "partition_quicksort")
    {
        return run_partition_quicksort(partition_quicksort);
    }

    cerr << "Unknown function: " << function_name << '\n';
    return 2;
}
