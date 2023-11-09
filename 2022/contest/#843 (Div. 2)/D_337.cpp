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
const int LO = 20 ; 
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ,m  ,  k ;
int h[N],dd[N] , P[N]; 
vi g[N] ; 

int pa[N][LO+2];
void read()
{
	cin>> n >> m>> k  ; 
	FOR(i,1,m)
	{
		cin>>P[i] ;  
	}
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v; 
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
}
void dfs(int u ,int p)
{	
	for(auto v : g[u])if(v!=p)
	{
		pa[v][0] = u ;
		h[v]=h[u]+1;  
		dfs(v,u) ;
		dd[u]|=dd[v];  
	}
}
pii dia()
{
	FOR(i,1,m)dd[P[i]]=1;
	h[1] =0  ; 
	dfs(1,0) ;
	
	int ans=1; 
	FOR(u,1,n)if(dd[u])if(h[u]>h[ans])ans=u;
	
	FOR(i,1,n)dd[i]= 0; 
	FOR(i,1,m)dd[P[i]]=1;
	h[ans] = 0 ;
	dfs(ans,0);
	int res= ans ;
	FOR(u,1,n)if(dd[u])if(h[u]>h[res])res= u ;
	FOR(i,1,n)dd[i]=0;
	
	return make_pair(ans,res) ;
}
int lca(int u ,int v )
{
	int ans= 0 ;
	if(h[u]<h[v])swap(u,v) ; 
	int dis= h[u]-h[v] ; 
	for(int i= 0 ;i<=LO;i++)
	{
		if(dis>>i&1)
		{
			ans+=(1<<i); 
			u=pa[u][i] ; 
		}
	} 
	if(u==v)return ans;
	FORD(i,LO,0)
	{
		int nu = pa[u][i] ;
		int nv = pa[v][i] ; 
		if(nu!=nv)
		{
			u=nu ;
			v=nv; 
			ans+=2*(1<<i);
		}
	}
	return ans+2;
}
void solve()
{
	pii tmp = dia() ; 
	h[1]=  0 ;
	dfs(1,0) ;
	FOR(j,1,LO)
	{	
		FOR(i,1,n)
		{
			pa[i][j]=pa[pa[i][j-1]][j-1]; 
		}
	} 
	FOR(i,1,n)dd[i]=0;
	FOR(i,1,m)dd[P[i]]= 1;  
	int res =0 ; 
	FOR(i,1,n)
	{
		int dis =max(lca(i,tmp.fi),lca(i,tmp.se));
		if(dis<=k)res++ ; 
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