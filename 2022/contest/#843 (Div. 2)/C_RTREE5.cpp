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
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n;  
vi g[N] ; 
ll a[N] , b[N] ; 
int dd[N][2]  ; 
ll f[N][2] ; 
void read()
{
	cin>>n; 
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,n)cin>>b[i] ; 
}	
void dfs(int u  , int p ,int okp )
{
	if(dd[u][okp])return ; 
	dd[u][okp] = 1 ; 
	for(auto v : g[u])if(v!=p)
	{
		dfs(v,u,0) ; 
		dfs(v,u,1) ;
	}
	f[u][okp] = a[u] ;
	for(auto v : g[u])if(v!=p)
	{
		f[u][okp]+=f[v][1] ; 
	} 
	vll q ; 
	ll tmp =0 ;
	for(auto v : g[u])if(v!=p)
	{
		tmp+=f[v][1] ;
		q.pb(f[v][0]-f[v][1]);
	}
	sort(all(q));
	int cl = b[u] - okp ;
	if(cl>q.size())return ; 
	for(int i= 0 ;i<cl;i++)
	{
		tmp+=q[i] ; 
	} 
	f[u][okp] =min(f[u][okp],tmp) ;
}
void solve()
{
	dfs(1,0,0) ; 
	cout<<f[1][0];
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