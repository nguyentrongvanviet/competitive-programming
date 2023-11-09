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
#define        Mask(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n; 
vi g[N] ;

void doc()
{
	cin>> n; 
	FOR(i,1,n-3)
	{
		int u ,v; cin>> u >>  v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ;
	}

}

namespace sub1
{
	map<vi,int>TP ; 
	int node= 0 ;
	map<pii,vi>E;
	ll f[N][2] ; 
	void dfs(int u ,int p)
	{
		for(auto v:g[u])if(v!=p)
		{
			dfs(v,u) ; 
			f[u][1] = min(f[u][0]+1+min(f[v][1],f[v][0]),f[u][1]+min(1+f[v][0],f[v][1]));
			f[u][0]+=f[v][1] ; 
		}
	} 
    void xuly()
    { 
    	FOR(i,1,n)
    	{
    		g[i].pb(i+1==n+1?1:i+1) ;
    		g[i].pb(i-1==0?n:i-1) ; 
    	}
    	FOR(i,1,n)
    	{
    		sort(all(g[i]),[&](int u ,int v){ 
    			return (u>i&&v<i)||(( (u<i&&v<i)||(u>i&&v>i))&&u < v); 
    		}) ;
    	}
    	FOR(a,1,n)
    	{
    		FORN(j,0,SZ(g[a])-1)
    		{
    			int b = g[a][j] ;
    			int c = g[a][j+1] ;  
    			vi u = {a,b,c};
    			sort(all(u)); 
    			if(!TP.count(u))TP[u]=++node; 
    			int x=u[0] ; 
    			int y=u[1] ; 
    			int z=u[2] ; 
				E[mp(x,y)].pb(TP[u]) ;
				E[mp(y,z)].pb(TP[u]) ;
				E[mp(x,z)].pb(TP[u]) ; 
    		}
    	}
    	FOR(i,1,node)g[i].clear() ;
    	for(auto x :E)
    	{
    		uni(x.se)  ; 
    		if(SZ(x.se)==2)
    		{
    			int u =x.se[0] ; 
    			int v =x.se[1] ;
    			g[u].pb(v) ;
    			g[v].pb(u) ;
    		}
    	}
    	FOR(i,1,node)f[i][1]=oo; 
    	dfs(1,0) ;
    	cout<<f[1][1]<<el; 
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}