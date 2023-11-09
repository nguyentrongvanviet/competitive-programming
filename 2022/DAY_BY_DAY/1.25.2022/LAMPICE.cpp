#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
bool multitest = false;
#include<bits/stdc++.h>
using namespace std; 
void IOS()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r")){freopen(INPUT ,"r",stdin) ;freopen(OUTPUT,"w",stdout);}
}
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define viet first 
#define duyen second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define SZ(a) (int)a.size()
#define debug(a) cerr<<#a<<" "<<a<<el;
#define DV cerr<<"<---------------->"<<el;
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
template<class T>void print(ve<T>a){cerr<<"[ ";for(auto v : a)cerr<<v<<" ";cerr<<" ]"<<el;}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

int n , m; 
ll a[N] ; 
int dd[N] , sz[N] ; 
ll mu[N] ; 
vi g[N] ; 
bool ok ; 
unordered_set<ll,ll>exist[N] ;  
ve<pll>ds; 
int len ; 
int ma  ; 
void doc()
{
	cin>> n  ; 	
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,n-1)
	{
		int u ,v ;cin>>u>>v ;
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
	mu[0] = 1; 
	FOR(i,1,n)mu[i] = mu[i-1]*cs%sm; 
}
void dfsz(int u ,int p)
{
	sz[u] = 1;  
	for(auto v :g[u])if(v!=p&&dd[v]==0)
	{
		dfsz(v,u) ; 
		sz[u]+=sz[v] ; 
	}
}
int centroid(int u ,int p ,int n)
{
	for(auto v: g[u])if(v!=p&&dd[v]==0)
	{	
		if(sz[v]>n/2)return centroid(v,u,n) ; 
	}
	return u ; 
}
void dfs1(int u  ,int p, int h , ll down , ll up )
{	
	down = down*cs+a[u]	; 
	// up =  up + a[u]*mu[h]  ;
	ma=max(ma,h) ; 
	ds.pb(mp(down,up));
	for(auto v : g[u])if(v!=p&&dd[v]==0)
	{
		dfs1(v,u,h+1,down,up);
	}
}
void solve(int u)
{
	ma  = 0 ;
	dd[u] = 1; 
	for(auto v : g[u])
	{
		dfs1(v,u,1,a[u],a[u]); 
	}

	for(auto v : g[u])if(dd[v]==0)
	{
		dfsz(v,u);
		solve(centroid(v,u,sz[v]));
	}
}
bool check(int val )
{
	len = val; 
	dfsz(1,0) ; 
	ok =0 ; 
	solve(1);
	return ok; 
}
int tknp()
{
	int ans= 1 ; 
	int l = 2; 
	int r = n; 
	while(l<=r)
	{
		int mid =(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;  
	}
	return ans; 
} 
void xuly()
{
	int res = tknp() ; 
	cout<<res;
}	

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        // doc(); 
        // xuly();
    }
    cerr<<"Time: "<<clock()<<"ms"<<el;
}