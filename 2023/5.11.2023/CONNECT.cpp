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
#define        Mask(i)  (1ll<<(i))
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
const int N = 5e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
int a[N][N] ;
void doc()
{
    cin>> n >> m ; 
    FOR(i,1,n)FOR(j,1,m)
    {
        char x; cin>>x; 
        a[i][j] = x-'0' ; 
    }
}

// namespace sub1
// {
//     int cost[N][N] ;
//     int L[N][N] ; 
//     int R[N][N] ;
//     bool in(int x ,int y)
//     {
//         return 1<=x&&x<=n&&1<=y&&y<=m ;
//     }
//     struct DL
//     {
//         int x, y ; 
//         int val; 
//     } ;
//     struct cmpDL
//     {
//         bool operator()(const DL&a, const DL&b)const
//         {
//             return a.val>b.val; 
//         }
//     } ; 
//     void build(int c,int f[N][N])
//     {
//         priority_queue<DL,ve<DL>,cmpDL>q ;
//         FOR(i,1,n)
//         {
//             q.push({i,c,f[i][c]=cost[i][c]});
//         }
//         while(!q.empty())
//         {
//             int x =q.top().x; 
//             int y = q.top().y ;
//             int val =q.top().val; 
//             q.pop();
//             if(f[x][y]<val)continue ;
//             FORN(i,0,4)
//             {
//                 int nx=x+xx[i] ; 
//                 int ny=y+yy[i] ; 
//                 if(!in(nx,ny))continue ;
//                 if(mini(f[nx][ny],val+cost[nx][ny]))
//                 {
//                     q.push({nx,ny,f[nx][ny]}) ; 
//                 }
//             }
//         }
//     } 
//     struct BG
//     {
//         int x, y ; 
//         bool l ,r ;
//         int val; 
//     } ; 
//     struct cmpBG
//     {
//         bool operator()(const BG&a, const BG&b)const
//         {
//             return a.val>b.val; 
//         }
//     } ; 
//     int res = oo; 
//     void dij()
//     {
//         priority_queue<BG,ve<BG>,cmpBG>q; 
//         FOR(j,1,m)
//         {
//             q.push({1,j,0,0,f[1][j][0][0]=cost[1][j]});
//         }
//         while(!q.empty())
//         {
//             int x   = q.top().x ;
//             int y   = q.top().y ;
//             bool l  = q.top().l; 
//             bool r  = q.top().r ;
//             int val = q.top().val;
//             if(val>res)break; 
//             q.pop() ; 
//             if(f[x][y][l][r]<val)continue ;
//             if(l==0&&mini(f[x][y][1][r],val+L[x][y]-cost[x][y]))
//             {
//                 q.push({x,y,1,r,f[x][y][1][r]}) ; 
//             }
//             if(r==0&&mini(f[x][y][l][1],val+R[x][y]-cost[x][y]))
//             {
//                 q.push({x,y,l,1,f[x][y][l][1]}) ; 
//             }
//             FORN(i,0,4)
//             {
//                 int nx = x+xx[i] ;
//                 int ny = y+yy[i] ;    
//                 if(!in(nx,ny))continue ; 
//                 if(mini(f[nx][ny][l][r],f[x][y][l][r]+cost[nx][ny]))
//                 {
//                     q.push({nx,ny,l,r,f[nx][ny][l][r]}); 
//                 }
//             }
//         }
//         FOR(i,1,m)
//         {
//             mini(res,f[n][i][1][1]) ; 
//         }
//     }
//     void solve(int val)
//     {
//         FOR(i,1,n)FOR(j,1,m)
//         {
//             cost[i][j] = abs(a[i][j]-val) ;
//             L[i][j] = R[i][j] = oo ; 
//             FOR(l,0,1)FOR(r,0,1)f[i][j][l][r]=oo ;
//         }
//         build(1,L) ; 
//         build(m,R) ; 
//         dij(); 
//     }
//     void xuly()
//     {
//         FOR(i,0,9)solve(i) ;
//         cout<<res;
//     }
// }

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/
namespace sub2
{
    bool in(int x ,int y)
    {
        return 1<=x&&x<=n&&1<=y&&y<=m ; 
    }
    int cost[N][N] ;
    int L[N][N] , R[N][N] ; 
    int f[N][N][2][2] ; 
    int res = oo ;
    struct DL
    {
        int x , y ; 
    } ; 
    ve<DL>val[9005];
    void build(int f[N][N],int c)
    {
        FOR(i,1,n)
        {
            val[f[i][c] = cost[i][c]].pb({i,c});
        }
        FOR(V,0,9000)
        {
            if(V>res)break;
            while(!val[V].empty())
            {
                int x = val[V].back().x ;
                int y = val[V].back().y ;
                val[V].pk() ; 
                if(f[x][y]<V)continue ;
                FORN(i,0,4)
                {
                    int nx= x+xx[i] ; 
                    int ny= y+yy[i] ; 
                    if(!in(nx,ny))continue ;
                    if(mini(f[nx][ny],V+cost[nx][ny]))
                    {
                        val[f[nx][ny]].pb({nx,ny}) ;
                    }
                }
            }
        }
    }
    struct BG
    {
        int x, y ; 
        bool l , r;  
    } ; 
    ve<BG>VAL[9005] ; 
    void dij()
    {
        FOR(j,1,m)
        {
            f[1][j][0][0] = cost[1][j] ;  
            VAL[f[1][j][0][0] = cost[1][j]].pb({1,j,0,0});
        }
        FOR(V,0,9000)
        {
            if(V>res)break;
            while(!VAL[V].empty())
            {
                int x = VAL[V].back().x ; 
                int y = VAL[V].back().y ;
                bool l = VAL[V].back().l ;
                bool r = VAL[V].back().r ; 
                VAL[V].pk() ; 
                if(f[x][y][l][r]<V)continue ;
                if(l==0&&mini(f[x][y][1][r],V-cost[x][y]+L[x][y]))
                {   
                    VAL[f[x][y][1][r]].pb({x,y,1,r}) ; 
                }
                if(r==0&&mini(f[x][y][l][1],V-cost[x][y]+R[x][y]))
                {       
                    VAL[f[x][y][l][1]].pb({x,y,l,1}) ; 
                }   
                FORN(i,0,4)
                {
                    int nx = x+xx[i] ; 
                    int ny = y+yy[i] ; 
                    if(mini(f[nx][ny][l][r],V+cost[nx][ny]))
                    {
                        VAL[V+cost[nx][ny]].pb({nx,ny,l,r}) ;
                    }
                }
            }
        }
        FOR(i,1,m)
        {
            mini(res,f[n][i][1][1]) ;
        }
    }   

    void solve(int val)
    {
        FOR(i,1,n)FOR(j,1,m)
        {
            cost[i][j] = abs(val-a[i][j]) ;
            L[i][j] = oo ; 
            R[i][j] = oo ; 
            FOR(l,0,1)FOR(r,0,1)f[i][j][l][r] = oo; 
        }
        build(L,1) ; 
        build(R,m) ;
        dij() ; 
    }
    void xuly()
    {   
        FOR(i,0,9)
        {
            solve(i) ;
        }
        cout<<res;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}