#include<bits/stdc++.h>
using namespace std;
struct node{
	long long left;
	long long right;
	long long swap;
};
#define INF -1000000000
class SegmentTree{
	private:
	long long n;
	vector<long long>A;
	vector<node>st;
	long long left(long long p)
	{
		return (1<<p);
	}
	long long right(long long p)
	{
		return (1<<p)+1;
	}
	void build(long long p,long long l,long long r)
	{
		if(l==r)
		{
			st[p].left=A[l];
			st[p].right=A[r];
			st[p].swap=0;
		}
		else
		{
			build(left(p),l,(l+r)/2);
			build(right(p),((l+r)/2)+1,r);
			long long ll,lr,ls,rl,rr,rs;
			ll=st[left(p)].left;
			lr=st[left(p)].right;
			ls=st[left(p)].swap;
			rl=st[right(p)].left;
			rr=st[right(p)].right;
			rs=st[right(p)].swap;
			if(lr<rl && (rl-lr)==1)
			{
				st[p].left=ll;
				st[p].right=rr;
				st[p].swap=ls+rs;
			}
			else if(rr<ll && (ll-rr)==1)
			{
				st[p].left=rl;
				st[p].right=lr;
				st[p].swap=ls+rs+1;
			}
			else
			{
				st[p].left=min(ll,rl);
				st[p].right=max(lr,rr);
				st[p].swap=INF;
			}
		}
	}
	long long ans(long long p)
	{
		return st[p].swap;
	}
	public:
		SegmentTree(const vector<long long> &_A)
		{
			//cout<<"constructor called\n";
			A=_A;
			long long n=A.size();
			//cout<<"size :"<<n<<"\n";
			node nd;
			nd.left=-1;
			nd.right=-1;
			nd.swap=0;
			//cout<<"going to assign\n";
			for(long long i=0;i<4*n;i++)
			{
				st.push_back(nd);
			}
			//cout<<"assignment completed\n";
			//for(long long i=0;i<4*n;i++)
			//{
            //    cout<<st[i].left<<" "<<st[i].right<<" "<<st[i].swap<<"\n";
			//}
			//cout<<"build called\n";
			build(1,0,n-1);
		}
		long long ans()
		{
			return ans(1);
		}
	
};
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long>v;
		long long l,r;
		for(long long i=0;i<n;i++)
		{
			cin>>l>>r;
			if(l==-1)
			{
				v.push_back(r);
			}
		}
		/*for(int i=0;i<v.size();i++)
	    cout<<v[i]<<" ";
	    cout<<"\n";*/
	    SegmentTree st(v);
	    long long a=st.ans();
	    if (a>=0)
	    cout<<a;
	    else
	    cout<<"-1";
	    cout<<"\n";
	}
	return 0;
}

