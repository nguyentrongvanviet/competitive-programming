#include<bits/stdc++.h>
using namespace std;

#define TASK "D"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =1e6+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
struct node
{
	int dong , tay , nam  ,bac ;
	node  operator +(const node & a)const
	{
		return node{dong+a.dong,tay+a.tay,nam+a.nam,bac+a.bac};
	}
};
int n ; 
char a[N] ; 
node st[8*N ] ;
int lazy[8*N] ; 
void build(int id , int l , int r )
{
	if(l==r)
	{
		if(a[l]=='E')
		{
			st[id].dong= 1; 
		}
		else if(a[l]=='W')
		{
			st[id].tay=1 ; 
		}
		else if(a[l]=='S')
		{
			st[id].nam=1; 
		}
		else if(a[l]=='N')
		{
			st[id].bac= 1;
		}
		return ; 
	}
	int mid =(l+r)/2 ; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r)  ;
	st[id] =st[id*2]+st[id*2+1];
}
void dolazy(int id )
{
	if(lazy[id]==0)return ; 
	if(lazy[id]==1)
	{
		int d=st[id].dong  ; 
		int t= st[id].tay ; 
		int n=st[id].nam ; 
		int b =st[id].bac; 
		st[id].dong = n ; 
		st[id].nam= t; 
		st[id].tay=b ; 
		st[id].bac= d; 
	}
	else if(lazy[id]==2)
	{
		int d=st[id].dong  ; 
		int t= st[id].tay ; 
		int n=st[id].nam ; 
		int b =st[id].bac; 
		st[id].dong = n ; 
		st[id].nam= t; 
		st[id].tay=b ; 
		st[id].bac= d; 
	}
	else if(lazy[id]==3)
	{
		int d=st[id].dong  ; 
		int t= st[id].tay ; 
		int n=st[id].nam ; 
		int b =st[id].bac; 
		st[id].dong= n ; 
		st[id].nam= t; 
		st[id].tay=b ; 
		st[id].bac= d; 
	}
	lazy[id*2]+=lazy[id] ; 
	lazy[id*2+1]+=lazy[id]; 
	lazy[id] = 0 ;
	lazy[id*2]%=4 ; 
	lazy[id*2+1]%=4 ;
}
void update(int id, int l , int r, int t, int p ,int k )
{
	dolazy(id) ;
	if(r<t||p<l)return ;  
	if(t<=l&&r<=p)
	{
		lazy[id]+=k ; 
		dolazy(id) ; 
		return ; 
	}
	int mid =(l+r)>>1 ; 
	update(id*2,l,mid,t,p,k) ; 
	update(id*2+1,mid+1,r,t,p,k) ; 
	st[id] =(st[id*2]+st[id*2+1]);
}
void up(int id, int l , int r, int pos ,char k )
{
	dolazy(id) ; 
	if(r<pos||pos<l)return ;
	if(l==r&&l==pos)
	{
		st[id].dong=st[id].tay=st[id].nam=st[id].bac = 0 ; 
		if(k=='E')
		{
			st[id].dong= 1; 
		}
		else if(k=='W')
		{
			st[id].tay=1 ; 
		}
		else if(k=='S')
		{
			st[id].nam=1; 
		}
		else if(k=='N')
		{
			st[id].bac= 1;
		}
		return ;
	}	
	int mid =(l+r)>>1 ; 
	up(id*2,l,mid,pos,k) ; 
	up(id*2+1,mid+1,r,pos,k) ; 
	st[id] =(st[id*2]+st[id*2+1]);
}
void doc()
{
	int q;  
    cin>> n >>q ; 
    FOR(i,1,n)
    {
    	cin>>a[i]  ;
    }
    build(1,1,n) ; 
    int res= 0 ;
    FOR(i,1,q)
    {
    	int t ; cin>>t ; 
    	if(t==1)
    	{
    		int pos  ; cin>>pos ; 
    		char x ; 
    		cin>>x ;  
    		up(1,1,n,pos,x) ; 
    	}
    	else 
    	{
    		int l , r ,  k; 
    		cin>>l>>r>> k; 
    		k%=4; 
    		update(1,1,n,l,r,k) ;
    	}
    	if(st[1].dong==st[1].tay&&st[1].nam==st[1].bac)
    	{
    		cout<<i<<"\n";
    		cout<<st[1].dong<<" "<<st[1].tay<<" "<<st[1].nam<<" "<<st[1].bac<<endl;
    		res++ ;
    	}
    }
    cout<<res;
}
int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}