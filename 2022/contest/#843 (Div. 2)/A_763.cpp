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
ll rd(ll l , ll r )
{
	return l+rand()%(r-l+1);
}
vi value ; 
unordered_map<ll,ll> pos ; 
int n; 
ll a[N]  , sz[N] ;
vi g[N] ; 
ll f[N] ; 
void read()
{
	cin>> n; 
	FOR(i,1,n-1)
	{
		int u , v ; cin>>u>>v ; 
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
	FOR(i,1,n)cin>>a[i] , value.pb(a[i]) ; 
	sort(all(value)) ;
	value.resize(unique(all(value))-value.begin()) ;
	for(int i= 0 ;i<value.size();i++)
	{
		ll x =rd(1,1e12);
		while(pos.count(x))
		{
			x=rd(1,1e12) ; 
		}
		pos[value[i]]= x ;   
	}
	for(int i =1 ;i<=n;i++)a[i] = pos[a[i]];  
}
void dfs(int u ,int p)
{
	f[u] = a[u] ; 
	sz[u] =1 ; 
	for(auto v: g[u])if(v!=p)
	{
		dfs(v,u) ;
		f[u]+=f[v] ; 
		sz[u]+=sz[v] ;
	}
}
int res= 0 ; 
void dfsout(int u , int p)
{
	ll d= f[1]-f[u] ; 
	bool ok = 1 ;
	for(auto v  : g[u])if(v!=p)
	{
		if(f[v]!=a[v]*sz[v])
		{
			ok = 0 ; 
			break;  
		}
	}
	if(d==a[p]*(n-sz[u])&&(ok))res= u; 
	if(res)return ; 
	for(auto v : g[u])if(v!=p)
	{
		dfsout(v,u) ; 
	}
}
void solve()
{
	dfs(1,0) ;
	dfsout(1,0) ; 		
	if(res==0)cout<<"NO"; 
	else cout<<"YES"<<el<<res; 
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    srand(time(0)) ; 
    while(test--)
    {
        read(); 
        solve();
    }
}