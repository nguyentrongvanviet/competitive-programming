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
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m;  
int a[N] ; 
struct DL
{
    int y ,color ; 
    DL(){} 
    DL(int y ,int color ):y(y),color(color){} 
}; 
ve<DL> spec[N] ; 
bool ok[4][4] ;
void doc()
{
    cin>> n;  
    FOR(i,1,n)
    {
        cin>>a[i] ; 
    }
    cin>>m ; 
    for(int i=1;i<=m;i++)
    {
        int x ,y,c ; cin>>x>>y>>c ; 
        spec[x].push_back({y,c}) ; 
    }
    for(int color=1;color<=3;color++)for(int move=1;move<=3;move++)
    {
        cin>>ok[color][move] ; 
    }
}

    void add(int &a ,int b)
    {
        a+=b ;
        if(a>=sm)a-=sm ; 
    }
namespace sub1
{
    struct MT
    {
        int n , m ; 
        vector<vector<int>> mt ; 
        MT(int n=0 , int m=0):n(n),m(m)
        {
            mt.resize(n+1,vector<int>(m+1,0)) ; 
        }
        friend MT mul(const MT& a , const MT& b)
        {
            MT c(a.n,b.m) ; 
            for(int i=1;i<=a.n;i++)
            for(int k=1;k<=a.m;k++)
            for(int j=1;j<=b.m;j++)
            {
                add(c.mt[i][j],1ll*a.mt[i][k]*b.mt[k][j]%sm) ; 
            }
            return c ; 
        } 
        friend MT operator *(const MT&a , const MT&b)
        {
            return mul(a,b) ; 
        }
        void operator = (const MT&a)
        {
            n = a.n ; 
            m = a.m ; 
            mt = a.mt ; 
        }
    }; 
    vi operator*(const vector<int>&A , const MT& B)
    {
        // MT A(1,a.size()-1) ; 
        // FOR(i,1,A.m)A.mt[1][i] = a[i] ; 
        // MT res =  A*B ;
        // FOR(i,1,a.size()-1)a[i] = res.mt[1][i] ; 
        // return a ;  
        vector<int> C(A.size(),0) ; 
        FOR(i,1,A.size()-1)
        {
            FOR(j,1,B.m)
            {
                add(C[i],1ll*A[j]*B.mt[j][i]%sm) ; 
            }
        }
        return C ;
    }
    int trans(int x ,int y ,int z)
    {
        return (16*x+4*y+z)+1 ; 
    }
    bool used[4] ; 
    int mex(const vector<int>&a )
    {
        FOR(i,0,3)used[i] = 0 ; 
        for(auto x : a)used[x] = 1;  
        FOR(i,0,3)if(used[i]==0)return i ;
        return 9374783;
    }
    MT mu[31] ;
    MT color_mt[4] ; 
    void POW(vi& x , int len)
    {
        FORD(i,30,0)
        {
            if(len>>i&1)
            {
                x = x*mu[i] ; 
            }
        }
    }
    int f[N][4] ; 
    void xuly()
    {
        FOR(i,1,3)color_mt[i] = MT(64,64) ; 
        FOR(color,1,3)
        { 
            FOR(i,0,3)
            {
                FOR(j,0,3)
                {
                    FOR(k,0,3)
                    {
                        // i , j , k 
                        // j , k , z 
                        vector<int> last = {i,j,k} ;
                        vector<int> value ;  
                        FOR(move,1,3)
                        {
                            if(ok[color][move])
                            {
                                value.push_back(last[last.size()-move]) ; 
                            }
                        }
                        int z = mex(value) ; 
                        color_mt[color].mt[trans(i,j,k)][trans(j,k,z)]++; 
                    } 
                }
            }
        }
        MT B(64,64) ; 
        FOR(color,1,3)
        {
            FOR(i,1,64)FOR(j,1,64)
            {
                B.mt[i][j] += color_mt[color].mt[i][j] ; 
            }
        }  
        mu[0] = B ; 
        FOR(i,1,30)
        {
            mu[i] = mu[i-1]*mu[i-1] ; 
        }
        f[0][0] =1 ; 
        FOR(i,1,n)
        {
            sort(all(spec[i]),[] (const DL& a , const DL& b){return a.y<b.y;}) ; 
        }
        FOR(i,1,n)
        {
            vi A(65,0) ;
            A[trans(3,3,3)] = 1 ; 
            int pre = 0 ; 
            for(auto pt : spec[i])
            {
                POW(A,pt.y-pre-1); 
                A = A*color_mt[pt.color] ; 
                pre=pt.y ;  
            }
            POW(A,a[i]-pre) ; 
            FOR(k,0,3)
            {       
                int cnt = 0 ; 
                FOR(i,0,3)
                {
                    FOR(j,0,3)
                    {
                        add(cnt,A[trans(i,j,k)]) ;  
                    }   
                }
                FOR(pre,0,3)
                {
                    add(f[i][pre^k], 1ll*f[i-1][pre]*cnt%sm);
                }
            }    
        }
        cout<<f[n][0] ; 
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