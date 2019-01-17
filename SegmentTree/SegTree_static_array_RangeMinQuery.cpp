#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
      private:
	  vector<long long> st,A;
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
	  	st[p]=l;
	  	else
	  	{
	  		build(left(p),l,(l+r)/2);
	  		build(right(p),((l+r)/2)+1,r);
	  		int minl_i=st[left(p)],minr_i=st[right(p)];
	  		st[p]=(A[minl_i]<=A[minr_i])?minl_i:minr_i;
		}
	  }
	  int RMQ(int p,int l,int r,int i,int j)
	  {
	  	if(i>r || j<l)
	  	return -1;
	  	if(l>=i && r<=j)
	  	return st[p];
	  	
	  	int minl_i=RMQ(left(p),l,(l+r)/2,i,j);
	  	int minr_i=RMQ(right(p),((l+r)/2)+1,r,i,j);
	  	return (A[minl_i]<=A[minr_i])?minl_i:minr_i;
	  }
	  
	  public:
	  	SegmentTree(const vector<long long> &_A)
	  	{
	  		A=_A;
	  		n=(int)A.size();
	  		st.assign(4*n,0);
	  		build(1,0,n-1);
		}
		
		int RMQ(int i,int j)
		{
			return RMQ(1,0,n-1,i,j);
		}
		  

};

int main()
{
	int arr[]={18,17,13,19,15,11,20};
	vector<long long> A(arr,arr+7);
	SegmentTree st(A);
	cout<<"RMQ(1,3) "<<st.RMQ(1,3)<<"\n";
	cout<<"RMQ(4,6) "<<st.RMQ(4,6)<<"\n";
	return 0;
}
