/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

#include<bits/stdc++.h>
using namespace std; 


#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll
#define            tct  template<typename T>
#define             LB  lower_bound
#define             UB  upper_bound 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 20, CH = 26 ; 
// end of macros and constant  

int n; 
vi g[N] ; 
int a[N] ; 
int sz[N] ;
int dd[N]; 
int cnt[1<<LO] ; 
ll f[N] ; 
ll dp[N] ;
void doc()
{
    cin>> n; 
    FOR(i,1,n-1)
    {
        int u,v ; cin>>u>>v ;
        g[u].pb(v) ; 
        g[v].pb(u) ; 
    }
    FOR(i,1,n)
    {
        char x ;cin>>x ;
        a[i] = x-'a' ; 
    }
}
void dfsz(int u ,int p)
{
    sz[u] =1 ; 
    for(auto v : g[u])if(v!=p&&dd[v]==0)
    {
        dfsz(v,u) ; 
        sz[u]+=sz[v] ; 
    }
}
int cen(int u ,int p ,int n)
{
    for(auto v: g[u])if(v!=p&&dd[v]==0)
    {
        if(sz[v]>n/2)return cen(v,u,n);  
    }
    return u ; 
}
void dfs(int u ,int p ,int val ,int c)
{
    val^=(1<<a[u]) ; 
    cnt[val]+=c ; 
    for(auto v :g[u])if(v!=p&&dd[v]==0)
    {   
        dfs(v,u,val,c);
    }
}
void dfs1(int u ,int p ,int root , int val )
{
    val^=(1<<a[u]) ; 
    dp[root]+=cnt[val] ;
    FORN(i,0,LO){
        dp[root]+=cnt[val^(1<<i)] ; 
    }
    for(auto v :g[u])if(v!=p&&dd[v]==0)
    {
        dfs1(v,u,root,val) ;
    }
}

ll dfs2(int u ,int p ,int val )
{
    val^=(1<<a[u]) ; 
    ll sl = 0 ; 
    sl+=cnt[val] ; 
    FORN(i,0,LO)
        sl+=cnt[val^(1<<i)] ; 
    for(auto v :g[u])if(dd[v]==0&&v!=p)
    {
        sl+=dfs2(v,u,val) ; 
    }
    f[u]+=sl ; 
    return sl  ; 
}
void solve(int u )
{   
    dd[u] = 1 ; 
    for(auto v: g[u])if(dd[v]==0)
    {   
        dfs(v,u,1<<a[u],1) ; 
    } 

    f[u]+=cnt[0] ;
    FORN(i,0,LO)
    {
        f[u]+=cnt[1<<i] ;
    }
    for(auto v : g[u])if(dd[v]==0)
    {
        dfs(v,u,1<<a[u],-1) ;
        dfs1(v,u,u,0) ; 
        dfs(v,u,1<<a[u],1) ; 
    }
    f[u]+=dp[u]/2;
    cnt[1<<a[u]]++;
    for(auto v : g[u])if(dd[v]==0)
    {
        dfs(v,u,1<<a[u],-1) ;
        dfs2(v,u,0) ;
        dfs(v,u,1<<a[u],1) ;
    }
    for(auto v: g[u])if(dd[v]==0)
    {   
        dfs(v,u,1<<a[u],-1) ; 
    }   
    cnt[1<<a[u]]--;
    for(auto v: g[u])if(dd[v]==0)
    {
        dfsz(v,u); 
        solve(cen(v,u,sz[v])) ; 
    }
}

void xuly()
{
    dfsz(1,0);
    solve(cen(1,0,n)) ;  
    FOR(i,1,n)cout<<f[i]+1<<" ";    
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}