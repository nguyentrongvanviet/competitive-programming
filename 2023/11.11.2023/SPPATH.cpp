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
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 250000+5 , oo = 2e9 , LO = 21 , CH = 26 ; 


int n , q ; 
vi g[N] ; 

void doc()
{
	cin>> n >>q ;
	FOR(i,1,n-1)
	{
		int u ,v ; 
		cin>> u >> v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}    
}

namespace sub1
{
	int sz[N] ; 
	int P[N][LO+1] ; 
	ll f[N][LO+1] ; 	
	ll lost[N][LO+1] ; 
	int h[N] ; 
	void dfs(int u ,int p)
	{
		sz[u] =1 ;
		f[u][0] = 1; 
		for(auto v : g[u])if(v!=p)
		{
			h[v] = h[u]+1; 
			P[v][0] = u ;
			dfs(v,u) ;
			f[u][0]+=1ll*sz[v]*sz[u] ; 
			sz[u]+=sz[v] ; 
		}
		for(auto v : g[u])if(v!=p)
		{
			lost[v][0] = sz[v]*(sz[u]-sz[v]) ; 
		}
	}
	void solve(int u ,int v)
	{
		if(u==v){
			return void(cout<<f[u][0]+sz[u]*(n-sz[u])<<el) ; 
		} 
		if(h[u]<h[v])swap(u,v) ;
		int pre= u ; 
		ll res = 0 ;
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])
		{
			res+=f[u][i]-lost[u][i] ; 
			u =P[u][i]  ;
		}
		if(u==v)
		{
			FORD(i,LO,0)if(h[pre]-(1<<i)>h[v])
			{
				pre=P[pre][i] ; 
			}
			res= res+f[u][0]+sz[u]*(n-sz[u])-sz[pre]*(n-sz[u]) ;  
			cout<<res<<el;
		}
		else
		{
			FORD(i,LO,0)
			{
				int nu =P[u][i] ; 
				int nv = P[v][i] ; 
				if(nu==nv)continue ; 
				res+=f[u][i]-lost[u][i] + f[v][i] - lost[v][i] ; 
				u=nu ; 
				v=nv ;
			}
			res+=f[u][0]+f[v][0] ; 
			int c=  P[u][0] ;
			res= res+sz[c]*(n-sz[c])+f[c][0]-sz[u]*(n-sz[u])-sz[v]*(n-sz[v])+sz[u]*sz[v] ; 
			cout<<res<<el;
		}
	}
    void xuly()
    {
        dfs(1,0); 
        FOR(j,1,LO)FOR(i,1,n)
        {
        	P[i][j] = P[P[i][j-1]][j-1] ; 
        	f[i][j] = f[i][j-1]+f[P[i][j-1]][j-1] ;
        	lost[i][j] = lost[i][j-1]+lost[P[i][j-1]][j-1] ;  
        } 
        while(q--)
        {
        	int u ,v ; cin>> u>>v ;
        	solve(u,v) ; 
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}