/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "upgrade"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 

#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define          SZ(_)  (int)(_.size())
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q; 
struct X
{
	int v , k;  
} ; 
ve<X> dd[N] ;
int cost[N] ; 
vi g[N]; 
struct DL
{
	int u ,v , k; 
} ; 
DL E[N] ;
void doc()
{
    cin>> n  ; 
    FOR(i,1,n-1)
    {
    	int u ,v ;cin>>u>>v ;
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
    cin>>q; 
    FOR(i,1,q)
    {
    	int u ,v , k ;cin>>u>>v>>k ; 
    	dd[u].pb({v,k});
    	dd[v].pb({u,k});
    	E[i] = {u,v,k} ; 
    }
}
namespace sub2
{ 
	int in[N] , out[N] ;
	int h[N] ; 
	int P[N][LO+2];
	bool con(int v ,int u)
	{ 
		return in[u]<=in[v]&&out[v]<=out[u] ; 
	
	}
	int tt = 0 ;
	void dfs(int u ,int p )
	{
		in[u]=++tt; 
		for(auto v :g[u])if(v!=p)
		{
			h[v]=h[u]+1 ;
			P[v][0] = u ; 
			dfs(v,u) ;
		}
		out[u]=tt ; 
	}
	ll st[4*N] ; 
	ll lazy[4*N] ; 
	void dolazy(int id, int l,int r)
	{
		st[id]+=lazy[id] ;
		if(l!=r)
		{
			lazy[id*2]+=lazy[id] ; 
			lazy[id*2+1]+=lazy[id] ; 
		}
		lazy[id] = 0 ;
	}
	void up(int id, int l ,int r ,int  t ,int p , int val)
	{
		dolazy(id,l,r) ;  
		if(t<=l&&r<=p)
		{
			lazy[id]+=val; 
			dolazy(id,l,r) ;
			return ; 
		}
		if(r<t||p<l)return;  
		int mid= (l+r)/2; 
		up(id*2,l,mid,t,p,val) ; 
		up(id*2+1,mid+1,r,t,p,val) ; 
		st[id] =max(st[id*2],st[id*2+1]) ; 
	}
	ll get(int id, int l, int r, int t, int p )
	{
		dolazy(id,l,r) ; 
		if(t<=l&&r<=p)
		{
			return st[id] ; 
		}
		if(r<t||p<l)return 0 ;
		int mid=(l+r)/2; 
		return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
	}
	ll res = 0; 
	int go(int u ,int c)
	{
		FORD(i,LO,0)if(h[u]-(1<<i)>h[c])u=P[u][i]  ;
		return u ; 
	}
	ve<pii> mat[N] ;
	void up(int v, int u ,int k)
	{
		if(con(u,v))
		{
			int c =go(u,v) ; 
			up(1,1,n,in[1],out[1],k) ; 
			up(1,1,n,in[c],out[c],-k);
		}
		else
		{
			up(1,1,n,in[v],out[v],k) ; 
		}
	}
	void solve(int u ,int p)
	{
		for(auto x:dd[u])
		{	
			int v=x.v; 
			int k=x.k; 
			// if(u==2)cout<<u<<" "<<v<<" "<<k<<el;
			if(!con(v,u))
			{  
				up(v,u,k) ;
				if(u==2)
				{
					// cout<<v<<" "<<u<<" "<<k<<el; 
					// cout<<get(1,1,n,in[3],out[3])<<el; 
				}
			}
			else
			{
				int c= go(v,u) ; 	
				mat[c].pb({v,k}); 
			}
		} 
		maxi(res,st[1]);
		// cout<<u<<" "<<get(1,1,n,in[1]/,out[1])<<el;
		for(auto v:g[u])if(v!=p)
		{
			for(auto x : mat[v])
			{
				int V= x.fi ; 
				int k = x.se ; 
				up(1,1,n,in[V],out[V],-k) ; 
			}
			solve(v,u) ; 
			for(auto x : mat[v])
			{
				int V= x.fi ; 
				int k = x.se ; 
				up(1,1,n,in[V],out[V],k) ; 
			}
		}
		for(auto x:dd[u])
		{	
			int v=x.v; 
			int k=x.k; 
			if(!con(v,u))
			{
				up(v,u,-k) ; 
			}
		} 
	}
    void xuly()
    {
    	dfs(1,0) ; 
    	FOR(j,1,LO)FOR(i,1,n)P[i][j] = P[P[i][j-1]][j-1] ; 
    	FOR(i,1,q)
    	{	
    		if(h[E[i].u]>h[E[i].v])swap(E[i].u,E[i].v) ;
    		if(con(E[i].v,E[i].u))
    		{
    			up(1,1,n,in[E[i].v],out[E[i].v],E[i].k) ; 
    		}
    	}
   		solve(1,0) ;
   		cout<<res;  
    }	
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ;
        sub2::xuly() ;  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}
