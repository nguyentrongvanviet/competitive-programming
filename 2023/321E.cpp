/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
#define TASK "321E"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

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
#define            tct  template<typename T>
#define             LB  lower_bound
#define             UB  upper_bound 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n , K ; 
int a[4005][4005] ;
ll s[4005][4005] ; 
ll f[4005][805] ;  
void doc()
{
	cin>> n >> K ; 
	FOR(i,1,n)FOR(j,1,n)cin>>a[i][j] , s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j] ; 
}
ll C(int l ,int r)
{
	return (s[r][r]-s[r][l-1]-s[l-1][r]+ s[l-1][l-1])/2;
}
namespace sub1
{
	// C(l,r) satisfy quadrangle inequality => otp[k][i] <=otp[k][i+1] ;  
	void xuly()
	{	
		FOR(i,1,n)
		{
			f[i][1] = s[i][i]/2 ; 
		}
		
		FOR(k,2,K)
		{
			FOR(i,k,n)
			{
				f[i][k] = inf ; 
				FOR(j,k,i)
				{
					mini(f[i][k],f[j-1][k-1]+C(j,i));
				}
			}
		}
		cout<<f[n][K]<<el; 
	}
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/
namespace sub2
{

	void solve(int l ,int r , int optl , int optr ,int k)
	{
		if(l>r)return ; 
		int mid= (l+r)/2; 
		int pos = 0 ;  
		FOR(i,optl,min(optr,mid))
		{
			if(mini(f[mid][k],f[i-1][k-1]+C(i,mid)))
			{
				pos=i ;
			}
		}
		solve(l,mid-1,optl,pos,k) ;
		solve(mid+1,r,pos,optr,k) ; 
	}
	void xuly()
	{
		FOR(i,1,n)FOR(j,1,K)
		{
			f[i][j] = inf ;
		}
		FOR(i,1,n)
		{
			f[i][1]= C(1,i);
		}
		FOR(i,2,K)
		{
			solve(1,n,1,n,i);
		}
		cout<<f[n][K]<<el;
	}
}
signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
    	sub2::xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}