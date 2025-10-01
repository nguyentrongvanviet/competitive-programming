/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
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
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m;

struct Edge
{
    int u ,v , w ,id ; 
    Edge(int u=0,int v =0,int w=0,int id=0) : u(u) , v(v) , w(w),id(id) {}
}; 
Edge E[N] ; 
struct ke
{
    int v, w ;
}  ;
ve<ke>g[N] ; 
void doc()
{
    cin>> n >> m; 
    FOR(i,1,m)
    {
        E[i].id = i ; 
        cin>>E[i].u>>E[i].v>>E[i].w ; 
    }   
}

namespace sub1
{
    int pa[N] ;
    int goc(int u)
    {
        return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
    }
    ll res = 0 ; 
    bool hop(int u ,int v,int w )
    {
        int chau = goc(u) ; 
        int chav = goc(v) ; 
        if(chau==chav)return 0 ;  
        pa[chau] = chav ; 
        g[u].pb({v,w}) ; 
        g[v].pb({u,w}) ; 
        res+=w ; 
        return 1 ;
    }
    int dd[N] ;
    int P[N][LO+1] ;
    int MI[N][LO+1] ;
    int h[N] ;
    void dfs(int u ,int p)
    {
        for(auto [v,w]:g[u])if(v!=p)
        {
            h[v] = h[u]+1 ; 
            P[v][0] = u ; 
            MI[v][0] = w; 
            FOR(i,1,LO)P[v][i] = P[P[v][i-1]][i-1],MI[v][i]=max(MI[v][i-1],MI[P[v][i-1]][i-1]) ; 
            dfs(v,u) ; 
        }
    }   
    int mi(int u ,int v)
    {
        int mi = 0; 
        if(h[u]<h[v])swap(u,v) ; 
        FORD(i,LO,0)if(h[P[u][i]]>=h[v])maxi(mi,MI[u][i]),u = P[u][i] ; 
        if(u==v)return mi;
        FORD(i,LO,0)if(P[u][i]!=P[v][i])
        {
            maxi(mi,MI[u][i]),maxi(mi,MI[v][i]),u = P[u][i] , v = P[v][i] ; 
        }
        return max({mi,MI[u][0],MI[v][0]}) ;
    }
    void xuly()
    {
        ve<Edge>q ;
        FOR(i,1,m)
        {
            q.push_back(E[i]) ; 
        }
        sort(all(q),[](Edge a , Edge b){return a.w<b.w;}); 
        FOR(i,1,n)pa[i] = i ; 
        for(auto [u,v,w,id] : q)
        {
            if(hop(u,v,w))dd[id] = 1 ;
        }
        dfs(1,0) ; 
        FOR(i,1,m)
        {
            if(dd[i])
            {
                cout<<res<<el;
            }
            else cout<<res-mi(E[i].u,E[i].v)+E[i].w<<el; 
        }
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}