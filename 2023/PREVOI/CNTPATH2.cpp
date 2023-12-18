/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "CNTPATH2"
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


int n , m , k; 
int layer(int pos)
{
	return (pos+m-1)/m ;
}
void doc()
{
    cin>> n >> m >> k; 
}

namespace sub1
{
	ll pw(ll a , ll n)
	{
		if(n==0)return 1; 
		ll b = pw(a,n/2) ;
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm; 
	}
	struct Edge
	{
		int u ,v; 
	}E[N] ;
	map<ll,ll>f ;
	vi spec[N] ;
	ve<Edge>g[N] ;
    void xuly()
    {
    	vll V; 
	    FOR(i,1,k)
	    {
	    	int u ,v; cin>> u >>v ;
	    	E[i] = {u,v}; 
	    	int L1 = layer(u) ; 
	    	int L2 = layer(v) ; 
	    	V.pb(L1) ;
	    	V.pb(L2) ;
	    }
	    V.pb(0) ;
	    V.pb(n+1) ; 
	    uni(V)  ;
	    FOR(i,1,k)
	    {
	    	int u =E[i].u ; 
	    	int v =E[i].v ; 
	    	int L1 = UB(all(V),layer(u))-V.begin() ;
	    	int L2 = UB(all(V),layer(v))-V.begin() ;
	    	g[L2].pb({u,v}) ;
	    	spec[L1].pb(u) ; 
	    }
	    ll way = 1;
	    f[0] = 1 ;   
	    FOR(i,2,SZ(V))
	    {
	    	ll cur = way*pw(m,V[i-1]-V[i-2]-1)%sm; 
	    	ll tot = (cur*(i<SZ(V)?m:1))%sm; 
	    	for(auto x:g[i])
	    	{
	    		int v= x.v; 
	    		f[v] =cur; 
	    	}
	    	for(auto x:g[i])
	    	{	
	    		ll u =x.u ;
	    		ll v =x.v; 
	    		(f[v]+=f[u])%=sm;
	    		(tot+=f[u])%=sm;  
	    	}
	    	way=tot ; 
	    	for(auto v:spec[i])
	    	{
	    		if(f.count(v)==0)f[v] = cur ;
	    	}
	    }
	    cout<<way<<el;
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