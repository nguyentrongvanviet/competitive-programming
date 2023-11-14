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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        Mask(i)  (1ll<<(i))
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
short a[N] ;
str S ;
void doc()
{
	cin>>S ; 
	n = SZ(S) ; 
	S="%"+S ; 
}	
	
namespace sub1
{
	const int N =5e3+5;  
	struct ke
	{
		int r;
		int way ; 
	} ; 
	ve<ke>g[N] ; 
	map<char,short>Val; 
	ll f[N][N][2] ; 
	ll solve(int l ,int r, int ok)
	{
		if(l>r)return 1 ; 
		ll &val = f[l][r][ok] ; 
		if(val!=-1)return val ;  
		val =0 ; 
		if(ok)
		{
			int way= 0 ; 
			if(a[l]+a[r]==0)way=1 ;
			else if(a[l]+a[r]==10)way =3 ; 
			else if(a[l]==5&&a[r]<0)way =1 ; 
			else if(a[l]!=5&&a[r]==5)way =1 ; 
			val = 1ll*way*solve(l+1,r-1,0)%sm;
		}
		else
		{
			for(auto x : g[l])
			{
				int R=  x.r ; 
				if(R>r)break;
				(val+=solve(l,R,1)%sm*solve(R+1,r,0)%sm)%=sm; 
				// if(l==1&&r==n&&ok==0)cout<<R<<" "<<val<<el;
			}
		}
		// cout<<l<<" "<<r<<" "<<ok<<" "<<val<<el;
		return val; 

	}
    void xuly()
    {
    	Val['('] = 1 ; 
    	Val['['] = 2 ; 
    	Val['{'] = 3 ; 
    	Val[')'] = -1 ; 
    	Val[']'] = -2 ; 
    	Val['}'] = -3 ; 
    	Val['?'] = 5 ; 
		FOR(i,1,n)a[i] = Val[S[i]] ; 
    	FOR(i,1,n)
    	{
    		if(a[i]>0)
    		{
    			for(int j= i+1;j<=n;j+=2)
    			{
    				if(a[i]+a[j]==0)
    				{
    					g[i].pb({j,1}) ; 
    				}
    				else if(a[i]+a[j]==10)g[i].pb({j,3}) ; 
    				else if(a[i]==5&&a[j]<0)g[i].pb({j,1}) ; 
    				else if(a[i]!=5&&a[j]==5)g[i].pb({j,1}) ;
    			}
    		}
    	}
    	FOR(i,1,n)FOR(j,1,n)FOR(ok,0,1)f[i][j][ok] = -1 ; 
    	cout<<solve(1,n,0) ; 
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