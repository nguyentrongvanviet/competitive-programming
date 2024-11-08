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

int n  ;
ll L , R; 
struct ke
{
    int v; ll w ;
} ; 
ve<ke>g[N] ; 
ll h[N] ; 
void dfs(int u ,int p)
{
    for(auto [v,w] : g[u])if(v!=p)
    {
        h[v] = h[u]^w ; 
        dfs(v,u) ; 
    }
}
int T[700*700*64][2] ; 
int node = 0; 
void add(long long val)
{
    int r = 1 ; 
    for(int i=LO;i>=0;i--)
    {
        int j = BIT(val,i) ; 
        if(T[r][j]==0)
        {
            T[r][j] = ++node;  
        }
        r=T[r][j] ; 
    }
}   
ll get(ll val)
{
    ll ans = val ; 
    int r = 1 ; 
    for(int i=LO;i>=0;i--)
    {
        int j = BIT(val,i) ; 
        if(T[r][j]==0)
        {
            
        }
        else
        {

        }
    }
    return ans ; 
}
void doc()
{
    cin>> n >> L >> R ;
    for(int i=1;i<=n-1;i++)
    {
        int u , v ; ll w ; 
        cin>>u>>v>>w ; 
        g[u].pb({v,w}) ; 
        g[v].pb({u,w}) ; 
    } 
    dfs(1,0) ; 
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        add(h[i]^h[j]) ; 
    }
    ll res = 0 ; 
    FOR(u,1,n)FOR(v,1,n)if(u!=v)
    {
        res=max(res,get(h[u]^h[v])) ; 
    }
    cout<<res ; 
}

namespace sub1
{
    void xuly()
    {

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