// Author: Nguyen Quoc Phu Dep Trai    

#define TASK "TRAVEL"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define int long long
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
#define sz(x) (int)((x).size())
#define el '\n'
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define fd(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define btctz(a) __builtin_ctz(a) // bit 1 MIN
#define btclz(a) __builtin_clz(a)  // bit 1 MAX
#define            tct  template<typename T>
#define BIT(x,i) ((x>>i)&1)
#define MASK(x) (1<<(x))
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}

tct void prt(T a[] ,int n ){f(i,1,n)cout<<a[i]<<" ";cout<<el;}
#define print(a) for(auto  _v : a )cout<<_v<<" ";cout<<'\n';

const int N =1e6+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = (int)1e9 , llinf = (ll)1e18 + 7LL , MOD=1e9+7 , LG=__lg(N);
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

// end template and solution


int n,m,k,tplt=0,tp[N],sz[N],num[N],low[N],timeDFS=0,res=0,sl[N];
vector<ll>adj[N],dp[N],sum[N];
vector<pll>g[N];
stack<ll>st;
void read()
{
    cin>>n>>m>>k;
    f(i,1,m){
        int u,v;
        cin>>u>>v;
        g[u].pb(mp(v,i));
        g[v].pb(mp(u,i));
    }
}

namespace small{
    void solve(){

    }
}
void tarjan(ll u,ll p){
    num[u]=low[u]=++timeDFS;
    st.push(u);
    for(auto w:g[u]){
        int v=w.fi;
        int idx=w.se;
        if(idx==p) continue;
        if(!num[v]){
            tarjan(v,idx);
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
            sl[tplt]++;
        } while(v!=u);
    }
}
void dfs(int u,int p){
    sz[u]=sl[u];
    sum[u].pb(sz[u]);
    dp[u].pb(sz[u]);
    for(auto [v,id]:g[u])if(v!=p){
        dfs(v,u);
    }
    for(auto [v,id]:g[u])if(v!=p)
    {
        sz[u]+=sz[v];
        if(sum[u].size()<sum[v].size()){
            swap(sum[u],sum[v]);
            swap(dp[u],dp[v]);
        }
        int pre=res; 
        f(i,1,sum[v].size()){
            int len=i-1;
            // if(k-len<0)
            // {
            //     res+=sum[u][0]*dp[v][sz(sum[v])-i];
            // }
            if(sum[u].size()>k-len) res+=sum[u][sz(sum[u])-k+len-1]*dp[v][sz(sum[v])-i];
        }
        if(u==1)cout<<res-pre<<el;
        f(i,1,sum[v].size()){
            sum[u][sz(sum[u])-i]+=sum[v][sz(sum[v])-i];
            dp[u][sz(sum[u])-i]+=dp[v][sz(sum[v])-i];
        }
    }
    cout<<"node"<<" "<<u<<el;
    print(sum[u]);  
    print(dp[u]) ;
    cout<<el;
}
namespace big{
    void solve(){
        // f(i,1,n) if(!num[i]) tarjan(i,0);
        // f(u,1,n)for(auto v:g[u])if(tp[u]!=tp[v.fi]){
        //     adj[tp[u]].pb(tp[v.fi]);
        // }
        f(i,1,n)sl[i] = 1 ; 
        dfs(1,0);
        cout<<res;
    }
}

signed main()   
{
    srand(time(0));
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
        small::solve();
        big::solve();
    }
    cerr << "\nTime: " << clock() << "ms\n";
}