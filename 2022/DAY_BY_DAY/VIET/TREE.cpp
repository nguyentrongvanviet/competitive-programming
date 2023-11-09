#define TASK "TREE"
#include<bits/stdc++.h>
using namespace std; 
// #define int long long 
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
const int N =4e5+1 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n;  
vi g[N] ;
int dd[N]  ,sz[N] ;  
int dis =0 ; 
ll res =0 ; 
void read()
{
	cin>> n; 
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v ;  
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}
void dfsz(int u ,int p)
{
	sz[u] =1; 
	for(auto v:  g[u])
	{
		if(v==p||dd[v])continue ;
		dfsz(v,u); 
		sz[u]+=sz[v] ;
	}
}
int centroid(int u ,int p ,int n )
{
	for(auto v: g[u])
	{
		if(v==p||dd[v])continue ; 
		if(sz[v]>n/2)return centroid(v,u,n); 
	}
	return u ;
}
int ma = 0 ; 
ll sl =0  ;
void dfs(int u, int p,int h)
{
	if(h>ma)ma=h,sl =1;
	else if(h==ma)sl++;
	for(auto v: g[u])
	{
		if(dd[v]==1||v==p)continue; 
		dfs(v,u,h+1) ;
	}
}
void solve(int u )
{
	dd[u] =1 ;
	int matot  = 1 ;
	ll cnt= 1 ; 
	for(auto v : g[u])
	{
		if(dd[v])continue ;
		ma= 0 ; 
		sl =0 ; 
		dfs(v,u,1); 
		if(matot+ma>dis)
		{
			dis=matot+ma; 
			res= sl*cnt; 
		}
		else if(matot+ma==dis)
		{
			dis=matot+ma; 
			res+=sl*cnt; 
		}
		if(matot<ma+1)matot=ma+1,cnt=sl ; 
		else if(matot==ma+1)cnt+=sl;
	}
	for(auto v : g[u])
	{
		if(dd[v]==1)continue ; 
		dfsz(v,u) ;  
		solve(centroid(v,u,sz[v]));
	}
}
void solve()
{
	dfsz(1,0); 
	solve(centroid(1,1,n));
	cout<<dis<<" "<<res ;
	// cout << '\n' << clock() <<" ms";
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