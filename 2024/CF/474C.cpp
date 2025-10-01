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
struct pt
{
    ll x ,y ; 
    pt(ll x=0 , ll y=0): x(x) , y(y) {} 
    pt operator -(pt a)
    {
        return pt(x-a.x,y-a.y) ; 
    }
    pt operator+(pt a)
    {
        return pt(x+a.x,y+a.y) ;
    }
    ll operator *(pt a)
    {
        return x*a.y-y*a.x ; 
    }
    bool operator == (pt a )
    {
        return x==a.x&&y==a.y ; 
    }
}; 
ve<pt>P[N] ; 

pt rotate(pt a )
{
    return pt(-a.y,a.x) ; 
}
ll dis(pt a ,pt b)
{
    return sq(a.x-b.x)+sq(a.y-b.y) ; 
}
bool check(pt a, pt b , pt c ,pt d)
{
    if(dis(a,b)>dis(a,c))swap(b,c) ; 
    if(dis(a,d)>dis(a,c))swap(c,d) ; 
    return dis(a,b)&&max({dis(a,b),dis(b,c),dis(c,d),dis(d,a)})==min({dis(a,b),dis(b,c),dis(c,d),dis(d,a)})&&dis(a,c)==dis(b,d) ; 
}
void doc()
{
    cin>> n; 
    FOR(i,1,n){
        FOR(j,1,4)
        {
            P[j].clear() ; 
            pt a , goc ; 
            cin>>a.x>>a.y ; 
            cin>>goc.x>>goc.y ; 
            a = a-goc ; 
            FOR(t,1,4)
            {
                P[j].pb(goc+a) ; 
                // cout<<a.x<<" "<<a.y<<el;
                a = rotate(a) ; 
            }
        }
        int res = oo ; 
        FORN(x,0,4)FORN(y,0,4)FORN(z,0,4)FORN(t,0,4)
        {
            if(check(P[1][x],P[2][y],P[3][z],P[4][t]))
            {
                mini(res,x+y+z+t) ;  
            }
        }
        cout<<(res==oo?-1:res)<<el;
    }
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