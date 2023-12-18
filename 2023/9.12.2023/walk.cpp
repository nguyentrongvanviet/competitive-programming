/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "walk"
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
const ll inf = 1e18 , cs = 331 , sm = 1e7+1203; 
const int N = 4000+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , k , q; 
struct pt
{
	int x ,y ;
	bool operator<(const pt&a)const
	{
		return x<a.x||(x==a.x&&y<a.y) ;
	}
}p[N] ; 
void doc()
{
	cin>> n >> m >> k >> q; 
	FOR(i,1,k)
	{
		cin>>p[i].x>>p[i].y ;
	}
}

namespace sub1
{
	const int MAX = 4e6 ; 
	pt Q[N] ;
	ll fac[MAX+5] , inv_fac[MAX+5] ; 
	ll pw(ll a, ll n)
	{
		if(n==0)return 1 ; 
		ll b = pw(a,n/2) ; 
		if(n&1)return b*b%sm*a%sm; 
		return b*b%sm; 
	}
	ll C(int k ,int n)
	{
		if(k>n)return 0; 
		return fac[n]*inv_fac[k]%sm*inv_fac[n-k]%sm; 
	}
	ll way(pt a ,pt b)
	{
		if(a.x>b.x||a.y>b.y)return 0 ;
		return C(b.x-a.x,b.x-a.x+b.y-a.y) ; 
	}
	ll f[N] ; 
    void xuly()
    {	
    	fac[0] =1; 
    	FOR(i,1,MAX)fac[i] = fac[i-1]*i%sm ; 
    	inv_fac[MAX] = pw(fac[MAX],sm-2) ; 
    	FORD(i,MAX-1,0)inv_fac[i] = inv_fac[i+1]*(i+1)%sm;
    	sort(p+1,p+k+1) ; 
    	FOR(i,1,k)
    	{
    		f[i] = way(pt{1,1},p[i]) ; 
    		FOR(j,1,i-1)
    		{
    			(f[i]-=f[j]*way(p[j],p[i])%sm-sm)%=sm;
    		}		
    	}
    	FOR(i,1,q)
    	{
    		cin>>Q[i].x>>Q[i].y ; 
    	}
    	FOR(i,1,q)
    	{
    		ll res=way(pt{1,1},Q[i]) ; 
    		FOR(j,1,k)
    		{
    			(res-=f[j]*way(p[j],Q[i])%sm-sm)%=sm;
    		}
    		cout<<res<<" " ;
    	}
    }
}
namespace sub2
{
	ll f[500][500] ; 
	void xuly()
	{
		FOR(i,1,k)
		{
			int x =p[i].x; 
			int y = p[i].y; 
			f[x][y]= - 1; 
		}
		FOR(i,1,n)FOR(j,1,m)
		{
			if(i==1&&j==1)f[i][j]=1; 
			else 
			{
				if(f[i][j]==-1)f[i][j]= 0 ; 
				else 
				{
					f[i][j] = (f[i-1][j]+f[i][j-1])%sm; 
				}
			}
		}
		FOR(i,1,q)
		{
			int x ,y; cin>>x>>y; 
			cout<<f[x][y]<<" " ;
		}
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