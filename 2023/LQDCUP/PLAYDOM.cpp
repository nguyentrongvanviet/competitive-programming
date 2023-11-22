/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "PLAYDOM"
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
#define        Mask(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , D , T ; 
int a[N] ; 

void doc()
{
    cin>> n >> D >> T ;
    mini(D,n-1);
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    }
}

namespace sub1
{
	const int  N =5e2+5; 
	int f[N][N][N] ;
    void xuly()
    {
    	FOR(i,0,n)FOR(used,0,n)FOR(far,0,n)f[i][used][far] = oo ; 
    	if(a[1]<=T)
    	{
    		f[1][0][1] = 1 ;
    		f[1][1][0] = 1 ; 
    	}
    	else
    	{
    		f[1][0][0] = 0 ;
    	}
    	FOR(i,2,n)
    	{	
    		FOR(used,0,i-1)
    		{
    			mini(f[i][used][a[i]<=T?i:0],f[i-1][used][0]+(a[i]<=T));	

    			FOR(far,1,i-1)
	    		{
	    			int mi = min(a[i],a[far]+i-far) ; 
	    			int u = 0 ;
	    			if(mi>T){} 
	    			else if(mi==a[i])u=i ;
	    			else u =far ; 
    				mini(f[i][used][u] , f[i-1][used][far]+(u>0)) ; 
	    		}
	    		FOR(far,1,i)mini(f[i][used+1][0],f[i][used][far]) ; 
    		}
    	}
    	int res  = oo ;
    	FOR(used,0,D)FOR(far,0,n)mini(res,f[n][used][far]) ; 
    	cout<<res;
    }
}
namespace sub2
{
	int f[N] ;
	void xuly()
	{
		int far = 0 ; 
		FOR(i,1,n)
		{
			f[i] = f[i-1] ; 
			if((far&&a[far]+i-far<=T)||a[i]<=T)
			{
				f[i]++ ; 
			}
			if(a[i]<=T)
			{
				if(far==0||a[i]<a[far]+i-far)far=i; 
			}
		}	
		stack<int>st ; 
		int res = oo ; 
		FORD(i,n,1)
		{
			if(a[i]>T)st.push(i) ; 
			else
			{
				while(!st.empty()&&a[i]+st.top()-i<=T)st.pop() ;
			}
			mini(res,f[i-1]+(n-i+1-SZ(st))) ; 
		} 
		cout<<res<<el;
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
    else 
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        if(n<=500)sub1::xuly() ;
        else 
        if(D==1)sub2::xuly() ;
        else 
        if()sub3::xuly() ;
        else abort() ;  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}