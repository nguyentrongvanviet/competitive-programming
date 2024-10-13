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

int n , d , k ; 
int a[N] ; 
int sum[N] ;
struct DL
{
    int l , val ; 
}; 
ve<DL>Q[N] ;
int bit[N] ;
void up(int idx, int val)
{
    for(int i=idx;i<=n;i+=i&-i)bit[i]+=val;
}
int get(int idx )
{
    int ans =0 ; 
    for(int i=idx;i;i-=i&-i)ans+=bit[i] ;
    return ans ;
}

void doc()
{
    cin>> n >> d >> k ;
    FOR(i,1,n)bit[i] =0,sum[i]=0,Q[i].clear() ; 
    FOR(i,1,k)
    {
        int l ,r ;cin>> l>>r ; 
        Q[l].pb({r,1}) ; 
    }
    int ma = -1 , pos_ma = 0 , mi = oo , pos_mi = 0 ; 
    FOR(i,1,n)
    {
        for(auto [r,val] : Q[i])up(r,val) ; 
        if(i>=d)
        {
            if(maxi(ma,get(n)-get(i-d)))
            {
                pos_ma = i-d+1 ; 
            }
            if(mini(mi,get(n)-get(i-d)))
            {
                pos_mi = i-d+1; 
            }
        }
    }
    cout<<pos_ma<<" "<<pos_mi<<endl;
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
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("text.INP","r",stdin) ; 
    freopen("text.OUT","w",stdout) ;
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}