/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ;
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
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 998244353; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n , S ; 
struct ke 
{
	int v , w ; 
} ;
struct Edge
{
	int u ,v ,w;  
	bool operator<(const Edge&a)const
	{
		return w<a.w ;
	}
}; 
Edge E[N] ; 
set<pii>edge ; 
ve<ke>g[N] ; 
void doc()
{
	cin>> n >>S ; 
	FOR(i,1,n-1)
	{
		int u , v ,w;  cin>>u>>v>>w ;
		E[i] = {u,v,w} ;  
		g[u].pb({v,w}) ;
		g[v].pb({u,w}) ;
		edge.insert({u,v}) ;
	}
}
namespace sub1
{
	int P[N][LO+3],W[N][LO+3] ;
	int h[N] ; 
	void build_lca()
	{
		FOR(j,1,LO)FOR(i,1,n)
		{
			P[i][j]=P[P[i][j-1]][j-1] ;
			W[i][j] = max(W[i][j-1],W[P[i][j-1]][j-1]) ;  
		}
	}
	int lca(int u ,int v)
	{
		int ans = 0 ; 
		if(h[u]<h[v])swap(u,v) ;  
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])maxi(ans,W[u][i]),u=P[u][i] ;
		if(u==v)return ans ; 
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ; 
			if(nu!=nv)
			{
				maxi(ans,W[u][i]) ; 
				maxi(ans,W[v][i]) ;
				u=nu ; 
				v=nv ; 
			}
		}
		maxi(ans,W[u][0]) ; 
		maxi(ans,W[v][0]) ; 
		return ans ; 
	}
	void dfs(int u ,int p)
	{
		for(auto x:g[u])
		{
			int v = x.v ; 
			int w = x.w ;
			if(v==p)continue ; 
			h[v] = h[u]+1 ;
			P[v][0] = u ; 
			W[v][0] = w;  
			dfs(v,u) ; 
		}
	}

    void xuly()
    {
    	dfs(1,0) ;
    	build_lca() ;
    	ll res = 1;   
    	FOR(i,1,n)
    	{
    		FOR(j,i+1,n)if(edge.find({i,j})==edge.end())
    		{
    			(res*=S-lca(i,j)+1)%=sm;
    		}
    	}
    	cout<<res<<el;
    	FOR(i,1,n)g[i].clear();
    	edge.clear() ;
    }
}
namespace sub2
{
	int pa[N] ;
	int sz[N] ; 
	int goc(int u )
	{
		return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
	}
	void hop(int u ,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ; 
		if(chau==chav)return ; 
		pa[chau]=chav ; 
		sz[chav]+=sz[chau] ; 
	}
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%sm*a%sm;  	
		return b*b%sm ;
	}
	void xuly()
	{
		FOR(i,1,n)pa[i] = i , sz[i] = 1 ; 	
		sort(E+1,E+n-1+1) ; 
		ll res = 1 ; 
		FOR(i,1,n-1)
		{
			int u =goc(E[i].u) ; 
			int v= goc(E[i].v) ; 
			(res*=pw(S-E[i].w+1,(1LL*sz[u]*sz[v]-1)))%=sm ; 
			pa[u] =v;  
			sz[v]+=sz[u] ; 
		}
		cout<<res<<el;
	}
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1:*/j  :xuly() ; 
        sub2::xuly() ;
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}