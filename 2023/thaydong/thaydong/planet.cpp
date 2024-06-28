/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "planet"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n;  
int a[N] ;
void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
}

namespace sub1
{
	int f[N] , s[N] ; 
	ll res = 0 ;
	int st[N][LO+2] ; 
	void rmq()
	{
		FOR(i,1,n)
		{
			st[i][0] = a[i] ; 
		}
		FOR(j,1,lg(n))
		{
			FOR(i,1,n-(1<<j)+1)st[i][j] = gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]) ; 
		}
	}
	int get(int l ,int r)
	{
		int k = lg(r-l+1) ;
		return gcd(st[l][k],st[r-(1<<k)+1][k]) ; 
	}
	void solve()
	{
		FOR(j,0,lg(n))
		{
			st[1][j] = gcd(st[1][j],a[1]) ; 
		} 
		s[0] = 1 ;  
		int it =1 ; 
		FOR(i,1,n)
		{
			f[i] = 0; 
			while(get(it,i)==1)++it; 
			f[i] = (s[i-1]-(it-2<0?0:s[it-2])+sm)%sm;
			s[i] = (s[i-1]+f[i])%sm ; 
		}
	}
    void xuly()
    {
    	rmq() ; 
    	solve() ;
    	int res=f[n];  
    	FORD(st,n,2)
    	{
    		int pre=a[1] ; 
    		a[1]=gcd(a[1],a[st]) ; 
    		if(a[1]==1)break; 
    		if(a[1]!=pre)pre=a[1],solve() ; 
    		(res+=f[st-1])%=sm ; 
    	}
    	cout<<res<<el; 
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