#define TASK "COMNET"
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
const int N =1e3+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ,k , a, b ; 
vi g[N] ; 
ll f[N][5][N][2];	
void read()
{
	cin>> n >> k>> a>>b ;
	FOR(i,1,n-1)
	{
		int u ,v ;cin>>u>>v; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}
ll pre[N][N] , cur[N][N] ;
int sz[N] ; 
ll res=0 ; 
void dfs(int u ,int p)
{
	sz[u] =1 ; 
	for(auto v : g[u])if(v!=p)dfs(v,u),sz[u]+=sz[v];

	ve<vi>pre(k+1,vi(sz[u],0));
	ve<vi>cur(k+1,vi(sz[u],0)); 
	pre[0][0]=1;
	for(auto v : g[u])if(v!=p)
	{		
		FOR(i,1,k)FOR(j,1,sz[u]-1)
		{
			cur[i][j] = 0 ; 
			FOR(ii,0,i)FOR(jj,0,min(j-1,sz[v]-1))
			{
				cur[i][j]+=f[v][ii][jj][0]*pre[i-ii][j-jj-(ii?1:0)];
			}
		}
		FOR(i,1,k)FOR(j,1,sz[u]-1)pre[i][j]=cur[i][j];
	}
	FOR(i,0,k)FOR(j,0,sz[u]-1)
	{
		if(i&&j-(i>1?1:0)>=0)
		{
			f[u][i][j][1]=pre[i-1][j];
		}
		f[u][i][j][0]=f[u][i][j][1]+pre[i][j];
	}
	pre=ve<vi>(k+1,vi(sz[u],0)) ; 
	cur=ve<vi>(k+1,vi(sz[u],0)) ; 
	pre[0][0] = 1;  
	for(auto v : g[u])if(v!=p)
	{		
		FOR(i,1,k)FOR(j,1,sz[u]-1)
		{
			cur[i][j] = 0 ; 
			FOR(ii,0,min(k-1,i))FOR(jj,0,min(j-1,sz[v]-1))
			{
				cur[i][j]+=f[v][ii][jj][0]*pre[i-ii][j-jj-(ii?1:0)];
			}
		}
		FOR(i,1,k)FOR(j,1,sz[u]-1)pre[i][j]=cur[i][j];
	}
	FOR(i,a,min(sz[u]-1,b))
	{
		res+=pre[k][i];
	}	
}
void solve()
{
	dfs(1,0) ;
	FOR(i,1,n)
	{
		ll tmp =0; 
		FOR(j,a,b)
		{
			res+=f[i][k][j][1]; 
		}
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