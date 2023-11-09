#define TASK "text"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =5e4+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , k ; 
int dd[N] ; 
int sz[N] ; 
vi g[N] ; 
void read()
{
	cin>> n >> k; 
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}	
void predfs(int u ,int p)
{
	sz[u] = 1;
	for(auto v :g[u])if(dd[v]==0&&v!=p)
	{
		predfs(v,u) ; 
		sz[u]+=sz[v] ;
	}
}
int centroid(int u , int p , int n )
{
	for(auto v : g[u])if(dd[v]==0&&v!=p&&sz[v]>n/2)
	{	
		return centroid(v,u,n) ;
	}
	return u ; 
}
ll res=0 ; 
unordered_map<int,ll>d; 
vi dis;  
void dfs1(int u ,int p , int h )
{
	dis.pb(h) ; 
	for(auto v: g[u])if(dd[v]==0&&v!=p)	
	{	
		dfs1(v,u,h+1) ;
	}
}
void solve(int u)
{
	dd[u] =1 ; 
	d.clear() ;
	d[0]=1;
	for(auto v :g[u])if(dd[v]==0)
	{		
		dis.clear() ; 
		dfs1(v,u,1);
		for(auto x : dis)if(k-x>=0)res+=d[k-x];
		for(auto x : dis)d[x]++ ; 
	}	
	for(auto v : g[u])if(dd[v]==0)
	{
		predfs(v,u) ; 
		solve(centroid(v,0,sz[v]));
	}
}	
void solve()
{
	predfs(1,0);
	solve(centroid(1,0,n)) ; 
	cout<<res;
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}