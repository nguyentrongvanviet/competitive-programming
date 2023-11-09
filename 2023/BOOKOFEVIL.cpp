#define TASK "test"
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
 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){f(i,1,n)cout<<a[i]<<" ";cout<<el;}
struct bg{
	ll x,y,s;
};
const int N =1e6+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=16;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// ll num[N],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA
ll n,q,d,f[N],r[N],b[N];
vector<ll>g[N];
void read()
{
	cin>>n>>q>>d;
	f(i,1,n) f[i]=-inf,r[i]=-inf;
	f(i,1,q){
		ll x;
		cin>>x;
		f[x]=1;
		r[x]=0;
	}
	f(i,1,n-1){
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
}
void dfs(ll u,ll p){
	for(auto  v:g[u])if(v!=p){
		dfs(v,u);
		f[u]=max(f[u],f[v]+1);
	}
}
void dfs2(ll u,ll p){
	ll n1=-inf,n2=-inf;
	for(auto v:g[u])if(v!=p){
		if(f[v]>=n1){
			n2=n1;
			n1=f[v];
		}
		else if(f[v]>=n2){
			n2=f[v];
		}
	}
	for(auto v:g[u])if(v!=p){
		if(f[v]==n1) r[v]=max({r[v],r[u]+1,n2+1});
		else r[v]=max({r[v],r[u]+1,n1+1});
		dfs2(v,u);
	}
}
void solve()
{
	dfs(1,0);
	dfs2(1,0);
	ll res=0;
	f(i,1,n){
		res+=(r[i]<=d&&f[i]-1<=d);
	}
	cout<<res;
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
