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

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , q ; 
struct Edge
{
    int u ,v ,c ;
    bool operator<(const Edge&a)const
    {
        return c<a.c; 
    }
} ; 
Edge E[N] ;
struct Query
{
    int id ; 
    int TYPE ;
    int u , v ,c; 
    bool operator<(const Query&a)const
    {
        return c<a.c; 
    }
} ; 
Query Q[N] ; 
vi g[N] ; 

int in[N] , out[N] ;
int h[N] ; 
int P[N][LO+1] ; 
int bit1[N] ,bit2[N] ; 
int lca(int u ,int v)
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
            u=nu ; 
            v=nv ; 
        }
    }
    return P[u][0] ; 
}
void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n-1)
    {
        int u ,v,c ; cin>>u>>v>>c; 
        E[i] = {u,v,c} ; 
        g[u].pb(v); 
        g[v].pb(u);
    }
}

namespace sub1
{
    void up(int idx, int val,int bit[])
    {
        for(int i=idx;i<=2*n;i+=i&-i)bit[i]+=val;
    }
    int get(int idx ,int bit[] )
    {
        int ans =0 ; 
        for(int i=idx;i;i-=i&-i)ans+=bit[i] ;
        return ans ;
    }
    int get(int l ,int r,int bit[])
    {
        return get(r,bit)-get(l-1,bit) ;
    }
    int tt = 0 ;
    void dfs(int u ,int p)
    {
        in[u] = ++tt; 
        for(auto v: g[u])if(v!=p)
        {
            P[v][0] = u ; 
            h[v] = h[u]+1 ;
            dfs(v,u) ; 
        }
        out[u]=++tt ;
    }
    int res[N] ;
    void xuly()
    {
        dfs(1,0) ; 
        FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] ; 
        FOR(i,1,q)
        {   
            char TYPE ; cin>>TYPE;
            if(TYPE=='P')
            {
                int u ,v , c ; cin>>u>>v>>c; 
                Q[i]= {i,1,u,v,c};
            }
            else
            {
                int k , c; cin>>k>>c ;
                Q[i] = {i,2,E[k].u,E[k].v,c};
            }
        }
        sort(E+1,E+n) ; 
        sort(Q+1,Q+q+1) ;
        int it= 1 ;
        FOR(i,1,q)
        {
            while(it<=n-1&&E[it].c<=Q[i].c)
            {
                int u =E[it].u ; 
                int v= E[it].v ; 
                if(h[u]>h[v])swap(u,v) ;
                up(in[v],1,bit1);
                up(out[v],-1,bit1) ;
                up(in[v],1,bit2) ;
                ++it ;
            }       
            int u= Q[i].u ;
            int v= Q[i].v ;
            if(Q[i].TYPE==1)
            {
                if(h[u]>h[v])swap(u,v) ;
                int c= lca(u,v) ;
                res[Q[i].id] = get(in[u],bit1)+get(in[v],bit1)-2*get(in[c],bit1);
            }
            else
            {   
                if(h[v]>h[u])res[Q[i].id] = get(in[v]+1,out[v]-1,bit2);
                else res[Q[i].id] = get(2*n,bit2)-get(in[u]+1,out[u]-1,bit2);
            }
        }   
        FOR(i,1,q)cout<<res[i]<<el;
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