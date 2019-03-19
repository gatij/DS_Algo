#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> ii;
typedef vector< ii >  vii;
typedef vector<long long> vi;
class Graph{
	int node_count; //No of nodes
	int edge_count; //No of Edges
	vector<vii> adj_list;
	vi vis; // visited array for dfs
	
	void set_node(int n) // intialize the count of nodes
	{
		node_count=n;
	}
	
	void set_edge(int m)//  intialize the count of edges
	{
		edge_count=m;
	}
	
	void connect(int a,int b,long long w=1) // connect two nodes of graph
	{
		adj_list[a].push_back(make_pair(b,w));
		adj_list[b].push_back(make_pair(a,w));
	}
	
	public:
		Graph(int n,int m)  //constructor to intialize the graph object
		{
			set_node(n);
			set_edge(m);
			adj_list.resize(node_count+1);
			vis.assign(n+1,0);
		}
		
		void print_graph() // print the graph
		{
			for( int i=1;i<=node_count;i++)
			{
				cout<<"Node "<<i<<"--->";
				for(int j=0;j<adj_list[i].size();j++)
				{
					cout<<adj_list[i][j].first<<" ";
				}
				/*cout<<"\n";
				cout<<"Weight"<<"--->"; // to print weight of edges
				for(int j=0;j<adj_list[i].size();j++)
				{
					cout<<adj_list[i][j].second<<" ";
				}
				*/
				cout<<"\n\n";
			}
		}
		void add_edge(int a,int b,long long w=1) // make an edge
		{
			connect(a,b,w);
		}
		
		void dfs(int s)
		{
			vis[s]=1;//
			for(int i=0;i<adj_list[s].size();i++)
			{
				if(!vis[adj_list[s][i].first])
				{
					dfs(adj_list[s][i].first);
				}
			}
		}
		
		void reset_vis()
		{
			vis.assign(node_count+1,0);
		}
		void print_dfs(int s)
		 {
		 	vis[s]=1;//
		 	cout<<s<<" ";
			for(int i=0;i<adj_list[s].size();i++)
			{
				if(!vis[adj_list[s][i].first])
				{
					print_dfs(adj_list[s][i].first);
				}
			}
			cout<<"\n";
		 }
	
	
};

int main()
{
	int n,m,a,b,w,s;
	cin>>n>>m;
	Graph g(n,m);
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		//cin>>w; if graph is weighted 
		g.add_edge(a,b);
	}
	g.print_graph();
	cin>>s;//source
	g.print_dfs(s);
	
	return 0;
}
