#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
const int N = 2e5+5  , oo = 2e9 , LO =__lg(N); 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ;
int n , m;  
vi g[N] ; 
int dd[N],pa[N]  , deg[N] , sz[N] ; 
int goc(int u )
{
    return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
}
void hop(int u ,int v)
{
    int chau = goc(u) ; 
    int chav = goc(v) ; 
    if(chau==chav)return ; 
    pa[chau] = chav ; 
    sz[chav]+=sz[chau] ; 
} 
void doc()
{
    cin>> n >>m  ; 
    FOR(i,1,n)pa[i]=i , sz[i] = 1  , deg[i] = n-1 ; 
    FOR(i,1,m)
    {
        int u , v; cin>>u>>v ;
        deg[u]-- ; 
        deg[v]-- ; 
        g[u].pb(v) ; 
        g[v].pb(u) ;  
    }
    FOR(i,1,n)sort(all(g[i])) ; 
    for(int i= 1,tmp=0;i<=n;i++)
    {
        if(deg[i]>=n/2)
        {
            if(tmp==0)tmp=i  ;
            else hop(tmp,i); 
        }
        else dd[i] = 1;  
    }  
    FOR(u,1,n)if(dd[u]==1)
    {
        FORN(v,1,g[u][0])hop(u,v) ; 
        FORN(i,1,g[u].size())
            FORN(v,g[u][i-1]+1,g[u][i])hop(u,v) ; 
        FOR(v,g[u].back()+1,n)hop(u,v);
    }
    vi size_node ;
    for(int i= 1 ;i<=n;i++)if(pa[i]==i)size_node.pb(sz[i]) ; 
    cout<<size_node.size()<<el; 
    sort(all(size_node)) ; 
    for(auto x:size_node)cout<<x<<" ";
}       

void xuly()
{
    
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}