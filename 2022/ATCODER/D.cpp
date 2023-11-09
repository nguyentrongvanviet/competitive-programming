#define TASK "D"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  true ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pii> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n' 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(a%b,a);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
    void IOS()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N =2e3+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct DL
{
    int u ,v , dis; 
    bool operator<(const DL&a)const
    {
        return dis<a.dis ;
    }
}; 
int n ; 
char a[N] ;
vi g[N] ;
int p[N] ;
vii d[N] ; 
ve<DL>q ;
int Next[N][N],f[N][N];
void read()
{
    cin>>n ;  
    FOR(i,1,n)cin>>a[i]; 
    FORN(i,1,n)
    {
        int u ,v   ; cin>>u>>v ;
        g[u].pb(v) ; 
        g[v].pb(u)  ;
    }
}
void dfs(int root , int ne , int u ,int pa,int h )
{   
    q.pb({root,u,h}) ;
    Next[root][u]=ne ; 
    for(auto v :g[u])
    {
        if(v==pa)continue ;
        dfs(root,ne,v,u,h+1); 
    }
}
void solve()
{
    FOR(u,1,n)
    {
        for(auto v :g[u])
        {   
            dfs(u,v,v,u,1) ;
        }
    } 
    FOR(i,1,n)f[i][i]=1;
    sort(all(q)) ;
    int res=1 ;
    for(auto x : q)
    {        
        int u = x.u; 
        int v = x.v; 
        if(Next[u][v]==v)
        {
            if(a[u]==a[v])
            {
                res=max(res,2) ; 
                f[u][v] = 2 ;
            }
            else f[u][v] =1 ;
            continue ;  
        }
        f[u][v] =max(f[Next[u][v]][v],f[u][Next[v][u]]);
        if(a[u]==a[v])f[u][v]= max(f[u][v],2+f[Next[u][v]][Next[v][u]]);
        res=max(res,f[u][v]) ; 
    }
    cout<<res<<el;      
}
void clear()
{
    q.clear() ; 
    FOR(i,1,n)FOR(j,1,n)Next[i][j],f[i][j] = 0 ; 
    FOR(i,1,n)d[i].clear(),g[i].clear();
}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
        clear();
    }
}	