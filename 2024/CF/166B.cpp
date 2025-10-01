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

int n , m; 
struct pt
{
    ll x , y ; 
    pt(ll x= 0 , ll y =0):x(x),y(y){} 
    pt operator - (pt a){return {x-a.x,y-a.y};}
    ll operator * (pt a){return x*a.y-y*a.x;}
    bool operator < (pt a){return x<a.x||(x==a.x&&y<a.y);}
    bool operator == (pt a){return x==a.x&&y==a.y;}
} ; 
ve<pt>a ; 
pt b[N] ;
ll ccw(pt A , pt B , pt C)
{
    return (B-A)*(C-B)  ; 
}
void doc()
{
    cin>> n;
    FOR(i,1,n)
    {
        ll x ,y ; cin>>x>>y ; 
        a.pb({x,y}) ; 
    }    
    
    sort(all(a)) ; 
    sort(a.begin()+1,a.end(),[](pt A, pt B ){return ccw(a[0],A,B)<0;}) ; 
    int End = 0 ; 
    ++n ; 
    a.push_back(a[0]) ; 
    FORN(i,1,n)
    {
        if(a[i].x<a[i-1].x)
        {
            End = i ; 
            break;  
        }
    }
    ve<pt>up, down;
    End--; 
    FOR(i,0,End)
    {
        up.pb(a[i]) ; 
    }   
    FORD(i,n-1,End)
    {
        down.pb(a[i]) ; 
    }
    // cout<<"UP"<<el;
    // for(auto [x,y]:up)cout<<x<<" "<<y<<el;
    // cout<<"DOWN"<<el;
    // for(auto [x,y]:down)cout<<x<<" "<<y<<el;
    // return ;
    bool ok = 1 ; 
    cin>> m; 
    FOR(i,1,m)
    {
        cin>>b[i].x>>b[i].y ; 
    }
    // return ; 
    FOR(i,1,m)
    {
        pt A = b[i] ;
        ll x = A.x;
        ll y = A.y ; 
        if(x<=up[0].x||up.back().x<=x||x<=down[0].x||down.back().x<=x) 
        {
            ok = 0 ;
            break ; 
        }
        int l ,r,ans ; 
        l = 0 ;
        r = up.size()-1 ; 
        while(l<=r)
        {
            int mid =(l+r)>>1 ;
            if(up[mid].x<=x)ans=mid,l=mid+1 ; 
            else r=mid-1 ; 
        }
        if(ccw(up[ans],up[ans+1],A)>=0)
        {
            ok = 0;  
            break ;
        }   
        l = 0 ;
        r = down.size()-1 ; 
        while(l<=r)
        {
            int mid =(l+r)>>1 ;
            if(down[mid].x<=x)ans=mid,l=mid+1 ; 
            else r=mid-1 ; 
        }
        if(ccw(down[ans],down[ans+1],A)<=0)
        {
            ok = 0;  
            break ;
        }
    }
    cout<<(ok?"YES":"NO")<<el; 
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