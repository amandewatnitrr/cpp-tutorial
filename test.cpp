#include <iostream>

using namespace std;
#define MAX 50
void input(int [][MAX],int,int);
void output(int [][MAX],int,int);

int main()
{
	int r,c,a[MAX][MAX];
	cout<<"\nEnter the row and column size of the array = ";
	cin>>r>>c;
	cout<<"\nEnter the values into the array --> \n";
	input(a,r,c);
	cout<<"\nThe Values in the array are --> \n";
	output(a,r,c);
	return 0;
}

void input(int **a,int r,int c)
{
	for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				{
					cin>> a[i][j];
				}
		}
}

void output(int a[][MAX],int r,int c)
{
	for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				{
					cout<<a[i][j]<<" ";
				}
			cout<<endl;
		}
}
