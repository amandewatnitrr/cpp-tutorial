#include <template.h>
#define MAXX 50
using namespace std;
void bruteforce(int **,int ,int);
void optimise1(int **,int ,int);

int main()
{
    int r,c;
    cin>>r>>c;
    int **a = new int *[r];

    vector<int>r1;
    vector<int>c1;

    for(int i=0;i<r;i++)
        {
            a[i] = new int[c];
            for(int j=0;j<c;j++)
                {
                    cin>>a[i][j];
                }
        }

    
   optimise1(a,r,c);

    for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                {
                    cout<<a[i][j]<<" ";
                }
            cout<<endl;
        }
    
}

void bruteforce(int **a,int r,int c)
    {
        /*
            Time Complexity in this case is (N*M)*(N+M).
        */
        for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                    {
                        if(a[i][j] == 0)
                            {
                                for(int k=0;k<r;k++)
                                    {
                                        if(a[k][j] == 1)
                                            {
                                                a[k][j] = -1;
                                            }
                                    }

                                for(int k=0;k<c;k++)
                                    {
                                        if(a[i][k] == 1)
                                            {
                                                a[i][k] = -1;
                                            }
                                    }   
                            }
                    }
            }
        
        for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                    {
                        if(a[i][j]==-1)
                            {
                                a[i][j]=0;
                            }
                    }
            }
    }

void optimise1(int **a,int r,int c)
	{
		int *R = new int[r];
		int *C = new int[c];

        for(int i=0;i<r;i++)
            {
                R[i]=1;
            }
        for(int i=0;i<c;i++)
            {
                C[i]=1;
            }

		 for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                    {
                        if(a[i][j] == 0)
                            {
                            	R[i]=0;
                                C[j]=0;
							}
					}
			}

        for(int i=0;i<r;i++)
            {
                cout<<R[i]<<" ";
            }
            cout<<endl;
        for(int i=0;i<c;i++)
            {
                 cout<<C[i]<<" ";
            }
        cout<<endl;
        cout<<endl;


         for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                    {
                        if(R[i]*C[j]==0)
                            {
                            	a[i][j]=0;
							}
					}
			}
		
	}
