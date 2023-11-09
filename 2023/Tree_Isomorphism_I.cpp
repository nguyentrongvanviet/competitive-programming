/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ; 

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
#define            tct  template<typename T>
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
const ll inf = 1e18, cs = 2, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n; 
int a[N] ; 
vi g[N],adj[N] ; 
ll mu[N] ;
int sz[N] ; 
void doc()
{  
	cin>> n; 
	FOR(i,1,n)g[i].clear(),adj[i].clear();
	FOR(i,1,n-1)
	{
		int u, v ; cin>>u>>v; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}	
	FOR(i,1,n-1)
	{
		int u ,v; cin>>u >>v ;
		adj[u].pb(v) ;
		adj[v].pb(u) ; 
	}
}
struct DL
{
	int len ; 
	ll value ; 
	bool operator<(const DL&a)const
	{
		return len<a.len||(len==a.len&&value<a.value) ; 
	}
}; 
ll f[N] ; 
ll dfs(int u, int p , vi g[])
{
	ve<DL>q ; 
	sz[u] = 1 ; 
	for(auto v: g[u])if(v!=p)
	{
		ll val = dfs(v,u,g) ; 
		sz[u]+=sz[v] ;
		q.pb({2*sz[v],val}); 
	}
	sort(all(q)); 
	ll hash ='{';
	int len =0 ; 
	for(auto x: q)
	{	
		int len = x.len ; 
		ll value = x.value ; 
		hash = (hash*mu[len]%sm+value)%sm;
	}
	hash=(hash*cs+'}')%sm;
	f[u] = hash ; 
	return hash ;

}

void xuly()
{	
	mu[0] = 1 ; 
	FOR(i,1,2*n)mu[i]=mu[i-1]*cs%sm; 
	ll X = dfs(1,0,g) ;
	ll Y = dfs(1,0,adj) ;
	cout<<(X==Y?"YES":"NO")<<el;
	
}

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Khanh An loves you very much !"<<el;
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}