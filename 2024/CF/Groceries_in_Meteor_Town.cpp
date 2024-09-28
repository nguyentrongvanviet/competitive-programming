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
const int N = 12e5+5 , oo = 2e9 , LO = 20 , CH = 26 ; 

int numnode, numquery ;
struct Edge
{
    int u ,v ,w ;
    bool operator<(const Edge&a)const
    {
        return w<a.w ; 
    }
}E[N] ; 
void doc()
{
    cin>>numnode>>numquery ;
    FOR(i,1,numnode-1)
    {
        int u ,v ,w;cin>> u >>v>>w;
        E[i] = {u,v,w} ; 
    }
}

namespace sub1
{
    int pa[N] ; 
    vi g[N] ; 
    int res[N] ; 
    int root(int u)
    {
        return pa[u] == u ? u : pa[u] = root(pa[u]) ; 
    }
    void merge(int u ,int v, int w )
    {
        int chau = root(u) ; 
        int chav = root(v) ; 
        ++numnode ; 
        res[numnode] = w ; 
        pa[numnode] = pa[chau] = pa[chav] = numnode; 
        g[numnode].push_back(chau) ; 
        g[numnode].push_back(chav) ; 

    }
    int time_dfs = 0 , tt = 0 ; 
    int a[N] , in[N] , at[N] , pos[N]; 
    void dfs(int u)
    {
        ++time_dfs ; 
        in[u] = time_dfs ; 
        at[time_dfs] = u ;
        a[++tt] = in[u] ; 
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
        DL(int _mi = oo ,int _ma = 0 )
        {
            mi = _mi ; 
            ma = _ma ; 
        }
        friend DL operator +(DL a , DL b)
        {
            return DL(min(a.mi,b.mi),max(a.ma,b.ma)) ;
        }
    } ; 
    struct IT
    {
        vector<DL>value,st ; 
        vector<int>lazy; 
        void build(int id, int l ,int r ,int *a )
        {
            if(l==r)
            {
                value[id] = {a[l],a[l]} ; 
                return ; 
            }
            int mid =(l+r)>>1; 
            build(id<<1,l,mid,a) ; 
            build(id<<1|1,mid+1,r,a) ; 
            value[id] = value[id<<1]+value[id<<1|1] ; 
        }
        IT(int *a ,int n)
        {   
            value.resize(4*n+1) ; 
            st.resize(4*n+1) ; 
            lazy.resize(4*n+1,-1) ;  
            build(1,1,n,a) ; 
        }
        void dolazy(int id , int l, int r)
        {
            if(lazy[id]==-1)return ; 
            if(lazy[id]==1)st[id] = value[id] ; 
            else st[id] = DL() ; 
            if(l!=r)
            {
                lazy[id<<1] = lazy[id] ;
                lazy[id<<1|1] = lazy[id]; 
            }
            lazy[id] = -1 ; 
        }
        void up(int id , int l, int r ,int t ,int p ,int ok)
        {
            dolazy(id,l,r) ; 
            if(r<t||p<l)return ; 
            if(t<=l&&r<=p)
            {
                lazy[id] = ok ; 
                dolazy(id,l,r) ;
                return ; 
            }
            int mid = (l+r)>>1 ;
            up(id<<1,l,mid,t,p,ok) ;
            up(id<<1|1,mid+1,r,t,p,ok) ; 
            st[id] = st[id<<1]+st[id<<1|1] ; 
        }
        DL get(int id ,int l ,int r ,int t , int p)
        {
            dolazy(id,l,r) ; 
            if(t<=l&&r<=p)return st[id] ; 
            if(r<t||p<l)return DL() ; 
            int mid =(l+r)>>1 ;
            return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ; 
        }
    } ;
    int st[N][LO+1] ; 
    void build_rmq()
    {
        FOR(i,1,tt)st[i][0]=a[i] ; 
        FOR(j,1,LO)FOR(i,1,tt-(1<<j)+1)st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
    int get(int l , int r )
    {
        int k = lg(r-l+1) ; 
        return min(st[l][k],st[r-(1<<k)+1][k]);
    }
    void xuly()
    {
        sort(E+1,E+numnode) ;
        FOR(i,1,numnode)pa[i] = i ; 
        int n = numnode-1 ; 
        FOR(i,1,n)
        {
            merge(E[i].u,E[i].v,E[i].w) ;
        } 
        dfs(numnode) ; 
        IT ST = IT(in,numnode) ; 
        build_rmq() ; 
        FOR(i,1,numquery)
        {
            int type ; cin>> type ; 
            if(type==1||type==2)
            {
                int l, r ; cin>> l >>r ; 
                type%=2 ; 
                ST.up(1,1,numnode,l,r,type) ; 
            }
            else
            {
                int u ; cin>> u ; 
                DL tmp = ST.st[1] ; 
                if(tmp.mi==oo||(tmp.mi==tmp.ma&&tmp.mi==in[u]))
                {
                    cout<<-1<<el ; 
                    continue ;
                }
                mini(tmp.mi,in[u]) ; 
                maxi(tmp.ma,in[u]) ; 
                int c = at[get(pos[tmp.mi],pos[tmp.ma])] ; 
                cout<<res[c]<<el; 
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