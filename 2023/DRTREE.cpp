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
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n; 
int a[N] ;
vi g[N] ; 
void doc()
{
	cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n-1)
    {
        int u ; cin>>u ; 
        g[u].pb(i+1) ;
    }
}
int h[N] ; 
ll f[N] ; 
int P[N][LO+1] ; 
void dfs(int u , int p )
{
    f[u]=a[u] ;
    for(auto v :g[u])if(v!=p)
    {
        h[v]+=h[u]+1;  
        P[v][0] = u ;  
        dfs(v,u) ; 
        f[u]+=f[v] ;
    }
}
int goup(int u ,int d)
{
    FOR(i,0,LO)if(d>>i&1)u=P[u][i] ;
    return u ;
}
ll get(int u , int root )
{
    if(h[u]>h[root])return f[u] ; 
    int dis =  h[root]-h[u] ; 
    if(goup(root,dis)!=u)return f[u] ; 
    if(u==root)return f[1] ;
    int v= goup(root,dis-1) ;
    return f[1]-f[v] ; 
}
void xuly()
{
    dfs(1,0) ; 
    FOR(j,1,LO)FOR(i,1,n)
    {
        P[i][j] = P[P[i][j-1]][j-1] ; 
    } 
    int q;  
    cin>>q; 
    int root = 1 ;
    while(q--)
    {
        char x ; cin>>x ;
        int  u; cin>>u ;
        if(x=='R')
        {   
            root = u ;
        }
        else
        {
            cout<<get(u,root)<<el;
        }
    }
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