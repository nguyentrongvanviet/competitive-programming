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
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 
const int M =17 ; 

int n , m; 
int have[N] ; 
int node[M]; 
ll need[M]; 
struct ke
{
	int v , w;  
} ; 
ve<ke>g[N] ; 
ll tot = 0 ; 
void doc()
{
	cin>> n >> m ; 
	FOR(i,1,n)cin>>have[i],tot+=have[i] ;     
	FORN(i,0,m)cin>>node[i] ; 
	FORN(i,0,m)cin>>need[i] ; 
	FOR(i,1,n-1)
	{
		int u , v , w  ; cin >> u >> v >> w ; 
		g[u].pb({v,w}) ; 
		g[v].pb({u,w}) ;  
	}
}

namespace sub1
{
	ll dis[M][N] ; 
	void dfs(int u ,int p , ll dis[])
	{
		for(auto x : g[u])
		{
			int v = x.v ; 
			int w = x.w ; 
			if(v==p)continue ; 
			dis[v] = dis[u]+w;
			dfs(v,u,dis) ;  
		}
	}
	int ok[N] ; 
	ll f[1<<M] ; 
	bool check( ll val)
	{
		int tt = Mask(m)-1; 
		FOR(i,1,n)ok[i]=0 ; 
		FOR(i,0,tt)f[i] = 0 ;
		FORN(i,0,m)
		{
			FOR(v,1,n)if(dis[i][v]<=val)ok[v]|=Mask(i) ;
		}
		FOR(i,1,n)
		{		
			f[tt^ok[i]]+=have[i] ;
		}
		FORN(i,0,m)
		{
			FOR(msk,0,tt)
			{
				if(BIT(msk,i)==0)
				{
					f[msk]+=f[msk|Mask(i)]; 
				}
			}
		}
		FOR(msk,0,tt)
		{
			ll tmp = 0 ; 
			FORN(i,0,m)if(BIT(msk,i))tmp+=need[i] ;
			if(tmp>tot-f[msk])return 0 ; 
		}
		return 1 ;
	}
	ll tknp()
	{
    	ll l = 0; 
    	ll r = 1e11 ; 
    	ll ans = -1 ; 
    	while(l<=r)
    	{
    		ll mid = (l+r)/2; 
    		if(check(mid))ans=mid,r=mid-1 ;
    		else l=mid+1; 
    	}
    	return ans; 
	}
    void xuly()
    {
    	FORN(i,0,m)dfs(node[i],0,dis[i]);  
    	ll res = tknp() ;			
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}