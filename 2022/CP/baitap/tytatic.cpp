#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 

const int N= 2e5+5 ,oo = 1e9 ; 
const ll  inf = 1e17 , sm =1e9+7 ; 

ll n , q;  
ll b[N] ,a[N] ; 
ll st[N] ; 
int pos[N] ;  
vector<int>g[N] ;
int sz[N] ;
int tt = 0; 
void predfs(int u , int p )
{
	pos[u] =++tt ; 
	a[tt] = b[u] ; 
	sz[u] = 1; 
	for(int i= 0;i<g[u].size();i++)
	{
		int v =g[u][i] ; 
		if(v==p)continue ;
		predfs(v,u) ; 
		sz[u]+=sz[v]; 
	}
}
void build(int id , int l , int r )
{
	if(l==r)
	{
		st[id] = a[l]  ; 
		return ; 
	}
	int mid =(l+r)>>1; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r); 
	st[id] =st[id*2]+st[id*2+1] ; 
}
ll get(int id , int l ,int r , int t , int p )
{
	if(t<=l&&r<=p)return st[id]  ; 
	if(r<t||p<l)return 0  ;
	int mid =(l+r)>>1; 
	return get(id*2,l,mid,t,p) +get(id*2+1,mid+1,r,t,p) ;  
}
void up(int id , int l , int r ,int pos , ll val )
{
	if(l==r&&l==pos)
	{
		st[id]=val; 
		return ;  
	}
	if(r<pos||pos<l)return ; 
	int mid=(l+r)>>1 ; 
	up(id*2,l,mid,pos,val) ; 
	up(id*2+1,mid+1,r,pos,val) ;
	st[id] =st[id*2]+st[id*2+1] ;  
}
void inp()
{
	cin>> n>>q; 
	for(int i =1 ;i<=n;++i)
	{
		cin>>b[i] ; 
	}
	for(int i= 1;i<=n-1;i++)
	{
		int u , v; 
		cin>>u>>v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ;
	}
	predfs(1,0) ;
	build(1,1,n) ;  
	while(q--)
	{
		char x; 
		cin>>x ; 
		if(x=='Q')
		{
			int u ; 
			cin>>u ; 
			cout<<get(1,1,n,pos[u],pos[u]+sz[u]-1)<<"\n";
		}
		else 
		{
			int u ; 
			ll val ; 
			cin>>u>>val ; 
			up(1,1,n,pos[u],val) ; 
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ; 
	freopen("o.txt","w",stdout) ; 
	inp() ; 
}
