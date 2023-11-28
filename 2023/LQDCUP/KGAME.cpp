/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "KGAME"
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
#define int ll 
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 27 , sm = 1e9+7; 
const int N = 3e4+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , k; 
int f[N] ;

void doc()
{
   	cin>> n >> k; 
   	if(k==1)
   	{
   		cout<<1;
   		exit(0) ;
   	}
}

namespace sub1
{
	int f[N][105];
	int a[N] ;  
	ll ha[N],mu[N] ;
	int cnt =0 ;  
	ll get(int l ,int r)
	{
		return (ha[r] - ha[l-1]*mu[r-l+1]%sm+sm)%sm;
	}
	bool check(int len)
	{
		for(int i=1;i+len-1<=cnt;i+=len)
		{
			if(get(i,i+len-1)!=get(1,len))return 0; 
		}
		return 1; 
	}
    void xuly()
    {
	   	FOR(i,1,3e4)
	   	{
	   		FOR(pre,1,k)
	   		{
	   			FOR(cur,1,k)if(pre!=cur)
	   			{
	   				if(i>=cur&&f[i-cur][cur]==0)
	   				{
	   					f[i][pre] =1 ; 
	   				}
	   			}
	   		}
	   	}
	   	mu[0] = 1; 

	   	FOR(i,1,3e4)mu[i] = mu[i-1]*cs%sm ; 
	   	int pre =0 ;  
	   	FOR(i,1,3e4)
	   	{
	   		bool ok = 0; 
	   		FOR(j,1,k)
	   		{
	   			if(i>=j&&f[i-j][j]==0)
	   			{
	   				ok =1 ;
	   				break;
	   			}
	   		}
	   		if(ok==0)
	   		 	{
	   			a[++cnt] =  i-pre ; 
	   			ha[cnt] = (ha[cnt-1]*cs+a[cnt])%sm;
	   			pre=i ; 
	   		}
	   	}
	   	int ck =0  ; 
	   	FOR(i,1,cnt)
	   	{
	   		if(check(i))
	   		{
	   			ck = i; 
	   			break;
	   		}
	   	}
	   	// prt(a,cnt) ;
	   	// cout<<ck<<el;
	   	assert(ck) ;
	   	assert(ck<=cnt) ;  
	   	int sum = 0; 
	   	FOR(i,1,ck)sum+=a[i] ;
	   	assert(sum) ;
	   	n%=sum ;
	   	int tot = 0;    
	   	FOR(i,1,ck)
	   	{
	   		(tot+=a[i])%=sum; 
	   		if(tot==n)return void(cout<<0) ; 
	   	}
	   	cout<<1<<el; 
    }
}
namespace sub2
{

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
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}