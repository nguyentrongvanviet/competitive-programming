/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "SHLGOOD"
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

int xx[] = {0,-1,0,1,-1,-1,1,1} ; 
int yy[] = {-1,0,1,0,-1,1,-1,1} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m; 
int a[N][N] ;

int color[N][N] ; 

void doc()
{
   	cin >> n >> m; 
    FOR(i,1,n)FOR(j,1,m)color[i][j] = -1 ;
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ; 
}
namespace sub1
{
    bool in(int x, int y)
    {
        return 1<=x && x<=n && 1<=y && y<=m ;
    }
    void dfs(int x, int y ,int c)
    {
        color[x][y]=c; 
        if(a[x][y] && a[x][y]%2!=c)
        {
            cout<<-1<<el; 
            exit(0) ;
        }
        FORN(i,4,8)
        {
            int nx= x+xx[i] ;
            int ny= y+yy[i] ;
            if(!in(nx,ny))continue ; 
            if(color[nx][ny]==-1)
            {
                dfs(nx,ny,c^1) ;
            }
            else if(color[nx][ny]!=(c^1)) 
            {
                cout<<-1<<el;
                exit(0) ;
            }
        }
    }
    void xuly()
    {
        FOR(i,1,n)FOR(j,1,m)if(color[i][j]==-1)
        {
            dfs(i,j,a[i][j]&1) ;    
        }
        FOR(i,1,n)FOR(j,1,m)
        {
            if(a[i][j])
            {
                if(a[i-1][j]>=a[i][j]||a[i][j-1]>=a[i][j])return void(cout<<-1<<el) ;
            }
            else
            { 
                a[i][j] = max(a[i-1][j],a[i][j-1])+1; 
                if(color[i][j]==-1)
                {
                    dfs(i,j,a[i][j]&1) ;
                } 
                else if(a[i][j]%2!=color[i][j])++a[i][j] ; 
            }
        }
        ll res = 0; 
        FOR(i,1,n)FOR(j,1,m)res+=a[i][j] ; 
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}