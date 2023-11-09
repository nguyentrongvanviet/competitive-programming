#define TASK "input"
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
    if(fopen("input.txt","r"))
    {
        freopen("input.txt","r",stdin) ;
        freopen("output.txt","w",stdout) ;
    }
}
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n;  

void read()
{
	cin>>  n; 
}
void dfs(int u , int p , ve<vi>& g, ve<int>& h)
{
	for(auto v : g[u])
	{
		if(v==p)continue ;
		h[v] = h[u] +1 ;  
		dfs(v,u,g,h) ; 
	}
}
int dia(int n , ve<pii>&q)
{
	ve<vi> g(n+1); 
	vi h(n+1,0) ;  
	FORN(i,0,q.size())
	{
		g[q[i].fi].pb(q[i].se) ; 
		g[q[i].se].pb(q[i].fi) ; 
	}
	dfs(1,0,g,h) ;
	int u = 1 ;  
	FOR(i,1,n)
	{
		if(h[i]>h[u]) u=i ; 
	} 
	h= vi(n+1,0);
	dfs(u,0,g,h) ; 
	int ans = 0 ;
	FOR(i,1,n)ans=max(ans,h[i]);
	return ans;   
}
void solve()
{
	int res= 0 ;
	FOR(i,1,n)
	{
		int sz;  cin>>sz;
		ve<pii>q;
		FOR(j,1,sz-1)
		{
			int u , v; 
			cin>>u>>v; 
			q.pb({u,v});  
		}
		res+=dia(sz,q) ;
	}
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