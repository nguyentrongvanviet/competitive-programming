/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "BUILDTREE"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 
#define int long long 
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

int n , m ; 
ll W[N] ; 
struct ke
{
	int v,w ; 
} ; 
ve<ke>g[N] ; 
void doc()
{
	cin>> n >> m; 
	FOR(i,1,m)
	{
		cin>>W[i] ; 
	}
	FOR(i,1,n-1-m)
	{
		int u,v,w; cin>> u >>v >>w;
		g[u].pb({v,w}) ;
		g[v].pb({u,w}) ; 
	}
}

namespace sub1
{
	int sz[N] ;
	ll res = 0 ; 
	ll f[N] ; 
	void cal_sz(int u ,int p)
	{
		sz[u] = 1 ; 
		for(auto x:g[u])
		{
			int v=x.v; 
			if(v==p)continue ;
			cal_sz(v,u) ;
			sz[u]+=sz[v] ; 
		}
	}
	int cen(int u ,int p ,int n)
	{
		for(auto x:g[u])
		{
			int v =x.v; 
			if(v==p)continue ;
			if(sz[v]>n/2)return cen(v,u,n) ; 
		}
		return u ;
	}
	void add(ll &a  ,ll b)
	{
		a+=b; 
		if(a>=sm)a-=sm; 
	}
	void dfs(int u ,int p,int root)
	{
		for(auto x:g[u])
		{	
			int v = x.v; 
			int w = x.w; 
			if(v==p)continue ;
			dfs(v,u,root) ;
			add(res,1ll*sz[v]*(sz[root]-sz[v])*w%sm);
			f[u]+=f[v]+1ll*w*sz[v] ;	 
		}
	}
	struct DL
	{
		ll d ,sz ; 
		bool operator<(const DL&a)const
		{
			return sz<a.sz ; 
		}
	};
	DL Q[N] ; 
    void xuly()
    {
    	int cnt = 0 ;
    	FOR(i,1,n)if(sz[i]==0)
    	{
    		cal_sz(i,0) ; 
    		int u = cen(i,0,sz[i]) ;
    		cal_sz(u,0) ; 
    		dfs(u,0,u) ; 
    		Q[++cnt] = {f[u],sz[u]} ;
    	}
    	sort(Q+1,Q+cnt+1) ; 
    	assert(cnt==m+1) ;
    	sort(W+1,W+m+1,greater<int>()); 
    	ll sum_d=Q[m+1].d , sum_sz=Q[m+1].sz;
    	ll S = 0 ;
    	FOR(i,1,m)
    	{
    		ll d = Q[i].d; 
    		int sz = Q[i].sz;
    		add(res,(d*sum_sz%sm+sum_d*sz%sm)%sm) ;
    		add(res,sz*(S+W[i]*sum_sz)%sm);
    		add(sum_d,d%sm) ; 
    		add(sum_sz,sz) ;	
    		add(S,1ll*W[i]*sz%sm) ;  
    	}
    	cout<<(res%sm+sm)%sm<<el; 
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