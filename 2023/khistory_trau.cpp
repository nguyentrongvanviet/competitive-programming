    // Author: Nguyen Quoc Phu Dep Trai    
#define TASK "text"
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
const ll INF=(ll)1e18 + 7LL;
ll product(ll a,ll b){
    if(a==0||b==0) return 0;
    return INF/a<b?INF:a*b;
}
const int N =1e6+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=__lg(N);
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
// end template 


ll num[N],low[N],timeDFS=0,tplt=0,was[N],tp[N],child[N]; // DFS
// ll up[N][20],h[N],dist[N][20],mi[N][20],ma[N][20],par[N]; //LCA
ll n,m,a[N],d[N];
stack<ll>st;
vector<ll>g[N];
vector<ll>query[N];
void add_edge(int u ,int v ,int tu ,int tv)
{
	g[u<<1^tu^1].pb(v<<1^tv) ; 
	g[v<<1^tv^1].pb(u<<1^tu) ;
}
void read()
{
    cin>>n>>m;
    f(i,1,n) cin>>a[i];
    f(i,1,m){
        ll size,x;
        cin>>size; f(j,1,size){
            cin>>x;
            query[x].pb(i);
        }
    }
    f(i,1,n){
        ll u=query[i][0]; ll v=query[i][1];
        if(!a[i]){
            add_edge(u,v,1,1);
            add_edge(u,v,0,0);
        }
        else {
            add_edge(u,v,1,0);
            add_edge(u,v,0,1);
        }
    }
}
void dfs(ll u,ll p){
    num[u]=low[u]=++timeDFS;
    st.push(u);
    for(auto v:g[u]){
        if(v==p) continue;
        if(tp[v]) continue;
        if(!num[v]){
            //par[v]=u;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else {
            low[u]=min(low[u],num[v]);
        }
    }
    if(low[u]==num[u]){
        ll v;
        tplt++;
        do{
            v=st.top();
            st.pop();
            tp[v]=tplt;
        } while(v!=u);
    }
}
void solve()
{
	f(i,1<<1,(m<<1)^1){
		if(!num[i]) dfs(i,0);
	}
    ll res=0;
    f(i,1,m){
        if(tp[i<<1]==tp[i<<1^1]) return void(cout<<"NO");
    }
    cout<<"YES";
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