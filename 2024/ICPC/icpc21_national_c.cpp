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

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;} 

void add(ll& a , ll b){a+=b;if(a>=sm)a-=sm;}
void sub(ll& a , ll b){a-=b;if(a<0)a+=sm;}

struct pt
{
    ll x, y; 
    pt operator-(pt a)
    {
        return {x-a.x,y-a.y} ; 
    }
    ll operator*(pt a )
    {   
        return x*a.y-y*a.x ;
    }
};
ll ccw(pt a, pt b ,pt c)
{
    return (b-a)*(c-b) ; 
}
ll dis(pt& a , pt& b)
{
    return sq(a.x-b.x)+sq(a.y-b.y) ; 
}
bool check(pt a ,pt b ,pt c )
{
   return ccw(a,b,c)!=0;
}
vll edges(pt& a,  pt& b ,pt& c)
{
    ll A = dis(a,b) ;
    ll B = dis(b,c) ;
    ll C = dis(a,c) ; 
    return {A,B,C} ;
}
int n ; 
pt a[N]  ; 
ve<vll> sl ; 
ve<vll> one[N] ;
ve<vll> two[N][N] ; 
bool cmp(const vll&a , const vll&b)
{
    return  a[0]<b[0]||(a[0]==b[0]&&a[1]<b[1])||(a[0]==b[0]&&a[1]==b[1]&&a[2]<b[2]);
}
int get(ve<vll> &a ,vll val)
{
    return UB(all(a),val)-LB(all(a),val) ;
}
void doc()
{
    cin>> n;
    FOR(i,1,n)cin>>a[i].x>>a[i].y ; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(check(a[i],a[j],a[k]))
                {
                    vll tmp = {dis(a[i],a[j]),dis(a[k],a[j]),dis(a[i],a[k])};  
                    sl.pb(tmp) ;
                    one[i].pb(tmp) ; 
                    one[j].pb(tmp) ; 
                    one[k].pb(tmp) ; 
                }
            }
        }
    }
    FOR(i,1,n)FOR(j,i+1,n)FOR(k,j+1,n)if(check(a[i],a[j],a[k]))
    {
        vll tmp = {dis(a[i],a[j]),dis(a[j],a[k]),dis(a[i],a[k])};
        two[i][j].pb(tmp) ; 
        two[i][k].pb(tmp) ;
        two[j][k].pb(tmp) ; 
    }
    FOR(i,1,n)sort(all(one[i]),cmp) ;
    FOR(i,1,n)FOR(j,i+1,n)sort(all(two[i][j]),cmp) ; 
    sort(all(sl),cmp) ; 
    ll res = 0 ; 
	FOR(i,1,n)FOR(j,i+1,n)FOR(k,j+1,n)if(check(a[i],a[j],a[k]))
    {
        vll E={dis(a[i],a[j]),dis(a[j],a[k]),dis(a[i],a[k])} ; 
        res+=get(sl,E); 
		res-=get(one[i],E)+get(one[j],E)+get(one[k],E) ;
		res+=get(two[i][j],E)+get(two[j][k],E)+get(two[i][k],E) ;
        if(E[0]!=E[1]&&E[1]!=E[2]&&E[0]!=E[2])res-=1;
        else res-=2;        
    }
    cout<<res<<el; 
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
