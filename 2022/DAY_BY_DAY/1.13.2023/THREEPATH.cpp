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
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ;
vi g[N] ;
pii f[N] , h[N];
pii d1[N],d2[N];
int res= -1 ;  
ve<pii> q[N];
void read()
{
	cin>> n; 
	FOR(i,1,n-1)
	{
		int u ,v;  cin>>u>>v; 
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
}
int A ,  B ,C ; 
void ma(int &res, pii a ,pii b ,pii c )
{
	if(res<a.fi+b.fi+c.fi)
	{
		A = a.se; 
		B = b.se; 
		C = c.se;
		res=a.fi+b.fi+c.fi; 
	}
}

void dfs(int u , int p )
{
	f[u]=make_pair(0,u);
	for(auto v : g[u])if(v!=p)
	{
		dfs(v,u) ;
		if(f[u].fi<f[v].fi+1)f[u] = make_pair(f[v].fi+1,f[v].se);
		q[u].pb(make_pair(f[v].fi+1,f[v].se)); 
		if(res<f[v].fi+1)
		{
			res=  f[v].fi+1; 
			A =u ;  
			B =f[v].se;
			C = v ;
		}
	}
	sort(all(q[u]),greater<pii>());
	if(q[u].size()>=3)
	{
		ma(res,q[u][0],q[u][1],q[u][2]) ; 
	}
}
void dfsz(int u ,int p )
{		
	d1[u] = {0,u};
	d2[u] ={0,u};
	if(p)
	{
		if(d1[p].se==f[u].se){d1[u]=make_pair(d2[p].fi+1,d2[p].se);}
		else d1[u] = make_pair(d1[p].fi+1,d1[p].se);
	} 
	if(q[u].size()>=2)
	{
		// if(q[u][0].se==5)cout<<u<<" "<<d1[u].fi<<" "<<d1[u].se<<el;
		ma(res,q[u][0],q[u][1],d1[u]);
	}
	for(auto x : q[u])
	{
		if(d1[u]<=x)d2[u] = d1[u],d1[u]=x; 
		else if(x>d2[u])d2[u] = x; 
	}
	for(auto v : g[u])if(v!=p)
	{	
		dfsz(v,u) ;
	}
}
void solve()
{
	dfs(1,0) ; 
	dfsz(1,0) ;
	cout<<res<<el; 
	cout<<A<<" "<<B<<" "<<C;
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