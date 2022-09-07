#include <iostream>	
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

using namespace std;

void bintodec();
void octtodec();
void hextodec();
void dectooct();
void dectohex();

int main()
{
	octtodec();
}

void bintodec()
{
	int n;
	cout<<"\nEnter no. of bits in binary data --> ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the binary number --> ";
	for(int i=0;i<n;i++){cin>>a[i];}
	int sum = 0;
	for(int i=n-1,j=0;i>=0,j<n;i--,j++)
		{
			sum  = sum + pow(2,j) * a[i];
		}
	cout<<"\nDecimal Conversion of given Binary Number = "<<sum<<endl;
}

void octtodec()
{	
	int n;
	cout<<"\nEnter no. of digits in Octal --> ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the Octal number --> ";
	for(int i=0;i<n;i++){cin>>a[i];}
	int sum = 0;
	for(int i=n-1,j=0;i>=0,j<n;i--,j++)
		{
			if(a[i]>7){cout<<"\nIncorrect Input.. "<<endl;
			return ;}
			sum  = sum + pow(8,j) * a[i];
		}
	cout<<"\nDecimal Conversion of given Octal Number = "<<sum<<endl;
}

void hextodec()
{	
	string s;
	cout<<"\nEnter the number in Hexadecimal format = ";
	cin>>s;
	double sum = 0;
	for(int i=s.size()-1;i>=0;i--)
		{
			if(isdigit(s[i]))
				{
					sum = sum + (s[i] - '0')*pow(16,s.size()-1-i);
				}
			if(isalpha(s[i]))
				{
					int k = 0;
					if(s[i] == 'A'){k=10;}
					if(s[i] == 'B'){k=11;}
					if(s[i] == 'C'){k=12;}
					if(s[i] == 'D'){k=13;}
					if(s[i] == 'E'){k=14;}
					if(s[i] == 'F'){k=15;}
					sum = sum + k;
				}
		}
	cout<<"\nThe Decimal of given HexaDecimal Number is = "<<sum<<endl;
}

void dectooct()
{	
	int s,n,c;
	cout<<"\nEnter the number in decimal format = ";
	cin>>s;
	n=s;
	c=0;
	int sum = 0;
	while(s!=0)
		{
			s = s/10;
			c++;
		}
	int d1,d2,d3;
	d3 = n;
	int i=0; 
	while(d3!=0)
	{
		d2 = d3 % 8;
		sum = sum + pow(10,i)*d2;
		i++;
		d3 = d3/8;
		
	}
	cout<<"\nThe Octal of given Decimal Number is = "<<sum<<endl;
}

void dectohex()
{	
	int n,c,k;
	cout<<"\nEnter the number in decimal format = ";
	cin>>k;
	n=k;
	c=0;
	string s,p;
	while(k!=0)
		{
			k = k/10;
			c++;
		}
	int d1,d2,d3;
	d3 = n;
	int i=0; 
	while(d3!=0)
	{
		d2 = d3 % 16;
		
		if(d2<10){s[i] = d2;}
		if(d2>9)
			{
				if(d2 == 10){s[i] = 'A';}
				if(d2 == 11){s[i] = 'B';}
				if(d2 == 12){s[i] = 'C';}
				if(d2 == 13){s[i] = 'D';}
				if(d2 == 14){s[i] = 'E';}
				if(d2 == 15){s[i] = 'F';}
			}
		i++;
		d3 = d3/16;
		
	}
	cout<<"\nThe Octal of given Decimal Number is = ";
	for(int k=0,j = i-1 ;j >= 0,k < i;j--,k++)
		{
			p[k]=s[j];
			if(isdigit(p[k])){cout<<p[k];}
			else{cout<<"("<<(int)p[k]<<")";}
		}
	cout<<endl;
}
