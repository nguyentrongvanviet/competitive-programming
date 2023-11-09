#define TASK "text"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;
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
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
vi g[N] ; 
ll l[N] , r[N] ;
ll f[N][2] ; 
void read()
{
	cin>> n; 
	FOR(i,1,n)cin>>l[i]>>r[i] ; 
	FOR(i,1,n-1)
	{
		int u ,v ;cin>>u>>v ; 	
		g[u].pb(v) ; 
		g[v].pb(u) ;
	}
}
void dfs(int u , int p)
{
	for(auto v : g[u])if(v!=p)
	{
		dfs(v,u); 
		f[u][0]+=max(f[v][1]+abs(r[v]-l[u]),f[v][0]+abs(l[v]-l[u]));
		f[u][1]+=max(f[v][0]+abs(l[v]-r[u]),f[v][1]+abs(r[v]-r[u])); 
	}
}
void solve()
{	
	dfs(1,0) ; 
	cout<<max(f[1][1],f[1][0])<<el;
}
void clear()
{
	FOR(i,1,n)
	{
		f[i][0]=f[i][1] = 0 ; 
		g[i].clear() ; 
	}
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
        clear();
    }
}