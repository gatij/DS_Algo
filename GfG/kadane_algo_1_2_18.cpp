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
		int a[n];
		int sum=0,maxsum;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(i==0)
			maxsum=a[i];
			sum+=a[i];
			if(sum>maxsum)
			{
				maxsum=sum;
			}
			if(sum<0)
			{
				sum=0;
			}
		}
		cout<<maxsum<<"\n";
	}
	return 0;
}
