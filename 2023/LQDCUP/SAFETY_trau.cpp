/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "SAFETY"
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
#define lg(a) 63 - __builtin_clzll(a)
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

int n, H ; 
int a[N] ;

void doc()
{
    cin>> n >> H  ; 
    FOR(i,1,n)cin>>a[i] ;
}

namespace sub1
{
    void xuly()
    {
     	sort(a+1,a+n+1) ;
     	ll res = 0 ; 
     	FOR(i,1,n)
     	{
     		res+=abs(a[i]-a[(1+n)/2]) ; 
     	}   
     	cout<<res;
    }
}
namespace sub2
{
	ll f[N][502]; 
	void xuly()
	{
		FOR(i,1,n)
		{
			FOR(j,0,400)
			{
				f[i][j] = inf ;
				FOR(k,max(0,j-H),min(400,H+j))
				{	
					mini(f[i][j] , f[i-1][k]+abs(a[i]-j));
				}
			}	
		}
		ll res= inf ;
		FOR(i,0,400)mini(res,f[n][i]); 
		cout<<res ;
	}	
}
namespace sub3
{
	const int LO = lg(5005) ;
	ll st[5005][LO+1];
	ll f[5005][5005] ; 
	void build(int id)
	{
		FOR(i,0,5000)st[i][0] = f[id][i] ;
		FOR(j,1,LO)FOR(i,0,5000-Mask(j))
		{
			st[i][j] = min(st[i][j-1],st[i+Mask(j-1)][j-1]); 
		}
	}
	ll get(int l ,int r)
	{
		int k = lg(r-l+1) ;
		return min(st[l][k],st[r-Mask(k)+1][k]) ;
	}
	void xuly()
	{
		FOR(i,1,n)
		{
			build(i-1) ; 
			FOR(j,0,5000)
			{	
				f[i][j] = get(max(0,j-H),min(5000,j+H))+abs(a[i]-j) ;
			}
		}
		ll res=inf ; 
		FOR(i,0,5000)mini(res,f[n][i]) ;
		cout<<res;
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
    else 
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.ANS","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // if(H==0)
        // {
	    //     sub1::xuly() ; 
        // }
        // else 
        if(n<=500&&*max_element(a+1,a+n+1)<=400)sub2::xuly() ; 
        // else
        	// sub3::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}