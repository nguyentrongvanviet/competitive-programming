/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "input"
#define INPUT TASK".txt" 
#define OUTPUT TASK".txt"
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
const int N = 20 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , k ; 
ll cost[N+1][N+1] ; 
void doc()
{
    cin>> n >> k ;     
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>cost[i][j] ; 
}

namespace sub1
{
    long long f[1<<N] ;
    ll tinh(int msk )
    {
        if(__builtin_popcount(msk)==k)return 0 ; 
        if(f[msk]!=inf)return f[msk] ; 
        for(int i=1;i<=n;i++)if((msk>>(i-1)&1)==1)
        {
            for(int j=1;j<=n;j++)if((msk>>(j-1)&1)==1 x)if(i!=j)
            {
                f[msk] = min(f[msk] , tinh(msk^(1<<(i-1))) + cost[i][j]) ; 
            }
        }
        return f[msk] ; 
    }
    void xuly()
    {
        for(int i=0;i<(1<<n);i++)
        {
            f[i] = inf ; 
        }
        ll res = tinh((1<<n)-1) ; 
        cout<<res<<endl; 
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    // freopen("input.txt","r",stdin) ;
    // freopen("output.txt","w",stdout) ; 
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}