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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}

int n , k , W , M ; 
ll smin , smax;  
int a[N] ; 
void doc()
{
    cin>> n >> k >> W >> M >> smin >> smax ; 
    FOR(i,1,n)
    {
        cin>>a[i] ; 
        a[i]=a[i]*M ; 
    }
}
ll f[N][N] ; 
ll sum[N][N] ;  
void init()
{
    int n = 15 ; 
    f[0][0]=1;
    FOR(i,1,n)
    {
        f[i][0]=1;
        FOR(j,1,i-1)
        {
            f[i][j] = f[i-1][j]*(j+1) + f[i-1][j-1]*(i-j);
        }
    }
    FOR(i,1,n)
    {
        sum[i][0] = 1 ; 
        FOR(j,1,n)
        {
            sum[i][j] = sum[i][j-1]+f[i][j];
        }
    }
}
namespace sub1
{
    ll s[N] ; 
    ll get(int l ,int r )
    {
        return s[r]-s[l-1] ;
    }
    ll ma[N][N]; 
    void xuly()
    {
        FOR(i,1,n)
        {
            s[i] = s[i-1]+a[i] ; 
            if(smin<=s[i]&&s[i]<=smax)
            {
                ma[i][1] = sum[i][W];
            }
        }
        FOR(j,2,k)
        {
            FOR(i,j,n)
            {
                ma[i][j] = 0 ; 
                FOR(ii,j-1,i-1)if(smin<=s[i]-s[ii]&&s[i]-s[ii]<=smax)
                {
                    maxi(ma[i][j],ma[ii][j-1]+sum[i-ii][W]);
                }
            }
        }
        cout<<ma[n][k]<<el;
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
    init() ; 
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cout<<test<<el;
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}