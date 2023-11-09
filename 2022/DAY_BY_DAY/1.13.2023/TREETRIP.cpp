#define TASK "TREETRIP"
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
struct ke 
{
	int v; 
	ll w ; 
} ;
int n  ; 
ll A , B ; 
ve<ke>g[N] ; 
ll f[N][2]; 
void read()
{
	cin>> n >> A >> B ; 
	FOR(i,1,n-1)
	{
		int u , v  ;ll w; 
		cin>>u>>v>>w;
		g[u].pb({v,w*A}); 
		g[v].pb({u,w*A}); 
	}
}
void dfs(int u ,int p )
{
	for(auto x : g[u])if(x.v!=p)dfs(x.v,u);
	int con = g[u].size()-(u==1?0:1) ; 
	if(con==0)f[u][1]=0,f[u][0]=0;
	if(con==1)
	{
		for(auto x : g[u])
		{
			int v= x.v ; 
			ll w = x.w ; 
			if(v==p)continue ; 
			f[u][1] = min(f[v][0]+B,f[v][1]+w); 
			f[u][0] =  min({f[u][1],w+f[v][1],B+f[v][0]});
		}
	}
	if(con>=2)
	{	
		vll val;  
		ll tmp = 0 ; 
		for(auto x: g[u])
		{
			int v = x.v ; 
			ll w = x.w;  
			if(v==p)continue;
			val.pb(f[v][1]+w-(f[v][0]+B)) ;	
			tmp+=f[v][0]+B; 
		}	
		sort(all(val));
		tmp+=val[0]+val[1]; 
		f[u][0] = min(f[u][0],tmp); 
	}
	if(con>=2)
	{
		ll mi = inf ; 
		ll tmp = 0  ; 
		for(auto x: g[u])
		{
			int v= x.v ;
			ll w = x. w; 
			if(v==p)continue;
			tmp+=B+f[v][0];
			mi=min(mi,f[v][1]+w-(B+f[v][0]));
		}
		f[u][0] =min(f[u][0],tmp) ;
		f[u][1] =min(f[u][1],tmp) ;
		tmp+=mi ; 
		f[u][0] =min(f[u][0],tmp) ;
		f[u][1] =min(f[u][1],tmp);
	}
}
void solve()
{
	FOR(i,1,n)f[i][1]=f[i][0]=inf;
	dfs(1,0); 
	if(n==2)
	{
		cout<<min(B*2,g[1][0].w*2)<<el;
		return ; 
	}
	cout<<B+min(f[1][1],f[1][0]); 
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