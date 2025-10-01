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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n, M ; 
struct ke
{
    int v ,w ; 
} ; 
ve<ke>g[N] ; 
void doc()
{
    cin>> n >> M ; 
    FOR(i,1,n-1)
    {
        int u ,v , w;  cin>> u >>v >>w ; 
        g[u].pb({v,w}) ; 
        g[v].pb({u,w}) ; 
    }
}

namespace sub1
{
    int sz[N] ; 
    int dd[N] ; 
    void dfsz(int u ,int p)
    {
        sz[u] = 1 ;
        for(auto [v,w]:g[u])if(v!=p&&dd[v]==0)
        {
            dfsz(v,u) ; 
            sz[u]+=sz[v] ; 
        }
    }
    int cen(int u ,int p ,int n)
    {
        for(auto [v,w] : g[u])if(v!=p&&dd[v]==0)
        {
            if(sz[v]>n/2)
            {
                return cen(v,u,n) ; 
            }
        }
        return u ; 
    }
    ll pw(ll a, ll n)
    {
        if(n==0) return 1;
        ll b = pw(a,n/2); 
        if(n&1)return b*b%M*a%M;
        return b*b%M ;
    }
    int MU[N] ; 
    int IV[N] ; 
    ll res = 0 ;
    map<int,int>sl1,sl2;   
    void dfs_get(int u ,int p,int h ,int val1,int val2)
    {
        int d1 =  (-1ll*val1*IV[h]%M+M)%M;
        if(sl1.count(d1))res+=sl1[d1];
        if(sl2.count(val2))res+=sl2[val2]; 
        for(auto [v,w]:g[u])if(dd[v]==0&&v!=p)
        {
            dfs_get(v,u,h+1,(1ll*val1*10+w)%M,(val2+1ll*w*MU[h])%M) ;
        }
    }
    void dfs_build(int u ,int p ,int h ,int val1,int val2)
    {
        sl1[val1]++ ;
        int d2 = (-1ll*val2*IV[h]%M+M)%M ;
        sl2[d2]++ ;  
        for(auto [v,w] : g[u])if(dd[v]==0&&v!=p)
        {
            dfs_build(v,u,h+1,(val1+1ll*w*MU[h])%M,(1ll*val2*10+w)%M) ; 
        }
    }
    void solve(int u )
    {
        dd[u] = 1 ;
        sl1.clear() ;
        sl2.clear() ;
        sl1[0] = 1 ; 
        sl2[0] = 1 ; 
        for(auto [v,w]:g[u])if(dd[v]==0)
        {
            dfs_get(v,u,1,w%M,w%M) ;
            dfs_build(v,u,1,w%M,w%M) ;  
        }
        for(auto [v,w]:g[u])if(dd[v]==0)
        {
            dfsz(v,u) ; 
            solve(cen(v,u,sz[v])) ; 
        }
    }
    int phi(int n)
    {
        int res = n ; 
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)n/=i ; 
                res -=res/i ; 
            }
        }
        if(n>1)res-=res/n ;
        return res ;  
    }
    void xuly()
    {
        if(M==1)
        {
            cout<<1ll*n*(n-1)<<el;
            return ; 
        }
        MU[0] = 1 ;
        FOR(i,1,n)
        {
            MU[i] = 1ll*MU[i-1]*10%M ; 
        } 
        int iv = pw(10,phi(M)-1) ;
        IV[0] = 1 ;  
        FOR(i,1,n)
        {
            IV[i] = 1ll*IV[i-1]*iv%M; 
        }
        dfsz(0,0) ;
        solve(cen(0,0,n)) ;  
        cout<<res<<el;  
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