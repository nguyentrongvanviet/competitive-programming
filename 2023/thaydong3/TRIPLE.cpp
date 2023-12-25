/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "TRIPLE"
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


int n;
struct pt
{
	ll x ,y; 
}a[N] ;
void doc()
{
    cin>> n; 
    FOR(i,1,n)
    {
    	cin>>a[i].x>>a[i].y;
    }
}	

namespace sub1
{
	const int N = 3e3+5 ;
	int near[N] ;
	int dis(pt a , pt b)
	{
		return abs(a.x-b.x)+abs(a.y-b.y) ;
	} 
	bitset<N>ans[N] ;	
    void xuly()
    {
    	FOR(i,1,n)near[i] = oo ; 
    	FOR(i,1,n)FOR(j,1,n)if(i!=j)
    	{
    		mini(near[i],dis(a[i],a[j])) ; 
    	}
    	FOR(i,1,n)FOR(j,i+1,n)if(near[i]==near[j]&&dis(a[i],a[j])==near[i])
    	{
    		ans[i][j] = 1; 	
    	}
    	int res = 0 ;
    	FOR(i,1,n)FOR(j,i+1,n)if(near[i]==near[j]&&dis(a[i],a[j])==near[i])
    	{	
    		res+=(ans[i]&ans[j]).count() ; 
    	}
    	cout<<res<<el;
    }
}
namespace sub2
{
	int dis(pt a , pt b)
	{
		return abs(a.x-b.x)+abs(a.y-b.y) ;
	} 
	void xuly()
	{
		FOR(i,1,20)FOR(j,1,20)FOR(x,1,20)FOR(y,1,20)
		{
			int cnt = 0 ; 
			FOR(u,1,20)FOR(v,1,20)
			{
				pt a = {i,j} ;
				pt b = {x,y} ; 
				pt c = {u,v} ;
				if(dis(a,c)==dis(b,c)&&dis(a,c)==dis(b,a))
				{
					if(i-j!=x-y&&x-y!=u-v&&i-j!=u-v&&i+j!=x+y&&x+y!=u+v&&u+v!=i+j)
					{
						cout<<-1;
					}
					cnt++ ; 
					// cout<<i-j<<" "<<i+j<<" "<<x-y<<" "<<y+x<<" "<<u-v<<" "<<v+u<<el;
				} 
			}
			cout<<cnt<<el;
		}
	}
}
namespace sub3
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
        // sub2::xuly() ;
        // sub3::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}