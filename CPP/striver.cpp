#include <template.h>
#define MAXX 50
using namespace std;

void print_1_to_n(int);
void print_n_to_1(int,int );
int main()
{
    int n;
    cin>>n;    
    print_n_to_1(n,1);

}

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