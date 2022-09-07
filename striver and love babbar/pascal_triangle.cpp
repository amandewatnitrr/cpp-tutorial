#include <template.h>
using namespace std;
void bruteforce(int);
void optimise1(int );
int binomial(int ,int);

int main()
{
    int n;
    cin>>n;
    optimise1(n);
}

int binomial(int n,int k)
    {
        int res=1;
        if(k>n-k)
            {
                k=n-k;
            }
        for(int i=0;i<k;i++)
            {
                res*=(n-i);
                res/=(i+1);
            }

        return res;
    }
void bruteforce(int n)
    {
        /*Time Complexity in this case is O(n^3). */
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
                {
                    cout<<binomial(i,j)<<" ";
                }
            cout<<endl;
        }
    }
void optimise1(int n)
    {
        /*Time complexity is O(n^2) and Space Complexity is also same.*/
        int arr[n][n];
        for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= i; j++)
                    {
                        if (i == j || j == 0)
                            {arr[i][j] = 1;}
                        else
                            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
                        cout << arr[i][j] << " ";
                    }
                cout << "\n";
            }

    }
