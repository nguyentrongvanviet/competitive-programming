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
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n; 
struct pt
{
    ll x ,y ;
    pt(ll _x=0 , ll _y= 0)
    {
        x=_x,y=_y ;
    }
    pt operator - (pt a )
    {
        return pt{x-a.x,y-a.y} ;
    }
    ll operator * (pt a )
    {
        return x*a.y-y*a.x ;
    }
} ;
ve<pt> a ;

#define eb emplace_back 
void doc()
{
    cin>> n; 
    FOR(i,1,n)
    {
        ll x,y ; cin>>x>>y;
        a.eb(x,y) ;
    }
}

namespace sub1
{
    bool cmp1(pt a , pt b )
    {
        return a.y<b.y||(a.y==b.y&&a.x<b.x) ; 
    }    
    pt goc ; 
    db dis(pt a , pt b)
    {
        return sqrt(sq(a.x-b.x)+sq(a.y-b.y)) ; 
    }
    ll ccw(pt a, pt b , pt c)
    {
        return (b-a)*(c-b) ; 
    }
    bool cmp2(pt a, pt b)
    {   
        if(ccw(goc,a,b)==0)
        {
            return dis(goc,a)<dis(goc,b) ; 
        }
        return ccw(goc,a,b)>0 ; 
    }
    ve<pt> convexhull(ve<pt>& P )
    {
        ve<pt>hull ; 
        sort(all(P),cmp1) ;
        goc = P[0] ;
        sort(P.begin()+1,P.end(),cmp2) ; 
        P.pb(goc) ;   
        FORN(i,0,SZ(P))
        {
            while(SZ(hull)>=2 && ccw(hull[SZ(hull)-2],hull.back(),P[i])<=0)
            {
                hull.pk() ;
            }
            hull.pb(P[i]) ; 
        }
        hull.pk() ;
        return hull; 
    }
    void xuly()
    {
        ve<pt>res= convexhull(a) ;
        cout<<SZ(res)<<el; 
        ll area = 0 ; 
        FORN(i,1,SZ(res))
        {
            area+=res[i-1]*res[i]  ; 
        }
        area+=res.back()*res[0] ;
        area=abs(area) ; 
        if(area%2==0)cout<<area/2<<".0"<<el;
        else cout<<area/2<<".5"<<el;
        for(auto p :res)
        {
            cout<<p.x<<" "<<p.y<<el;
        }
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}