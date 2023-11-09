#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second

const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct query
{
	int l , r  ; 
	ll val ; 
};	
int n  , m;  
ll a[N] ; 
query q[N] ;
ll st[8*N] ; 
void build(int id , int l ,int r )
{
	if(l==r)
	{
		st[id] =a[l] ; 
		return ; 
	}
	int mid = (l+r)>>1; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id]=max(st[id*2],st[id*2+1]) ; 
}
ll get(int id , int l ,int r , int t , int p )
{
	if(t<=l&&r<=p)return st[id] ; 
	if(r<t||p<l)return -inf ; 
	int mid=(l+r)>>1; 
	return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ;  
}
void inp()
{
	cin>> n>> m; 
	for(int i=1 ;i<=m;i++)
	{
		int l , r ; 
		ll val ; 
		cin>>l>>r>>val ; 
		a[l]+=val;  
		a[r+1]-=val ; 
		q[i] ={l,r,val} ; 
	}   
	for(int  i=1 ;i<=n;i++)
	{
		a[i]= a[i-1]+a[i] ; 
		
	}
	build(1,1,n) ;
	ll res=inf; 
	for(int i= 1;i<=m;i++)
	{
		int l = q[i].l ; 
		int r= q[i].r ; 
		int val = q[i].val ;
		res=min(res,max({get(1,1,n,1,l-1),get(1,1,n,r+1,n),get(1,1,n,l,r)-val})) ;
	} 
	cout<<res; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    while(t--)
    {
        inp();
    }
    return 0;
}