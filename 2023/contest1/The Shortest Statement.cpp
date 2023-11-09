/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "The Shortest Statement"
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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ;
struct Edge
{
	int u ,v ,c  ; 
} ; 
Edge E[N] ;
struct ke
{
	int v ,c ; 
} ; 
ve<ke>g[N] ; 
void doc()
{
    cin>> n >> m; 
    FOR(i,1,m)
    {
    	int u , v ,c ; 
    	cin>>u>>v>>c ;  
    	E[i] = {u,v,c} ;
    }
}

namespace sub1
{
	vi spec ;
	int pa[N] ;
	int h[N] ; 
	ll d[N] ; 
	int P[N][LO+5] ; 
	ll dis[45][N] ; 
	int goc(int u )
	{
		return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
	}
	void hop(int u ,int v,int c)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ; 
		if(chau==chav)
		{
			spec.pb(u) ; 
			spec.pb(v) ; 
			return ; 
		} 
		g[u].pb({v,c}) ;
		g[v].pb({u,c}) ;
		pa[chau]=chav ; 
	}	
	struct DL
	{
		int u ;
		ll val ; 
	}; 
	struct cmp
	{
		bool operator()(const DL&a ,const DL&b)
		{
			return a.val>b.val; 
		}
	}; 
	void dij(int s , ll f[] )
	{
		priority_queue<DL,ve<DL>,cmp>q; 
		FOR(i,1,n)f[i] = inf ; 
		q.push({s,f[s]=0}) ;
		while(!q.empty())
		{
			int u = q.top().u ; 
			ll val =q.top().val ;  
			q.pop() ; 
			if(f[u]<val)continue ; 
			for(auto x:g[u])
			{
				int v = x.v ; 
				int w = x.c ; 
				if(mini(f[v],f[u]+w))q.push({v,f[v]=f[u]+w}) ;  
			}
		}
	}	
	void dfs(int u ,int p)
	{
		for(auto x: g[u])
		{
			int v=x.v; 
			int c=x.c; 
			if(v==p)continue ; 
			d[v]= d[u]+c; 
			P[v][0] = u ;
			h[v]=h[u]+1; 
			dfs(v,u) ; 
		}
	}
	int lca(int u ,int v)
	{
		if(h[u]<h[v])swap(u,v) ;
		FORD(i,LO,0)
		{
			if(h[u]-(1<<i)>=h[v])u=P[u][i] ; 
		}
		if(u==v)return u ; 
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ;
			if(nu!=nv)
			{
				u=nu ; 
				v=nv ; 
			}
		}
		return P[u][0]  ; 
	}
    void xuly()
    {
    	FOR(i,1,n)pa[i] = i ; 
    	FOR(i,1,m)hop(E[i].u,E[i].v,E[i].c) ; 
    	dfs(1,0) ; 
    	FOR(j,1,LO)
    	{
    		FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] ;
    	}
    	
    	FOR(i,1,n)g[i].clear() ; 

    	FOR(i,1,m)
    	{
    		g[E[i].u].pb({E[i].v,E[i].c}) ;
    		g[E[i].v].pb({E[i].u,E[i].c}) ; 
    	}
    	uni(spec) ;
    	FORN(i,0,spec.size())
    	{
    		dij(spec[i],dis[i]) ; 
    	}
    	int q; 
    	cin>>q ; 
    	while(q--)
    	{
    		int u ,v ;cin>>u>>v; 
    		ll res= d[u]+d[v]-2*d[lca(u,v)] ; 
    		FORN(i,0,spec.size())
    		{
    			mini(res,dis[i][u]+dis[i][v]) ;
    		}
    		cout<<res<<el;
    	}
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}