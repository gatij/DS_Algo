#include<bits/stdc++.h>
using namespace std;

// return the parent of the node
int find(vector<pair<int,int> > &u,int i)
{
	if(u[i].first==i)
	return i;
	
	else
	{
		u[i].first=find(u,u[i].first);
		return u[i].first;
	}
	
}

// union of nodes from different sets
void unite(vector<pair<int,int> > &u, int i,int j)
{
	if(find(u,i)!=find(u,j))
	{
		if(u[i].second<u[j].second)
		{
			u[i].first=u[j].first;
			u[i].second=max(u[j].second,u[i].second+1);
		}
		else
		{
			u[j].first=u[i].first;
			u[j].second=max(u[i].second,u[j].second+1);
		}
	}
}
int main()
{
	int m,n,x,y,z;//n - nodes ,m - no of edges
	cin>>n>>m;
	vector<pair<int,pair<int,int> > >v(m);
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		v[i].first=z;//weight
		v[i].second.first=x;//start node
		v[i].second.second=y;//end node
	}
	sort(v.begin(),v.end());// sort edges according to weight in non decreasing order
	vector<pair<int,int> >u(n);
	int vis[n],c=0;
	for(int i=0;i<n;i++)
	{
		u[i].first=i;//parent
		u[i].second=0;//height
		vis[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		if(find(u,v[i].second.first)!=find(u,v[i].second.second))// if edge not causing cycle then we take it
		{
			unite(u,v[i].second.first,v[i].second.second);
			if(vis[v[i].second.first]==0)
			{
				vis[v[i].second.first]=1;
				c++;
			}
			if(vis[v[i].second.second]==0)
			{
				vis[v[i].second.second]=1;
				c++;
			}
			cout<<v[i].second.second<<" "<<v[i].second.first<<"------"<<v[i].first<<"\n";
		}
		if(c==n)// all nodes visited ; Minimum Spanning Tree obtained
		{
			break;
		}
	}
	return 0;
}
