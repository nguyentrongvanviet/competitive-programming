
// Author: Nguyen Quoc Phu Dep Trai	
#define TASK "test"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
#define mp make_pair
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin())
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define pt pop_front
#define pf push_front
#define el '\n'
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define fd(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define            tct  template<typename T>
#define BIT ((x>>i)&1)
#define MASK(x) (1<<(x))

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){f(i,1,n)cout<<a[i]<<" ";cout<<el;}

const int N =3e3+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=__lg(N);
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// end template 


// ll num[N],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA

ll n,sub[N][N],par[N][N],dp[N][N];
vector<ll>g[N];
void read()
{
	cin>>n;
	f(i,1,n-1){
		ll  u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
}
void dfs(ll u,ll p,ll root){
	sub[u][root]=1;
	for(auto v:g[u])if(v!=p){
		par[v][root]=u;
		dfs(v,u,root);
		sub[u][root]+=sub[v][root];
	}
}
ll get(ll u,ll v){
	if(u==v) return 0;
	if(dp[u][v]!=-1) return dp[u][v];
	return dp[u][v]=sub[u][v]*sub[v][u]+max(get(par[u][v],v),get(par[v][u],u));
}
void solve()
{
	f(i,1,n) f(j,1,n) dp[i][j]=-1;
	f(i,1,n) dfs(i,i,i);
	ll ans=0;
	f(i,1,n) f(j,1,n) maxi(ans,get(i,j));
	cout<<ans;
}

signed main()	
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen(TASK".INP", "r"))
	{
		freopen(TASK".INP", "r", stdin);
		freopen(TASK".OUT", "w", stdout);
	}
	fast;
    int test =1; 
  //  cin>>test;
   while(test--)
    {
        read(); 
        solve();
    }
    cerr << "\nTime: " << clock() << "ms\n";
}