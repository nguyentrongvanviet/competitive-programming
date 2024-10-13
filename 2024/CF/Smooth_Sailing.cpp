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

int xx[] = {0,0,-1,0,1,-1,-1,1,1}; 
int yy[] = {0,-1,0,1,0,-1,1,1,-1};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ,q ; 
ve<ve<char>>grid ;
pii island ;
void doc()
{
    cin >> n >>m>>q;
    grid.resize(n+2,ve<char>(m+1)) ; 
    FOR(i,1,n)FOR(j,1,m)
    {
        cin>>grid[i][j] ;
        if(grid[i][j]=='#')
        {
            island = mp(i,j) ; 
        }
    }
    
}

namespace sub1
{
    ve<vi>f;
    bool IN(int x ,int y)
    {
        return 1<=x&&x<=n&&1<=y&&y<=m ; 
    }
    void spread() 
    {
        f.resize(n+1,vi(m+1,-1)) ; 
        // bool IN = [](int x ,int y ){
        //     return 1<=x&&x<=n&&1<=y&&y<=m; 
        // };
        queue<pii>q ; 
        FOR(i,1,n)FOR(j,1,m)if(grid[i][j]=='v')
        {
            f[i][j] = 0 ;
            q.push(mp(i,j)) ;
        }
        while(!q.empty())
        {
            auto [x,y] = q.front() ; 
            q.pop() ;
            FOR(i,1,4)
            {
                int nx = x+xx[i] ;
                int ny = y+yy[i] ; 
                if(!IN(nx,ny)||f[nx][ny]!=-1)continue ; 
                f[nx][ny] = f[x][y]+1 ;
                q.push(mp(nx,ny)); 
            }
        }
    }
    ve<ve<bool>> dd ; 
    void dfs(int x ,int y,int val)
    {
        dd[x][y] = 1; 
        FOR(i,1,4)
        {
            int nx = x+xx[i] ;
            int ny = y+yy[i] ; 
            if(!IN(nx,ny)||grid[nx][ny]=='#'||dd[nx][ny]||f[nx][ny]<val)continue ;
            dfs(nx,ny,val);  
        }
    }
    void CK(int x, int y , bool& ok)
    {   
        dd[x][y] = 1 ; 
        if(x==1||y==1||x==n||y==m)
        {
            ok = 0;
            return ; 
        }
        FOR(i,1,8)
        {
            int nx = x+xx[i] ;
            int ny = y+yy[i] ; 
            if(!IN(nx,ny)||dd[nx][ny])continue ; 
            CK(nx,ny,ok) ; 
        }
    }
    bool check(int x, int y ,int val)
    {
        dd = ve<ve<bool>>(n+1,ve<bool>(m+1,0)) ; 
        dfs(x,y,val) ; 
        bool ok = 1 ; 
        CK(island.fi,island.se,ok) ; 
        return ok ;
    }
    void xuly()
    {
        spread() ; 
        int MA = 0 ;
        FOR(i,1,n)
        {
            maxi(MA,*max_element(all(f[i]))) ; 
        }
        while(q--)
        {
            int x, y ; 
            cin>> x>> y ; 
            int l = 0 ;
            int r = f[x][y] ;  
            int ans = 0 ; 
            while(l<=r)
            {
                int mid = (l+r)>>1 ;
                if(check(x,y,mid)) ans=mid,l=mid+1;
                else r=mid-1 ;
            }
            cout<<ans<<el;
        }
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