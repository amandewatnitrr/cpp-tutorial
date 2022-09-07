#include <template.h>
#define MAXX 50
using namespace std;

int kadanealgos(vector<int>&,int);

int main()
{
    vector<int>a,b;
    int k,n,sum=0;

    cin>>n;
    for(int i=0;i<n;i++)
        {
            cin>>k;
            sum+=k;
            a.push_back(k);
            b.push_back(-1*k);
        }
    int kadanesum = kadanealgos(a,n); // Maximum Subarray Sum
    int negatesum = kadanealgos(b,n); // Sum of Non-Contributing Elements
    int cmaxsum = sum-negatesum; // Maximum Circular Subarray Sum
    int max;

    if(cmaxsum>=kadanesum)
        {
            max= cmaxsum;
        }
    else 
        {
            max = kadanesum;
        }
    cout<<max<<endl;
}

int kadanealgos(vector<int> &a,int n)
    {
        int csum=0;
        int maxsum=0;
        for (int i = 0; i <n;i++)
            {
                csum+=a[i];
                if(csum<0)
                    {
                        csum=0;
                    }
                if(maxsum<csum)
                    {
                        maxsum=csum;
                    }
            }
        return maxsum;
    }
