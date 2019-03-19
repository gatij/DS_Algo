#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> ii;
typedef vector< ii >  vii;
typedef vector<long long> vi;

# define INF 1000000007
class Graph{
	int node_count; //No of nodes
	int edge_count; //No of Edges
	vector<vii> adj_list;
	vi dis; // distance array for bfs
	
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
			dis.assign(n+1,INF); //intiallly every thing is at INF distance from each other
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
		
		void bfs(int s)
		{
			dis[s]=0;// dis from s to s is zero
			queue<int> Q;
			Q.push(s);
			while(!Q.empty())
			{
				int u=Q.front();
				Q.pop();
			for(int i=0;i<adj_list[u].size();i++)
			{
				if(dis[adj_list[s][i].first]==INF)
				{
					Q.push(adj_list[s][i].first);
					dis[adj_list[s][i].first]=dis[u]+1;
				}
			}
			
			}
			
		}
		
		void reset_vis()
		{
			dis.assign(node_count+1,INF);
		}
		void print_bfs(int s)
		 {
		 	dis[s]=0;// dis from s to s is zero
		 	int ln=0,nln=0,lc=0;
			queue<int> Q;
			Q.push(s);
			cout<<s<<"\n";
			ln++;
			lc++;
			while(!Q.empty())
			{
			int u=Q.front();
			Q.pop();
			ln--;
			for(int i=0;i<adj_list[u].size();i++)
			{
				if(dis[adj_list[u][i].first]==INF)
				{
					Q.push(adj_list[u][i].first);
					dis[adj_list[u][i].first]=dis[u]+1;
					
					cout<<adj_list[u][i].first<<" "; //printing layer
					nln++;
				}
			}
			if(ln==0)
			{
				ln=nln;
				nln=0;
				cout<<"\n";
				lc++;
			}
			
			}
			cout<<"total no of layers: "<<lc<<"\n";
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
	g.print_bfs(s);
	
	return 0;
}
