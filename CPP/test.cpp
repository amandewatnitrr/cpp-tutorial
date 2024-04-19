#include <iostream>
#include <stack>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <math.h>
#include <atomic>
#include <condition_variable>

using namespace std;

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
void ll_main();


/*Sorting Algrithms*/

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

/*Kadane's Algorithm*/

int kadanealgos(vector<int>&,int);
void array_swap(int *,int ,int );

void array_input(int *,int);
void array_traversal(int *,int);
void insert_in_array_at_pos(int *, int &, int ,int );

void vector_input(vector<int> &);
void vector2d_input(vector<vector<int> > &);
void printvectorint(vector<int>&);
void printvectorchar(vector<char>&);
void search_in_rowise_and_colwise_sorted_2d_vector(vector<vector<int> > &,int);

void subarrays_of_vector(vector<int> &);

int maximum_circular_subarray_sum(vector<int> &);
void spiral_order_traversal(vector<vector<int> >& );

/*Basic Bit Manipulation Operations*/

int getbit(int ,int);
int setbit(int ,int);
int clearbit(int , int);
int updatebit(int , int, int);
void binary_representation_of_number(int );
vector<int> count0s1s_in_binary_represent_of_number(int );
int onescomplement(int );

// Interview Questions

void generate_and_count_subset_of_set(vector<int> &);

vector<int> display_all_unique_elements_in_vector(vector<int> &v);

vector<int> sieve_of_eratosthenes(int );

int shorter_angle_bw_hour_and_minute(int , int );

bool isperfectnumber(int );
bool check_2_numbers_same(int ,int );

int reverse_the_number(int );

void print_permutations_of_string(string , string);

bool check_if_array_sorted(int [],int);

vector<int> first_and_last_occurance_of_ele_unsorted_array(int *, int , int , int , vector<int> &);

int fibonaci_nth_term(int);

void print_subsequence(int,vector<int> &,vector<int> &);
void print_subsequence_whose_sum_is_k(int ,vector<int> &,vector<int> &,int,int );
bool print_1_subsequence_whose_sum_is_k(int ,vector<int> &,vector<int> &,int ,int );

int count_subsequence_whose_sum_is_k(int i,vector<int> &,vector<int> &,int ,int ,int &);

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
bool isPalindromeString(string);

void rat_in_maze(vector<vector<int> > &maze,int i,int j,vector<vector<int> > &vis,string s,int n,vector<string>&ans);

void reverse_words_in_sentence(string str);

int no_of_ways_n_elements_can_be_divided_into_groups(int );
int tiling_problem(int , int );
int ways_to_reach_nth_stair_by_taking_atmost_k_steps(int , int );

void remove_duplicates_from_sorted_array(vector<int> &v);

void two_elements_whose_sum_closest_to_0(vector<int> &v);

void createDuplicateArray(vector<pair<string, int> >& wordidx,vector<string>& v);
void print_all_anagrams_together(vector<string> &v);

bool isEven(int n);
bool isOdd(int n);

// Multi-threading

int main()
{
    ll_main();
    return 0;
}

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
        for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
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
                if(a[mid]==1)
                    {
                        mid++;
                    }
                if(a[mid]==2)
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
        if(n==1)
            {
                return 1;
            }
        return n * factorial(n-1);
    }

bool check_palindrome_string(string s,int i)
    {
        if(i>=s.size()/2)
            {
                return true;
            }
        if(s[i]!=s[s.size()-1-i])
            {
                return false;
            }
        return check_palindrome_string(s,i+1);
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

void remove_duplicates_from_sorted_array(vector<int>& a){

    // Time Complexity of this problem is O(n).
    // Space Complexity of this problem is O(1).

    bubblesort(a);

    int n = a.size();
    int j = 0;

    for(int i=0;i<n-1;i++){
        if(a[i] != a[i+1]){
            a[j++] = a[i];
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
    llnode* todelete = head->next;
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
