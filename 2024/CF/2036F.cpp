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

#define BIT(msk,bit) int(msk>>bit&1)
ll xor_all(ll R)
{
    if(R<=0)return 0 ; 
    ll res = 0 ; 
    FOR(need,0,59)if(R>>need)
    {
        ll lR = (R&((1ll<<need)-1));
        ll rR = (R>>(need+1)) ;
        if(BIT(R,need))
        {
            if((((rR<<need)|lR)&1)==0)
            {
                res^=(1ll<<need) ; 
            }
        }
        else 
        {
            if(need==0&&(rR&1))
            {
                res^=1 ;
            }
        }

    }
    return res ; 
}
ll xormod2i_k(ll r , int concern, ll k )
{
    ll res = xor_all(r) ; 
    ll nR = (r>>concern) ; 
    ll lR = (r&((1ll<<concern)-1)) ; 
    if(lR>=k)
    {
        res^=(xor_all(nR)<<concern) ;
        if((nR&1)==0)
        {
            res^=k ; 
        }
    }
    else if(lR<k)
    {
        res^=(xor_all(nR-1)<<concern) ; 
        if(nR&1)
        {
            res^=k ; 
        }
    }
    return res ; 
}

void doc()
{
    ll l , r , i , k ; cin>> l >> r >> i >> k;
    // cout<<xormod2i_k(l-1,i,k)<<el;
    cout<<(xormod2i_k(r,i,k)^xormod2i_k(l-1,i,k))<<el;        
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