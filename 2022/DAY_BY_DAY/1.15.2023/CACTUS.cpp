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
const int N =5e3+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , m; 
vi g[N] ; 
int tt =0 ;  
int id[N] , low[N] ; 
stack<int>st ;
int res= 0; 

void clear()
{
	tt= 0;
	res = 0 ;
	FOR(i,1,n)
	{
		g[i].clear() ; 
		low[i] = id[i] = 0 ;
	}
}
void read()
{
	cin>>n>>m;
	FOR(i,1,m)
	{
		int u ,v; 
		cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	} 
}
void dfs(int u ,int p)
{
	low[u] = id[u] = ++tt; 
	st.push(u) ;
	for(auto v :g[u])if(v!=p)
	{
		if(id[v])
		{
			low[u] = min(low[u],id[v]) ; 
		}
		else
		{
			dfs(v,u) ; 
			low[u] =min(low[u],low[v]) ;
		}
	}
	if(low[u]==id[u])
	{
		int t ; 
		int ans = 0; 
		do
		{
			t=st.top();
			st.pop();
			++ans;  
		}
		while(t!=u);
		res=max(res,ans) ;
	}
}
void solve()
{
	FOR(i,1,n)if(id[i]==0)dfs(i,0);
	if(res==1)cout<<0<<el; 
	else cout<<res<<el;
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
    	clear();
        read(); 
        solve();
    }
}