
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

const int N =1e6, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=__lg(N);
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// end template 
const  int MAXN=2*N+1;
// ll num[N],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA
struct DL{
	ll type;
	ll x;
	ll y0,y1;
	bool operator  <  (const DL &A) const {
		return x<A.x;
	}
};
vector <DL> P;
ll n;
void read()
{
	cin>>n;
	f(i,1,n){
		ll u,v,x,y;
		cin>>u>>v>>x>>y;
		u+=N; v+=N; x+=N; y+=N;
		P.pb({1,u,v,y-1});
		P.pb({-1,x,v,y-1});
	}
}
pll st[8*N]; ll lazy[8*N];

pll merge(pll A,pll B){
	if(A.fi<B.fi) return A;
	if(A.fi>B.fi) return B;
	return {A.fi,A.se+B.se};
}
void fix(ll id,ll l,ll r){
	if(!lazy[id])return;
	st[id].fi+=lazy[id];
	if(l!=r){
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
	}
	lazy[id]=0;
}
void build(ll id,ll l,ll r){
	if(l==r){
		st[id]={0,1};
		return;
	}
	ll mid=(l+r)>>1;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
void update(ll id,ll l,ll r,ll u,ll v,ll val){
	fix(id,l,r);
	if(u>r||v<l) return;
	if(u<=l&&r<=v){
		lazy[id]+=val;
		fix(id,l,r);
		return;
	}
	ll mid=(l+r)>>1;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id]=merge(st[id*2],st[id*2+1]);
}
void solve()
{
	build(1,0,MAXN);
	sort(all(P));
	update(1,0,MAXN,P[0].y0,P[0].y1,P[0].type);
	ll res=0;
	FORN(i,1,2*n){
		res+=(MAXN+1-st[1].se)*(P[i].x-P[i-1].x);
		update(1,0,MAXN,P[i].y0,P[i].y1,P[i].type);
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