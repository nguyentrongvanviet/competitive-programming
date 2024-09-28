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
const int N = 5e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , q ; 
vi g[N] ;
int dd[N] ; 
int a[N] ; 
struct Edge
{
    int u ,v ;
}E[N] ;
struct Query
{
    int type , u ; 
}Q[N] ;
void doc()
{
    cin>> n >> m >> q; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,m)
    {
        cin>>E[i].u>>E[i].v ;
    }
    FOR(i,1,q)
    {
        cin>>Q[i].type>>Q[i].u ; 
        if(Q[i].type==2)dd[Q[i].u] = 1;   
    }
}

namespace sub1
{
    int pa[N] ;
    int goc(int u )
    {
        return pa[u]==u ? u:pa[u]=goc(pa[u]) ; 
    }
    void hop(int u ,int v)
    {
        ++n ; 
        pa[n] = n ; 
        int chau = goc(u) ; 
        int chav = goc(v) ; 
        pa[chau] = pa[chav] = n ; 
        g[n].pb(chau) ; 
        if(chau!=chav)
        {
            g[n].push_back(chav); 
        }
    }
    int tt = 0 ;
    int in[N] , out[N];
    int at[N] ;  
    void dfs(int u )
    {
        // cout<<u<<el;
        in[u] = ++tt ; 
        at[tt] = u ; 
        for(auto v :g[u])
        {
            dfs(v) ; 
        }
        out[u] = tt ; 
    }
    int res[N] ;
    struct DL
    {
        int ma , pos  ;
        friend DL operator+(DL a, DL b)
        {
            if(a.ma>b.ma)return a ; 
            return b ;
        } 
    }st[4*N] ; 
    void build(int id ,int l , int r )
    {
        if(l==r)
        {
            st[id] = {a[at[l]],l} ;
            return ; 
        }
        int mid =(l+r)>>1 ;
        build(id<<1,l,mid) ; 
        build(id<<1|1,mid+1,r) ; 
        st[id] = st[id<<1]+st[id<<1|1] ; 
    }
    DL get(int id , int l ,int r ,int t ,int p)
    {
        if(t<=l&&r<=p)return st[id] ;
        if(r<t||p<l)return {-129371,l} ; 
        int mid =(l+r)>>1 ;
        return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ; 
    }
    void del(int id ,int l ,int r ,int pos)
    {
        if(r<pos||pos<l)return  ;
        if(l==r)
        {
            st[id] ={0,l} ;
            return ; 
        }
        int mid =(l+r)>>1; 
        del(id<<1,l,mid,pos) ;
        del(id<<1|1,mid+1,r,pos) ; 
        st[id] = st[id<<1]+st[id<<1|1] ; 
    }
    void xuly()
    {
        FOR(i,1,n)
        {
            pa[i] = i ; 
        }
        FOR(i,1,m)if(dd[i]==0)
        {
            hop(E[i].u,E[i].v) ; 
        }
        FORD(i,q,1)
        {
            if(Q[i].type==1)
            {
                res[i] = goc(Q[i].u); 
            }
            else
            {   
                hop(E[Q[i].u].u,E[Q[i].u].v) ;                 
            }
        }
        FORD(i,n,1)if(in[i]==0)dfs(i) ;
        build(1,1,n) ;  
        // FOR(i,1,n)cout<<in[i]<<" "<<out[i]<<el;
        FOR(i,1,q)if(Q[i].type==1)
        {
            DL ans = get(1,1,n,in[res[i]],out[res[i]]) ;
            cout<<ans.ma<<el; 
            del(1,1,n,ans.pos) ; 
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