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
const int N = 3e5+5 , oo = 2e9 , LO = 20 , CH = 26 ; 

int n , m ,q ; 
ve<ve<char>>grid;

void doc()
{
    cin>> n >>m >>q ;
    grid.resize(n+1,ve<char>(m+1,0)) ; 
    FOR(i,1,n)FOR(j,1,m)
    {
        cin>>grid[i][j] ; 
    }
}

namespace sub1
{
    ve<vi>dis;
    bool in(int x ,int y)
    {
        return 1<=x&&x<=n&&1<=y&&y<=m ; 
    } 
    void bfs()
    {
        dis.resize(n+1,vi(m+1,-1)) ; 
        queue<pii>q ; 
        FOR(i,1,n)FOR(j,1,m)
        {
            if(grid[i][j]=='v')
            {
                dis[i][j] = 0 ; 
                q.push(mp(i,j)) ; 
            }
        }
        while(!q.empty())
        {
            auto [x,y] = q.front() ; 
            q.pop() ; 
            FOR(i,1,4)
            {
                int nx =x+xx[i] ;
                int ny =y+yy[i] ; 
                if(!in(nx,ny)||dis[nx][ny]!=-1)continue ; 
                dis[nx][ny] = dis[x][y]+1 ;
                q.push(mp(nx,ny)) ; 
            }
        }
    }
    int Node(int x, int y ,int ok )
    {
        return ((x-1)*m+y) + (ok?n*m:0) ; 
    }
    struct Edge
    {
        int u ,v ,w ; 
        bool operator<(const Edge&a)
        {
            return w>a.w ; 
        }
    }E[N*4] ;
    int pa[N*8] ; 
    int goc(int u)
    {
        return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
    }
    int node  ; 
    int res[8*N] ; 
    vi g[8*N] ; 
    void hop(int u ,int v,int w )
    {
        int chau = goc(u) ;
        int chav = goc(v) ; 
        ++node ;
        pa[node] = pa[chau] = pa[chav] = node ; 
        res[node] = w ; 
        g[node].pb(chau) ; 
        if(chau!=chav)
        {
            g[node].pb(chav) ;
        }
    }
    int P[8*N][LO+1] ; 
    int h[8*N] ; 
    void dfs(int u)
    {
        for(auto v :g[u])
        {
            P[v][0] = u ;
            FOR(j,1,LO)P[v][j]=P[P[v][j-1]][j-1] ; 
            h[v] = h[u]+1 ;  
            dfs(v) ;
        }
    }
    int lca(int u, int v)
    {
        if(h[u]<h[v])swap(u,v) ;
        FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])u=P[u][i] ; 
        if(u==v)return u ; 
        FORD(i,LO,0)
        {
            int nu = P[u][i] ;
            int nv = P[v][i] ;
            if(nu!=nv)
            {
                u = nu ; 
                v = nv ; 
            }
        }
        return P[u][0] ; 
    }
    void xuly()
    {
        int island_x ,island_y ; 
        FOR(i,1,n)FOR(j,1,m)
        {
            if(grid[i][j]=='#')
            {
                island_x = i ; 
                island_y = j ; 
            }
        }
        bfs() ; 
        int edge = 0; 
        FOR(x,1,n)FOR(y,1,m)
        {
            FOR(i,1,2)
            {
                int nx =x+xx[i] ;
                int ny =y+yy[i] ; 
                if(!in(nx,ny)||grid[x][y]=='#'||grid[nx][ny]=='#')continue ;
                int d= (i==2&&x==island_x&&y>island_y) ;
                FOR(D,0,1)E[++edge] = {Node(x,y,D),Node(nx,ny,D^d),min(dis[x][y],dis[nx][ny])} ; 
            }
        }
        node = 2*n*m ; 
        sort(E+1,E+edge+1) ; 
        for(int i=1;i<=2*n*m;i++)
        {
            pa[i] = i; 
        }
        FOR(i,1,edge)
        {
            hop(E[i].u,E[i].v,E[i].w) ; 
            if(E[i].w<3)continue ;
        }
        dfs(node) ; 
        while(q--)
        {
            int x , y ; 
            cin>> x>>y ; 
            int C = lca(Node(x,y,1),Node(x,y,0)) ; 
            cout<<res[C]<<el; 
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