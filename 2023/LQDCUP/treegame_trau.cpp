/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "treegame"
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
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m;
struct Edge
{
	int u ,v; 
}E[N] ; 
vi V ;
int exist_1=0;
void doc()
{
	cin>> n >> m; 
	FOR(i,1,n-1)
	{
		int p ;cin>> p ; 
	}
	FOR(i,1,m)
	{
		int u ,v ;cin>> u>>v ; 
		V.pb(u) ;
		V.pb(v) ; 
		E[i] = {u,v} ;
	}
	uni(V) ; 
}

namespace sub1
{
	int color[N] ; 
	bool ok ;
	struct ke
	{
		int v, type ; 
	} ; 
	ve<ke>g[N] ;
	void dfs(int u ,int c)
	{
		color[u] = c ;
		for(auto [v,type]:g[u])
		{
			if(color[v]==-1)
			{
				dfs(v,c^type) ; 
			}
			else 
			{
				if(color[v]!=(c^type))
				{
					ok = 0; 
					return ; 
				}
			}
		}
	}
	ll check(int id)
	{
		for(auto u :V)g[u].clear() ; 
		FOR(i,1,id)
		{
			g[E[i].u].pb({E[i].v,0}) ;
			g[E[i].v].pb({E[i].u,0}) ;
		}
		FOR(i,id+1,m)
		{
			g[E[i].u].pb({E[i].v,1}) ; 
			g[E[i].v].pb({E[i].u,1}) ; 
		} 
		FOR(i,1,n)color[i] = -1 ; 
		ll tmp = 1; 
		ok =1 ; 
		FOR(i,1,n)if(color[i]==-1)
		{
			dfs(i,0) ; 
			if(i!=1)(tmp*=2)%=sm ;
		}
		if(ok==0)return 0 ;
		return tmp ; 
	}
    void xuly()
    {
    	ll res = 0 ;
    	FOR(i,0,m)
    	{
    		// if(check(i))cout<<i<<el;
    		(res+=check(i))%=sm ; 
    	}
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.ANS","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}
