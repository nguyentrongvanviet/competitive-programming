/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "rotgame"
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
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 200+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ; 
int a[3][N] ; 
void doc()
{
	cin>> n  ; 
	FOR(i,1,2)
	{
		FOR(j,1,n)
		{
			cin>>a[i][j] ; 			
		}
	}
}

namespace sub1
{
	vi res ; 
	void trans(int i)
	{
		int x= a[1][i] ; 
		int y =a[1][i+1] ; 
		int z = a[2][i+1] ;
		int t = a[2][i] ; 
		a[1][i] = y ; 
		a[1][i+1] = z ;
		a[2][i+1] = t ; 
		a[2][i] = x ;  
	}
	void xoay(int i ,int k)
	{
		FOR(j,1,k)
		{
			res.pb(i);
			trans(i) ;
		}
	}
	void solve(int i ,int j)
	{
		if(i==j)
		{
			if(1<i&&i<n)
			{
				xoay(i-1,1) ; 
				xoay(i,3)  ; 
				xoay(i-1,3) ; 
				xoay(i,1) ; 
			}
			else if(i==1)
			{
				xoay(i+1,1) ; 
				xoay(1,1) ;
				xoay(i+1,3); 
			}
			else if(i==n)
			{
				xoay(i-2,3) ;
				xoay(i-1,3) ;
				xoay(i-2,3) ;   
			}
		}
		else if(i<j)
		{
			if(j-i>=2)
			{
				FOR(pos,i,j-1)
				{
					xoay(pos,1) ; 
				}
			}
			else 
			{
				xoay(i,1);
			}
		}	
		else if(i>j) 
		{	
			if(i-j>=2)
			{
				FORD(pos,i-1,j)
				{
					xoay(pos,3) ;
				}
			}
			else
			{
				xoay(i-1,3) ; 
			}
		}	
	}
    void xuly()
    {
    	if(n==2)
    	{
    		int d0 = a[1][1]+a[1][2] ; 
    		int d1 = a[1][2]+a[2][2] ; 
    		int d2 = a[2][2]+a[2][1] ;
    		int d3 = a[2][1]+a[1][1] ;
    		int ma =max({d0,d1,d2,d3}) ; 
    		if(d0==ma)
    		{
    			cout<<0<<el;
    		}
    		else if(d1==ma)
    		{
    			cout<<1<<el<<1; 
    		}
    		else if(d2==ma)
    		{
    			cout<<2<<el;
    			FOR(i,1,2)cout<<1<<" ";
    		}
    		else if(d3==ma)
    		{
    			cout<<3<<el;
    			FOR(i,1,3)
    			{	
    				cout<<1<<" ";
    			}
    		}
    		exit(0) ; 
     	}
     	while(1)
     	{
     		int st = 0 , en=  0 ;
     		FOR(i,1,n)
     		{
     			FOR(j,1,n)if(a[1][i]<a[2][j])
	     		{
	     			st= i ; 
	     			en =j ; 
	     			break;  
	     		}
	     		if(st)break;
	     	}	
	     	if(st==0)break;
     		solve(st,en) ;
     	}
     	cout<<SZ(res)<<el; 
     	prv(res) ; 
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
