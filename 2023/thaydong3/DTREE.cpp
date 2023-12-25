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
const int N = 4e5+5 , oo = 2e9 , LO = 19 , CH = 26 ; 

int n , q ;
vi g[N] ; 
void doc()
{
    cin >> n >>q ; 
    FOR(i,1,n-1)
    {
        int u  ,v; 
        cin>> u >>v ;
        g[u].pb(v) ;
        g[v].pb(u) ;
    }
}

namespace sub1
{
    int at[N] , in[N] ; 
    int time_dfs = 0 , tt = 0 ; 
    int h[N] ; 
    int st[2*N][LO+2] ;
    void dfs(int u ,int p)
    {
        int cur = ++time_dfs ;  
        at[cur] = u ; 
        in[u] = ++tt ; 
        st[tt][0] = cur ;
        for(auto v:g[u])if(v!=p)
        {
            h[v] = h[u]+1; 
            dfs(v,u) ;
            st[++tt][0] = cur; 
        }
    }
    void build_RMQ()
    {
        FOR(j,1,LO)FOR(i,1,tt-M(j)+1)st[i][j] = min(st[i][j-1],st[i+M(j-1)][j-1]) ;
    }
    int lca(int u ,int v)
    {
        int l = in[u] ;
        int r = in[v] ;
        if(l>r)swap(l,r) ; 
        int k = lg(r-l+1) ;
        return at[min(st[l][k],st[r-M(k)+1][k])] ;
    }
    int dis(int u ,int v)
    {
        return h[u] + h[v] - 2*h[lca(u,v)] ; 
    }
    int a[N] ;
    int X = 0, Y= 0, LEN = 0; 
    void add(int u )
    {
        if(X==0)
        {
            X=u;
            return ; 
        }
        if(Y==0)
        {
            Y=u ;
            LEN = dis(X,Y) ;
            return ; 
        }
        if(dis(X,u)<dis(Y,u))swap(X,Y);
        if(maxi(LEN,dis(X,u)))Y=u ;
    }
    int res[N] ;
    int dd[N] ;
    void xuly()
    {
        dfs(1,0) ;
        build_RMQ() ;
        FOR(i,1,q)
        {
            cin>>a[i] ;
            dd[a[i]] = 1;
        }
        FOR(i,1,n)if(dd[i]==0)
        {
            add(i) ; 
        }
        res[q] = LEN;
        FORD(i,q,1)
        {
            add(a[i]) ;
            res[i-1] = LEN ;
        }
        X=Y=LEN=0 ;
        FOR(i,1,q)
        {
            add(a[i]) ;  
            cout<<res[i]<<" "<<LEN<<el;
        }
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}