/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "TDL"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
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
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m;
vi g[N] ;
void doc()
{
    cin>> n; 
    FOR(i,1,n-1)
    {
        int u ,v ; cin>> u >> v; 
        g[u].pb(v) ;
        g[v].pb(u) ;
    }
    cin>> m; 
}

namespace sub1
{
    int f[N] ;
    void dfs(int u ,int p)
    {
        vi res; 
        for(auto v:g[u])if(v!=p)
        {
            dfs(v,u) ;
            res.pb(f[v]) ; 
        }
        sort(all(res),greater<int>()) ;
        int cnt = 0 ;  
        for(auto v:res)
        {
            ++cnt;
            maxi(f[u],v+cnt) ;
        }
    }
    void xuly()
    {
        int s; cin>>s;
        dfs(s,0) ; 
        cout<<f[s]<<el;
    }
}
namespace sub2
{
    int U , V ; 
    int f[N] ;
    int dis[N] ; 
    void calc(int u ,int p)
    {
        for(auto v:g[u])if(v!=p)
        {
            dis[v] = dis[u]+1 ;
            calc(v,u) ; 
        }
    }
    int dfs(int u ,int p, int cam)
    {
        f[u] = 0 ;
        vi res ;
        for(auto v:g[u])if(v!=p&&v!=cam)
        {
            res.pb(dfs(v,u,cam)) ; 
        }
        sort(all(res),greater<int>()) ;
        int cnt = 0 ;  
        for(auto v:res)
        {
            ++cnt;
            maxi(f[u],v+cnt) ;
        }
        return f[u] ;
    }
    void xuly()
    {
        int U , V  ; cin>> U >> V ; 
        calc(U,0) ;
        int cur = V ; 
        vi node;  
        while(cur!=U)
        {
            node.pb(cur) ;
            int ne = 0 ; 
            dis[ne] = oo ;
            for(auto v:g[cur])if(dis[ne]>dis[v])ne=v; 
            cur = ne ;
        }
        node.pb(U) ; 

        int res = oo ; 
        // FORN(i,0,SZ(node)-1)
        // {
        //     mini(res,max(dfs(V,0,node[i+1]),dfs(U,0,node[i]))) ;
        // }

        int l = 0 ;
        int r = SZ(node)-2 ; 
        while(l<=r)
        {
            int mid=(l+r)>>1 ;
            int L = dfs(V,0,node[mid+1]) ;
            int R = dfs(U,0,node[mid]) ;
            mini(res,max(L,R)) ; 
            if(L<R)
            {
                r=mid-1; 
            }
            else l=mid+1; 
        }
        cout<<res<<el;
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        if(m==1)sub1::xuly() ; 
        else sub2::xuly();
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}