#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
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
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout) ;
    }
}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

struct Edge 
{
	int u ,v ,w; 
};
int n , m ; 
Edge E[N] ;

vi g[N] ; 
stack<int>st ; 
int id[N] , low[N],tp[N] ; 
int tplt  , tt ; 
vi adj[N] ;  
int sz[N] ; 
bool in[N] ;
int cnt ;  
int dd[N] ; 
void doc()
{
	cin>> n >> m ;
	FOR(i,1,m)
	{
		int u ,v  ,w ; 
		cin>>u>>v>>w ;
		E[i] = {u,v,w};
	} 
}
void dfs(int u )
{
	id[u] = low[u] = ++tt; 
	st.push(u) ; 
	for(auto v:g[u])
	{
		if(tp[v])continue; 
		if(id[v])low[u] = min(low[u],id[v]) ;
		else dfs(v) , low[u] = min(low[u],low[v]) ;
	}
	if(low[u]==id[u])
	{
		int t; 
		++tplt; 
		do
		{
			t= st.top() ; 
			st.pop() ;
			tp[t] = tplt ;  
		}while(u!=t);
	}
}
void go(int u)
{
	dd[u] = 1; 
	cnt++ ; 
	for(auto v :adj[u])
	{
		if(dd[v]==0)go(v);  
	}
}
bool check(int val)
{
	set<pii>exist ;
	FOR(i,1,n)g[i].clear(),dd[i]=id[i]=low[i]=tp[i]=sz[i]=in[i]=0,adj[i].clear();
	tplt = tt = 0 ; 
	FOR(i,1,m)
	{
		int u = E[i].u ;
		int v = E[i].v ; 
		int w = E[i].w;
		g[u].pb(v) ; 
		if(w<=val)g[v].pb(u) ; 
	}
	FOR(u,1,n)if(id[u]==0)dfs(u); 
	FOR(u,1,n)for(auto v: g[u])
	{
		int x= tp[u] ; 
		int y = tp[v] ; 
		if(x!=y)if(exist.find(mp(x,y))==exist.end())
		{
			exist.insert(mp(x,y));
			adj[x].pb(y) ;
			in[y] = 1; 
		}	
	}
	cnt =0 ; 

	FOR(i,1,tplt)
	{
		if(in[i]==0)
		{
			go(i) ; 
			break;
		} 
	}
	// cout<<cnt<<" "<<tplt<<" "<<val<<el;
	return cnt==tplt;   
}
int tknp()
{
	int l = 0 ;
	int r = (int)1e9 ;
	int ans = -1 ; 
	while(l<=r)
	{
		int mid =(l+r)/2; 
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans; 
}
void xuly()
{
	// cout<<check(9535)<<el;
	int res = tknp() ; 
	cout<<res<<el;
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        doc(); 
        xuly();
    }
}