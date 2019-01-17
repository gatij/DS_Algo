#include<bits/stdc++.h>
using namespace std;
#define INF -1000000000
 struct node{
 	long long l;
 	long long r;
 	long long swap;
 };
 
class SegmentTree{
      private:
	  vector<long long>A;
	  vector<node> st;
	  int n;
	  int left(int p)
	  {
	  	return (1<<p);
	  }	
	  int right(int p)
	  {
	  	return (1<<p)+1;
	  }
	  
	  void build(int p,int l,int r)
	  {
	  	if(l==r)
	  	{
	  		st[p].l=A[l];
	  		st[p].r=A[r];
	  		st[p].swap=0;
		}
	  	else
	  	{
	  		build(left(p),l,(l+r)/2);
	  		build(right(p),((l+r)/2)+1,r);
	  		long long ll,lr,ls,rl,rr,rs;
	  		ll=st[left(p)].l;
	  		lr=st[left(p)].r;
	  		ls=st[left(p)].swap;
	  		rl=st[right(p)].l;
	  		rr=st[right(p)].r;
	  		rs=st[left(p)].swap;
	  		if(lr<rl)
	  		{
	  			st[p].l=ll;
	  			st[p].r=rr;
	  			st[p].swap=ls+rs;
			  }
			  else if(rr<ll)
			  {
			  	st[p].l=rl;
			  	st[p].r=lr;
			  	st[p].swap=ls+rs+1;
			  }
			  else
			  {
			  	st[p].l=min(ll,rl);
			  	st[p].r=max(lr,rr);
			  	st[p].swap=INF;
			  }
		}
	  }
	  int RMQ(int p)
	  {
	  	
	  	return st[p].swap;
	  	
	  }
	  
	  public:
	  	SegmentTree(const vector<long long> &_A)
	  	{
	  		A=_A;
	  		n=(int)A.size();
	  		for(int i=0;i<4*n;i++)
	  		{
	  			st[i].l=-1;
	  			st[i].r=-1;
	  			st[i].swap=0;
			  }
	  		build(1,0,n-1);
		}
		
		int RMQ()
		{
			return RMQ(1);
		}
		  

};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<long long>v;
		long long l,r;
		for(int i=0;i<n;i++)
		{
			cin>>l>>r;
			if(l==-1)
			{
				v.push_back(r);
			}
		}
	SegmentTree st(v);
		cout<<st.RMQ()<<"\n";
	}
	return 0;
}
