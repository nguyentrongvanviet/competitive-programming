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
const ll inf = 1e12 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , k ;
struct ke
{
	int v, w ; 
} ; 
int dd[N] ; 
ve<ke>g[N] ;  
void doc()
{
	cin>> n >> k; 
	FOR(i,1,n-1)
	{
		int u ,v , w; cin>> u >> v >>w; 
		g[u].pb({v,w}) ;
		g[v].pb({u,w}) ; 
	}
	FOR(i,1,k)
	{
		int u ; cin>> u ;
		dd[u]  =1 ;
	}
}

namespace sub1
{
	int sz[N] ; 
	ll f[N] , ma[N] , up[N] ; 
	void dfs(int u ,int p)
	{
		sz[u] = dd[u] ; 
		if(dd[u])ma[u] = 0 ;
		for(auto [v,w]:g[u])if(v!=p)
		{
			dfs(v,u) ; 
			sz[u]+=sz[v] ; 
			f[u]+= f[v]+1ll*w*(sz[v]!=0) ; 
			if(sz[v])maxi(ma[u],ma[v]+w) ; 
		}
	}
	ll res[N] ;
	ll ma_up[N] ; 
	void solve(int u ,int p)
	{
		ll ma1 = -inf , ma2 = -inf ; 
		res[u] = 2*f[u]+2*up[u]-max({0ll,ma[u],ma_up[u]}) ; 
		if(dd[u])
		{
			ma1= 0 ;
		}
		for(auto [v,w]:g[u])if(v!=p&&ma[v]>=0)
		{
			if(ma1<=ma[v]+w)
			{
				ma2 = ma1; 
				ma1 = ma[v]+w ; 
			}
			else maxi(ma2,ma[v]+w) ; 
		}
		for(auto [v,w]:g[u])if(v!=p)
		{
			up[v] = up[u]+1ll*w*(k-sz[v]!=0)
				+f[u]-(f[v]+1ll*w*(sz[v]!=0)) ; 
			ma_up[v] = ma_up[u]+w*(k-sz[u]!=0); 
			if(ma[v]+w!=ma1)maxi(ma_up[v],ma1+w) ; 
			else maxi(ma_up[v],ma2+w) ; 
			solve(v,u) ;
		}
	}
    void xuly()
    {
    	FOR(i,1,n)ma[i] = -inf ;
        dfs(1,0)  ; 

    	solve(1,0) ;
    	// cout<<f[2]<<" "<<up[2]<<" "<<ma[2]<<" "<<ma_up[2]<<el;
    	assert(*min_element(res+1,res+n+1)>=0);
    	FOR(i,1,n)cout<<res[i]<<el;
    }
}
namespace sub2
{
	int f[N]  ; 
	ll ma[N] ; 
	ll h[N] ; 
	ll res ; 
	void dfs(int u ,int p)
	{
		if(dd[u])f[u]=1,ma[u] =h[u] ; 
		else f[u] = 0 , ma[u] = 0 ;
		for(auto [v,w] : g[u])if(v!=p)
		{
			h[v] = h[u]+w ;  
			dfs(v,u) ;
			if(f[v])
			{
				res+=w;
				f[u]=1 ; 
				maxi(ma[u],ma[v]) ; 
			}
		}
	}
	void xuly()
	{
		// dfs(2,0) ; 
		FOR(u,1,n)
		{ 
			res = 0;
			FOR(i,1,n)f[i] = 0 , h[i] = 0 , ma[i] = 0 ;  
			dfs(u,0) ;
			cout<<2*res-ma[u]<<el;
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
        // sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}