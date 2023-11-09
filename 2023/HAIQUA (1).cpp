#define TASK "HAIQUA"
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
ll n,k,t[N],a[N],s[N],idx[N],val[N],f[N];
vector<ll>g[N];
void read()
{
	cin>>n>>k;
	f(i,1,n) cin>>t[i];
	f(i,1,n) cin>>a[i];
	f(i,1,n) s[i]=s[i-1]+a[i];
}

void solve()
{
	ll res=0;
	f(i,1,n){
		g[t[i]].pb(s[i-1]-s[idx[t[i]]]);
		g[t[i]].pb(a[i]*(1-k));
		idx[t[i]]=i;
	}
	f(i,1,k)g[i].pb(s[n]-s[idx[i]]);
	f(i,1,k){
		for(int j=0;j<g[i].size();j++){
			val[j]=(j>=1?val[j-1]:0)+g[i][j];
		}
		ll ma=-inf;
		for(int j=0;j<g[i].size();j++){
			f[j]=max(g[i][j],ma+val[j]);
			ma=max(ma,f[j]-val[j]);
			res=max(res,f[j]);
		}
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