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
const int N = 5e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

str s ;
int n; 
int mex(vector<int>&a)
{
    sort(all(a)) ; 
    a.resize(unique(all(a))-a.begin()) ; 
    for(int i=0;i<a.size();i++)if(a[i]!=i)return i ; 
    return a.size() ; 
}

int f[N][N] ; 
int solve(int l ,int r )
{
    if(f[l][r]!=-1)return f[l][r] ; 
    if(l==r)
    {
        return f[l][r] = 0 ; 
    }
    vector<int>val; 
    for(int i=l+1;i<=r-1;i++)
    {
        if(s[i-1]==s[i+1])
        {
            val.pb(solve(l,i-1)^solve(i+1,r)) ; 
        }
    }
    return f[l][r] = mex(val) ; 
}
void doc()
{
    cin>>s; 
    n = s.size() ;
    s="#"+s+"$"; 
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)f[i][j] = -1 ; 
    if(solve(1,n))
    {
        cout<<"First"<<el; 
        FOR(i,2,n-1)
        {
            if(s[i+1]==s[i-1]&&(f[1][i-1]^f[i+1][n])==0)
            {
                cout<<i;
                break; 
            }
        }
    }
    else cout<<"Second"<<el;
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
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}