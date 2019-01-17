//Greedy Algorithms Examples
//Algorithm 1 : maximum number of Disjoint Activity Selection Problem

#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int>& x, const pair<int,int>& y)//sort by second element of pair
{
	return (x.second < y.second);
}
class Activity
{
	
	vector<pair<int,int> > A;
	int n;
	int ans;
	public:
		Activity(const vector<pair<int,int> >& _A)
		{
			A=_A;
			n=(int)(A.size());
			ans=1;
		}
		
		int guess()
		{
			sort(A.begin(),A.end(),compare);
			int x=A[0].second;
			for(int i=1;i<n;i++)
			{
				if(A[i].first>=x)
				{
					ans++;
					x=A[i].second;
				}
			}
			
			return ans;
		}
		
		
};

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<pair<int,int> >v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i].first;
		}
		for(int i=0;i<n;i++)
		{
			cin>>v[i].second;
		}
		
		Activity act(v);
		cout<<act.guess()<<"\n";
	}
	return 0;
}
