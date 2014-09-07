#include<iostream>
#include<map>
#include<vector>
#include <algorithm>
#include<functional>
#include<set>
using namespace std;


int main()
{
	int diff[30001]={0};
	int n;
		
	while(cin>>n)	
	{
		
		int num,prev;
		cin>>num;
		prev=num;
		if(n==1)
		{
			cout<<"Jolly"<<endl;
			continue;
		}
		int i;
		for(i=1;i<n;i++)
		{
			cin>>num;
			diff[i-1]=abs(num-prev);
			prev=num;
		}
		sort(&diff[0],&diff[i-1]);
		int j;
		for(j=1;j<n;j++)
			if(diff[j-1]!=j)
			{
				cout<<"Not jolly"<<endl;
				break;
			}
			if(j==n)
				cout<<"Jolly"<<endl;
	}
	return 0;
}