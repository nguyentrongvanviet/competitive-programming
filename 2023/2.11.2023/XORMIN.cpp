/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "XORMIN"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ;
int test = 1 ;  

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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  ((msk)>>(i)&1)
#define        Mask(i)  (1<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 19 , CH = 26 ; 


int n , q; 
vi g[N] ; 
int a[N] ;


void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n)cin>>a[i]  ; 
    FOR(i,1,n-1)
    {
        int u ,v ; cin>> u >> v; 
        g[u].pb(v) ; 
        g[v].pb(u) ; 
    }
}       

namespace sub1
{
    int pa[N] ;
    void dfs(int u ,int p)
    {
        for(auto v:g[u])if(v!=p)
        {
            pa[v] =u ; 
            dfs(v,u) ; 
        }
    }
    int res_val , res_u ; 
    void solve(int u ,int p ,int k )
    {
        if(maxi(res_val,a[u]^k))res_u = u ;
        else if(res_val==(a[u]^k))mini(res_u,u) ;
        for(auto v: g[u])if(v!=p)
        {
            solve(v,u,k) ;
        }
    }
    void xuly()
    {
        dfs(1,0) ;
        res_u = res_val = 0 ;
        while(q--)
        {
            int u, k; cin>>u>>k ;
            // u^=res_u ; 
            // k^=res_val;
            res_u = oo ;
            res_val = 0 ;
            solve(u,pa[u],k) ;
            cout<<res_u<<" "<<res_val<<el;
        }  
        FOR(i,1,n)g[i].clear();
    }
}
namespace sub2
{

    int T[N*LO*(LO+1)][2] ;
    int node = 0 ;
    int res[N*LO*(LO+1)] ;
    int H[N];
    int copy(int v)
    {
        ++node ;
        FOR(i,0,1)T[node][i] = T[v][i] ; 
        res[node] = res[v] ; 
        return node;
    }
    void add(int v , int val , int u)
    {
        int cur = copy(H[u]);
        H[u] = cur ;
        FORD(i,LO,0)
        {
            int j = BIT(val,i) ;
            T[cur][j] = copy(T[cur][j]) ;  
            cur=T[cur][j] ;
        }
        if(res[cur]==0)res[cur] =  v ; 
        else mini(res[cur],v);
    }
    vi tp[N] ;
    int sz[N] ; 
    void dfs(int u ,int p)
    {
        sz[u] = 1 ; 
        tp[u].pb(u) ;
        add(u,a[u],u) ;

        for(auto v:g[u])if(v!=p)
        {
            dfs(v,u) ;
            if(sz[u]<sz[v])
            {   
                swap(tp[u],tp[v]) ;
                H[u] = copy(H[v]) ;
            }
            for(auto x:tp[v])
            {
                add(x,a[x],u) ;
                tp[u].pb(x);
            }
            sz[u]+=sz[v] ;
        }    
    }
    int res_u , res_val; 
    void solve(int u ,int mask)
    {
        u=H[u] ; 
        FORD(i,LO,0)
        {
            int j= BIT(mask,i) ; 
            if(T[u][j^1])
            {
                u=T[u][j^1] ;
                res_val^=Mask(i) ; 
            }
            else u=T[u][j] ; 
        }
        res_u = res[u] ; 
    }
    void xuly()
    {
        dfs(1,0) ;
        res_u = 0 , res_val = 0 ;
        // cout<<node<<el;
        while(q--)
        {
            int u , val; cin>>u >>val ;
            u^=res_u ; 
            val^=res_val; 
            res_u = 0 ; 
            res_val = 0 ; 
            solve(u,val) ;
            cout<<res_u<<" "<<res_val<<el;
        }
        FOR(i,1,n)g[i].clear() ;
        FOR(i,1,node)
        {
            FOR(j,0,1)T[i][j] = 0 ; 
            res[i] = 0 ;
        }
        FOR(i,1,n)H[i] =0,tp[i].clear() ; 
        node= 0 ; 
    }
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}