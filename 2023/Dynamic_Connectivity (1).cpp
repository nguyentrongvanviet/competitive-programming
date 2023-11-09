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
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()))
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
void add(ll u,ll v,vector<ll> adj[]){
	adj[u].pb(v);
	adj[v].pb(u);
}
const int N =1e6+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=__lg(N);
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// ll nurN],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA
struct DL{
	ll u,v;
	ll type;
} Q[N];

ll n,m,k,q,en[N],res[N];
map <pll,vll> r;
stack <pll> s;
void read()
{
	cin>>n>>m>>k;
	q=m+k;
	f(i,1,m){
		ll u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		Q[i]={u,v,1};
		en[i]=q;
		r[mp(u,v)].pb(i);
	}
	f(i,m+1,m+k){
		ll type,u,v;
		cin>>type>>u>>v;
		if(u>v) swap(u,v);
		Q[i]={u,v,type};
		if(type==1){
			en[i]=q;
			r[mp(u,v)].pb(i);
		}
		else {
			en[r[mp(u,v)].back()]=i-1;
			r[mp(u,v)].pk();
		}
	}
}
ll par[N],sz[N],ans=0;
ll find(ll u){
	return u==par[u]?u:find(par[u]);
}
void merge(ll u,ll v){
	u=find(par[u]); v=find(par[v]);
	if(u==v) return;
	if(sz[u]>sz[v]) swap(u,v);
	ans--;
	par[u]=v;
	sz[v]+=sz[u];
	s.push({u,v});
}
vector <pll> st[4*N];
void update(ll id,ll l,ll r,ll u,ll v,pll add){
	if(u>r||v<l)return;
	if(u<=l&&r<=v){
		st[id].pb(add);
		return;
	}
	ll mid=(l+r)>>1;
	update(id*2,l,mid,u,v,add);
	update(id*2+1,mid+1,r,u,v,add);
}
void roll_back(ll len){
	while((ll)s.size()>len){
		ll u=s.top().fi;
		ll v=s.top().se;
		if(sz[u]>sz[v])swap(u,v);
		par[u]=u;
		sz[v]-=sz[u];
		ans++;
		s.pop();
	}
}
void cal(ll id,ll l,ll r){
	ll len=s.size();
	for(auto v:st[id]) merge(v.fi,v.se);
	if(l==r){
		res[l]=ans;
		roll_back(len);
		return;
	}
	ll mid=(l+r)>>1;
	cal(id*2,l,mid);
	cal(id*2+1,mid+1,r);
	roll_back(len);
}
void solve()
{
	f(i,1,q) if(Q[i].type==1) update(1,1,q,i,en[i],mp(Q[i].u,Q[i].v));
	f(i,1,n) par[i]=i,sz[i]=1;
	ans=n;
	cal(1,1,q);
	f(i,m,q){
		cout<<res[i]<<" ";
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