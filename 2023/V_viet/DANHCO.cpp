/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "DANHCO"
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
#define     BIT(msk,i)  ((msk)>>(i)&1)
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


ll n  ;
int m , k ;
struct pt
{
	ll x ,y; 
}a[N] ; 

void doc()
{
    cin>> n >> m >> k; 
    FOR(i,1,k)
    {
    	cin>>a[i].x>>a[i].y ;

    }
}

namespace sub1
{
	int f[N][52] ;
	int dd[N][52] ;
	void add(int &a ,int b)
	{
		a+=b;
		if(a>=sm)a-=sm; 
	}
	bool in(int x ,int y)
	{
		return 1<=x&&x<=n&&1<=y&&y<=m ; 
	}
    void xuly()
    {
    	FOR(i,1,k)
    	{
    		dd[a[i].x][a[i].y] = 1; 
    	}
    	FOR(i,1,m)f[1][i] = (dd[1][i]==0) ; 	
    	FOR(i,2,n)
    	{
    		FOR(j,1,m)if(dd[i][j]==0)
    		{
    			FOR(x,-2,-1)FOR(y,-2,2)
    			{
    				if(abs(x)+abs(y)==3)
    				{
    					int nx = i+x; 
    					int ny = j+y;
    					if(in(nx,ny))add(f[i][j],f[nx][ny]) ;
    				}
    			}
    		}
    	}
    	int res = 0;
    	FOR(i,1,m)
    	{
    		add(res,f[n][i]) ; 
    	}
    	cout<<res<<el;
    }
}
namespace sub2
{
	void add(int &a ,int b)
	{
		a+=b;
		if(a>=sm)a-=sm;
	}
	struct MT
	{
		int n , m; 
		int mt[101][101] ;
		MT(int _n= 0 ,int _m = 0 )
		{
			n=_n ;
			m=_m ;
			FOR(i,1,n)FOR(j,1,m)mt[i][j] = 0 ; 
		}
		friend MT operator * (const MT&a , const MT& b )
		{
			int n = a.n; 
			int m = b.m; 
			MT ans(n,m) ;
			FOR(i,1,n)FOR(j,1,m)
			{
				FOR(k,1,a.m)add(ans.mt[i][j],1ll*a.mt[i][k]*b.mt[k][j]%sm);
			}
			return ans ;
		}
	} ;
	MT mu[62] ;
	MT pw(MT a , ll n)
	{
		if(n==1)return a ;
		MT b = pw(a,n/2) ;
		if(n&1)return b*b*a ;
		return b*b ;
	}
	int dd[3][55] ;
	vi cam[55] ; 
	bool in(int x ,int y)
	{
		return 1<=x&&x<=n&&1<=y&&y<=m ; 
	}
	void xuly()
	{
		vll V ;
		FOR(i,1,k)
		{
			if(a[i].x<=2)
			{
				dd[a[i].x][a[i].y]=1;
			}
			else V.pb(a[i].x) ; 
		}
		if(n!=2)V.pb(n) ;
		if(n==1)
		{
			int res = 0; 
			FOR(i,1,m)add(res,dd[1][i]==0) ;
			cout<<res<<el;
			return ;
		}
		uni(V) ;
		FOR(i,1,k)if(a[i].x>2)
		{
			int pos = LB(all(V),a[i].x)-V.begin() ; 
			cam[pos].pb(a[i].y) ;
		}
		MT a(1,2*m) ;
		// build ma tran khoi nguyen 
		FOR(i,1,m)
		{
			a.mt[1][i]  = (dd[1][i]==0) ; 
		}
		FOR(i,1,m)if(dd[2][i]==0)
		{		
			FOR(c,-2,2)if(abs(c)==2&&1<=i+c && i+c<=m)
			{
				(a.mt[1][i+m]+=a.mt[1][i+c])%=sm ;
			}
		}
		// FOR(i,1,2*m)cout<<a.mt[1][i]<<" ";
		// cout<<el;
		// build ma tran quan he   
		MT b(2*m,2*m) ;
		FOR(i,1,m)
		{
			b.mt[i+m][i] = 1; 
		}
		FOR(j,1,m)
		{
			FOR(x,-2,-1)
			{
				FOR(y,-2,2)if(abs(x)+abs(y)==3)
				{
					if(1<=j+y&&j+y<=m)
					{
						b.mt[j+y+(x==-1?m:0)][j+m]=1;
					}
				}
			}
		}

		mu[0] = b; 
		FOR(i,1,60)mu[i]= mu[i-1]*mu[i-1];
		ll pre = 2;
		FORN(i,0,SZ(V))
		{
			// a=(a*pw(b,V[i]-pre)) ; 
			FORD(j,LO,0)if(BIT(V[i]-pre,j))
			{
				a=a*mu[j];
			}
			for(auto pos : cam[i])
			{
				a.mt[1][pos+m]=0;
			}
			pre = V[i] ;
		}
		// return ;
		int res = 0 ;
		FOR(i,1,m)
		{
			add(res,a.mt[1][i+m]) ; 
		}
		// FOR(i,1,m)
		// {
		// 	cout<<a.mt[1][i]<<" ";
		// }
		// cout<<el; 
		// FOR(i,1,m)cout<<a.mt[1][i+m]<<" ";
		// cout<<el;
		assert(res>=0) ;
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
        // sub1::xuly() ; 
        sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}