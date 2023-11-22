// Author: Nguyen Quoc Phu Dep Trai    

#define TASK "text"
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
#define vii vector<int>
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

const int N =5e5+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = (int)1e9 , llinf = (ll)1e18 + 7LL , MOD=1e9+7 , LG=__lg(N);
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

// end template and solution

int n,k,a[N],in[N],pos[N],timeDFS=0,out[N],up[N][LG+2],h[N],weight[N],cnt=0,co[N];
pii f[N];
vector<pll>g[N],adj[N];
set<ll>save;
void read()
{
    cin>>n>>k;
    f(i,1,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
    }
    f(i,1,k) cin>>a[i],co[a[i]]=1;
}

namespace small{
    void solve(){

    }
}
void dfs(int u,int p){
    in[u]=++timeDFS;
    pos[timeDFS]=u;
    for(auto e:g[u]){
        int v=e.fi;
        int w=e.se;
        if(v==p) continue;
        up[v][0]=u;
        h[v]=h[u]+1;
        weight[v]=weight[u]+w;
        f(i,1,LG) up[v][i]=up[up[v][i-1]][i-1];
        dfs(v,u);
    }
    out[u]=timeDFS;
}
int lca(int u,int v){
    if(h[u]!=h[v]) {
        if(h[u]<h[v]) swap(u,v);
        int k=h[u]-h[v];
        f(i,0,LG)if(BIT(k,i)){
            u=up[u][i];
        }
    }
    if(u==v) return u;
    fd(i,LG,0)if(up[v][i]!=up[u][i]){
        u=up[u][i];
        v=up[v][i];
    }
    return up[u][0];
}
int dist(int u,int v){
    int p=lca(u,v);
    return weight[u]+weight[v]-2*weight[p];
}
void find(int u,int p,int &node,int kc){
    if(maxi(cnt,kc))node=u;
    for(auto e:adj[u]){
        int v=e.fi;
        int w=e.se;
        if(v==p) continue;
        find(v,u,node,kc+w);
    }
}
void bfs(vll &save){
    f(i,1,n) f[i]=mp(inf,0ll);
    queue<pii>q;
    for(auto v:save){
        f[v]=mp(0ll,v);
        q.push(mp(v,v));
    }
    while(!q.empty()){
        pii c=q.front();
        int u=c.fi;
        int node=c.se;
        q.pop();
        for(auto e:g[u]){
            int v=e.fi;
            int w=e.se;
            if(f[v]==mp(inf,0ll)){
                f[v].fi=f[u].fi+w;
                f[v].se=f[u].se;
                q.push(mp(v,node));
            }
        }
    }
}
int sl[N];
void build(int u,int p){
    sl[u]=co[u];
    for(auto e:g[u]){
        int v=e.fi;
        int w=e.se;
        if(v==p) continue;
        build(v,u);
        sl[u]+=sl[v];
        if(sl[v]) adj[u].pb(mp(v,w)),adj[v].pb(mp(u,w));
    }
}
namespace big{
    void solve(){
        dfs(1,0);
        ll res=0;
        vll Q;
        f(i,1,k) Q.pb(a[i]);
        sort(all(Q),[&](int x,int y){
            return in[x]<in[y];
        });
        FORN(i,1,sz(Q)){
            int u=Q[i-1];
            int v=Q[i];
            res+=dist(u,v);
        }
        if(Q[0]!=Q.back())res+=dist(Q[0],Q.back());
        build(Q[0],0);
        // f(i,1,n){
        //  cout<<i<<el;
        //  for(auto v:adj[i]) cout<<v.fi<<" "<<v.se<<el;
        //      cout<<el;
        // }
        vll wait;
        f(i,1,k) wait.pb(a[i]);
        f(i,1,n) if(adj[i].size()) wait.pb(i);
        uni(wait);
        bfs(wait);
        cnt=0;
        int l=0,r=0;
        find(Q[0],0,l,0);
        cnt=0;
        find(l,0,r,0);
        f(i,1,n){
            pii u=f[i];
            int ans=res;
            int mindist=max(dist(u.se,l),dist(u.se,r));
            ans+=f[i].fi;
            ans-=mindist;
            cout<<ans<<el;
        }
        // int ans=res;
    }
}

signed main()   
{
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(TASK".INP", "r"))
    {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".ANS", "w", stdout);
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