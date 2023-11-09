#define TASK "ROBBINSON"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
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
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
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

const int N =2e3+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

struct ke 
{
	int v ; 
	ll t,  h ;
} ; 
struct DL
{
	int u ; 
	ll k ; 
	ll t ;
};
struct cmp
{
	bool operator()(DL a , DL b)
	{
		return a.t>b.t||(a.t==b.t&&a.k<b.k);
	}
};
int k , n , m;
ve<ke>g[N]  ; 
ll f[N][202];  
bool dd[N][202] ; 
ll res = inf ; 
void read()
{
	cin>>  k >> n >> m ; 
	FOR(i,1,m)
	{
		int u , v ;  ll  t , h ; 
		cin>>u>>v>>t>>h; 
		g[u].pb({v,t,h}); 
		g[v].pb({u,t,h});
	} 
}
void dij(int s ,int t )
{
	priority_queue<DL,ve<DL>,cmp>q ; 
	FOR(i,1,n)
	{
		FOR(j,0,k)
		{
			f[i][j] = inf; 
			dd[i][j] = 0 ; 
		}
	}
	f[s][k] =  0 ;
	q.push({s,k,0});
	while(!q.empty())
	{
		int u= q.top().u; 
		int k =q.top().k ;
		q.pop() ; 
		if(dd[u][k])continue ;
		if(u==t)res=min(res,f[u][k]) ; 
		dd[u][k] = 1; 
		for(auto x : g[u])
		{
			int v = x.v;
			ll t= x.t ;  
			ll h = x.h; 
			if(k-h>0)
			{
				int nk =k-h ;
				if(dd[v][nk])continue ;
				if(f[v][nk]>f[u][k]+t)
				{
					q.push({v,nk,f[v][nk]=f[u][k]+t}) ;
				}
			}
		}
	}
}
void solve()
{
	int A , B ; 
	cin>>A>>B ; 
	dij(A,B) ; 
	if(res==inf)cout<<-1; 
	else cout<<res;
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