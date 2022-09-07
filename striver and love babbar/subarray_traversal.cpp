#include <template.h>
using namespace std;
void traversesubarray(vector<int>&);

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
    traversesubarray(v);
}

void traversesubarray(vector<int>&v)
    {
        for (int i=0;i<v.size();i++)
            {
                for (int j=i;j<v.size();j++)
                    {
                        for (int k = i;k<=j;k++)
                            {
                                cout<<v[k]<<" ";
                            }
                        cout<<endl;
                    }
            }
    }
