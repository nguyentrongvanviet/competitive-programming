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
ll n,m,lazy[4*N],st[N],t[4*N],en[N],sz[N],timeDFS=0,par[N];
vector<ll>g[N];
void read()
{
	cin>>n;
	f(i,1,n-1){
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
}
void dfs(ll u,ll p){
	st[u]=++timeDFS;
	sz[u]=1;
	for(auto v:g[u])if(v!=p){
		par[v]=u;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	en[u]=timeDFS;
}
void fix(ll id,ll l,ll r){
	ll mid=(l+r)/2;
	if(lazy[id]!=-1){
		lazy[id*2]=lazy[id*2+1]=lazy[id];
		t[id*2]=lazy[id]*(mid-l+1);
		t[id*2+1]=lazy[id]*(r-mid);
		lazy[id]=-1;
	}
	return;
}
void update(ll id,ll l,ll r,ll u,ll v,ll val){
	if(l>v||r<u)return;
	if(u<=l&&r<=v){
		t[id]=(r-l+1)*val;
		lazy[id]=val;
		return;
	}
	fix(id,l,r);
	ll mid=(l+r)>>1;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	t[id]=t[id*2]+t[id*2+1];
}
ll get(ll id,ll l,ll r,ll u,ll v){
	if(l>v||r<u)return 0;
	if(u<=l&&r<=v)return t[id];
	fix(id,l,r);
	ll mid=(l+r)>>1;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void solve()
{
	dfs(1,0);
	f(i,1,4*n)lazy[i]=-1;
	cin>>m;
	while(m--){
		ll type,u;
		cin>>type>>u;
		if(type==1){
			if(u!=1&&get(1,1,n,st[u],en[u])<sz[u])update(1,1,n,st[par[u]],st[par[u]],0);
			update(1,1,n,st[u],en[u],1);
		}
		else if(type==2){
			update(1,1,n,st[u],st[u],0);
		}
		else  {
			ll val=get(1,1,n,st[u],en[u]);
			cout<<(val==sz[u]?1:0)<<el;
		}
	}
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