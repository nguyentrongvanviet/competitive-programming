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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n; 
struct DL
{
    int Money , Size ;
    int id ;     
    bool operator<(const DL&a)const
    {
        return Size<a.Size ; 
    }
}a[N] ;
int m ;  
map<int,ve<pii>> affordable;
map<int,pii> ma1,ma2; 
void doc()
{
    cin>> n; 
    FOR(i,1,n)
    {
        int c, s ; cin>>c>>s ;
        a[i] = {c,s,i} ; 
    }
    sort(a+1,a+n+1) ; 
    cin>> m; 
    FOR(i,1,m)
    {
        int money , Size ; cin>>money >> Size ;
        affordable[Size].pb({money,i}) ; 
    }
    for(auto [x,y]:affordable)
    {
        sort(all(y)) ; 
        ma1[x] = y.back() ; 
        if(y.size()>1)ma2[x] = y[y.size()-2] ;
    }
}

namespace sub1
{
    int f[N][2] ; 
    int canget(int money , int Size)
    {
        if(ma1.count(Size)==0)return 0 ;
        if(ma2[Size].fi>=money)return 2 ;
        if(ma1[Size].fi>=money)return 1 ; 
        return 0 ; 
    }
    struct TT
    {
        int pos,ok,x ; 
    }; 
    int res[N] ; 
    int pre[N][2] ; 
    int get(int money , int Size)
    {
        if(ma1.count(Size)==0)return 0 ;
        if(ma2[Size].fi>=money)return ma2[Size].se ;
        if(ma1[Size].fi>=money)return ma1[Size].se ; 
        return 0 ;
    }
    void xuly()
    {
        FOR(i,1,n)
        {
            f[i][0] = -1 ; 
            f[i][1] = -1 ; 
        }
        a[0] = {-12831,173} ; 
        FOR(i,1,n)
        {
            if(maxi(f[i][0],f[i-1][0]))
            {
                pre[i][0] = 1 ; 
            }
            if(maxi(f[i][0],f[i-1][1]))
            {
                pre[i][0] = 2 ; 
            }
            if(maxi(f[i][1],f[i-1][0]+(canget(a[i].Money,a[i].Size)?a[i].Money:0)))
            {
                pre[i][1] = 3; 
            }
            if(maxi(f[i][1],f[i-1][1]+(canget(a[i].Money,a[i].Size)?a[i].Money:0)))
            {
                pre[i][1] = 4 ; 
            }
            if(a[i-1].Size+1!=a[i].Size)
            {
                if(maxi(f[i][0],f[i-1][0]+(canget(a[i].Money,a[i].Size-1)?a[i].Money:0)))
                {
                    pre[i][0] = 5 ; 
                }
                if(maxi(f[i][0],f[i-1][1]+(canget(a[i].Money,a[i].Size-1)?a[i].Money:0)))
                {
                    pre[i][0] = 6 ; 
                }
            }
            else
            {
                if(maxi(f[i][0],f[i-1][0]+(canget(a[i].Money,a[i].Size-1)?a[i].Money:0)))
                {
                    pre[i][0] = 7 ; 
                }
                int x = canget(a[i-1].Money,a[i].Size-1) ; 
                int y = canget(a[i].Money,a[i].Size-1) ; 
                if(x&&y&&!(x==1&&y==1))
                {
                    if(maxi(f[i][0] , f[i-1][1]+a[i].Money)) 
                    {
                        pre[i][0] = 8 ;
                    } 
                }
            }
        }
        cout<<max(f[n][0],f[n][1])<<el;
        int tt = 0 ; 
        if(f[n][0]<f[n][1]) tt = 1 ; 
        int dont = 0 ; 
        FORD(i,n,1)
        {
            int type = pre[i][tt] ; 
            if(type==1)
            {
                tt = 0 ; 
            }
            else if(type==2)
            {
                tt = 1 ; 
            }
            else if(type==3)
            {
                tt = 0 ; 
                if(dont==0)res[a[i].id] = get(a[i].Money,a[i].Size) ; 
            }
            else if (type==4)
            {
                tt = 1 ; 
                if(dont==0)res[a[i].id] = get(a[i].Money,a[i].Size) ;
            }
            else if(type==5)
            {
                tt = 0  ; 
                res[a[i].id] = get(a[i].Money,a[i].Size-1) ;
            }
            else if(type==6)
            {
                tt = 1 ; 
                res[a[i].id] = get(a[i].Money,a[i].Size-1) ;
            }
            else if(type==7)
            {
                tt = 0 ; 
                res[a[i].id] = get(a[i].Money,a[i].Size-1) ;
            }   
            else{
                tt = 1 ; 
                res[a[i].id] = get(a[i].Money,a[i].Size-1) ;
                res[a[i-1].id] = get(a[i-1].Money,a[i].Size-1) ;
                if(res[a[i].id]==res[a[i-1].id])
                {
                    res[a[i].id]  = ma1[a[i].Size-1].se ;
                }
                dont =1 ; 
            }
            dont = 0 ; 
        }
        int cnt = 0 ; 
        FOR(i,1,n)
        {
            if(res[i])
            {
                cnt++ ; 
            }
        }
        cout<<cnt<<el; 
        FOR(i,1,n)
        {
            if(res[i])
            {
                cout<<res[i]<<" "<<i<<el;
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