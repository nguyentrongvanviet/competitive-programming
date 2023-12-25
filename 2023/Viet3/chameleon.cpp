/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "chameleon"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
vi g[N] ; 
ll A , B , C; 
struct Edge
{
	int u ,v ; 
}E[N] ;
void doc()
{
	cin>> n >> m >>A>>B>>C;
	FOR(i,1,m)
	{
		int u , v ; cin>> u >>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
		E[i] = {u,v} ;
	}
}

namespace sub1
{
	ll res = 0 ; 
	int dd[N] ; 
	bool dfs(int u ,int need ,int camu ,int camv)
	{
		if(u==need)return 1; 
		dd[u] = 1 ;
		for(auto v:g[u])if(!(u==camu&&v==camv)&&!(u==camv&&v==camu))
		{
			if(dd[v]==0)
			{
				if(dfs(v,need,camu,camv))return 1; 
			}
		}
		return 0; 
	}
	bool cal(int u ,int need ,int cam)
	{
		if(u==need)return 1; 
		dd[u] = 1 ;
		for(auto v:g[u])if(v!=cam)
		{
			if(dd[v]==0)
			{
				if(cal(v,need,cam))return 1; 
			}
		}
		return 0; 

	}
	void solve(int u ,int v)
	{
		int spec_edge = 0 ; 
		FOR(i,1,m)
		{
			spec_edge+=(dfs(u,v,E[i].u,E[i].v)==0) ;
			FOR(x,1,n)dd[x]=0; 
		}
		int spec_node = 2;
		FOR(i,1,n)if(i!=u&&i!=v)
		{
			spec_node+=(cal(u,v,i)==0);
			FOR(x,1,n)dd[x]=0; 
		}
		if(C==1)(res+=(spec_edge*A%sm+spec_node*B%sm)%sm)%=sm;
		else (res+=sq(spec_edge*A%sm+spec_node*B%sm)%sm)%=sm;
	}
    void xuly()
    { 
    	FOR(i,1,n)FOR(j,i+1,n)
    	{
    		solve(i,j) ; 
    	}
    	cout<<res<<el;
    }
}
namespace sub2
{
	int id[N] , low[N] , id[N] , sz[N] ;
	stack<int>st;
	int tt = 0 , tplt = 0; 	
	void dfs(int u ,int p)
	{
		id[u] = low[u] = ++tt; 
		st.push(u) ;
		for(auto v:g[u])if(v!=p)
		{
			if(id[v])mini(low[u],id[v]) ;
			else dfs(v,u) , mini(low[u],low[v]) ;
		}		
		if(id[u]==low[u])
		{
			++tplt; 
			int t; 
			do
			{
				t=st.top() ;
				st.pop() ; 
				tp[t] = tplt; 
				sz[tplt]++;
			}while(t!=u) ;	
		}
	}
	struct ke
	{
		int v , st; 
	} ;
	ve<ke>g[N] ;
	int sz[N] ;
	void cal_sz(int u ,int p)
	{
		for(auto x:adj[u])
		{
			int v= x.v ;
			if(dd[v]||v==p)continue ;
			cal_sz(v,u) ;
			sz[u]+=sz[v] ;
		}
	}
	int cen(int u ,int p ,int n)
	{
		for(auto x:adj[u])
		{
			int v=x.v; 
			if(dd[v]||v==p||sz[v]<=n/2)continue ; 
			return cen(v,u,n) ;
		}
		return u; 
	}
	int dd[N] ;
	int h[N] ;
	ll tot , sum , cnt ;
	void build(int u ,int p , int root )
	{
		cnt+=sz[u] ; 
		res+= tot + h[u]*S + sum - f[root]*sz[u]*B ;
		tot+= h[u]*sz[u] + sz[u]*;
		for(auto x:adj[u])
		{
			int v = x.v ;
			if(dd[v]||v==p)continue ;
			h[v] = h[u] + 1 ;
			build(v,u,root) ;
		}
	}
	void solve(int u)
	{ 			
		dd[u] =1 ;
		sum = 0 ;
		for(auto x:adj[u])
		{
			int v = x.v ; 
			int st = x.st ;
			h[v] = 1 ;
			build(v,u,st) ;
			sum+=tot ; 
			tot = cnt = 0 ;
		}
		for(auto x:adj[u])
		{
			int st = x.st ;
			f[st] = 0 ;
		}
		for(auto x:adj[u])
		{
			int v=x.v; 
			if(dd[v])continue ;
			cal_sz(v,u) ;
			solve(cen(v,u,sz[v])) ;
		}
	}	
	void xuly()
	{
		dfs(1,0) ; 
		FOR(i,1,m)
		{
			int u= E[i].u ;
			int v= E[i].v; 
			if(tp[u]!=tp[v])
			{
				adj[tp[u]].pb({tp[v],u}) ;
				adj[tp[v]].pb({tp[u],v}) ;
			}
		}
		cal_sz(1,0) ;
		assert(sz[1]==n) ;
		solve(cen(1,0,n)) ;
		FOR(i,1,tplt)
		{
			// (res+=sz[i]*(sz[i-1])/2*2*)
		}
		cout<<res<<el;
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