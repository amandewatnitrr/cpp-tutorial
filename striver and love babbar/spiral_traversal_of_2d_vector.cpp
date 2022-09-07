#include <template.h>
#define MAXX 50
using namespace std;

int spiraltraversal(vector<vector<int>> &);

int main()
{
    int n,m,k;
    vector<vector<int>>v;
    cin>>n>>m;

    for (int i = 0; i < n; i++)
        {
            vector<int>r;
            for (int j = 0; j < m; j++)
                {
                    cin>>k;
                    r.push_back(k);
                }            
            v.push_back(r);
        }
    
    for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
                {
                    cout<<v[i][j]<<" ";
                }            
            cout<<endl;
        }
    
    cout<<endl;

    spiraltraversal(v);


}

int spiraltraversal(vector<vector<int>>&v)
    {
        int rs=0;
        int re=v[0].size()-1;
        int cs=0;
        int ce=v.size()-1;

        while (rs<=re && cs<=ce)
        {
            for (int i=cs;i<=ce;i++)
                {
                    cout<<v[rs][i]<<" ";
                }
            rs++;
            
            for(int i=rs;i<=re;i++)
                {
                    cout<<v[i][ce]<<" ";
                }
            ce--;

            for (int i=ce;i>=cs;i--)
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
