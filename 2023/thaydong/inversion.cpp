/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "inversion"
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
const int N = 5e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q; 
int a[N] ; 
void doc()
{
	cin>> n ;   
	FOR(i,1,n)
	{
		char x ; cin>>x ;
		a[i] = x-'a'+1;  
	}	
	cin>>q ; 
}

namespace sub1
{
	int cnt['z'+5] ;
    void xuly()
    {

        FOR(_,1,q)
        {
        	int l ,r ; cin>>l>>r ;
        	ll res = 0 ;  
        	FOR(i,l,r)
        	{
        		FOR(j,a[i]+1,'z')res+=cnt[j] ;
        		cnt[a[i]]++;
        	}
        	cout<<res<<el;
        	FOR(i,'a','z')cnt[i] = 0 ; 
        }
    }
}
namespace sub2
{
	ll s[N][CH+4] ;
	ll cnt[N][CH+3] ; 
	ll f[N] ; 
	void xuly()
	{
		FOR(i,1,n)
		{
			FORD(j,CH,1)
			{
				cnt[i][j] = cnt[i-1][j]+(a[i]==j) ; 
				s[i][j] = s[i-1][j]+(a[i]>j) ;
			}
		}
		FOR(i,1,n)
		{
			f[i] = f[i-1]+s[i][a[i]] ; 
		}
		FOR(_,1,q)
		{
			int l, r; cin>>l>>r ; 
			ll res = f[r]-f[l-1] ; 
			FOR(i,1,CH)
			{
				res-=s[l-1][i]*(cnt[r][i]-cnt[l-1][i]) ; 
			}
			cout<<res<<el;
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ;
        sub2::xuly() ;  
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}