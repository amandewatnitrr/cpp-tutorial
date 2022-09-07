#include <template.h>
using namespace std;
void bruteforce(vector<int>&);
void recurrsive(vector<int>&,int,int);

int main()
{
    int n,k;
    vector<int>v;
    cin>>n;
    
    for (int i = 0; i <n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
    
    recurrsive(v,0,v.size()-1);

    for(auto i = 0; i <v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
}

void bruteforce(vector<int>&v)
    {
        /*Time Complexity in this case is O(n).*/
        int start=0;
        int end=v.size()-1;
        int temp;

        while(start<end)
            {
                temp = v[start];
                v[start]=v[end];
                v[end]=temp;
                start++;end--;
            }
    }

void recurrsive(vector<int>&v,int start,int end)
    {
        if(start<end)
            {
                int temp = v[start];
                v[start]=v[end];
                v[end]=temp;
                recurrsive(v,++start,--end);
            }
        else
            {
                return;
            }
    }
