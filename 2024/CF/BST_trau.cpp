/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

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
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , k ;
struct Edge
{
    int u ,v ; 
}E[N] ;
vi g[N] ; 
void doc()
{
    cin>> n >> k; 
    FOR(i,1,n-1)
    {
        cin>>E[i].u>>E[i].v ;
    }
}

namespace sub1
{
    const int N =2e3+5; 
    int C[N][N] ; 
    void xuly()
    {
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                C[i][j] = 1e9 ; 
            }
            C[i][i] = 0 ; 
        }
        FOR(i,1,n-1)
        {
            C[E[i].u][E[i].v]=1 ;
            C[E[i].v][E[i].u]=1 ; 
        }
        FOR(k,1,n)
        {
            FOR(i,1,n)FOR(j,1,n)
            {
                mini(C[i][j],C[i][k]+C[k][j]) ; 
            }
        }
        vector<int>res(n,0) ; 
        FOR(i,1,n)FOR(j,1,n)
        {
            res[C[i][j]]++ ; 
        }
        FORN(i,0,n)cout<<res[i]<<" ";
    }   
}
namespace sub2
{
    int P[N][LO+3] ;
    int h[N] ; 
    void dfs(int u ,int p)
    {
        for(auto v :g[u])if(v!=p)
        {
            h[v]=h[u]+1; 
            P[v][0] = u  ; 
            FOR(i,1,LO)P[v][i]=P[P[v][i-1]][i-1]; 
            dfs(v,u) ; 
        }
    }
    int lca(int u ,int v)
    {
        int dis = 0 ;
        if(h[u]<h[v])swap(u,v) ;  
        FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])dis+=(1<<i),u=P[u][i] ;
        if(u==v)return dis ; 
        FORD(i,LO,0)
        {
            int nu = P[u][i] ; 
            int nv = P[v][i] ; 
            if(nu!=nv)
            {
                dis+=2*(1<<i) ; 
                u=nu ; 
                v=nv ; 
            }
        }
        dis+=2 ; 
        return dis ; 
    }
    void xuly()
    {
        FOR(i,1,n-1)
        {
            g[E[i].u].pb(E[i].v) ;
            g[E[i].v].pb(E[i].u) ; 
        }
        dfs(1,0) ;
        vector<int>res(n); 
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                res[lca(i,j)]++ ; 
            }
        }
        FORN(i,0,n)cout<<res[i]<<" ";
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
        sub2::xuly() ; 
        // cout<<el;
        // if(sqrt(k)<=n)sub2::xuly() ; 
        // sub3::xuly() ;  
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}