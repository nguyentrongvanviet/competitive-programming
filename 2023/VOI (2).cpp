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
ll n,m,a[N],b[N],st[4*N],lazy[4*N];
void read()
{
	cin>>n>>m;
	f(i,1,n) cin>>a[i];
	f(i,1,m) cin>>b[i];
}
void fix(ll id,ll l,ll r){
	if(!lazy[id])return;
	st[id]+=lazy[id];
	if(l!=r){
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
	}
	lazy[id]=0;
}
void update(ll id,ll l,ll r,ll u,ll v,ll val){
	fix(id,l,r);
	if(u>r||v<l)return;
	if(u<=l&&r<=v){
		lazy[id]+=val;
		fix(id,l,r);
		return;
	}
	ll mid=(l+r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id]=min(st[id*2],st[id*2+1]);
}
ll get(ll id,ll l,ll r){
	fix(id,l,r);
	if(l==r){
		return (st[id]<0?l:-1);
	}
	ll mid=(l+r)/2;
	fix(id*2,l,mid); fix(id*2+1,mid+1,r);
	if(st[id*2+1]<0) return get(id*2+1,mid+1,r);
	return get(id*2,l,mid);
}
void solve()
{
	f(i,1,n) update(1,1,N,1,a[i],-1);
	f(i,1,m)update(1,1,N,1,b[i],1);
	ll q;
	cin>>q;
	while(q--){
		ll t,u,v;
		cin>>t>>u>>v;
		--t;
		if(t){
			update(1,1,N,1,b[u],-1);
			b[u]=v;
			update(1,1,N,1,b[u],1);
		}
		else {
			update(1,1,N,1,a[u],1);
			a[u]=v;
			update(1,1,N,1,a[u],-1);
		}
		cout<<get(1,1,N)<<el;
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