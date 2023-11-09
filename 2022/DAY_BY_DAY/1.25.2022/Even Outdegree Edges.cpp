#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
bool multitest = false;
#include<bits/stdc++.h>
using namespace std; 
void IOS()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r")){freopen(INPUT ,"r",stdin) ;freopen(OUTPUT,"w",stdout);}
}
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define viet first 
#define duyen second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define SZ(a) (int)a.size()
#define debug(a) cerr<<#a<<" "<<a<<el;
#define DV cerr<<"<---------------->"<<el;
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
template<class T>void print(ve<T>a){cerr<<"[ ";for(auto v : a)cerr<<v<<" ";cerr<<" ]"<<el;}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
int n ,m ; 
vi g[N] ; 
int dd[N] ; 
int par[N] ; 
ve<pii>ans; 
void doc()
{
    cin>> n >> m; 
    FOR(i,1,m)
    {
        int u ,v ;cin>>u>>v; 
        g[u].pb(v) ; 
        g[v].pb(u) ; 
        // cerr<<u<<" "<<v<<el;
    }
}
int tt = 0;
void dfs(int u , int p)
{
    cerr<<u<<el;
    dd[u] = ++tt; 
    for(auto v: g[u])if(v!=p)
    {
        if(dd[v]==0)
        {
            dfs(v,u);
            if(par[v])ans.pb(mp(v,u)),par[v]^=1;
            else ans.pb(mp(u,v)),par[u]^=1;
        }
        else if(dd[v]<dd[u])
        {
            par[u]^=1;  
            ans.pb(mp(u,v));
        }
    }
}
void xuly()
{
    FOR(i,1,n)
    {
        if(dd[i]==0)dfs(i,0) ; 
    }
    FOR(i,1,n)if(par[i])return void(cout<<"IMPOSSIBLE");
    for(auto it : ans)cout<<it.viet<<" "<<it.duyen<<el;
}
 
signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        doc(); 
        xuly();
    }
    cerr<<"Time: "<<clock()<<"ms"<<el;
}