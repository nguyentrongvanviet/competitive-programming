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
#define     Bit(msk,i)  (msk>>(i)&1)
#define          SZ(_)  (int)(_.size())
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
const ll inf = 1e18 , cs = 331 , sm = 987654319; 
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n; 
int a[N] ; 
int P[N] ;
vi V ; 
void doc()
{
	cin>> n;
	FOR(i,1,n)
	{
		cin>>a[i] ; 
		V.pb(a[i]) ; 
	}
	uni(V); 
	FOR(i,1,n)
	{
		P[i] = UB(all(V),a[i])-V.begin() ; 
	}
}

namespace sub1
{
	struct BIT
	{
		vll bit ;
		int n ;  
		BIT(){}
		BIT(int _n ){
			n = _n ; 
			bit.resize(n+2,0) ;
		}
		void up(int id , ll val)
		{
			for(int i=id;i<=n;i+=i&-i)(bit[i]+=val)%=sm ; 
		}
		ll get(int id )
		{
			ll ans =0 ; 
			for(int i =id;i;i-=i&-i)(ans+=bit[i])%=sm ;
			return ans; 
		}
		ll get(int l ,int r)
		{
			if(l>r)return 0 ;
			return (get(r)-get(l-1)+sm)%sm; 
		}
	} ;
	ll cur[N][N] ;
	BIT f[N] ;
    void xuly()
    {   
    	FOR(layer,2,7)
    	{
    		FOR(i,1,n)
    		{
    			f[i] = BIT(n) ; 
    			FOR(j,1,n)f[i].up(P[j],cur[i][j]),cur[i][j]=0 ; 
    		}
    		if(layer==2)
    		{
    			FOR(i,1,n)FOR(j,1,i-1)if(a[i]<a[j])
    				cur[i][j] = 1 ;
    		}

    		if(layer==3)
    		{
    			FOR(i,1,n)FORN(j,1,i)if(a[i]>a[j])
					cur[i][j] = f[j].get(P[i]+1,n);			
    		}

    		if(layer==4)
    		{
    			FOR(i,1,n)FORN(j,1,i)if(a[i]<a[j])
    				cur[i][j] = f[j].get(P[i]+1,P[j]);
    		}
    		if(layer==5)
    		{
    			FOR(i,1,n)FORN(j,1,i)if(a[i]<a[j])
    				cur[i][j] = f[j].get(P[j]+1,n) ;
    		}
    		if(layer==6)
    		{
    			FOR(i,1,n)FORN(j,1,i)if(a[i]>a[j])
    			{
    				cur[i][j] = f[j].get(P[i]+1,n) ; 
    			}
    		}
    		if(layer==7)
    		{
    			FOR(i,1,n)FORN(j,1,i)if(a[i]<a[j])
    			{
    				cur[i][j] = f[j].get(P[i]+1,P[j]-1) ; 	
    			}
    		}
    	}
    	ll res =0 ; 
    	FOR(i,1,n)FOR(j,1,n)(res+=cur[i][j])%=sm; 

    	cout<<res;
    }
}
namespace sub2
{

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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}