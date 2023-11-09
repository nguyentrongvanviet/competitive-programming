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
const int N =1e5+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=16;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// ll num[N],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA
ll dp[N][12][4],n,m,k,x,newdp[12][4];
vector<ll>g[N];
void read()
{
	cin>>n>>m;
	f(i,1,n-1){
		int u,v;
		cin>>u>>v;
		g[u].pb(v); g[v].pb(u);
	}
	cin>>k>>x;
}
void dfs(ll u,ll p){
	dp[u][0][0]=k-1;
	dp[u][1][1]=1;
	dp[u][0][2]=m-k;
	for(auto v:g[u])if(v!=p){
		dfs(v,u);
		f(a,0,x)f(b,0,x-a){
			newdp[a+b][1]=(newdp[a+b][1]+dp[u][a][1]*dp[v][b][0]%sm)%sm;
			newdp[a+b][2]=(newdp[a+b][2]+dp[u][a][2]*(dp[v][b][0]+dp[v][b][2]%sm)%sm)%sm;
			newdp[a+b][0]=(newdp[a+b][0]+dp[u][a][0]*(dp[v][b][0]+dp[v][b][1]+dp[v][b][2]%sm)%sm)%sm;
		}
		f(a,0,x)f(b,0,2){
			dp[u][a][b]=newdp[a][b];
			newdp[a][b]=0;
		}
	}
}
void solve()
{
	dfs(1,0);
	ll res=0;
	f(a,0,x) f(b,0,2) (res+=dp[1][a][b])%=sm;
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