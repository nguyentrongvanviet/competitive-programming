/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "FROG"
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
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , d ;  
int a[N] , b[N] ; 

void doc()
{
    cin>>  n >>d ; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n)cin>>b[i] ; 
}

namespace sub1
{
	const int N =2e2+5;
	ll f[N][N] ;
    void xuly()
    {
    	FOR(i,0,n)FOR(j,0,n)f[i][j] = -inf ;
    	f[1][1] = a[1]+b[1]; 
        FOR(i,1,n)
        {
        	FOR(j,1,n)if(abs(i-j)<=d)
        	{
        		FOR(k,1,i-1)maxi(f[i][j],f[k][j]+a[i]) ; 
        		FOR(k,1,j-1)maxi(f[i][j],f[i][k]+b[j]) ; 
        	}
        }
        cout<<f[n][n]<<el;
    }
}
namespace sub2
{
	const int  N= 2e3+5 ;
	ll f[N][N] ; 
	ll ma[N] ; 
	void xuly()
	{	
		FOR(i,1,n)FOR(j,1,n)
		{
			f[i][j] = -inf ; 
		}
		f[1][1] = a[1]+b[1] ;
		FOR(i,1,n)ma[i] = -inf ;
		FOR(i,1,n)
		{
			ll cur = -inf ;
			FOR(j,1,n)
			{
				if(abs(i-j)<=d)
				{
					maxi(f[i][j],cur+b[j]) ; 
					maxi(f[i][j],ma[j]+a[i]); 
				}
				maxi(cur,f[i][j]) ; 
				maxi(ma[j],f[i][j]) ;
			}	
		}
		cout<<f[n][n];
	}
}
namespace sub3
{
	ll res = 0 ;
	ll fa[N] , fb[N] ; 	
	void xuly()
	{
		FOR(i,1,n)
		{	
			if(a[i]>0)res+=a[i],a[i]=0;
			else a[i] = -a[i] ;
			if(b[i]>0)res+=b[i] ,b[i]=0 ;
			else b[i] = -b[i] ; 
		}	
		deque<int>Qfa , Qfb , mia,mib ;
		res+=-a[1]-b[1]-a[n]-b[n] ;
		a[1]=b[1]=a[n]=b[n] = 0 ; 
		fa[1] = 0 ; 
		fb[1] = 0 ; 
		Qfa.pb(1) ; 
		Qfb.pb(1) ; 
		mia.pb(1) ; 
		mib.pb(1) ;
		// prt(a,n) ;
		// prt(b,n) ; 
		FOR(i,2,n)
		{
			while(Qfa.front()<i-d)Qfa.pop_front() ; 
			while(Qfb.front()<i-d)Qfb.pop_front() ;
			while(mia.front()<i-d)mia.pop_front() ; 
			while(mib.front()<i-d)mib.pop_front() ;
			
			fa[i] = fb[Qfb.front()] + a[i] ;
			fb[i] = fa[Qfa.front()] + b[i] ;
			while(!mia.empty()&&a[mia.back()]>=a[i])mia.pk() ;
			while(!mib.empty()&&b[mib.back()]>=b[i])mib.pk() ; 
			mia.pb(i) ;
			mib.pb(i) ;
			mini(fa[i],fa[Qfa.front()]+b[mib.front()]+a[i]) ; 
			mini(fb[i],fb[Qfb.front()]+a[mia.front()]+b[i]) ;
			while(!Qfa.empty()&&fa[Qfa.back()]>=fa[i])Qfa.pk() ;
			while(!Qfb.empty()&&fb[Qfb.back()]>=fb[i])Qfb.pk() ; 
			Qfa.pb(i) ; 
			Qfb.pb(i) ; 
		}		
		// prt(fa,n) ; 
		// prt(fb,n) ;
		res-=min(fa[n],fb[n]) ; 
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // if(n<=200)sub1::xuly() ; 
        // else if(n<=2e3)sub2::xuly() ; 
        sub3::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}