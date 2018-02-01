#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a,s=0;
		for(int i=1;i<n;i++)
		{
			cin>>a;
			s+=a;
		}
		cout<<((n*(n+1))/2)-s<<"\n";
		
	}
	return 0;
}
