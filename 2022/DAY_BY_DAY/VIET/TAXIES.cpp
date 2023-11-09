#define TASK "TAXIES"
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
const int N =5e3+2 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , m;  
ll c[N] ; 
int r[N] ; 
vi g[N];
ll f[N][N] ;
struct DL
{
	int u ; 
	int cl;  
	ll cost; 
};  
struct cmp
{
	bool operator()(DL a, DL b)
	{
		return a.cost>b.cost ;
	}
};
void read()
{
	cin>> n >>m ; 
	FOR(i,1,n)cin>>c[i]>>r[i] ; 
	FOR(i,1,m)
	{
		int u ,v ; 
		cin>>u>>v;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}
ll dij(int s, int t )
{
	priority_queue<DL,ve<DL>,cmp>q ;
	for(int i= 1;i<=n;i++)
	{
		for(int j= 0;j<=n;j++)
		{
			f[i][j] = inf; 
		}
	}
	f[s][0]= 0 ; 
	q.push({s,0,f[s][0]}); 
	while(!q.empty())
	{
		DL tmp = q.top() ; 
		q.pop() ; 
		int u = tmp.u ; 
		int cl =tmp.cl; 
		ll w= tmp.cost;
		if(u==t)return w;
		if(f[u][cl]!=w)continue;
		if(f[u][0]>f[u][cl])
		{
			q.push({u,0,f[u][0]=f[u][cl]});
		}
		if(cl)
		{
			for(auto v : g[u])
			{
				if(f[v][cl-1]>f[u][cl])
				{
					q.push({v,cl-1,f[v][cl-1] =f[u][cl]}) ; 
				}
			}
		}
		if(f[u][r[u]]>f[u][cl]+c[u])
		{
			q.push({u,r[u],f[u][r[u]]=f[u][cl]+c[u]});
		}
	}
	return 0 ; 
}
void solve()
{
	ll res=  dij(1,n) ; 
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