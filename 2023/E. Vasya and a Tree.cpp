/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
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
#define           btpc  __builtin_popcountll
#define            tct  template<class T>
#define             LB  lower_bound
#define             UB  upper_bound 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 3e5+5, oo = 2e9, LO = 17, CH = 26 ; 

int n , m ; 
vi g[N] ; 
int h[N] ; 
void doc()
{
	cin>> n; 
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}
namespace sub1
{
	ve<pii>q[N] ; 
	ll res[N] ; 
	ll bit[N] ;
	void up(int idx, int val)
	{
	    for(int i=idx;i<=n;i+=i&-i)bit[i]+=val;
	}
	ll get(int idx )
	{
	    ll ans =0 ; 
	    for(int i=idx;i;i-=i&-i)ans+=bit[i] ;
	    return ans ;
	}
	
	void dfs(int u ,int p)
	{
		for(auto [x,y] : q[u])
		{
			up(min(n,h[u]+x),y) ;
		}
		res[u] = get(n)-get(h[u]-1); 
		for(auto v:g[u])if(v!=p)
		{
			h[v] = h[u]+1; 
			dfs(v,u) ; 
		}
		for(auto [x,y]:q[u])
		{
			up(min(n,h[u]+x),-y);
		}
	}
    void xuly()
    {
        h[1] =1 ; 
       	cin>>m ; 
       	FOR(i,1,m)
       	{
       		int u ,d ,x ; cin>>u>>d>>x ; 
       		q[u].pb({d,x}) ; 
       	}
        dfs(1,0) ; 
        prt(res,n) ; 
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
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