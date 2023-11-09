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
const int N =3e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n;  
vi g[N] ; 
int f[N] ,sz[N] ;
void read()
{
	cin>>n  ; 
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v ; g[u].pb(v) ; g[v].pb(u) ; 
	}
}	
int res = 0 ; 
void dfs(int u , int p)
{
	sz[u] =1 ;
	for(auto v: g[u])if(v!=p)
	{
		dfs(v,u) ;
		sz[u] +=sz[v] ; 
	}
	if(u==1)
	{
		if(g[u].size()==1)res=n-2; 
		else
		{
			res=max(sz[g[u][0]]-1+f[g[u][1]],sz[g[u][1]]-1+f[g[u][0]]);
		}
	}
	else
	{
		if(g[u].size()==1)
		{
			f[u] =  0;
		}
		else
		{
			if(g[u].size()==2)
			{
				f[u] = sz[u]-2; 
			}
			else
			{	
				int pre = -1;  
				for(auto v : g[u])if(v!=p)
				{
					if(pre!=-1)
					{
						f[u] = max(f[pre]+sz[v]-1,f[v]+sz[pre]-1);
					} 
					else pre= v;
				}
			}
		}
	}
}
void solve()
{
	res= 0 ;
	dfs(1,0) ; 
	cout<<res<<el;
}
void clear()
{
	FOR(i,1,n)g[i].clear() , f[i] = 0 ;
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
        clear() ; 
    }
}