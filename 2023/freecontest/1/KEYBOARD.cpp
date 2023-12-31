/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "KEYBOARD"
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
const int N = 70+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ; 
char a[N][N] ;
char b[N][N] ;
int vowel[256]; 
int tot = 0 ; 
void doc()
{
    cin>> n >> m ;
    vowel['u'] = vowel['e'] = vowel['o'] = vowel['a'] = vowel['i'] = vowel['y'] = 1 ;  
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j],tot+=vowel[(int)a[i][j]] ; 
    FOR(i,1,n)FOR(j,1,m)cin>>b[i][j] ; 
}

namespace sub1
{
    int can = 0 ;
    char C[] = {'-','|','-','|'}; 
    bool in(int x , int y)
    {
        return 1<=x && x<=n && 1<=y&&y<=m ; 

    }
    int f[N][N] , ma[N][N] ; 
    int dd[N][N] ;
    bool dfs(int x ,int y)
    {
        bool ok = vowel[(int)a[x][y]] ; 
        dd[x][y] = 1 ;
        can+=ok ;
        FORN(i,0,4)
        {
            int nx= x+xx[i] ; 
            int ny= y+yy[i] ; 
            int dx = nx+xx[i] ; 
            int dy = ny+yy[i] ; 
            if(in(dx,dy) && dd[dx][dy]==0 && (b[nx][ny]==C[i]))
            {
                if(dfs(dx,dy))
                {
                    f[x][y] += f[dx][dy]+1;  
                    maxi(ma[x][y],ma[dx][dy]+1) ;
                    ok = 1 ; 
                }
            }
        }
        return ok ; 
    }
    void xuly()
    {
        FOR(i,1,n)FOR(j,1,m)
        {
            if(b[i][j]=='.')
            {
                dfs(i,j) ; 
                if(can<tot)return void(cout<<"NIE"<<el) ; 
                return void(cout<<2*f[i][j]-ma[i][j]<<el) ;
            }
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