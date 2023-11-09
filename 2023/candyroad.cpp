/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "candyroad"
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
#define int long long 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n  ; 
ll m ; 
int a[N] ; 
vi V ;
ll sum = 0;  
void doc()
{
   	cin>> n>> m; 
   	FOR(i,1,n)cin>>a[i] , V.pb(a[i]) ; 
    sum=n*(n+1)/2%sm*(m*(m+1)/2%sm)%sm;
}

namespace sub1
{
	int dd[N] ;
    void xuly()
    {
    	uni(V) ; 
    	FOR(i,1,n)
    	{
    		a[i] = LB(all(V),a[i])-V.begin() ; 
    	}

    	ll res = 0 ; 
    	FOR(i,1,n)
    	{
    		ll cnt =0 ; 
    		FORD(j,i,1)
    		{
    			(cnt+=(dd[a[j]]==0?V[a[j]]:0))%=sm;
    			dd[a[j]]=1 ; 
    			(res+=cnt)%=sm ; 
            }
            FORD(j,i,1)dd[a[j]]=0;
    	}
        cout<<(sum-res+sm)%sm ;     
    }
}
namespace sub2
{
    int la[N] ; 
    void xuly()
    {
        uni(V) ; 
        FOR(i,1,n)
        {
            a[i] = LB(all(V),a[i])-V.begin(); 
        }
        ll res = 0 , cnt= 0 ; 
        FOR(i,1,n)
        {
            int u = la[a[i]] ; 
            (cnt-=1LL*u*V[a[i]]%sm-sm)%=sm;
            la[a[i]] = i ; 
            (cnt+=1LL*i*V[a[i]]%sm-sm)%=sm;
            (res+=cnt)%=sm;
        }
        cout<<(sum-res+sm)%sm; 
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
        // sub1::xuly() ; 
        sub2::xuly() ;
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}