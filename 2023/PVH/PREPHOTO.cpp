/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "PREPHOTO"
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

int n , L , k ;
struct range
{
	int l,r;
	bool operator<(const range&a)const
	{
		return r<a.r||(r==a.r&&a.l<l) ;
	}
};
range a[N] ;
void doc()
{
	cin>> n >>L>>k; 
	FOR(i,1,n)
	{
		int x, y ;cin>>x >>y ; 
		if(x>y)swap(x,y) ;
		a[i] = {x,y} ;
	}
	/* compress in to ranges do not contain each other 
	-> consist only intersect or not intersect */
	sort(a+1,a+n+1) ;  
	ve<range>V ;
	FOR(i,1,n)
	{
		while(!V.empty()&&V.back().l>=a[i].l)
		{
			V.pk() ;
		}
		V.pb(a[i]) ;
	}
	n = SZ(V) ;
	FOR(i,1,n)a[i] = V[i-1] ;
}

namespace sub1
{
	const int N = 2e2+5; 
	ll f[N][N] ;
    void xuly()
    {
    	FOR(i,0,n)FOR(j,0,k)f[i][j] = inf; 
    	f[0][0] = 0 ;
		FOR(j,1,n)
		{
			FOR(i,1,n)
			{
				FOR(ii,1,i)
				{	
					mini(f[i][j],f[ii-1][j-1]+sq(a[i].r-a[ii].l+1)-sq(max(0,a[ii-1].r-a[ii].l+1)));
				}
			}
		}
			ll res = inf ; 
		FOR(i,1,k)mini(res,f[n][i]) ; 
		cout<<res<<el; 
    }
}
namespace sub2
{
	const int N = 2e3+5 ;
	ll f[N][N] ;
	ll cost(int ii ,int i )
	{
		return sq(a[i].r-a[ii].l+1)-sq(max(0,a[ii-1].r-a[ii].l+1));
	}
	void cal(int k ,int l ,int r ,int oL ,int oR ){
		if(l>r)return ; 
		int mid=(l+r)>>1; 
		ll &best = f[mid][k] ;
		int pos = -1;  
		FOR(i,oL,min(oR,mid))
		{
			if(mini(best,f[i-1][k-1]+cost(i,mid)))pos=i; 
		}
		assert(pos!=-1) ;
		cal(k,l,mid-1,oL,pos) ; 
		cal(k,mid+1,r,pos,oR) ; 
	}
	void xuly()
	{
		FOR(i,0,n)FOR(j,0,n)f[i][j] = inf; 
		mini(k,n) ;
		f[0][0] = 0 ; 
		FOR(j,1,n)
		{
			cal(j,j,n,j,n) ; 
		}
		cout<<f[n][k] ;
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
       	sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}