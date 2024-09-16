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
#define SZ(a) (int)(a.size())
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
struct pt
{
    ll x ,y ;
    pt(int _x = 0 , int _y = 0)
    {
        x=_x ; 
        y=_y ; 
    }
    pt operator - (pt a )
    {
        return pt(x-a.x,y-a.y) ; 
    }
    ll operator * (pt a )
    {
        return x*a.y-y*a.x ; 
    }
    friend bool operator < (pt a, pt b)
    {
        return a.x<b.x||(a.x==b.x&&a.y<b.y) ; 
    }
    bool operator != (pt a)
    {
        return x!=a.x||y!=a.y ;
    }
} ; 
pt a[N] ; 
void doc()
{
    cin>> n; 
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y ; 
}

namespace sub1
{
    pt root ;
    ll ccw(pt a , pt b ,pt c )
    {
        return (b-a)*(c-b) ; 
    }
    ll dis2(pt a , pt b)
    {
        return sq(a.x-b.x)+sq(a.y-b.y) ; 
    }
    bool cmp1(pt a, pt b)
    {
        if(ccw(root,a,b)==0)
        {
            return dis2(root,a)<dis2(root,b) ;
        }
        return ccw(root,a,b)<0 ;
    }   
    vector<pt>Hull(vector<pt> P)
    {
        vector<pt>ans  ;
        root = P[0] ; 
        sort(P.begin()+1,P.end(),cmp1) ;
        P.push_back(P[0]) ;  
        ans.push_back(P[0]) ;
        for(int i=1;i<SZ(P);i++)
        {   
            while(ans.size()>1&&ccw(ans[ans.size()-2],ans.back(),P[i])>0)
            {
                ans.pk() ; 
            }
            ans.pb(P[i]) ; 
        }
        return ans ; 
    }
    void xuly() 
    {
        sort(a+1,a+n+1) ; 
        vector<pt>P ; 
        for(int i=1;i<=n;i++)
        {
            if(P.empty()||P.back()!=a[i])P.pb(a[i]) ;
        }
        sort(all(P)) ;
        vector<pt> H = Hull(P) ; 
        ll res = 0 ; 
        for(int i=1;i<SZ(H);i++)
        {
            res+=max(abs(H[i].x-H[i-1].x),abs(H[i].y-H[i-1].y)) ; 
        }
        cout<<res+4 ; 
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