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
#define          SZ(_)  (int)(_.size())
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
void doc()
{
    cin>> n >> m; 
}

namespace sub1
{
    const int B = 1e3+1 ; 
    bitset<B>E[N] ; 
    void xuly()
    {        
        while(m--)
        {
            int u ,v ;cin>>u>>v ;
            E[u].set(v,1) ; 
        }
        ll res= 0;  
        FOR(i,1,n)FOR(j,i+1,n)
        {
            int tmp = (E[i]&E[j]).count() ; 
            res+=(1ll*tmp*(tmp-1))/2;
        }
        cout<<res; 
    }
}
namespace sub2
{
    vi g[N] ; 
    int dd[N] ; 
    void xuly()
    {
        FOR(i,1,m)
        {
            int u ,v ; cin>>u>>v; 
            g[v].pb(u) ; 
        }
        map<pii,int>sl ; 
        ll res =0 ; 
        FOR(i,1,n)if(SZ(g[i])<=(int)sqrt(m))
        {
            FORN(x,0,SZ(g[i]))
            {
                FORN(y,x+1,SZ(g[i]))
                {
                    int u = g[i][x] ; 
                    int v = g[i][y] ; 
                    if(u>v)swap(u,v) ; 
                    res+=sl[mp(u,v)] ;
                    sl[mp(u,v)]++;
                }
            }
        }
        FOR(i,1,n)if(SZ(g[i])>(int)sqrt(m))
        {
            for(auto u : g[i])dd[u] = 1; 
            FOR(u,1,i-1)if(SZ(g[u])<=(int)sqrt(m))
            {
                int cnt = 0 ;
                for(auto v:g[u])cnt+=dd[v] ;
                res+=1ll*(cnt*(cnt-1))/2;
            }   
            FOR(u,i+1,n)
            {
                int cnt = 0 ;
                for(auto v:g[u])cnt[v]+=dd[v] ;
                res+=1ll*(cnt*(cnt-1))/2;
            }
            for(auto u : g[i])dd[u] = 0; 
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
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}