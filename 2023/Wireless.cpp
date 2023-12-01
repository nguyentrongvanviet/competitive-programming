/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "wireless"
#define INPUT TASK".INP"
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;

#include<bits/stdc++.h>
using namespace std;

#define             ll  long long
#define             db  double
#define             ve  vector
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair
#define             fi  first
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin())
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)

ll lg(ll a) {return __lg(a);}
ll sq(ll a) {return a * a;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll rd(ll l , ll r ) {return l + 1LL * rand() * rand() * rand() % (r - l + 1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el;

tct bool mini(T& a, T b) {return (a > b) ? a = b, 1 : 0;}
tct bool maxi(T& a, T b) {return (a < b) ? a = b, 1 : 0;}

int xx[] = {0, 0, -1, 0, 1};
int yy[] = {0, -1, 0, 1, 0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9 + 7;
const int N = 5e5 + 5 , oo = 2e9 , LO = 19 , CH = 26 ;

int n , q ;
struct ke
{
	int v;
	ll  w;
} ;
ve<ke>g[N] ;
vi Q[(int)1e5 + 5] ;
void doc()
{
	cin >> n >> q ;
	FOR(i, 1, n - 1)
	{
		int u , v, w ; cin >> u >> v >> w;
		g[u].pb({v, w}) ;
		g[v].pb({u, w}) ;
	}
	FOR(i, 1, q)
	{
		int k; cin >> k;
		while (k--)
		{
			int u ; cin >> u ;
			Q[i].pb(u) ;
		}
	}
}
namespace subfull
{
	int h[N] ;
	int P[N][LO + 3] ;
	ll W[N][LO + 3] ;
	int in[N] , out[N] ;
	ve<ke>adj[N] ;
	int tt = 0 ;
	void dfs(int u , int p)
	{
		in[u] = ++tt;
		for (auto x : g[u])
		{
			int v = x.v ;
			int w = x.w ;
			if (v == p)continue ;
			h[v] = h[u] + 1 ;
			W[v][0] =  w;
			P[v][0] = u ;
			dfs(v, u) ;
		}
		out[u] = ++tt;
	}
	pair<int, ll> lca(int u , int v)
	{
		ll res = 0 ;
		if (h[u] < h[v])swap(u, v) ;
		FORD(i, LO, 0)if (h[u] - (1 << i) >= h[v])res += W[u][i], u = P[u][i] ;
		if (u == v)return {u, res} ;
		FORD(i, LO, 0)
		{
			int nu = P[u][i] ;
			int nv = P[v][i] ;
			if (nu != nv)
			{
				res += W[u][i] + W[v][i] ;
				u = nu ;
				v = nv ;
			}
		}
		return {P[u][0], res + W[u][0] + W[v][0]} ;
	}
	ll sz[N] , f[N] , d[N] ;
	ll res  ;
	int root ;
	void DFS(int u , int p)
	{
		for (auto x : adj[u])
		{
			int v = x.v;
			ll w = x.w ;
			if (v == p)continue ;
			DFS(v, u) ;
			sz[u] += sz[v] ;
			f[u] += f[v] + 1ll * w * sz[v] ;
		}
	}
	void solve(int u , int p )
	{
		mini(res, f[u] + d[u]) ;
		for (auto x : adj[u])
		{
			int v = x.v ;
			ll w = x.w ;
			if (v == p)continue ;
			d[v] = f[u] + d[u] - (f[v] + 1ll * w * sz[v]) + 1ll * (sz[root] - sz[v]) * w ;
			solve(v, u) ;
		}
	}
	void xuly()
	{
		dfs(1, 0) ;
		FOR(j, 1, LO)FOR(i, 1, n)P[i][j] = P[P[i][j - 1]][j - 1], W[i][j] = W[i][j - 1] + W[P[i][j - 1]][j - 1]  ;
		FOR(i, 1, q)
		{
			sort(all(Q[i]), [&](int u , int v) {return in[u] < in[v];});
			int k = Q[i].size() ;
			for (auto u : Q[i])sz[u] = 1;
			FORN(j, 1, k)
			{
				Q[i].pb(lca(Q[i][j], Q[i][j - 1]).fi) ;
			}
			stack<int>st ;
			uni(Q[i]) ;
			sort(all(Q[i]), [&](int u , int v) {return in[u] < in[v];});
			for (auto u : Q[i])
			{
				while (!st.empty() && out[st.top()] < in[u])st.pop() ;
				if (st.size())
				{
					pair<int, ll> c = lca(st.top(), u) ;
					adj[st.top()].pb({u, c.se}) ;
				}
				st.push(u) ;

			}
			root = Q[i][0] ;
			DFS(root, 0) ;
			res = inf ;
			solve(root, 0) ;
			cout << res << el;
			for (auto u : Q[i])sz[u] = 0, f[u] = 0, d[u] = 0, adj[u].clear() ;
		}
	}
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); srand(time(0));
	if (fopen(INPUT, "r"))
	{
		freopen(INPUT , "r", stdin);
		freopen(OUTPUT, "w", stdout);
	}
	if (mtt)cin >> test;

	FOR(i, 1, test)
	{
		doc() ;
		subfull::xuly() ;
	}
	cerr << el << "Love KA : " << clock() << "ms" << el;
}
