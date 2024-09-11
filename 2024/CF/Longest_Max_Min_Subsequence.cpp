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
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n; 
int a[N] ; 
int last[N] ;
struct DL
{
    int mi, pos_mi , ma , pos_ma ; 
    DL(int _mi = 1e9  ,int _pos_mi=0, int _ma=0 ,int _pos_ma = 0 ) 
    {
        mi=_mi ; 
        pos_mi = _pos_mi ; 
        ma=_ma ; 
        pos_ma = _pos_ma ; 
    } 
    friend DL operator + (DL a , DL b )
    {
        int mi = min(a.mi,b.mi) ;
        int pos_mi = a.pos_mi ; 
        if(mi!=a.mi)pos_mi=b.pos_mi ; 

        int ma = max(a.ma,b.ma) ;
        int pos_ma = a.pos_ma ; 
        if(ma!=a.ma)pos_ma=b.pos_ma ; 
        return DL(mi,pos_mi,ma,pos_ma) ; 
    }
} ;
DL st[4*N] ; 
void build(int id, int l ,int r )
{
    if(l==r)
    {
        st[id] = DL(a[l],l,a[l],l) ; 
        return ; 
    }
    int mid =(l+r)>>1 ; 
    build(id<<1,l,mid) ; 
    build(id<<1|1,mid+1,r) ; 
    st[id] = st[id<<1]+st[id<<1|1] ; 
}
void del(int id, int l ,int r ,int pos)
{
    if(r<pos||pos<l)return ; 
    if(l==r)
    {
        st[id] = DL() ; 
        return ; 
    }
    int mid =(l+r)>>1 ;
    del(id<<1,l,mid,pos) ; 
    del(id<<1|1,mid+1,r,pos) ;
    st[id] = st[id<<1]+st[id<<1|1] ; 
}
DL get(int id, int l ,int r ,int t, int p)
{
    if(r<t||p<l)return DL() ; 
    if(t<=l&&r<=p)return st[id] ; 
    int mid = (l+r)>>1 ;
    return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ; 
}
vi P[N] ; 
void doc()
{
    cin>> n; 
    for(int i=1;i<=n;i++)
    {
        cin>>a[i] ;
        last[a[i]] = i ;  
        P[a[i]].push_back(i) ; 
    }
    build(1,1,n) ;
    set<int>s ; 
    for(int i=1;i<=n;i++)
    {
        s.insert(last[a[i]]) ; 
    }
    int deg = -1 ; 
    vector<int>res ; 
    int pos = 1 ; 
    while(!s.empty())
    {
        int t = *s.begin() ; 
        int value = a[t] ; 
        while(pos<=t)
        {
            DL tmp = get(1,1,n,pos,t) ;
            // cout<<pos<<" "<<tmp.ma<<" "<<tmp.mi<<el;
            if(deg<0)
            {
                res.push_back(tmp.ma) ;
                pos=tmp.pos_ma+1 ; 
                s.erase(last[tmp.ma]) ; 
                for(auto x : P[tmp.ma])  
                {
                    del(1,1,n,x) ; 
                }
            }
            else
            {
                res.push_back(tmp.mi) ;
                pos = tmp.pos_mi+1 ;
                s.erase(last[tmp.mi]) ;      
                for(auto x : P[tmp.mi])
                {
                    del(1,1,n,x) ; 
                } 
            }
            deg=-deg ; 
            if(res.back()==value)break;
        }
    }
    cout<<res.size()<<el;
    prv(res) ;
    for(int i=1;i<=n;i++)P[i].clear() ; 
}

namespace sub1
{
    void xuly()
    {

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