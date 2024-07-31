#include <iostream>
#include <stack>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <math.h>
#include <atomic>
#include <condition_variable>
#include <map>
#include <set>
#include <string>

#define ll long long
#define ld long double

/*
 * The internal command that is run by the C++ compiler to execute the program is
 * g++ main.cpp -o main.out
*/

/**
 * Deep Copy vs Shallow Copy
 *
 * Shallow copy doesn't create a seprate copy of the variables, it copies the pointer not the data.
 * In deep copy, the data is cloned and the memory is not shared.
 * Default constructor is an example of Shallow copy.
 *
 * Shallow Copy is faster compared to Deep Copy.
 * Shallow Copy reflects changes to both the new & the copied object.
*/

/**
 * RUNTIME ERROS:-
 *
 * SIGSEV:
 * - The most common error i.e. a segmentation fault.
 * - This is caused when something out of scope is trying to be accessed.
 * - For example, an array index that goes out of it's scope causing buffer overflow
 * or anincorrectly initialized pointer.
 * - This happens when a program tries to write beyond it's allocated memory.
 *
 * SIGXFSZ:
 * - This means the "output limit is exceeded", and the program printed too much output data than anticipated.
 *
 * SIGFPE:
 * - This means a "Floating Point Error".
 * - This occurs usaually when we are trying to divide a number by zero or trying to do square root of a negative number.
 *
 * SIGABRT:
 * - These are raised by the program itself.
 * - The program gets aborted in the middle of execution, due to inefficient memory.
 *
 * NZEC:
 * - This means the program exited returning a value different from 0 to shell.
 *
 * MEMORY-LIMIT-EXCEEDED:
 * - This means the program tried to allocate memory beyond the memory allocated.
 *
 * SIGTERM:
 * - Generic Signal used to cause program termination, this can be blocked by the user.
 *
 *
 *
 *
*/

using namespace std;
/**
 * The keyword using technically means, use this whenever you can.
 * This refers, in this case, to the std namespace.
 * So whenever the computer comes across cout, cin, endl or anything of that matter,
 * it will read it as std::cout, std::cin or std::endl.
*/

/**
 * STATIC
 * When a variable is made static, the scope of the variable gets limited to that file only.
 * When used with value inside a function, these static variables etain there values between fucntion calls.
 *
 *
 * When used a STATIC member functions, that means function is independent of any obvject of the class.
 * It can be called using using class name without actually creating the object of the class.
 *
 * Static member functions cannot accept non-static data members directly because they don't have the access to object's state.
 * These can be useful  for operations that are not specific to any object but are related to the class as a  whole.
*/

/**
 * Class vs Structure
 *
 * CLASSES:
 * - User Defined data type with it's own data members and member functions
 * - NULL Values are possible.
 * - By default the data members and member functions are private.
 *
 * STRUCTURE:
 * - User defined data type to group items of different types together.
 * - NULL Values are not possible.
 * - The Data Members are public by default.
 *
*/

/* Virtual Class Implementation */

/**
 * Early Binding is the scenario where the compiler matches the function call with correct function definition at compile time.
 * Late Binding happens in scenario where the compiler matches the function call with it;s definition at run-time.
 *
 * Pure Virtual Function is also known as Abstract Class and, it has no definition of itself in the parent class.
 * To create such a function 0 is assigned to that particular function.
 *
 * The concept of "Interfaces" is alien to C++, but is pretty nessecary in Java.
 * It is used to achieve abstraction and Multiple Inheritence in Java.
 *
 * Interface is similar to an abstract class with the difference that all it's functions are pur virtual functions,
 * and, it has no member variables.
 *
 * The derived classes must implement each of it's virtual functions.
*/

class base
    {
        public:

        virtual void print()
            { //The keyword virtual enforces the binding of the pointer to the function of child class during run-time.
                cout<<"This is the print function of base class"<<endl;
            }

        void display()
            {
                cout<<"This is the display function of base class"<<endl;
            }

    };

class child: public base
    {
        public:

        void print()
            {
                cout<<"This is the print function of child class"<<endl;
            }

        void display()
            {
                cout<<"This is the display function of child class"<<endl;
            }

    };

void virtual_class_demo(){

    base *bptr = new child();
    /**
     * The above is a demonstration that we created a pointer of type of base class pointing to the child class object.
    */
    bptr->print(); // Here, because the print function in the base class is a virtual function, gets overriden by child.
    bptr->display(); // While, in this case this doesn't happen so because, display is not a virtual function in the base class.
}


/* DIAMOND PROBLEM IN C++ */

/**
 * Inheritence in itself is a very useful concept in programming when it comes to Object Oriented Programming.
 * But, not all type of inheritence have an advantage, some of these inheritence types might carry some of it's drawbacks.
 *
 * The most famous example of this is DIAMOND PROBLEM IN MULTIPLE INHERITENCE.
 * So, let's say we have a class named BASE, which is inherited by PARENT-1 and PARENT-2.
 * Now, PARENT-1 and PARENT-2 both are inherited into a single class named CHILD.
 * This will cause a error to come up, as both the classes inherited into the CHILD class will have the same BASE class inherited into it.
 * This will lead to confusion during method resolution and member access.
 *
 * This issue can be resolved using `Virtual Inheritence`.
*/

class base_diamond{
    public:
        void fun(){
            cout<<"Hello World";
        }
};

class parent_1_diamond: virtual public base_diamond{
    public:
};

class parent_2_diamond: virtual public base_diamond{
    public:
};

class child_diamond: public parent_1_diamond, public parent_2_diamond{

};

void main_diamond(){
    child_diamond* obj = new child_diamond();
    obj->fun();
    return;
}

/**
 * POINTERS:
 * - Pointers are special type of variables that contain address to another variable.
 *
 * Types of pointers in C++:
 *
 * 1. VOID-POINTER:
 * - Special type of pointer in C++ which represents the absence of type.
 * - Flexible as they can point to any type of data-type
 * - Can't be directyl derefrenced and needs to be transformed into some data-type to be dereferenced.
 *
 * 2. INVALID-POINTER:
 * - A Pointer pointing to a valid address but not to a valid element.
 * - For example, an un-initialized pointer variable is an example of invalid pointer.
 *
 * 3. NULL-POINTER:
 * - Pointer that points to no where and not just an invalid address.
 *
 * 4. OPAQUE-POINTER:
 * - Pointer that points to a structure whose contents are not known at the time of definition.
 *
 * 5. NEAR-POINTER:
 * - Near Pointers are used to store 16-bit addresses.
 * - The Size of near pointer is 2 bytes.
 * - Using a Near Pointer we can only reach upto 64KBs of data in the Data Segment.
 *
 * 6. FAR-POINTER:
 * - It stores data in two 16-bit registers that allow it to access the memory outside the current segment.
 * - In Far Pointer, the segment can't be modified as increasing/decreasing only changes offset but not segment address.
 * - The Size of Far Pointer is 4 bytes.
 *
 * 7. HUGE-POINTER:
 * - A Huge Pointer stores addresses in 2 registers, similar to a far pointer allowing it to access outside the current segment.
 * - Both offset and segement address is changed. That is why we can jump from 1 segment to another.
 * - The Huge Pointer always compares the absolute address.
 * - The Size of Huge Pointer is 4 bytes.
 *
 * 8. DANGLING-POINTER:
 * - A pointer to a memory location that has been deleted is called a Dangling Pointer.
 *
 * 9. WILD-POINTER:
 * - A Pointer that has not been initialized to anything is known as Wild Pointer.
 *
*/

// Linked List
class llnode
{
public:
    int data;
    llnode* next; /*The type of pointer is same as the class, cause the pointer points to the next node.*/

    llnode(int val)
    {
        data = val;
        next = NULL;
    }
};

void ll_insertathead(llnode* &head, int val);
void ll_insertattail(llnode* &head, int val);
void ll_display(llnode* head);
bool ll_search(llnode* head,int key);
void ll_deletee(llnode* &head, int val);
void ll_deleteathead(llnode* &head);
void ll_make_intersect(llnode*, llnode*,int);
int ll_intersection(llnode*,llnode*);
int ll_length(llnode*);
void ll_reverse(llnode* &head);
llnode* ll_reverseknodes(llnode* &head,int k);
void ll_makecycle(llnode* &head,int pos);
bool ll_detectcycle(llnode* head);
void ll_kappend(llnode* &,int ,int );
void ll_deletecycle(llnode* &head);
void ll_bubblesort(llnode* &);
void ll_main();

/* Circular Linked List */

void cll_insertathead(llnode* &head, int val);
void cll_insertattail(llnode* &head, int val);
void cll_deleteathead(llnode* &head);
void cll_deletee(llnode* &head, int pos);
void cll_display(llnode* head);

/* Doubly Linked List */

class dllnode{
    public:
    int data;
    dllnode* next; /*The type of pointer is same as the class, cause the pointer points to the next node.*/
    dllnode* prev;

    dllnode(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};

void dll_insertathead(dllnode* &head, int val);
void dll_insertattail(dllnode* &head, int val);
void dll_deleteathead(dllnode* &head);
void dll_delete(dllnode* &head, int pos);
void dll_display(dllnode* head);

/* Binary Tree */

class btnode{
    public:

    int data;
    btnode* left;
    btnode* right;

    btnode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

    /**
     * In tree, data is stored in hierarichal order. A Tree is a non-linear Hierarichal Data Structure.
     * It consists of nodes and subtrees.
     *
     * Some terminologies associated with the tree:
     * Parent Node: The Node which is predecessor of a node.
     * Child Node: The Node which is immediate successor of a node.
     * Root Node: The top-most node of a tree.
     * Degree of Node: The total count of subtrees attached to that node.
     * Leaf Node: A Node that does not have any child.
     * Anceastor Node: Any predecessor node on path from root to that node.
     * Sibling: Children of same parent node.
     * Depth of a Node: The count of edges from root to that node.
     * Internal Node: A Node with 1 child only.
     * Maximum nodes at level L is 2^L.
     * Maximum nodes in a tree of height H is (2^H) - 1.
     * For N, nodes minimum possible height is log2(N+1).
     *
     * Types of Binary Tree:
     * - Full Binary tree: each internal node has exactly 2 or 0 children.
     * - Perfect Binary tree: All leaf nodes are at same level, and each internal node has 2 children.
     * - Complete Binary tree: When all it's levels are completely filled.
     * - Pathelogical Binary Tree: Each Internal node has a single child, either left or right one.
     * - Skewed Binary Tree: If all it's internal node has exactly 1 child, and either left or right child dominate the tree.
    */
};


// Construct the Binary Tree with preorder and inorder.
btnode* buildTree(vector<int>, vector<int>,int,int,int &);
int search_in_inorder(vector<int>,int,int,int);
int height_bt(btnode*);
int summ_all_nodes_bt(btnode*);
int count_nodes_bt(btnode*);
int diameter_bt(btnode*);
btnode* insertnodebt(btnode*, int);
void deleteDeepestNode(btnode*, btnode*);
btnode* deletenodebt(btnode*,int);
int getLevelNodebt(btnode*,int ,int);

// Display the Binary Tree
void preorder(btnode*);
void inorder(btnode*);
void postorder(btnode*);
void levelorder(btnode*);
void print_kth_level_of_bt(btnode*,int);

// Basic Binary Tree Questiohns
int sum_all_node_kth_lvl_bt(btnode*, int);

/* Sorting Algrithms */

int binarysearch(vector<int>,int h);
void bubblesort(vector<int>&);
void insertionsort(vector<int>&);
void selectionsort(vector<int>&);

void merge(vector<int>&,int,int,int);
void mergesort(vector<int>&,int,int);

void quicksort(vector<int> &,int ,int);
void swap_quicksort(vector<int>&,int,int);
int partition_quicksort(vector<int>&,int,int);
void dnfsort(vector<int> &);
void wavesort(int[],int);

/* Array Operations */

void array_input(int *,int);
void subarray_of_array(int *,int);
void array_traversal(int *,int);
void insert_in_array_at_pos(int *, int &, int ,int );
void quicksort_array(int *, int,int,int);
int pivot_quicksort_array(int *, int,int,int);
bool check_array_sorted(int *,int);
bool check_if_array_sorted(int [],int);
bool check_if_array_sorted_even_if_rotated(int *,int);
void reverse_array(int *,int);
void second_largest_and_smallest_element_in_array(int *,int);
void rotate_array_k_times_right(int *,int,int);
vector<int> union_of_array(int *,int *, int, int);
int find_missing_number_N(int *, int);
void distinct_elements_in_array(int *,int);
int longest_subarray_sum_k(int *, int, int);
void lexicographic_greater_permutation_main();
vector<int> leaders_in_array(int *, int );
bool linear_search_array(int *,int,int);
int count_all_subarray_sum_k(int *, int, int);
int max_product_subarray(int *,int);
vector<int> first_and_last_occurance_of_ele_unsorted_array(int *, int , int , int , vector<int> &);
void remove_duplicates_from_sorted_array(vector<int> &v);
void frequency_of_number_in_array(int *,int);
void move_all_the_zeros_to_right_array(int *,int);
int count_max_consc_1s_array(int *, int);
void rearrange_elements_by_sign_sorted(int*, int);
int subarrays_with_xor_k(int *, int , int );
int count_inversions_in_array(int *, int );
int count_inversions_in_array_mergesort(int*,int,int);
int count_inversions_in_array_merge(int*,int,int,int);

/* Algorithms */

int boyer_moore_voting_algo(int *, int);
vector<int> majority_element_n3(int *, int );

/*Kadane's Algorithm*/

int kadanealgos(vector<int>&,int);
void array_swap(int *,int ,int );

/* Vector Operations */

void vector_input(vector<int> &);
void vector2d_input(vector<vector<int> > &);
void printvectorint(vector<int>&);
void printvectorchar(vector<char>&);
void search_in_rowise_and_colwise_sorted_2d_vector(vector<vector<int> > &,int);
void rotate_vector_k_times_right(vector<int> &,int k);

void subarrays_of_vector(vector<int> &);

int maximum_circular_subarray_sum(vector<int> &);
void spiral_order_traversal(vector<vector<int> >& );

vector<int> display_all_unique_elements_in_vector(vector<int> &v);

void print_subsequence(int,vector<int> &,vector<int> &);
void print_subsequence_whose_sum_is_k(int ,vector<int> &,vector<int> &,int,int );
bool print_1_subsequence_whose_sum_is_k(int ,vector<int> &,vector<int> &,int ,int );

int count_subsequence_whose_sum_is_k(int i,vector<int> &,vector<int> &,int ,int ,int &);



void two_elements_whose_sum_closest_to_0(vector<int> &v);

void generate_and_count_subset_of_set(vector<int> &);

/* String Operations */

void input_string(string &str);
void print_string(string &str);
void print_string_by_char(string &str);

/*Basic Bit Manipulation Operations*/

int getbit(int ,int);
int setbit(int ,int);
int clearbit(int , int);
int updatebit(int , int, int);
void binary_representation_of_number(int );
vector<int> count0s1s_in_binary_represent_of_number(int );
int onescomplement(int );


/* Matrix / 2-D Array Operations */

int** matrix_input(int , int);
void print_matrix(int **, int , int );
void set_matrix_zero(int **, int ,int );
void rotate_matrix_clockwise(int **,int ,int );
void spiral_traversal_matrix(int **, int , int );

/* Stack Implementation with Array */

class stackk{
    int* arr;
    int top;

    public:
    stackk(int n)
        {
            arr = new int[n];
            top= -1;
        }

    void push(int x,int n)
        {
            if(top == n-1)
                {
                    cout<<"\nStack Overflow";
                    return;
                }

            top++;
            arr[top] = x;
        }

    void pop()
        {
            if(top == -1)
                {
                    return;
                }
            top--;
        }

    int peek()
        {
            if(top == -1)
                {
                    cout<<"\nNo element ";
                    return -1;
                }
            return arr[top];
        }

    bool empty()
        {
            return top==-1;
        }
};

/* Stack Implementation using 2 queue */

class stack2queue{
    queue<int> q1;
    queue<int> q2;

    public:
    void push(int x)
        {
            q1.push(x);
        }

    void pop()
        {
            if(q1.empty())
                {
                    return;
                }
            while(q1.size()!=1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
            q1.pop();
            swap(q1,q2);
        }

    int top()
        {
            if(q1.empty())
                {
                    return -1;
                }
            while(q1.size()!=1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
            int x = q1.front();
            q2.push(x);
            swap(q1,q2);
            return x;
        }

    bool empty()
        {
            return q1.empty();
        }

};

/* Stack implementation using 1 Queue */

class stack1queue{


    queue<int> q1;

    public:
    void push(int x)
        {
            q1.push(x);

            if(q1.size() == 1){
                return;
            }

            for(auto i=0;i<q1.size()-1;i++)
                {
                    q1.push(q1.front());
                    q1.pop();
                }
        }

    bool empty(){
        return q1.empty();
    }

    int top(){

        if(q1.empty()){
            return -1;
        }

        return q1.front();
    }

    void pop(){

        if(q1.empty()){
            return;
        }

        q1.pop();
    }
};

/* Stack */

void reverse_stack(stack<int> &st);
void print_stack(stack<int> s);

/* Queue implementation using Linked List */

class queue_ll
	{
		llnode* front;
		llnode* back;

		public:

		queue_ll()
			{
				front = NULL;
				back = NULL;
			}

		void push(int x)
            {
                llnode* n = new llnode(x);

                if(isempty())
                    {
                        front = n;
                        back = n;
                    }

                back->next = n;
                back = n;

            }

		void pop()
            {
                if(isempty())
                    {
                        cout<<"Queue is empty";
                        return ;
                    }
                llnode* todelete = front;
                front = front->next;
                delete todelete;
            }
		int peek()
            {
                if(isempty())
                    {
                        cout<<"Queue is empty";
                        exit(1);
                    }
                return front->data;
            }

		bool isempty()
            {
                if(front == NULL)
                    {
                        return true;
                    }
                else{return false;}
            }
	};

/* Queue using 2 stack */

class queueusing2stack
	{
		stack<int>s1;
        stack<int>s2;

		public:

		void push(int x){
				s1.push(x);
		}

        int top(){
            if(s1.empty() and s2.empty())
                {
                    cout<<"Empty Queue";
                    return -1;
                }
            while(s1.size()!=1){
                s2.push(s1.top());
                s1.pop();
            }
            int x = s1.top();
            s1.pop();
            s2.push(x);
            swap(s1,s2);
            return x;
        }

		int pop(){
            if(s1.empty() and s2.empty())
                {
                    cout<<"Empty Queue";
                    return -1;
                }
            while(s1.size()!=1){
                s2.push(s1.top());
                s1.pop();
            }
            int x = s1.top();
            s1.pop();
            swap(s1,s2);
            return x;

        }

		bool isempty(){
				if(s1.empty()){ return true;}
				return false;
        }

	};

// Mathematical Operations

void swap(int &, int &);
int gcd(int, int);
int find_gcd(int *,int );
long long find_lcm(int *,int );
bool check_armstrong(ll);
ll count_digits(ll);
bool isEven(int n);
bool isOdd(int n);
vector<int> sieve_of_eratosthenes(int );
int shorter_angle_bw_hour_and_minute(int , int );
bool isperfectnumber(int );
bool check_2_numbers_same(int ,int );
int reverse_the_number(int );
void divisor_of_natural_number(ll);
int fibonaci_nth_term(int);
int binomoal_coeff(int ,int);


// String Operations

void print_permutations_of_string(string , string);
bool isPalindromeString(string);
void reverse_words_in_sentence(string str);

// STAR DESIGN PATTERN

void lbstar(int n);
void rbstar(int n);
void lastar(int n);
void equilateral_triangle_pattern(int n);
void diamond_pattern(int n);
void left_base_triangle_pattern(int n);
void right_base_triangle_pattern(int n);
void pascal_triangle(int );


// MAP OPERATIONS
map<int,int> map_input_int();
void print_map_int(map<int,int> );
int good_sequence_frequency_equals_number(int *a, int n);

// Interview Questions

bool balanced_paranthesis_using_stack(string s);



void combination_sum_39_leetcode(int ,int ,vector<int>& ,vector<int>&,vector<vector<int> >&);
void combination_sum_II_40_leetcode(int ,int ,vector<int>& ,vector<int>& ,vector<vector<int> >& );

vector<int> print_sum_of_all_subsets_in_ascending(vector<int>&, int,int ,vector<int>&,vector<int> &);
void subsets_78_leetcode(int ,vector<int> &,vector<int> &,vector<vector<int> > &);
void subsets_II_90_leetcode(int ,vector<int> &,vector<int> &,vector<vector<int> > &);

void permutation_of_vector(vector<int> &,vector<int> &,vector<bool> &);

bool nqueens_51_leetcode(int **,int,int);
bool issafe(int **,int,int,int);

bool sudoku_solver_leetcode_37(vector<vector<char> > &);
bool isvalidsudoku(vector<vector<char> >&,int ,int , char );

void palindrome_partioning_leetcode_131(vector<vector<string> >&ans,string s,string temp,vector<string>v,int index);

void rat_in_maze(vector<vector<int> > &maze,int i,int j,vector<vector<int> > &vis,string s,int n,vector<string>&ans);

void createDuplicateArray(vector<pair<string, int> >& wordidx,vector<string>& v);
void print_all_anagrams_together(vector<string> &v);

int no_of_ways_n_elements_can_be_divided_into_groups(int );
int tiling_problem(int , int );
int ways_to_reach_nth_stair_by_taking_atmost_k_steps(int , int );

int largest_rectangle_on_histogram(vector<int> v);

int knapsack_problem(int,int ,vector<int> ,vector<int> );

int trapping_rainwater(vector<int> &v);

int top_left_to_bottom_right_no_blockagThe(int,int);

void find_highest_and_lowest_frequency_element(int *, int);

int stock_buy_and_sell(int *, int);

vector<int> _2sum(vector<int> &, int);

int _3sum(int *, int, int);

void lexicographic_greater_permutation(vector<int> &v,vector<int> &ans,vector<bool> &map, vector< vector<int> >  &res);

int longest_successive_elements(int *, int);

/*****************************************************************************************************************/
/******************************** MAIN SECTION OF PROGRAM ********************************************************/
/*****************************************************************************************************************/

int main()
{

    vector<int> pre, in;
    int k;
    vector_input(pre);
    vector_input(in);

    int idx = 0;
    btnode* bt = buildTree(pre,in,0,pre.size()-1,idx);
    
    return 0;
}

/*****************************************************************************************************************/
/******************************** END OF MAIN SECTION  ***********************************************************/
/*****************************************************************************************************************/


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/* ARRAY OPERATIONS */

void array_input(int *v,int n)
    {
        // Dynamic Initialization of 1D Array: int *a= new int[n];
        for(int i=0;i<n;i++)
            {
                cin>>v[i];
            }
    }
void array_traversal(int *arr,int n)
    {
        for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
    }
void insert_in_array(int *arr,int &n, int pos, int val)
    {
        for(int i=n-1;i>=0;i--)
            {
                arr[i+1]=arr[i];
            }
        arr[pos-1]=val;
        n++;
    }

void subarray_of_array(int *a,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
    }

    return;
}

bool check_array_sorted(int *a, int n){

    if(n == 0 || n == 1){
        return true;
    }

    for(int i=1;i<n;i++){
        if(a[i-1] > a[i]){
            return false;
        }
    }

    return true;
}

void reverse_array(int *a, int n){
    int start = 0, end = n-1;

    while(start<end){
        swap(a[start],a[end]);
        start++;
        end--;
    }
}


void frequency_of_number_in_array(int *a,int n){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    for(auto x: mp){
        cout<<x.first<<" "<<x.second<<endl;
    }
}

void find_highest_and_lowest_frequency_element(int *a, int n){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    int max_freq = INT_MIN, min_freq = INT_MAX;
    int max_ele = 0, min_ele = 0;

    for(auto x: mp){
        if(x.second>max_freq){
            max_freq = x.second;
            max_ele = x.first;
        }

        if(x.second<min_freq){
            min_freq = x.second;
            min_ele = x.first;
        }
    }

    cout<<max_ele<<" "<<max_freq<<endl;
    cout<<min_ele<<" "<<min_freq<<endl;
}

void second_largest_and_smallest_element_in_array(int *a,int n){

    if(n==0){
        cout<<"Invalid Input";
        return;
    }

    if(n==1){
        cout<<a[0];
        return;
    }

    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;

    for(int i=0;i<n;i++){
        if(a[i]<small){
            second_small = small;
            small = a[i];
        }

        else if(a[i]<second_small && a[i]!=small){
            second_small = a[i];
        }

        if(a[i]>large){
            second_large = large;
            large = a[i];
        }

        else if(a[i]>second_large && a[i]!=large){
            second_large = a[i];
        }
    }

    cout<<second_small<<" "<<second_large;
}

bool check_if_array_sorted_even_if_rotated(int *a,int n){
    if(n==0 || n==1){
        return true;
    }

    int count = 0;

    for(int i=1;i<n;i++){
        if(a[i-1]-a[i]>=0){
            count++;
        }
    }

    if(a[0]<a[n-1]){
        count++;
    }

    return (count<=1);
}

int count_max_consc_1s_array(int *a, int n){

    int maxx = INT_MIN, cnt = 0;

    for(int i=0;i<n;i++){
        if(a[i] == 1){
            cnt++;
        }

        else{
            cnt = 0;
        }
        maxx = max(cnt,maxx);
    }

    return maxx;
}

vector<int> union_of_array(int *a,int *b, int an, int bn){
    set<int> s;
    for(int i=0;i<an;i++){
        s.insert(a[i]);
    }

    for(int i=0;i<bn;i++){
        s.insert(b[i]);
    }

    vector<int> unionn;
    for(auto &x: s){
        unionn.push_back(x);
    }

    return unionn;
}

void move_all_the_zeros_to_right_array(int *a,int n){

    int insertatpos = 0;

    for(int i=0;i<n;i++){
        if(a[i]!=0){
            a[insertatpos] = a[i];
            insertatpos++;
        }
    }

    while(insertatpos < n){
        a[insertatpos] = 0;
        insertatpos++;
    }
}

void rotate_array_k_times_right(int *a,int n,int k){
    if(n==0 || n==1){
        return;
    }

    if(k==n){
        return;
    }

    if(k>n){
        k = k%n;
    }

    for(int i=0;i<k;i++){
        int temp = a[n-1];
        for(int j=n-1;j>0;j--){
            a[j] = a[j-1];
        }
        a[0] = temp;
    }
}

void remove_duplicates_from_sorted_array(vector<int>& a){

    // Time Complexity of this problem is O(n).
    // Space Complexity of this problem is O(1).

    bubblesort(a);

    int n = a.size();
    int j = 0;

    for(int i=0;i<n-1;i++){
        if(a[i] != a[i+1]){
            a[j] = a[i];
            j++;
        }
    }
    a[j++] = a[n-1];
    a.resize(j);

    // explain the code
    // We start from the 0th index and compare it with the next element.
    // If the current element is not equal to the next element, we increment the index j and assign the current element to the jth index.
    // If the current element is equal to the next element, we skip the current element and move to the next element.
    // Than, the last element is assigned to the jth index.
    // We resize the array to the value of j, to remove the duplicates.
}

int max_product_subarray(int *a,int n){
    /**
     * max_prod keeps track of the maximum prodcut ending at current index i
     * min_prod keeps track of the minimum product ending at current index i.
     * Cause a negative number in the array can cause the largest product to become the smallest product.
    */

    int max_prod = a[0],min_prod = a[0],result = a[0];

    for(int i=1;i<n;i++){
        int temp = max(a[i],max(max_prod*a[i],min_prod*a[i]));
        min_prod = min(a[i],min(max_prod*a[i],min_prod*a[i]));
        max_prod = temp;

        result = max(result,max_prod);
    }

    return result;

}

bool linear_search_array(int *a,int n,int num){
    for(int i=0;i<n;i++){
        if(a[i]==num){
            return true;
        }
    }
    return false;
}

vector<int> leaders_in_array(int *a, int n){

    // Leader is an element in array which is greater than all it's elements on the right hand side.
    vector<int> ans;

    int max =  a[n-1];
    ans.push_back(max);

    for(int i=n-1;i>=0;i--){
        if(a[i]>max){
            max = a[i];
            ans.push_back(max);
        }
    }

    return ans;
}

void quicksort_array(int *a, int n,int b, int e){

    if(n==0 || n == 1){
        return;
    }

    if(b<e){
        int pivot = pivot_quicksort_array(a,n,b,e);
        quicksort_array(a,n,b,pivot-1);
        quicksort_array(a,n,pivot+1,e);
    }
}

int pivot_quicksort_array(int *a, int n, int b,int e){
    int pivot = a[e];
    int i = b-1;
    for(int j=b;j<e;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return (i+1);
}


int subarrays_with_xor_k(int *a, int n, int k){

    /**
    * Here, we will be using the concept of prefix XOR.
    * xr: This variable holds the prefix XOR of subarray ending at index i
    * cnt: Count the number of suba-arrays who's XOR is k.
    * mp: A map to store how many times each prefix XOR value has occurred.
    *
    */

    int xr = 0;
    map<int, int> mp;
    mp[xr]++;

    /**
    * This might come in your mind that why we are taking xr = 0 and, than incrementing it's value in the map.
    * At the very beginning, before we start traversing throught the array xr = 0, hence we need to set mp[0] to 1,
    * as initialization of the map.
    *
    * When we encounter a subarray from the start of the array whose XOR equals k, the prefix XOR upto the current index will be k.
    * By initializing mp[0] = 1, we are able to consider the case when the prefix XOR upto the current index is k.
    */

    int cnt = 0;

    for(int i=0;i<n;i++){
        xr = xr ^ a[i]; // Calculate prefix XOR upto index i
        int x = xr ^ k; // Find a value needed to obtain XOR k
        cnt += mp[x]; // Add occurence of x to the count
        mp[xr]++; // Update map with current prefix XOR
    }

    return cnt;
}



int count_inversions_in_array(int *a, int n){

    // Time Complexity of this problem is O(nlogn).
    // Space Complexity of this problem is O(n).

    /**
     * We will be using the concept of divide and conquer to solve this problem via merge sort.
     * We will count the number of inversions while merging the two sorted arrays.
     * Will use a temp array to store the elements of 2 sorted array after merging.
     * The range of the `lar` array is left to mid and `rar` array is mid+1 to right.
     * Using the two-pointers, we select 2 elements from each half,
     * and consider the smallest among them, and insert it into the temp array.
     * After that, remaining elements in both the halfs will be copied as it is into the temp array.
     * Now, just transfer the elements of the temp array to range left to right in the original array.
    */


    return count_inversions_in_array_mergesort(a,0,n-1);

    /*

    Brute Force Approach

    int count = 0; // Count the nuumber of inversions

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

            if(a[i]>a[j]){
                count++;
            }
        }
    }

    return count;

    */
}


int count_inversions_in_array_mergesort(int *a, int b, int e) {
    int cnt = 0;
    if (b >= e) {
        return cnt;
    }
    int mid = (b + e) / 2;
    cnt += count_inversions_in_array_mergesort(a, b, mid);
    cnt += count_inversions_in_array_mergesort(a, mid + 1, e);
    cnt += count_inversions_in_array_merge(a, b, mid, e);

    return cnt;
}

int count_inversions_in_array_merge(int *a, int l, int m, int e) {
    vector<int> temp;
    int left = l;
    int right = m + 1;
    int cnt = 0;

    while (left <= m && right <= e) {
        if (a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        } else {
            temp.push_back(a[right]);
            cnt += m - left + 1;
            right++;
        }
    }

    while (left <= m) {
        temp.push_back(a[left]);
        left++;
    }

    while (right <= e) {
        temp.push_back(a[right]);
        right++;
    }

    for (int i = l; i <= e; i++) {
        a[i] = temp[i - l];
    }

    return cnt;
}



/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/



void vector_input(vector<int>& v)
    {
        int size,x;
        cin>>size;
        for(int i=0;i<size;i++)
            {
                cin>>x;
                v.push_back(x);
            }
    }
void vector_traversal(vector<int>& v)
    {
        for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
    }
void vector2d_input(vector<vector<int> > &v)
    {
        int r,c,x;
        cin>>r;
        for(int i=0;i<r;i++)
        {
            vector<int> temp;
            cin>>c;
            for(int j=0;j<c;j++)
                {
                    cin>>x;
                    temp.push_back(x);
                }
            v.push_back(temp);
        }
    }

int binarysearch(vector<int> &a, int h)
    {
        int b=0;
        int l=a.size()-1;
        int mid;

        while(b<=l)
            {
                mid = (b+l)/2;
                if(a[mid]==h)
                    {
                        return mid+1;
                    }
                else if(a[mid]>h)
                    {
                        l = mid-1;
                    }
                else
                    {
                        b = mid + 1;
                    }

            }

        return -1;
        /*Time Complexity of binary Search is log2(n)*/
    }

/*Notes about sorting algorithms*/

void bubblesort(vector<int> &v)
    {
        int temp=0;
        for(int i=0;i<v.size();i++)
            {
                for(int j=0;j<v.size()-i-1;j++)
                    {
                        if(v[j]>v[j+1])
                            {
                                temp = v[j+1];
                                v[j+1] = v[j];
                                v[j] = temp;
                            }
                    }
            }
        /*Time Complexity is O(n^2)*/
    }
void insertionsort(vector<int>&v)
    {
        int key=0,i;
        for(int j=1;j<v.size();j++)
            {
                key = v[j];
                i = j-1;

                while(v[i]>key && i>=0)
                    {
                        v[i+1]=v[i];
                        i--;
                    }
                v[i+1]=key;
            }
    }
void selectionsort(vector<int>&v)
    {
        int small=0,pos=0,temp=0;
        for(int i=0;i<v.size()-1;i++)
            {
                small = v[i];
                pos = i;

                for(int j=i+1;j<v.size();j++)
                    {
                        if(small>v[j])
                            {
                                pos = j;
                                small = v[j];
                            }
                    }
                temp = v[i];
                v[i] = v[pos];
                v[pos] = temp;
            }
    }

void mergesort(vector<int>&v,int b,int e)
    {
        if(b<e)
            {
                int mid = (b+e)/2;
                mergesort(v,b,mid);
                mergesort(v,mid+1,e);
                merge(v,b,mid,e);

            }
        /*
        Time Complexity of merge Sort is n*log(n).
        it's so because the inner working is based on Divide and conquer algorithm.
        And is multiplied with n because it takes linear time merging them.
        */
    }
void merge(vector<int>&v,int b,int mid,int e)
    {
        int n1 = mid+1-b;
        int n2 = e - mid;
        vector<int> v1,v2;

        for(int i=0;i<n1;i++)
            {
                v1.push_back(v[b+i]);
            }
        for(int i=mid+1;i<mid+1+n2;i++)
            {
                v2.push_back(v[i]);
            }

        int i=0,j=0,k=b;

        while(i<n1 && j<n2)
            {
                if(v1[i]<v2[j])
                    {
                        v[k]=v1[i];
                        i++;k++;
                    }
                else
                    {
                        v[k]=v2[j];
                        j++;k++;
                    }
            }

        while(i<n1)
            {
                v[k]=v1[i];
                i++;k++;
            }

        while(j<n2)
            {
                v[k]=v2[j];
                j++;k++;
            }

    }

void printvectorint(vector<int> &v)
    {
        for(int n: v)
            {
                cout<<n<<" ";
            }
    }
void printvectorchar(vector<char> &v)
    {
        for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
    }

void quicksort(vector<int> &v,int b,int e)
    {
        if(b<e)
            {
                int pivot =  partition_quicksort(v,b,e);
                quicksort(v,b,pivot-1);
                quicksort(v,pivot+1,e);
            }
    }
int partition_quicksort(vector<int> &v,int b,int e)
    {
        int pivot = v[e];
        int i= b-1;
        for(int j=b;j<e;j++)
            {
                if(v[j]<pivot)
                    {
                        i++;
                        swap_quicksort(v,i,j);
                    }

            }
            swap_quicksort(v,i+1,e);
            return (i+1);

    }
void swap_quicksort(vector<int> &v, int x,int y)
    {
        int temp = v[y];
        v[y] = v[x];
        v[x] = temp;
    }

void dnfsort(int *a,int n)
    {
        int low =0;
        int mid=0;
        int high=n-1;
        while(mid<high)
            {

                if(a[mid]==0)
                    {
                        array_swap(a,mid,low);
                        mid++;
                        low++;
                    }
                else if(a[mid]==1)
                    {
                        mid++;
                    }
                else if(a[mid]==2)
                    {
                        array_swap(a,mid,high);
                        high--;
                    }
            }
        /*Time Complexity is O(n).*/
    }
void array_swap(int *v,int a,int b)
    {
        int temp = v[a];
        v[a]=v[b];
        v[b]=temp;
    }

void wavesort(int v[],int n)
    {
        sort(v,v+n);
        for(int i=0;i<n-1;i+=2)
            {
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        /*The Time Complexity of Wave Sort is O(n).*/
    }

void subarrays_of_vector(vector<int> &v)
    {
        for(int i=0;i<v.size();i++)
            {
                for(int j=i;j<v.size();j++)
                    {
                        for(int k=i;k<=j;k++)
                            {
                                cout<<v[k]<<" ";
                            }
                        cout<<endl;
                    }
            }
    }


int kadanealgos(vector<int> &a,int n)
    {
        int currentSum = 0;
        int maxSum = INT_MIN;
        for (int num : a) {
            currentSum = max(num, currentSum + num);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }

int longest_subarray_sum_k(int *a, int n , int k){

    if(n==0){
        return 0;
    }


    // tsum records the running sum of elements
    // maxsize stores the length of subarray with sum k
    // mp map stores the running first occurance of the running sum when it doesnot match k.
    int tsum = 0,maxsize = 0;
    unordered_map<int, int> mp;

    for(int i=0;i<n;i++){
        tsum += a[i]; // Update tsum by adding a[i]

        if(tsum ==  k){
            maxsize = i+1; // We update the maxsize if tsum == k
        }

        /**
         * If the tsum is not equal to sum we check if tsum-k is present in array.
         * If present the size of this subarray that sums to k will be ( i - mp[ tsum - k ] ).
        */
        else if(mp.find(tsum-k) != mp.end()){
            maxsize =  max(maxsize,i-mp[tsum-k]);
        }

        // If the tsum is not in the map, we add it to the map.
        if(mp.find(tsum) == mp.end()){
            mp[tsum] = i;
        }
    }

    return maxsize;

    /*

    BRUTE FORCE APPROACH

    Time Consuming as the time complexity is O(n^2).
    Hence, inefficient when dealing with large arrays.

    int tsum = 0,maxsize = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                tsum += a[k];
            }
            if(tsum==summ){
                maxsize = max(maxsize,j-i+1);
            }

            tsum = 0;
        }
    }

    if(maxsize){
        return maxsize;
    }

    */

    return 0;
}

int count_all_subarray_sum_k(int *a, int n, int k){

    int cnt = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];

            if(sum == k){
                cnt++;
            }
        }
    }

    return cnt;
}

int maximum_circular_subarray_sum(vector<int> &v)
    {
        if(v.empty())
            {
                return 0;
            }

        // Check if all elements are negative
        bool allNegative = true;
        for (int num : v) {
            if (num >= 0) {
                allNegative = false;
                break;
            }
        }

        // If all elements are negative, return the maximum element
        if (allNegative) {
            int maxNegative = INT_MIN;
            for (int num : v) {
                maxNegative = max(maxNegative, num);
            }
            return maxNegative;
        }

        int maxKadane = kadanealgos(v,v.size());

        vector<int> nv;
        int totalsum=0;
        for(int num : v)
            {
                totalsum+=num;
                nv.push_back(-1*num);
            }

        int nvkadane=kadanealgos(nv,nv.size());
        int maxSubarraySum = totalsum + nvkadane;

        return max(maxKadane, maxSubarraySum);

    }

void spiral_order_traversal(vector<vector<int> > &v)
	{

        /* Time Complexity is O(n).*/

		int r = v.size();
		int c = v[0].size();

		int rs = 0;
		int re = r-1;
		int cs = 0;
		int ce = c-1;

		while(rs<=re && cs<=ce)
			{
				for(int i=cs;i<=ce;i++)
					{
						cout<<v[rs][i]<<" ";
					}
				rs++;
				for(int i=rs;i<=re;i++)
					{
						cout<<v[i][ce]<<" ";
					}
				ce--;
				for(int i=ce;i>=cs;i--)
					{
						cout<<v[re][i]<<" ";
					}
				re--;
				for(int i=re;i>=rs;i--)
					{
						cout<<v[i][cs]<<" ";
					}
				cs++;
			}

	}

void search_in_rowise_and_colwise_sorted_2d_vector(vector<vector<int> > &v,int ele)
    {
        if(v.empty())
            {
                cout<<"Empty Vector";
                return ;
            }

        int r = 0;
        int c = v[0].size()-1;
        while(r<v.size() && c>=0)
            {
                if(v[r].at(c)==ele)
                    {
                        cout<<"Element Found at "<<r<<" "<<c<<endl;
                        return ;
                    }
                if(v[r].at(c)>ele)
                    {
                        c--;
                    }
                else
                    {
                        r++;
                    }
            }
        cout<<"Element Not Found";
        return ;
    }

int getbit(int n,int i)
    {
        return ((n & (1<<i))!=0);
    }
int setbit(int n,int i)
    {
        return (n | (1<<i));
    }
int clearbit(int n,int i)
	{
		int mask = ~(1<<i);
		return n & mask;
	}
int updatebit(int n,int i,int value)
	{
		int clear = clearbit(n,i);
		return (clear | (value<<i));
	}
void binary_representation_of_number(int n)
    {
        if(n>1)
            {
                binary_representation_of_number(n>>1);
            }
        cout<<(n&1);
    }
vector<int> count0s1s_in_binary_represent_of_number(int n)
    {
        vector<int> result;
        for(int i=0;i<2;i++)
            {
                result.push_back(0);
            }
        while(n>0)
            {
                if(n&1)
                    {
                        result[1]++;
                    }
                else
                    {
                        result[0]++;
                    }
                n = n>>1;
            }
        return result;
    }
int briankernighan(int n)
    {
        /*Time Complexity here is O(log(n)).*/
        int countset=0;
        while(n)
            {
                n = n & (n-1);
                countset++;
            }
        return countset;
    }
int onescomplement(int n)
    {
        int nbits = floor(log2(n))+1;
        return ((1<<nbits)-1)^n;
    }

vector<int> display_all_unique_elements_in_vector(vector<int> &v)
    {
        sort(v.begin(), v.end());
        vector<int> ans;
        for (int i=0; i<v.size(); i++)
            {
                while (i < v.size()-1 && v[i] == v[i+1]){continue;}
                ans.push_back(v[i]);
            }
        return ans;
    }

vector<int> sieve_of_eratosthenes(int n)
    {
        /*
            Time Complexity here is O(n*log(log(n))).
            The Auxillary space is O(n).
        */
        vector<bool> a;
        vector<int> ans;
        for(int i=0;i<n;i++)
            {
                a.push_back(true);
            }
        for(int i=2;pow(i,2)<=n;i++)
            {
                if(a[i]==true)
                    {

                        for(int j=pow(i,2);j<=n;j+=i)
                            {
                                a[j]=false;
                            }
                    }
            }
        for(int i=2;i<=a.size();i++)
            {
                if(a[i])
                    {
                        ans.push_back(i);
                    }
            }
        return ans;
    }

int shorter_angle_bw_hour_and_minute(int h, int m)
    {
        int dpm = 6;
        int dph = 30;
        int ma,ha,anss;
        ma = dpm*m;
        ha = h * dph + (m*dph / 60);
        anss =  abs(ma-ha);
        if(anss>180)
        {anss = 360-anss;}
        return anss;
    }

bool isperfectnumber(int x)
    {

        int sum=0;
        for(int i=1;i<x;i++)
            {
                if(x%i==0)
                {
                sum+=i;
                }
            }
        if(sum==x)
            {
                return true;
            }
        else
            {
                return false;
            }
    }

int reverse_the_number(int x)
    {
        int rev,rem;
        while(x)
            {
                rem = x%10;
                rev=x*10;
                x=x/10;
            }
        return rev;
    }

void print_permutations_of_string(string s,string ans)
    {
        // Time Complexity is O(n*n!) and Auxilary Space needed is O(|s|).
        // There are n! permutations and n times to print them.
        char ch;
        /*The base case is condition checking if the string is empty, if so we print the answer.
        As we haave permuted for all the characters in s and s now is empty.*/

        if(s.length()==0)
            {
                cout<<ans<<endl;
                return ;
            }
        /*

        If not so than what we will do is choose a specific letter and make 2 substrings one from all the letters before ith letter and
        another after the ith letter, add them and add the ith character to the answer and go for further permutation of the remaing string.
        And This will happen similarly for all the letters.

        */
        else
            {
                for(int i=0;i<s.length();i++)
                    {
                        ch = s[i];
                        string left_substr = s.substr(0,i);
                        string right_substr = s.substr(i+1);
                        string rest = left_substr + right_substr;
                        print_permutations_of_string(rest, ans+ch);
                    }
            }
    }

bool check_if_array_sorted(int *v,int n)
    {
        // the Time Complexity here is O(n).

        /*
            If there is on element left in the array, or the size of array is 1 than no need to check it's sorted or not.
        */

        if(n==1)
            {
                return true;
            }

        bool result = check_if_array_sorted(v+1,n-1);
        /*
            Now we recursively check for each and every sub-array if it's sorted or not.
        */

        if(v[0]<v[1] && result) /*Check if the first and the second element of each substring is sorted or not.*/
            {
                return true;
            }
        else
            {
                return false;
            }
    }


bool check_2_numbers_same(int x,int y)
    {
        // Time Complexity is O(log(n)).
        return ((x^y)==0);
    }


vector<int> first_and_last_occurance_of_ele_unsorted_array(int *a, int key, int i, int n, vector<int> &ans)
    {
        /*

        A recursive approach to find the first element in an unsorted array. The Time complexity is O(n).
        The Same could have been done even using a linear search using for loop as well.

        */
        if(i==n)
            {
                return ans;
            }
        if(a[i]==key)
            {
                ans.push_back(i+1);
            }
        return first_and_last_occurance_of_ele_unsorted_array(a,key,++i,n,ans);
    }

/*

Programs to print from 1 to n and n to 1 with Backtracking.

void print_1_to_n(int n)
    {
        if(n==1)
            {
                cout<<"1"<<" ";
                return;
            }
        print_1_to_n(n-1);
        cout<<n<<" ";
    }

void print_n_to_1(int n,int i)
    {
        if(i==n)
            {
                cout<<i<<" ";
                return;
            }
        print_n_to_1(n,i+1);
        cout<<i<<" ";
    }

*/

int factorial(int n)
    {
        /*
            Recursive way to calculate factorial. The Time complexity is O(n).
        */
        if(n==1 || n==0)
            {
                return 1;
            }
        return n * factorial(n-1);
    }

bool check_palindrome_string(string s)
    {
        string t;
        for (char c : s) {
            if (isalnum(c)) {
                t += tolower(c);
            }
        }
        string r = t;
        reverse(r.begin(), r.end());
        return t == r;
    }

int fibonaci_nth_term(int n)
    {
        /*
            Time Complexityin this case over here is O(2^n).
        */
        if(n<=1)
            {
                return n;
            }
        return fibonaci_nth_term(n-1) + fibonaci_nth_term(n-2);
    }

void generate_and_count_subset_of_set(vector<int> &v)
    {
        /*
            Time Complexity in this case is O(n*(2^n)).
        */
        int count = 0;
        int n = v.size();
        for(int i=0;i<(1<<n);i++)
            {
                cout<<"{ ";
                for(int j=0;j<n;j++)
                    {
                        if(i & (1<<j))
                            {
                                cout<<v[j]<<" ";
                            }
                    }
                cout<<"}";
                count++;
                cout<<endl;
            }
        cout<<"Subsets = "<<count;
    }
void print_subsequence(int i,vector<int> &ans,vector<int> &v)
    {
        /*
            Time Complexity here is O(n*(2^n)), where n is multiplied considering the depth tof the recursion.
        */

       /*
            Explaination:

            Recursion tree for input {3,1,2}


                                                  f(0,[])
                                /                                        \
                              f(1,[3])                                   f(1,[])
                           /          \                             /              \
                      f(2,[3,1])       f(2,[3])                 f(2,[1])            f(2,[])
                     /        \        /       \                /       \           /       \
            f(3,[3,1,2]) f(3,[3,1])  f(3,[3,2]) f(3,[3])    f(3,[1,2])  f(3,[1]) f(3,[2])   f(3,[])
       */

        if(v.size()==0)
            {
                cout<<"{ }";
                return;
            }

        if(i>=v.size())
            {
                cout<<"{ ";
                printvectorint(ans);
                cout<<"}";
                cout<<endl;
                return;
            }

        ans.push_back(v[i]);
        print_subsequence(i+1,ans,v);
        ans.pop_back();
        print_subsequence(i+1,ans,v);
    }
void print_subsequence_whose_sum_is_k(int i,vector<int> &ans,vector<int> &v,int k,int sum)
    {
        /*
            Time Complexity here is O(n*(2^n)), where n is multiplied considering the depth tof the recursion.
        */

       /*
            Explaination:

            Recursion tree for input {3,1,2}


                                                     f(0,[],0)
                                /                                             \
                              f(1,[3],3)                                   f(1,[])
                           /          \                             /              \
                      f(2,[3,1],4)       f(2,[3],3)                 f(2,[1])            f(2,[])
                     /        \        /       \                /       \           /       \
            f(3,[3,1,2],6) f(3,[3,1],4)  f(3,[3,2],5) f(3,[3],3)    f(3,[1,2])  f(3,[1]) f(3,[2])   f(3,[])
       */

        if(v.size()==0)
            {
                cout<<"{ }";
                return;
            }

        if(i>=v.size())
            {
                if(sum==k)
                    {
                        cout<<"{ ";
                        printvectorint(ans);
                        cout<<"}";
                        cout<<endl;

                    }
                return;
            }

        ans.push_back(v[i]);
        sum +=v[i];
        print_subsequence_whose_sum_is_k(i+1,ans,v,k,sum);
        ans.pop_back();
        sum-=v[i];
        print_subsequence_whose_sum_is_k(i+1,ans,v,k,sum);
    }
int count_subsequence_whose_sum_is_k(int i,vector<int> &ans,vector<int> &v,int k,int sum,int &count)
    {
        /*
            Time Complexity here is O(n*(2^n)), where n is multiplied considering the depth tof the recursion.
        */

       /*
            Explaination:

            Recursion tree for input {3,1,2}


                                                     f(0,[],0)
                                /                                             \
                              f(1,[3],3)                                   f(1,[])
                           /          \                             /              \
                      f(2,[3,1],4)       f(2,[3],3)                 f(2,[1])            f(2,[])
                     /        \        /       \                /       \           /       \
            f(3,[3,1,2],6) f(3,[3,1],4)  f(3,[3,2],5) f(3,[3],3)    f(3,[1,2])  f(3,[1]) f(3,[2])   f(3,[])
       */

        if(v.size()==0)
            {
                cout<<"{ }";
                return 0;
            }

        if(i>=v.size())
            {
                if(sum==k)
                    {
                        cout<<"{ ";
                        printvectorint(ans);
                        cout<<"}";
                        cout<<endl;
                        return 1;
                    }
                return 0;
            }

        ans.push_back(v[i]);
        sum +=v[i];
        int l = count_subsequence_whose_sum_is_k(i+1,ans,v,k,sum,count);
        ans.pop_back();
        sum-=v[i];
        int r = count_subsequence_whose_sum_is_k(i+1,ans,v,k,sum,count);
        return l+r;
    }

void combination_sum_39_leetcode(int i,int target,vector<int>& ans,vector<int>& v,vector<vector<int> >& ansm)
    {
        /*

            Input: candidates = [2,3,6,7], target = 7
            Output: [[2,2,3],[7]]
            The Time Complexity here is O(m*(2^n)).
            m considering the case where we put the sub-sequence into a data-structure.
            Where Space complexity is m*x;
        */

       /*
            So, the base case here is if index is greater than or equal to size of the vector
            we check if the sum needed is achieved or not i.e. target =0 or not if so, we push the answer into vectoe and return,
            else we simply return.

            Now for further as the repeated use of the element is allowed , assuming that,
            we check if the element is less than the target, if it's less we keep, pushing the same element into our
            vector representing the subsequence and deducting the target by that value, if sum is achieved it gets pushed into the
            answer vector, if not we just pop out all the elements.

            and we look for the case where we choose to pick the next element in the given vector and it recursively goes on.
       */
        if(i==v.size())
            {
                if(target==0)
                    {
                        ansm.push_back(ans);
                        cout<<endl;
                    }
                return;
            }
        if(v[i]<=target)
            {
                ans.push_back(v[i]);
                combination_sum_39_leetcode(i,target-v[i],ans,v,ansm);
                ans.pop_back();
            }
        combination_sum_39_leetcode(i+1,target,ans,v,ansm);

    }
void combination_sum_II_40_leetcode(int i,int target,vector<int>& ans,vector<int>& v,vector<vector<int> >& ansm)
    {
        /*
            Time Complexity is O(k*(2^n)).
            Space Complexity is K*x.
        */

        if(target==0)   /* If we have obtained the required sum, that's the base case.*/
            {
                ansm.push_back(ans);
                return;
            }

        for(int j=i;j<v.size();j++)
            {

                /*
                    taking one element into consideration as start, we loop for other elements of the sub-sequence.
                    point to be noted the array or vector must be sorted.
                */

                /* During the process, we have 2 choices,
                either we pick the element, or we leave it,
                that's how recursion tree works in case of sub-sequences.*/

                /*
                    So, we first check starting the loop from ith index if this element is bigger than the target,
                    if yes, there's no point going ahead simply break out of loop.

                    If not than we check if j>i and if the current element is not same as the previous element, in
                    order to avoid having any duplicates in the answer, if so we skip.
                    if not so, we push the element in the answer vector and go for next recursive call, for next element in the subsequnce
                    and now the target is also decreased by v[j] and the same happens further elements of the sub-sequence.
                    and than if at any point subsequence becomes equal to target we store it in the vector.

                    Now befor looking for another subsequence, we pop out th elements stored in the vector.
                */
                if((j>i)&&(v[j]==v[j-1])){continue;}
                if(v[j]>target) {break;}
                ans.push_back(v[j]);
                combination_sum_II_40_leetcode(j+1,target-v[j],ans,v,ansm);
                ans.pop_back();

            }
    }
vector<int> print_sum_of_all_subsets_in_ascending(vector<int>&v, int sum,int i,vector<int>& ans,vector<int> &ansm)
    {

        if(i>=v.size())
            {
                ansm.push_back(sum);
                return ansm;
            }

        ans.push_back(v[i]);
        sum+=v[i];
        print_sum_of_all_subsets_in_ascending(v,sum,i+1,ans,ansm);
        ans.pop_back();
        sum-=v[i];
        print_sum_of_all_subsets_in_ascending(v,sum,i+1,ans,ansm);

        sort(ansm.begin(),ansm.end());
        return ansm;

        /*

        This is a loop based approach to the problem without recursion, the time complexity here is O(m*(2^n)).
        m is here cause we need to put the sum into a data structure.


        int sum;
        vector<int> ans;
        int n = v.size();
        for(int i=0;i<(1<<n);i++)
            {
                sum =0;
                for(int j=0;j<n;j++)
                    {
                        if(i & (1<<j))
                            {
                               sum+=v[j];
                            }
                    }
                ans.push_back(sum);
            }
        sort(ans.begin(),ans.end());
        return ans;
        */
    }

void subsets_78_leetcode(int i,vector<int> &ans,vector<int> &v,vector<vector<int> > &ansm)
    {
        if(i>=v.size())
            {
                ansm.push_back(ans);
                return;
            }
        ans.push_back(v[i]);
        subsets_78_leetcode(i+1,ans,v,ansm);
        ans.pop_back();
        subsets_78_leetcode(i+1,ans,v,ansm);
    }
void subsets_II_90_leetcode(int i,vector<int> &ans,vector<int> &v,vector<vector<int> > &ansm)
    {
        /*
            Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
            The solution set must not contain duplicate subsets. Return the solution in any order.

            Input: nums = [1,2,2]
            Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
        */

        /*
            Time Complexity is O(n*(2^n)), n is time reuqired to copy the vector.
            Space Complexity is O(2^n)*O(k) as 2^n is the number of subsets and k is the avg. size of each subset.
            Auxillay space is O(n) where n here is the depth of recursion.
        */
        ansm.push_back(ans);
        if(i==v.size()) {return;}
        for(int j=i;j<v.size();j++)
            {
                if(v[j]==v[j-1] && j>i)
                    {
                        continue;
                    }
                ans.push_back(v[j]);
                subsets_II_90_leetcode(j+1,ans,v,ansm);
                ans.pop_back();
            }
    }

void permutation_of_vector(vector<int> &v,vector<int> &ans,vector<bool> &map)
    {
        /*
            Time Complexity is O(n*n!).
            Space Complexity us O(n)+O(n).
        */

       if(ans.size()==v.size())
            {
                printvectorint(ans);
                cout<<endl;
                return;
            }

        for(int i=0;i<v.size();i++)
            {
                if(!map[i])
                    {
                        map[i]=true;
                        ans.push_back(v[i]);
                        permutation_of_vector(v,ans,map);
                        ans.pop_back();
                        map[i]=false;
                    }
            }
    }

bool nqueens_51_leetcode(int **ar, int c,int n)
	{
		if(c>=n)
			{
				// printsol(ar,n);
				return true;
			}

		for(int i=0;i<n;i++)
			{
				if(issafe(ar,i,c,n))
					{
						ar[i][c]=1;
						if(nqueens_51_leetcode(ar,c+1,n)){return true;}
						ar[i][c]=0;
					}
			}
		return false;
	}
bool issafe(int **a,int i, int j,int n)
	{
		for(int k=i-1;k>=0;k--){
			if(a[k][j]==1){
				return false;
			}
		}
		for(int k=j-1;k>=0;k--){
			if(a[i][k]==1){
				return false;
			}
		}
		for(int k=i-1,l=j-1;k>=0&&l>=0;k--,l--){
			if(a[k][l]==1){
				return false;
			}
		}
		for(int k=i+1,l=j-1;k<n&&l>=0;k++,l--){
			if(a[k][l]==1){
				return false;
			}
		}
		for(int k=i-1,l=j+1;k>=0&&l<n;k--,l++){
			if(a[k][l]==1){
				return false;
			}
		}

		return true;
	}

bool sudoku_solver_leetcode_37(vector<vector<char> > &v)
    {
        /*
            We traverse in the sudoku, looking for empty space, if we find a empty space, we check if a number can be put in that particular
            empty space and it's exsistence there is valid or not, if yes, we put it in there and than check through recursive call that if
            keeping that number solves it, if solves we return true, if not , we keep the space empty and check for other characters.

            If any of them deoesn't seem to solve we return false.
        */

        for(int i=0;i<v.size();i++)
            {
                for(int j=0;j<v[i].size();j++)
                    {
                        if(v[i][j]=='.')
                            {
                                for(char c='1';c<='9';c++)
                                    {
                                        if(isvalidsudoku(v,i,j,c))
                                            {
                                                v[i][j]=c;
                                                if(sudoku_solver_leetcode_37(v))
                                                    {
                                                        return true;
                                                    }
                                                v[i][j]='.';
                                            }
                                    }
                                return false;
                            }
                    }
            }
        return true;
    }
bool isvalidsudoku(vector<vector<char> >& v,int r,int c, char m)
    {
        for(int i=0;i<9;i++)
            {
                if(v[i][c]==m)
                    {
                        return false;
                    }
                if(v[r][i]==m)
                    {
                        return false;
                    }
                if(v[3*(r/3)+i/3][3*(c/3)+i%3]==m)
                    {
                        return false;
                    }
            }
        return true;
    }

void palindrome_partioning_leetcode_131(vector<vector<string> >&ans,string s,string temp,vector<string>v,int index)
    {
        if(index==s.length())
                {
                    cout<<"{ ";
                    for(int i=0;i<v.size();i++)
                        {
                            cout<<v[i]<<" ";
                        }
                    cout<<"}";
                    cout<<endl;
                    ans.push_back(v);
                    return;
                }

     for(int i=index;i<s.length();i++)
     {
         string temp=s.substr(index,i-index+1);
         if(isPalindromeString(temp))
         {
             v.push_back(temp);
             palindrome_partioning_leetcode_131(ans,s,temp,v,i+1);
             v.pop_back();
         }
     }
    }
bool isPalindromeString(string str)
    {
        if(str.length()==0)
        {
            return true;
        }
        string p=str;
        reverse(p.begin(),p.end());
        if(p==str)
        {
            return true;
        }

        return false;
    }

string getPermutation(int n,int k)
    {
        /*
            To optimize the above method mentioned above, observe that the value of k can be
            directly used to find the number at each index of the sequence.The first position of an n length sequence
            is occupied by each of the numbers from 1 to n exactly n! / n that is (n-1)! number of times and in ascending order.
            So the first position of the kth sequence will be occupied by the number present
            at index = k / (n-1)! (according to 1-based indexing).
            The currently found number can not occur again so it is removed from the original n numbers and
            now the problem reduces to finding the ( k % (n-1)! )th permutation sequence of the remaining n-1 numbers.
            This process can be repeated until we have only one number left which will be placed in the first position of the
            last 1-length sequence. The factorial values involved here can be very large as compared to k.
            So, the trick used to avoid the full computation of such large factorials is that as soon as the product n * (n-1) * …
            becomes greater than k, we no longer need to find the actual factorial value because:
        */
        int fact =1;
        vector<int> numbers;
        for(int i=1;i<n;i++)
            {
                fact = fact*i;
                numbers.push_back(i);
            }

        numbers.push_back(n);
        string ans="";
        k = k-1;
        while(true)
            {
                ans+=to_string(numbers[k/fact]);
                numbers.erase(numbers.begin()+k/fact);
                if(numbers.size()==0)
                    {
                        break;
                    }
                k = k% fact;
                fact = fact/numbers.size();

            }
        return ans;
    }

void rat_in_maze(vector<vector<int> > &maze,int i,int j,vector<vector<int> > &vis,string s,int n,vector<string> &ans)
    {
        if(i==n-1 && j==n-1)
            {
                ans.push_back(s);
                return ;
            }

        if(i+1<n && !vis[i+1][j] && maze[i+1][j]==1)//Down
            {
                vis[i][j] = 1;
                rat_in_maze(maze,i+1,j,vis,s+'D',n,ans);
                vis[i][j] = 0;
            }

        if(j-1>=0 && !vis[i][j-1] && maze[i][j-1]==1)//Left
            {
                vis[i][j] = 1;
                rat_in_maze(maze,i,j-1,vis,s+'L',n,ans);
                vis[i][j] = 0;
            }

        if(j+1<n && !vis[i][j+1] && maze[i][j+1]==1)//Right
            {
                vis[i][j] = 1;
                rat_in_maze(maze,i,j+1,vis,s+'R',n,ans);
                vis[i][j] = 0;
            }

        if(i-1>=0 && !vis[i-1][j] && maze[i-1][j]==1)//Up
            {
                vis[i][j] = 1;
                rat_in_maze(maze,i-1,j,vis,s+'U',n,ans);
                vis[i][j] = 0;
            }

    }

void reverse_words_in_sentence(string str){
    stack<char> st;

    // Traverse through the string and push all the characters in the stack till we encounter a space.
    for(int i=0;i<str.length();i++){
        if(str[i] != ' '){
            st.push(str[i]);
        }

        // If we encounter a space, we pop all the characters from the stack and print them.
        else{
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
            cout<<" ";
        }
    }

    // Since the last word in the string will not have a space after it, we need to print it separately.
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

int no_of_ways_n_elements_can_be_divided_into_groups(int n){
    // These groups can only be of 2 types either single or pairs.

    double a =1, b=2, c=0;

    // b represents the count of ways where the (i-1) friends are already paired up

    if(n<=2){
        return n;
    }

    /*
     * The concept behind this is that if the the nth element is alone, than we have to recurr for f(n-1)
     * If nth element is paired with any of the (n-1) elements,
     * than we have to recur for f(n-2) for the remaining elements, so (n-1)*f(n-2) is the number of ways.
    */

    for (int i=3;i<=n;i++){
        c = b + (i-1)*a;
        // (i - 1) * a represents the number of ways to pair the ith friend with each of the (i-1) already paired friends.
        a = b;
        b = c;
    }
    return c;

    /*
     * int count[n+1];
     *
     * for(int i=0;i<=n;i++){
     *
     *      if(i<=2){
     *          count[i] = i;
     *      }
     *
     *      else{
     *          count[i] = count[i-1] + (i-1)*count[i-2];
     *          // if the ith person is single, we have to iterate for (i-1)th person
     *          // if the ith person is paired, we have to iterate for (i-2)th person
     *      }
     *   }
     *   return count[n];
     * }
     *
     */
}

int tiling_problem(int n, int m){
    // The time complexity of this problem is O(n).
    // The Size of tiles is 1*m.

    int count[n+1];
    count[0] = 0;

    for(int i=0; i<=n;i++){
        if(i>m){
            count[i] = count[i-1] + count[i-m];
        }
        else if(i<m || i==1){
            count[i] = 1; // base case or i=m=1
        }
        else{
            count[i] = 2;
        }
    }
    return count[n];
}

int ways_to_reach_nth_stair_by_taking_atmost_k_steps(int n, int k){
    // The time complexity of this problem is O(n*k).
    // The Space complexity of this problem is O(n).
    int stairs = n+1;

    /* The size of the array is n+1, because we need to store the number of ways to reach the nth stair.
     * Assuming we have the 0th stair is 1st stair, so the size of the array is n+1.
     */

    int pw[stairs];
    pw[0] = 1; // Assuming 0th leap exist, so we assign it value 1 for calculation.

    // Loop to iterate all possible leaps upto k
    for(int i=0; i<=k ;i++){

        // Loop to count all possible ways to reach jth stair, with the help of ith leap or less.
        for(int j=0;j<=n;j++){
            if(j>=i){
                // Condition to check leaps possible from current stair.
                // We only consider leaps that are smaller than or equal to current stair position
                // Because if leap i is greater than j, than it's not possible to reach the jth stair.
                pw[j] += pw[j-i];

                /* pw[j] represents the current count of possible ways to reach the stair j.
                 *
                 * pw[j-i] represents the count of possible ways to reach the stair j - i, where i is the current leap size.
                 * This count indicates the number of ways to reach the current stair j using the leap size i or less.
                 */
            }
        }
    }
    return pw[n];
}

void two_elements_whose_sum_closest_to_0(vector<int> &v){
    int sum, min_sum= INT_MAX;
    int b= 0, e = v.size()-1;
    int min_l = b, min_r = v.size()-1;

    if(v.size()<2){
        cout<<"Invalid Input";
        return;
    }

    quicksort(v,0,v.size()-1);

    while(b<e){
        sum = v[b] + v[e];

        if(abs(sum)< abs(min_sum)){
            min_sum = sum;
            min_l = b;
            min_r = e;
        }

        if(sum<0){
            b++;
        }

        else{
            e--;
        }
    }

    cout << "The two elements whose sum is minimum are "<< v[min_l] << " and " << v[min_r];
}

void createDuplicateArray(vector<pair<string, int> >& wordidx,vector<string>& v)
{
    for (int i = 0; i < v.size(); i++) {
        wordidx.push_back(make_pair(v[i], i));
        // pair.first contains the input words and
        // pair.second contains its index
    }
}

void print_all_anagrams_together(vector<string> &v){
    vector< pair<string,int> > wordidx;
    createDuplicateArray(wordidx,v);

    for(int i=0;i<wordidx.size();i++){
        sort(wordidx[i].first.begin(),wordidx[i].first.end());
    }

    sort(wordidx.begin(),wordidx.end());
    for(int i=0;i<wordidx.size();i++){
        cout<<v[wordidx[i].second]<<" ";
    }

}

bool isEven(int n){
    /*
     * We can also directly use return (!(n&1));
     */
    if(n&1){
        return false;
    }
    return true;
}

bool isOdd(int n){
    /*
     * We can also directly use return (n&1);
     */
    if(n&1){
        return true;
    }
    return false;
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/* LINKED LIST FUNCTIONS */

void ll_main(){
    llnode* head = NULL;
    int i;
    cin>>i;
    int val;
    while(i)
    {
        i--;
        cin>>val;
        ll_insertattail(head,val);
    }
    int j,k;
    cin>>j>>k;
    ll_deletee(head,j);
    bool state = ll_search(head,k);
    cout<<state<<endl;

    ll_display(head);
}

void ll_insertattail(llnode* &head, int val)
{
    /* The head is passed by reference because we have to modify our Linked List.
     * This causes insertion from the end of linked list.
     */

    llnode* n = new llnode(val);
    llnode* temp =  head;
    if(head == NULL)
    {
        head = n;
        return;
    }

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void ll_insertathead(llnode* &head, int val)
{
    /* The head is passed by reference because we have to modify our Linked List.
     * This causes insertion fromt the begining of the linked list.
     */

    llnode* n = new llnode(val);
    n->next = head;
    head = n;
}

void ll_deleteathead(llnode* &head)
{
    llnode* todelete = head;
    head = head->next;

    delete todelete;
}

void ll_deletee(llnode* &head, int val)
{
    if(head == NULL){return;}
    if(head->next == NULL)
    {
        ll_deleteathead(head);
        return;
    }
    llnode* temp = head;
    while((temp->next->data != val) && (temp->next != NULL))
    {
        temp = temp->next;
    }
    llnode* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

bool ll_search(llnode* head,int key)
{
    llnode* temp = head;
    while(temp!=NULL)
    {
        if(temp->data ==key){return true;}
        temp = temp->next;
    }
    return false;

}

int ll_length(llnode* head)
    {
        llnode* temp=head;
        int count =0;
        while(temp!=NULL)
            {
                temp = temp->next;
                count++;
            }
        return count;
    }

void ll_make_intersect(llnode* a, llnode* b,int pos){
    int count = 1;

    if(pos == 0){
        cout<<"Intersection not possible";
        return;
    }

    llnode *tempa = a;
    llnode *tempb = b;

    while((count != pos)&&(tempa->next != NULL)){
        tempa= tempa -> next;
        count++;
    }

    if(tempa->next == NULL){
        cout<<"Intersection not possible";
        return;
    }

    while(tempb->next != NULL){
        tempb = tempb->next;
    }

    tempb->next = tempa;
}

int ll_intersection(llnode* a,llnode* b){
    int l1 = ll_length(a);
    int l2 = ll_length(b);

    int d = 0, count = 0;
    llnode* ptr1;
    llnode* ptr2;

    if(l1>=l2){
        d = l1-l2;
        ptr1 = a;
        ptr2 = b;

    }

    else{
        d = l2 - l1;
        ptr1 = b;
        ptr2 = a;
    }

    count +=d;

    while(d){
        ptr1 = ptr1 -> next;
        if(ptr1 == NULL){return 0;}
        d--;
    }

    while((ptr1 !=NULL)&&(ptr2!=(NULL))) {
        if (ptr1==ptr2) {
            return count;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        count++;
    }


    return 0;
}

void ll_reverse(llnode* &head){
    llnode* prev = NULL;
    llnode* curr = head;
    llnode* next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

llnode* ll_reverseknodes(llnode* &head,int k){
    llnode* curr = head;
    llnode* prev = NULL;
    llnode* nxt;
    int count = 0;
    while((curr!=NULL) && (count<k)){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++ ;
    }

    if(nxt!=NULL){
        head->next = ll_reverseknodes(nxt,k);
    }
    return prev;

}

void ll_makecycle(llnode* &head,int pos){
    llnode* temp = head;
    llnode* startnode;
    int n = ll_length(head);
    pos = pos % n;
    int count = 1;
    while(temp->next!=NULL){
        if(count == pos){
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;

}

bool ll_detectcycle(llnode* head){
    llnode* slow = head;
    llnode* fast = head;

    while((fast!=NULL)&&(fast->next!=NULL)){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;

}

void ll_deletecycle(llnode* &head)
    {
        llnode* slow = head;
        llnode* fast = head;
        int count = 1;


        do{
            fast = fast->next->next;
            slow = slow->next;
            }while(fast != slow);

        fast = head;
        while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        slow->next = NULL;

    }

void ll_kappend(llnode* &head,int k,int n)
    {
        if(!head){
            return;
        }

        k = k%n;

        llnode* temp = head;
        int count = 1;
        llnode* newhead;
        llnode* newtail;

        while(temp->next != NULL)
            {
                if(count == k)
                    {
                        newhead = temp->next;
                        newtail = temp;
                    }
                temp = temp->next;
                count++;
            }

        temp->next = head;
        head = newhead;
        newtail->next = NULL;
    }

void ll_bubblesort(llnode*& head) {
    int length = ll_length(head);
    for (int i = 0; i < length - 1; i++) { // optimized loop condition
        bool swapped = false; // use bool instead of int
        llnode* curr = head;
        for (int j = 0; j < length - i - 1; j++) {
            llnode* nextNode = curr->next;
            if (curr->data > nextNode->data) {
                std::swap(curr->data, nextNode->data); // swap data, not nodes
                swapped = true;
            }
            curr = nextNode;
        }
        if (!swapped) {
            break; // optimization: exit early if no swaps occurred
        }
    }
}

void ll_display(llnode* head)
{
    llnode* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/* CIRCULAR LINKEDLIST FUNCTION */

void cll_insertathead(llnode* &head, int val)
    {
        llnode* n = new llnode(val);
        llnode* temp = head;

        if(head == NULL)
            {
                n->next = n;
                head = n;
                return;
            }

        while(temp->next != head)
            {
                temp = temp->next;
            }
        temp->next = n;
        n->next = head;
    }

void cll_insertattail(llnode* &head, int val)
    {
        /* The head is passed by reference because we have to modify our Linked List.
         * This causes insertion from the end of doubly linked list.
         */
        if(head == NULL)
            {
                ll_insertathead(head,val);
                return;
            }

        llnode* n = new llnode(val);
        llnode* temp =  head;

        while(temp->next!=head)
            {
                temp = temp->next;
            }
        temp->next = n;
        n->next = head;
    }

void cll_deleteathead(llnode* &head)
    {
        llnode* temp = head;
        while(temp->next!=head)
            {
                temp = temp->next;
            }
        temp->next = head->next;
        llnode* todelete = head;
        head = head->next;

        delete todelete;
    }

void cll_deletee(llnode* &head, int pos)
    {
        if(!head){return;}

        if(pos==1)
            {
                cll_deleteathead(head);
                return;
            }

        llnode* temp = head;
        int count =1;

        while(count != pos-1)
            {
                temp = temp->next;
                count++;
            }
        llnode* todelete = temp->next;
        temp->next = temp->next->next;

        delete todelete;
    }


void cll_display(llnode* head)
    {
        if(!head){return;}
        llnode* temp = head;
        do{
                cout<<temp->data<<" ";
                temp=temp->next;

            }while(temp!=head);
        cout<<endl;
    }

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/* DOUBLY LINKED LIST */

void dll_insertathead(dllnode* &head, int val)
    {
        dllnode* n = new dllnode(val);
        n->next = head;
        if(head != NULL)
            {
                head->prev = n;
            }
        head = n;
    }

void dll_insertattail(dllnode* &head, int val)
    {
        /* The head is passed by reference because we have to modify our Linked List.
         * This causes insertion from the end of doubly linked list.
         */
        if(head == NULL)
            {
                dll_insertathead(head,val);
                return;
            }

        dllnode* n = new dllnode(val);
        dllnode* temp =  head;

        while(temp->next!=NULL)
            {
                temp = temp->next;
            }
        temp->next = n;
        n->prev = temp;
    }

void dll_deleteathead(dllnode* &head)
    {
        dllnode* todelete = head;
        head = head->next;
        head->prev = NULL;
        delete head;
    }

void dll_delete(dllnode* &head, int pos)
    {
        if(!head){return;}
        if(pos==1)
            {
                dll_deleteathead(head);
                return;
            }
        dllnode* temp = head;
        int count =1;
        while((count != pos) && (temp != NULL))
            {
                temp = temp->next;
                count++;
            }

        temp->prev->next = temp->next;
        if(temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
        delete temp;
    }


void dll_display(dllnode* head)
    {
        dllnode* temp = head;
        while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;

            }
        cout<<endl;
    }

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

void distinct_elements_in_array(int *a,int n){
    sort(a,a+n);
    for(int i=0;i<n;i++){
        while(i<n-1 && a[i]==a[i+1]){
            i++;
        }
        cout<<a[i]<<" ";
    }
}

int knapsack_problem(int n,int W,vector<int> w,vector<int> v){

    if(n==0 || W==0){
        return 0;
    }

    else{
        if(w[n-1]>W){
            return knapsack_problem(n-1,W,w,v);
        }
        else{
            return max(v[n-1]+knapsack_problem(n-1,W-w[n-1],w,v),knapsack_problem(n-1,W,w,v));
        }
    }
}

int trapping_rainwater(vector<int> &v){
    // Vector represents the height of each building.

   int left = 0, right = v.size()-1;
   int lmax = 0, rmax = 0;
   int res = 0;

    while (left<=right){

        if(v[left]<=v[right])
        {
            if(v[left]>=lmax){
                lmax = v[left];
            }

            else{
                res += lmax - v[left];
            }
            left++;
        }

        else{
            if(v[right]>=rmax){
                rmax = v[right];
            }

            else{
                res += rmax - v[right];
            }

            right--;
        }
    }

    return res;

}

int top_left_to_bottom_right_no_blockage(int m, int n){
    if(m==1 || n==1){
        return 1;
    }

    return top_left_to_bottom_right_no_blockage(m-1,n) + top_left_to_bottom_right_no_blockage(m,n-1);
}

int gcd(int a, int b){
    if(a==0){
        return b;
    }

    return gcd(b % a,a);
}


int find_gcd(int *a,int n){

    int res = a[0];
    for(int i=1;i<n;i++){
        res = gcd(a[i],res);

        if(res == 1){
            return 1;
        }
    }

    return res;
}

long long find_lcm(int *a,int n){
    long long res = a[0];
    for(int i=1;i<n;i++){
        res = ((a[i]*res)/(gcd(a[i],res)));
    }
    return res;
}

ll count_digits(ll n){
    return floor(log10(n) + 1);
}

bool check_armstrong(ll n){
    ll digits = count_digits(n);
    int temp = n, sum = 0;

    while(temp){
        int r = temp % 10;
        sum = sum + pow(r,digits);
        temp = temp/10;
    }

    return (sum == n);
}

void divisor_of_natural_number(ll n){

    vector<ll> v;

    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            if(n/i == i){
                v.push_back(i);
            }
            else{
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }

    sort(v.begin(),v.end());

    for(ll i: v){
        cout<<i<<" ";
    }
}

void rotate_vector_k_times_right(vector<int> &nums,int k){
    int n=nums.size();
    k=k%n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}

int find_missing_number_N(int *a, int n){
    int sum =  (n * (n+1))/2;

    int total = 0;
    for(int i=0;i<n;i++){
        total += a[i];
    }

    return sum - total;
}


/* STACK QUESTIONS */

bool balanced_paranthesis_using_stack(string s){
    stack<char> st;

    for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
                {
                    st.push(s[i]);
                    continue;
                }

            if(st.empty()){return false;}

            else if(s[i]==')')
                {
                    if(st.top()=='('){st.pop();}
                    else{return false;}
                }
            else if(s[i]==']')
                {
                    if(st.top()=='['){st.pop();}
                    else{return false;}
                }
            else if(s[i]=='}')
                {
                    if(st.top()=='{'){st.pop();}
                    else{return false;}
                }
        }

    if(!st.empty())
        {
            return false;
        }

    return true;
}

void print_stack(stack<int> s)
{
    // If stack is empty
    if (s.empty()){
        return;
    }

    int x = s.top();
    s.pop();
    cout << x << ' ';

    print_stack(s);
    s.push(x);
}

void reverse_stack(stack<int> &st)
    {
        if(st.empty())
            {
                return;
            }

        stack<int> temp;
        while(!st.empty())
            {
                temp.push(st.top());
                st.pop();
            }
        st = temp;
    }

vector< vector<int> > match_overlapping_sub_intervals(vector< vector<int> >& v) {
    // Sort the vector based on its starting elements
    sort(v.begin(), v.end());

    vector<vector<int> > ans;

    for (int i = 0; i < v.size(); i++) {
        if (ans.empty() || v[i][0] > ans.back()[1]) {
            ans.push_back(v[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], v[i][1]);
        }
    }

    return ans;
}


int largest_rectangle_on_histogram(vector<int> v){
    stack<int> st;
    int n = v.size();
    int max_area = 0;
    int tp;
    int area_with_top;
    int i = 0;

    while(i<n){
        if(st.empty() || v[st.top()]<=v[i]){
            st.push(i++);
        }

        else{
            tp = st.top();
            st.pop();

            area_with_top = v[tp] * (st.empty() ? i : i - st.top() - 1);

            if(max_area<area_with_top){
                max_area = area_with_top;
            }
        }
    }

    while(!st.empty()){
        tp = st.top();
        st.pop();

        area_with_top = v[tp] * (st.empty() ? i : i - st.top() - 1);

        if(max_area<area_with_top){
            max_area = area_with_top;
        }
    }

    return max_area;
}

int _3sum(int *a, int n, int sum){

    sort(a,a+n);
    int left = 0, right = 0,curr_sum = 0;

    for(int i=0;i<n-2;i++){

        // Skip duplicates of the first element
        if(i>0 && a[i] == a[i-1]){
            continue;
        }

        left = i+1;
        right = n-1;

        while(left<right){
            curr_sum = a[i] + a[left] + a[right];

            if(curr_sum == sum){
                cout<<a[i]<<" "<<a[left]<<" "<<a[right];
                cout<<endl;

                // Skip duplicates of Left Element
                while(left<right && a[left] == a[left + 1]){continue;}
                // Skip duplicates of Right Element
                while(left<right && a[right] == a[right - 1]){continue;}
                left++;
                right--;
            }

            else if(curr_sum<sum){
                left++;
            }

            else{
                right--;
            }
        }


    }

    return 0;

}

void _4sum(int *a, int n, int sum){

    sort(a,a+n);

    for(int i=0;i<n;i++){

        if(i>0 && a[i] == a[i-1]){continue;} // Skip the duplicates of the first iterator

        for(int j=i+1;j<n;j++){

            if(j>i+1 && a[j] == a[j-1]){continue;} // Skip the duplicates of the second iterator

            int k = j+1;
            int l = n-1;

            while(k<l){
                int s = a[i] + a[j] + a[k] + a[l];
                if(s == sum){
                    cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l];
                    cout<<endl;
                    k++;
                    l--;

                    // Skipping Duplicates
                    while(k<l && a[k] == a[k-1]) {k++;}
                    while(k<l && a[l] == a[l+1]) {l--;}


                }

                else if(s<sum){k++;}

                else{l--;}
            }

        }
    }
}




vector<int> _2sum(vector<int>& a, int sum) {
    vector<pair<int, int> > v;

    vector<int> res;

    for (int i = 0; i < a.size(); ++i) {
        v.push_back(make_pair(a[i], i));
    }

    // Sort the vector of pairs based on the elements
    sort(v.begin(), v.end());

    // Two pointers to find the indices of elements adding up to the sum
    int b = 0, e = a.size() - 1;

    int csum = 0;

    while (b < e) {
        csum = v[b].first + v[e].first;

        if (csum == sum) {
            vector<int> res;
            res.push_back(v[b].second); // Add 1 to the index to get the 1-based index
            res.push_back(v[e].second); // Add 1 to the index to get the 1-based index
            return res;
        }

        else if (csum < sum) {
            b++;
        }

        else {
            e--;
        }

        csum = 0;
    }


    return res;
}

int boyer_moore_voting_algo(int *a, int n){

    /**
     * This technique can be used in questions such as
     * Find the majority element that occur N/2 times.
    */

    int cnt = 0;
    int ele = 0;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            ele = a[i];
            cnt++;
        }

        else if(a[i] == ele){
            cnt++;
        }

        else{
            cnt--;
        }
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == ele) cnt1++;
    }

    if (cnt1 > floor(n/2)){
        return ele;
    }

    return -1;
}

/* STRING OPERATIONS */

void input_string(string &str){
    getline(cin,str);
}

void print_string(string &str){
    cout<<str;
}

void print_string_by_char(string &str){
    for(int i=0;i<str.length();i++){
        cout<<str[i];
    }
}

int minimum_add_make_paranthesis_valid(string &s){
    stack<char> st;
    int count = 0;

    for(int i=0;i<s.length();i++){

        if(s[i] == '('){
            st.push(s[i]);
        }

        else if(s[i] == ')'){

            if(st.empty()){
                count++;
            }

            else{
                st.pop();
            }
        }

    }

    return (count + st.size());
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/* BINARY TREE OPERATIONS */

btnode* buildTree(vector<int> pre, vector<int> in,int s,int e,int &idx){

    if(s>e || idx >= pre.size() || pre[idx] == -1){
        if (idx < pre.size()){idx++;}
        return NULL; // s>e this means that the subtree is non-existent.
    }

    int curr = pre[idx];
    idx++;
    btnode* n = new btnode(curr);

    if(s==e){
        return n; // The logic here means that if s==e, this means that this node is the leaf node and has no children.
    }

    int pos = search_in_inorder(in,s,e,curr); // This will help us divide the tree in left and right sides.
    n->left = buildTree(pre,in,s,pos-1,idx);
    n->right = buildTree(pre,in,pos+1,e,idx);

    return n;
}

int search_in_inorder(vector<int> in,int s,int e,int curr){

    for(int i=s;i<=e;i++){
        if(in[i] == curr){
            return i;
        }
    }

    return -1;
}

// Preorder Traversal of the Binary Tree
void preorder(btnode* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal of the Binary Tree
void inorder(btnode* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Postorder traversal of Binary Tree
void postorder(btnode* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int height_bt(btnode* bt){
    if(bt==NULL){
        return 0; // if the node is pointing to NULL return 0, as it doesn't have any height.
    }

    // Calculate the height of each subtree.

    int lh = height_bt(bt->left); // Calculate the height of left subtree
    int rh = height_bt(bt->right); // Calculate the height of right subtree

    return (max(lh,rh) + 1); //  The one with the longest subtree is longest, and it becomes the height of the tree.
}

void print_kth_level_of_bt(btnode* bt,int i){

    if(bt==NULL){
        return; // If the node is null, we can't print anything neither can we traverse further so return.
    }

    if(i==1){
        cout<<bt->data<<" "; // if the value of i is 1
    }

    else if(i>1){
        print_kth_level_of_bt(bt->left,i-1); // We traverser for each sucessor of the left subtree
        print_kth_level_of_bt(bt->right,i-1); // We traverse for each sucessor of the right subtree
    }
}

void levelorder(btnode* bt){

    int h = height_bt(bt);

    for(int i=1;i<=h;i++){
        print_kth_level_of_bt(bt,i);
    }
}

int sum_all_node_kth_lvl_bt(btnode* bt, int k){

    static int sum = 0;

    if(bt==NULL){
        return 0;
    }

    if(k==1){
        sum += bt->data;
    }

    else if(k>1){
        sum_all_node_kth_lvl_bt(bt->left,k-1);
        sum_all_node_kth_lvl_bt(bt->right,k-1);
    }

    return sum;

}

int summ_all_nodes_bt(btnode* bt){
    if(bt == NULL){
        return 0;
    }

    return (summ_all_nodes_bt(bt->left) + summ_all_nodes_bt(bt->right) + bt->data);
}

int count_nodes_bt(btnode* bt){
    if(bt == NULL){
        return 0;
    }

    return (count_nodes_bt(bt->left) + count_nodes_bt(bt->right) + 1);
}

int diameter_bt(btnode* bt){
    if (bt==NULL)
    {
        return 0;
    }

    int lh = height_bt(bt->left);
    int rh = height_bt(bt->right);

    int currdia = lh + rh + 1;
    int ldia = diameter_bt(bt->left);
    int rdia = diameter_bt(bt->right);

    return max(currdia,max(ldia,rdia));

}

btnode* insertnodebt(btnode* bt, int data){

    // If the tree is empty since the begining itself, the current node being inserted will become the root node.
    if(bt == NULL){
        bt = new btnode(data);
        return bt;
    }

    /**
     * Else, we do a level order traversal of the Binary Tree, untill we find a child place empty or missing.
     * */

    queue<btnode*> q;
    q.push(bt);

    while(!q.empty()){
        btnode* temp = q.front();
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }

        // If the left child of the Binary Tree is missing insert it as the left child.

        else{
            temp->left = new btnode(data);
            return bt;
        }


        if(temp->right != NULL){
            q.push(temp->right);
        }


        // If the right child of the Binary Tree is missing inser it as the right child.

        else{
            temp->right = new btnode(data);
            return bt;
        }
    }

    return bt;

}

btnode* deletenodebt(btnode* bt, int k){

    // If the tree is empty. return NULL
    if(bt==NULL){
        return NULL;
    }

    // If the tree has only one node
    if(bt->left == NULL && bt->right == NULL){
        if(bt->data == k){
            // If the node to be deleted is the root node, return NULL
            return NULL;
        }

        // Otherwise return the root node itself
        else{
            return bt;
        }
    }

    // We will do level order traversal of the tree
    queue<btnode*> q;
    q.push(bt);

    btnode* temp;
    btnode* key = NULL; // Will store the node to be deleted.

    // We will do level order traversal to find the deepest node, anb the node to be deleted.

    while(!q.empty()){
        temp = q.front();
        q.pop();

        // If the node with value to be deleted is found stor it's reference.
        if(temp->data == k){
            key = temp;
        }

        // Push left and right child of the node to the queue, it they exist.
        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

    // If the node to be deleted is found 
    if(key != NULL){
        // Replace the key node with the deepest node, which is temp right now.
        int x =  temp->data;
        key->data = x;
        // Now, delete the deepest node in the tree.
        deleteDeepestNode(bt,temp);
    }

    // Return the modified tree.
    return bt;

}

void deleteDeepestNode(btnode* bt, btnode* dnode){
    
    queue<btnode*> q;
    q.push(bt);

    // Level order traversal to find the deepest node.
    btnode* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();

        // If, we found the deepest node, delete it.
        if(temp == dnode){
            temp = NULL;
            delete(dnode);
            return;
        }

        // If the right child exists
        if(temp->right){
            
            // If the right child is the deepest node, delete it.
            if(temp->right ==  dnode){
                temp->right = NULL;
                delete(dnode);
                return;
            }

            // If not put it into the queue.
            else{
                q.push(temp->right);
            }
        }

        // If the left child exists
        if(temp->left){

            // If the left child is the deepest node, delete it.
            if(temp->left == dnode){
                temp->left = NULL;
                delete(dnode);
                return;
            }

            // If not put it into the queue.
            else{
                q.push(temp->left);
            }
        }
    }
}

int getLevelNodebt(btnode* temp,int k,int level){

    // If the tree is empty, return 0
    if(temp == NULL){
        return 0;
    }

    // If the current node is the node to be searched, return the level.
    if(temp->data == k){
        return level;
    }

    // Recursively check in the left subtree, increasing the level by 1.
    int downlevel = getLevelNodebt(temp->left,k,level+1);
    // If the node is found in the left subtree, return the level.
    if(downlevel){
        return downlevel;
    }

    // Recursively check in the Right subtree, increasing the level by 1.
    downlevel = getLevelNodebt(temp->right,k,level+1);
    
    if(downlevel){
        return downlevel;
    }

    return 0;
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

int stock_buy_and_sell(int *a, int n){
    int max_profit = 0;
    int min_price = INT_MAX;

    for(int i=0; i<n;i++){
        min_price = min(min_price,a[i]);
        max_profit = max(max_profit,a[i]-min_price);
    }

    return max_profit;
}

void rearrange_elements_by_sign_sorted(int* a, int n){
    int* pos = new int [n];
    int* neg = new int [n];
    int nl = 0, pl = 0;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            neg[nl] = a[i];
            nl++;
        }
        else{
            pos[pl] = a[i];
            pl++;
        }
    }

    quicksort_array(pos,pl,0,pl-1);
    quicksort_array(neg,nl,0,nl-1);

    int index = 0;


    if (pl < nl) {
        for (int i = 0; i < pl; i++) {
            a[index++] = pos[i];
            a[index++] = neg[i];
        }

        for (int i = pl; i < nl; i++) {
            a[index++] = neg[i];
        }
    }
    else {
        for (int i = 0; i < nl; i++) {
            a[index++] = pos[i];
            a[index++] = neg[i];
        }

        for (int i = nl; i < pl; i++) {
            a[index++] = pos[i];
        }
    }
}



void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;

}

void lbstar(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void rbstar(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= n - i) {
                cout<<" ";
            } else {
                cout<<"*";
            }
        }
        cout<<endl;
    }
}

void equilateral_triangle_pattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= n - i) {
                cout<<" ";
            } else {
                cout<<" *";
            }
        }
        cout<<endl;
    }
}

void diamond_pattern(int n){
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Print lower inverted triangle
    for (int i = n-1; i >= 1; i--) {
        // Print leading spaces
        for (int j = n; j > i; j--) {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void left_base_triangle_pattern(int n){
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void right_base_triangle_pattern(int n){
    cout<<endl;
    int k;

    for(int i=1;i<=n;i++){
        k=0;
        while(k!=(n-i)){
            cout<<" ";
            k++;
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=1;i<n;i++){
        k=0;
        while(k!=i){
            cout<<" ";
            k++;
        }
        for(int j=i;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void lastar(int n){
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pascal_triangle(int n){
    for(int i=0;i<n+1;i++){

        for(int j=0;j<=i;j++){
            cout<<binomoal_coeff(i,j)<<" ";
        }
        cout<<endl;
    }
}

void lexicographic_greater_permutation_main(){
    vector<int> v,ans;
    vector_input(v);
    vector<bool> map(v.size(),false);
    vector< vector<int> > res;
    lexicographic_greater_permutation(v,ans,map, res);

    sort(res.begin(),res.end());

    for(int i=0;i<res.size();i++){
        if(res[i]==v){
            i++;
            if(i==res.size()){
                printvectorint(res[1]);
            }
            else{
                printvectorint(res[i]);
            }
        }
    }
}

void lexicographic_greater_permutation(vector<int> &v,vector<int> &ans,vector<bool> &map, vector< vector<int> >  &res)
    {
        /*
            Time Complexity is O(n*n!).
            Space Complexity us O(n)+O(n).
        */

       if(ans.size() == v.size())
            {
                res.push_back(ans);
                return;
            }

        for(int i=0;i<v.size();i++)
            {
                if(!map[i])
                    {
                        map[i]=true;
                        ans.push_back(v[i]);
                        lexicographic_greater_permutation(v,ans,map,res);
                        ans.pop_back();
                        map[i]=false;
                    }
            }
    }

int longest_successive_elements(int *a, int n){
    if(n==0 || n==1){
        return n;
    }

    quicksort_array(a,n,0,n-1);
    int lastsm = a[0];
    int cnt = 0;
    int longest = 1;

    for(int i=1;i<n;i++){
        if(a[i]-1 == lastsm){
            cnt++;
            lastsm = a[i];
        }

        else if(a[i] != lastsm){
            cnt = 1;
            lastsm = a[i];
        }

        longest = max(longest,cnt);
    }

    return longest;
}


/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/* MATRIXX / 2D-ARRAY OPERATIONS */

int** matrix_input(int n, int m){
    int **a = new int* [n];

    for(int i=0;i<n;i++){
        a[i] = new int[m];
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    return a;
}

vector<int> search_matrix(int **a, int n, int m, int x){
    vector<int> pos;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == x){
                pos.push_back(i);
                pos.push_back(j);
                return pos;
            }
        }
    }

    return pos;
}

void set_matrix_zero(int **a, int n,int m){
    vector<int> pos = search_matrix(a,n,m,0);

    if(pos.empty()){
        return;
    }

    for(int i=0;i<n;i++){
        a[i][pos[1]] = 0;
    }

    for(int j=0;j<m;j++){
        a[pos[0]][j] = 0;
    }

}

void rotate_matrix_clockwise(int **a,int n,int m){

    // Transpose the Matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(a[i][j],a[j][i]);
        }
    }

    // Reverse each row of the Matrix

    int start = 0;
    int end = m-1;

    for(int i=0;i<n;i++){
        start = 0;
        end = m-1;

        while(start<end){
            swap(a[i][start],a[i][end]);
            start++;
            end--;
        }
    }
}

void spiral_traversal_matrix(int **a, int n, int m){
    int rs = 0;
    int re = n-1;

    int cs = 0;
    int ce = m-1;

    while(rs<=re && cs<=ce){
        for(int i=cs;i<=ce;i++){
            cout<<a[rs][i]<<" ";
        }

        rs++;

        for(int i=rs;i<=re;i++){
            cout<<a[i][ce]<<" ";
        }

        ce--;

        for(int i=ce;i>=cs;i--){
            cout<<a[re][i]<<" ";
        }

        re--;

        for(int i=re;i>=rs;i--){
            cout<<a[i][cs]<<" ";
        }

        cs++;
    }
}

void print_matrix(int **a, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/


int binomoal_coeff(int n,int k){
    int res = 1;

    if(k>n-k){
        k = n-k;
    }

    for(int i=1;i<=k;i++){
        res = res * (n-i+1)/i;
    }

    return res;
}

vector<int> majority_element_n3(int *a, int n){
    map<int,int> mp; // Map the elements against it's count
    vector<int> l;  // Result Vector, maximum there can be 3 elements with n/3 times occurance in the array but we will only take first 2.

    int mini = (n/3) + 1;

    for(int i=0;i<n;i++){
        mp[a[i]]++;

        if(mp[a[i]] == mini){
            l.push_back(a[i]);
        }

        if(l.size() == 2){
            break;
        }
    }

    return l;
}






/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/* MAP OPERATIONS */

map<int,int> map_input_int(){
    int n;
    cin>>n;

    map<int,int> mp;

    for(int i=0;i<n;i++){
        int key;
        int value;
        cin>>key>>value;
        mp[key] = value;
    }

    return mp;
}

void print_map_int(map<int,int> mp){

    for(const auto& itr : mp){
        cout<<itr.first<<"->"<<itr.second<<endl;
    }

    return;
}

int good_sequence_frequency_equals_number(int *a, int n){
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }

    int result = 0;

    for(auto i=mp.begin();i!=mp.end();i++){

        int num = i->first;
        int count = i->second;

        if(count == num){
            continue;
        }

        else if(count>num){
            result += count-num;
        }

        else{
            result += count;
        }
    }

    return result;
}

bool compare_value_sort_map_by_value(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

void sort_map_by_value_int(map<int,int> mp){
    vector<pair<int,int> > v;

    for(auto& it: mp){
        v.push_back(it);
    }

    sort(v.begin(),v.end(),compare_value_sort_map_by_value);
}

/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
