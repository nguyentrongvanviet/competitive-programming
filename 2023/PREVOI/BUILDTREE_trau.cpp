/*
DOANHONGBAO
1505
*/
#define TASK "BUILDTREE"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 0;
 
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
#define int ll
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 1e5+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;

int n,m;
int w[N];
ve<pii> g[N];

void doc()
{
	cin>>n>>m;
	FOR(i,1,m)
	{
		cin>>w[i];
	}
	FOR(i,1,n-m-1)
	{
		int u,v,w; cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
}

namespace sub1
{
	void xuly()
	{
		int res = 0;
		FOR(i,1,m)
		{
			res = (res + (n - 1) * w[i]) % sm;
		}
		cout<<res;
	}
}
namespace subfull
{
	int cnt = 0;
	int sl[N];
	int tp[N];
	int sz[N];
	int SZ[N];
	int c[N];
	int pa[N];
	void dfs(int u,int par)
	{
		tp[u] = cnt;
		sl[cnt]++;
		sz[u] = 1;
		for(auto o : g[u])
		{
			int v = o.fi;
			if(v == par) continue;
			dfs(v,u);
			sz[u] += sz[v];
		}
	}
	int cen(int u,int par,int sum)
	{
		for(auto o : g[u])
		{
			int v = o.fi;
			if(v == par) continue;
			if(sz[v] > sum/2) return cen(v,u,sum);
		}
		return u;
	}
	void DFS(int u,int par)
	{
		SZ[u] = 1;
		for(auto o : g[u])
		{
			int v = o.fi;
			if(v == par) continue;
			DFS(v,u);
			pa[v] = u;
			SZ[u] += SZ[v];
		}
	}
	pii line[N];
	void xuly()
	{
		FOR(i,1,n) if(tp[i] == 0) 
		{
			cnt++;
			dfs(i,0);	
			c[cnt] = cen(i,0,sl[cnt]);
			line[cnt] = {c[cnt],sl[cnt]};
		}
		sort(line + 1,line + cnt + 1,[](pii x,pii y){return x.se > y.se;});	
		sort(w + 1,w + m + 1);
		FOR(i,2,cnt)
		{
			int u = line[1].fi,v = line[i].fi;
			g[u].pb({v,w[i - 1]});
			g[v].pb({u,w[i - 1]});
		}
		DFS(1,0);
		int res = 0;
		FOR(i,1,n)  for(auto o : g[i]) if(o.fi != pa[i])
		{
			res = (res + SZ[o.fi] * (n - SZ[o.fi]) % sm * o.se) % sm;
		}
		cout<<res;
	}
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
		subfull::xuly();
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}