#define TASK "NINJASET"
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
const int N =4e3+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
int m ; 
int a[N] ,p[N]  ; 
vi g[N] ;
int f[N][N] ; 
vi value ;
unordered_map<int,int>pos ; 
void read()
{
	cin>>n ; 
	FOR(i,1,n)
	{
		cin>>a[i]>>p[i] ;
		value.pb(a[i]) ;
		if(i==1)continue ;
		g[p[i]].pb(i) ; 
		g[i].pb(p[i]) ;
	}
}
void dfs(int u ,int p)
{
	f[u][a[u]] = 1 ; 
	for(auto v: g[u])if(v!=p)dfs(v,u) ; 
	for(auto v : g[u])if(v!=p)
	{	
		f[u][a[u]]+=f[v][a[u]-1]; 
	}
	FOR(i,1,m)
	{
		int tmp = 0 ;
		for(auto v: g[u])if(v!=p)
		{
			tmp+=f[v][i] ; 
		}
		f[u][i]=max(f[u][i],tmp); 
	}
	FOR(i,1,m)f[u][i] = max(f[u][i],f[u][i-1]);
}
void solve()
{
	sort(all(value)) ; 
	value.resize(unique(all(value))-value.begin()) ; 
	m=value.size(); 
	FORN(i,0,value.size())pos[value[i]] = i+1; 
	FOR(i,1,n)a[i]=pos[a[i]] ; 
	dfs(1,0) ; 
	int res=0;  
	FOR(i,1,n)FOR(j,1,m)res=max(res,f[i][j]); 
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