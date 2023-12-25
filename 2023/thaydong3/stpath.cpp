/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "stpath"
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
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
const int N =1e5+30 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ,q ;
struct ke
{
	int v, w; 
} ;
ve<ke>adj[N] ;
struct Edge
{
	int u ,v ,w ; 
}E[N] ;
void doc()
{
	cin>> n >> m >> q; 
	if(n>1e5)abort() ;
	FOR(i,1,m)
	{
		cin>>E[i].u>>E[i].v>>E[i].w ;
		adj[E[i].u].pb({E[i].v,E[i].w}) ;
		adj[E[i].v].pb({E[i].u,E[i].w}) ; 
	}
}

namespace sub1
{
	ve<ke>g[N] ;
	int pa[N] ;
	ll f[50][N] ;
	struct DL
	{
		int u ; 
		ll val;  
	}; 
	struct cmp
	{
		bool operator()(const DL&a , const DL&b)const
		{
			return a.val>b.val; 
		}
	} ; 
	void dij(int u ,ll f[])
	{
		priority_queue<DL,ve<DL>,cmp>q; 
		FOR(i,1,n)f[i] = inf; 
		q.push({u,f[u]=0}) ;
		while(!q.empty())
		{
			int u = q.top().u ; 
			ll val = q.top().val;
			q.pop() ;
			if(f[u]<val)continue;
			for(auto x:adj[u])
			{
				int v =x.v; 
				int w =x.w; 
				if(mini(f[v],f[u]+w))
				{
					q.push({v,f[v]}) ;
				}
			}
		}
	}
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u] = goc(pa[u]) ;
	}
	bool hop(int u ,int v)
	{
		int chau = goc(u); 
		int chav = goc(v) ;
		if(chau==chav)return 0; 
		pa[chau] = chav ;
		return 1; 
	}
	ll d[N] ;
	int time_dfs = 0 , tt = 0 ; 
	int at[N] ,in[N] ;
	int st[N*2][LO+2]; 
	void dfs(int u ,int p)
	{
		int cur = ++time_dfs  ;
		at[time_dfs] = u ;
		in[u]=++tt;
		st[tt][0] = cur; 
		for(auto x:g[u])
		{
			int v=x.v; 
			int w= x.w; 
			if(v==p)continue ;
			d[v] = d[u]+w; 
			dfs(v,u) ;
			st[++tt][0] = cur; 
		}
	}
	void build_RMQ()
	{
		FOR(j,1,LO)FOR(i,1,tt-M(j)+1)
		{
			st[i][j] = min(st[i][j-1],st[i+M(j-1)][j-1]) ;
		}
	}
	int get_min(int l ,int r)
	{
		int k = lg(r-l+1);
		return min(st[l][k] , st[r-M(k)+1][k]) ;
	}
	int lca(int u ,int v)
	{
		int l = in[u] ; 
		int r = in[v] ;
		if(l>r)swap(l,r) ; 
		return at[get_min(l,r)] ;
	}
	ll DIS(int u ,int v)
	{
		return d[u] + d[v] - 2*d[lca(u,v)] ;
	}
    void xuly()
    {
    	FOR(i,1,n)pa[i] = i ;
    	vi spec; 
    	FOR(i,1,m)
    	{	
    		int u = E[i].u ;
    		int v = E[i].v ;
    		int w = E[i].w ;
    		if(hop(u,v))
    		{
    			g[u].pb({v,w}) ; 
    			g[v].pb({u,w}) ; 
    		}
    		else
    		{
    			spec.pb(u) ; 
    		}
    	}
    	uni(spec) ;
    	FOR(i,1,SZ(spec))
    	{
    		dij(spec[i-1],f[i]) ;
    	}
    	dfs(1,0) ;
    	build_RMQ() ;

    	while(q--)
    	{
    		int u ,v; cin>> u >>v; 
    		ll res = DIS(u,v) ; 
    		FOR(i,1,SZ(spec)) 
    		{
    			mini(res,f[i][u]+f[i][v]) ; 
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
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}