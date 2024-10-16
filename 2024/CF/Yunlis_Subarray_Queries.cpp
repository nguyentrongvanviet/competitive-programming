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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , k , q; 
int a[N] ; 

void doc()
{
    cin>> n >> k >>q ; 
    FOR(i,1,n)cin>>a[i],a[i]-=i ;
}

namespace sub1
{
    int c[N] ;
    struct DL
    {
        int val , sl; 
    } ; 
    struct cmp
    {
        bool operator()( DL a ,  DL b) 
        {   
            return a.sl>b.sl||(a.sl==b.sl&&a.val<b.val) ;
        }
    };
    map<int,int>sl ;
    set<DL,cmp>S ; 
    void add(int val)
    {
        S.erase({val,sl[val]}); 
        S.insert({val,++sl[val]}) ; 
    }
    void del(int val)
    {
        S.erase({val,sl[val]}) ; 
        S.insert({val,--sl[val]}) ; 
    }
    struct Query
    {
        int r , id ; 
    } ; 
    vector<Query> Q[N] ; 
    struct BG
    {
        ll sum  ; 
        int mi , ma ; 
        BG(ll _sum =0,int _mi=n+1,int _ma = -1 )
        {
            sum=_sum ; 
            mi=_mi ; 
            ma=_ma ; 
        }
        friend BG operator + (BG a , BG b )
        {
            return BG(a.sum+b.sum,min(a.mi,b.mi),max(a.ma,b.ma)); 
        }
    } ; 
    BG st[4*N] ;
    ll lazy[4*N] ; 
    ll res[N] ; 
    void dolazy(int id,int l, int r)
    {
        if(lazy[id]==-1)return ; 
        st[id]=BG(lazy[id]*(r-l+1),lazy[id],lazy[id]);
        if(l!=r)
        {
            lazy[id<<1] = lazy[id] ; 
            lazy[id<<1|1] = lazy[id] ; 
        }
        lazy[id] = -1 ;
    } 
    void up(int id, int l, int r, int t, int p , int val)
    {
        dolazy(id,l,r) ; 
        if(r<t||p<l)return; 
        if(t<=l&&r<=p)
        {   
            if(st[id].mi>=val)
            {
                lazy[id] = val ;
                dolazy(id,l,r)  ;
                return  ; 
            }
            if(st[id].ma<=val)return ;
        }   
        int mid = (l+r)>>1 ;
        up(id<<1,l,mid,t,p,val) ;
        up(id<<1|1,mid+1,r,t,p,val) ;
        st[id] = st[id<<1]+st[id<<1|1] ; 
    } 
    ll get(int id, int l ,int r ,int t ,int p)
    {
        dolazy(id,l,r) ;
        if(r<t||p<l)return 0; 
        if(t<=l&&r<=p)return st[id].sum ;
        int mid =(l+r)>>1; 
        return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ;
    }
    void xuly()
    {
        FOR(i,1,n)
        {
            S.insert(DL{a[i],sl[a[i]] = 0}) ; 
        }
        FOR(i,1,k)
        {
            add(a[i]) ; 
        }
        c[1] = k-(*S.begin()).sl;
        FOR(i,k+1,n)
        {
            del(a[i-k]) ;
            add(a[i]) ;
            c[i-k+1] = k-(*S.begin()).sl ; 
        }
        S.clear() ; 
        sl.clear() ;
        FOR(i,1,q)
        {
            int l , r ; cin>>l>>r ;
            Q[l].push_back({r,i}) ;  
        }
        FOR(id,1,4*n)
        {
            lazy[id] = -1 ;
            st[id]=BG() ; 
        }
        FORD(i,n-k+1,1)
        {   
            up(1,1,n,i+1,n-k+1,c[i]) ;
            up(1,1,n,i,i,c[i]) ;
            for(auto [r,id]:Q[i])
            {
                res[id] = get(1,1,n,i,r-k+1) ; 
            }
        }
        FOR(i,1,q)cout<<res[i]<<'\n' ; 
        FOR(i,1,n)Q[i].clear() ; 

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