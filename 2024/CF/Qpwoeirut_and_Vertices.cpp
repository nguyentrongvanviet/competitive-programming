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
const int N = 6e5+5 ;

int numnode , numedge , numquery ;
struct Edge
{
    int u ,v ; 
}edge[N] ; 
void doc()
{    
    cin>> numnode >> numedge >> numquery ; 
    FOR(i,1,numedge)
    {
        cin>>edge[i].u>>edge[i].v ; 
    }
}

namespace sub1
{
    int pa[N] ;
    vector<int>g[N] ; 
    int res[N] ; 
    int root(int u )
    {
        return pa[u] == u ? u : pa[u] = root(pa[u]) ; 
    }
    void merge(int u ,int v,int id )
    {
        int chau = root(u) ; 
        int chav = root(v) ; 
        numnode++ ;
        pa[numnode] = numnode; 
        res[numnode] = id; 
        pa[chau] = pa[chav] = numnode ; 
        g[numnode].push_back(chau) ; 
        if(chau!=chav)g[numnode].push_back(chav) ; 
    }
    int time_dfs = 0 , tt=0 ; 
    int in[N], at[N] , a[N] , pos[N] ; 
    void dfs(int u )
    {
        in[u]=++time_dfs ; 
        at[time_dfs] = u ;

        a[++tt] = time_dfs ;  
        pos[time_dfs] = tt ;
        for(auto v:g[u])
        {
            dfs(v) ;
            a[++tt] = in[u] ; 
        }
    }
    struct DL
    {
        int mi , ma ;
        DL(int _mi = 0 ,int _ma = 0)
        {
            mi = _mi ; 
            ma = _ma ; 
        }
        friend DL operator + (DL a , DL b)
        {
            return DL(min(a.mi,b.mi),max(a.ma,b.ma)) ; 
        }
    } ; 
    struct RMQ 
    {
        vector<vector<DL>>st ; 
        int n ; 
        int LO ; 
        RMQ(int *a , int n )
        {
            LO = lg(n) ; 
            st.resize(n+1,vector<DL>(LO+1)) ;
            FOR(i,1,n)
            {
                st[i][0] = {a[i],a[i]} ;
            }
            FOR(j,1,LO)
            {
                FOR(i,1,n-(1<<j)+1)st[i][j] = st[i][j-1] + st[i+(1<<j-1)][j-1] ;
            }
        }
        int get_min(int l, int r)
        {
            int k = lg(r-l+1) ; 
            return min(st[l][k].mi,st[r-(1<<k)+1][k].mi) ;
        }
        int get_max(int l ,int r )
        {
            int k = lg(r-l+1) ;
            return max(st[l][k].ma,st[r-(1<<k)+1][k].ma) ; 
        }
    };
    void xuly() 
    {
        FOR(i,1,numnode) pa[i] = i ; 
        FOR(i,1,numedge)
        {
            int u =edge[i].u ; 
            int v =edge[i].v ;
            merge(u,v,i) ; 
        }
        dfs(numnode) ;
        RMQ IN=RMQ(in,numnode) ;
        RMQ LCA_A=RMQ(a,tt) ;
        // prt(in,numnode)
        // prt(a,tt)
        FOR(i,1,numquery)
        {
            int l, r ; 
            cin>> l >>r ; 
            int L = pos[IN.get_min(l,r)] ;
            int R = pos[IN.get_max(l,r)] ;
            // cout<<L<<" "<<R<<el;
            // cout<<LCA_A.get_min(L,R)<<el;
            cout<<res[at[LCA_A.get_min(L,R)]]<<" ";
            // cout<<at[LCA_A.get_min(L,R)]<<" ";
        }
        cout<<'\n';
        time_dfs = tt = 0;  
        FOR(i,1,numnode)
        {
            res[i] = 0 ;
            g[i].clear() ; 
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