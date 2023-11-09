/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "d13mzdesign"
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
const ll inf = 1e18 , cs = 331 , sm = 111539786; 
const int N = 1e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , k ,s ; 
int d[(int)1e2+5][105][2] ; 


void doc()
{
    cin>> n >>m>> k >> s;
    FOR(i,1,s)
    {
    	int x , y ;cin>>x>>y ;
    	d[x-1][y][0] = 1;   
    	d[x][y][0] = 1 ;
    	d[x][y][1] = 1 ;  
    	d[x][y-1][1] = 1; 
    }
}

namespace sub1
{
	ll f[(int)1e2+5][105][5005]; 
	ll tinh(int x ,int y , int cl)
	{
		if(x==n+1)
		{
			return cl ==0 ; 
		}
		if(y==m+1)
		{
			return tinh(x+1,1,cl) ; 
		}
		ll &val = f[x][y][cl] ;
		if(val!=-1)return val; 
		val = 0 ; 
		if(cl>=2)
		{
			(val+=tinh(x,y+1,cl-2))%=sm ; 
		}
		if(d[x][y][1]==0&&cl)
		{
			(val+=tinh(x,y+1,cl-1))%=sm; 
		}
		if(d[x][y][0]==0&&cl)
		{
			(val+=tinh(x,y+1,cl-1))%=sm; 
		}
		return val; 

	}
    void xuly()
    {
    	int cl = k+s+(m+1)*(n+1)-1-(m+n) ; 
    	FOR(j,1,m)
    	{
    		d[n][j][0] = 1 ; 
    	}
    	FOR(i,1,n)
    	{
    		d[i][m][1] = 1;  
    	}
    	FOR(i,1,n+1)FOR(j,1,m+1)
    	{
    		FOR(k,0,cl)f[i][j][k] = -1 ; 
    	}
    	cout<<tinh(1,1,cl);
    }
}
namespace subtrau
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}
