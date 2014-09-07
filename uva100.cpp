#include<iostream>

using namespace std;
int a[1000000]={0};
int cycles(long long n)
{
	if(n==1) return 1;
	if(n<1000000)
		if(a[n]>0) 
			return a[n];
	if ( n%2 == 0 )
		n/=2;
	else
		n=3*n+1;
	int c= 1+ cycles(n);
	if(n<1000000)
		a[n]=c-1;
	return c;
}

int main()
{
	int first,second;	
	while(cin>>first>>second)
	{
		int i,j;
		if (first>second)
			i=second,j=first;
		else
			i=first,j=second;
		int max=0;
		for(int k=i;k<=j;k++)
		{
			int count=cycles(k);
			if (count>max)
				max=count;
		}
		cout<<first<<' '<<second<<' '<<max<<endl;
		first=false;
	}
	return 0;
}