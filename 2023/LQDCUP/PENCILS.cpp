/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "PENCILS"
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


int n , K ;
int a[N][4] ; 

void doc()
{
	cin>> n >> K; 
	FOR(i,1,n)
	{
		FOR(j,1,3)cin>>a[i][j] ; 
	}    
}
int dis(int i ,int j)
{
	int ma = 0 ; 
	FOR(t,1,3)
	{		
		maxi(ma,max({abs(a[i][t]-a[j][t])})) ; 
	}
	return ma ; 
}
namespace sub1
{
    void xuly()
    {
    	int res = oo ; 
    	int res_msk = 0 ; 
        FORN(msk,1,Mask(n))if(btpc(msk)==K)
        {
        	int tmp = 0 ;
        	FORN(i,0,n)if(BIT(msk,i))FORN(j,0,n)if(BIT(msk,j))
        	{
        		maxi(tmp,dis(i+1,j+1)) ; 
        	}
        	if(mini(res,tmp))res_msk=msk;  
        }
        cout<<res<<el;
        FORN(i,0,n)if(BIT(res_msk,i))
        {
        	FOR(j,1,3)cout<<a[i+1][j]<<" " ;
        	cout<<el;
        }
    }
}
namespace sub2
{
	int s[260][260][260];
	bool check(int len ,int ok )
	{
		int d = len+1; 

		FOR(i,d,256)FOR(j,d,256)FOR(k,d,256)
		// FOR(i,4,4)FOR(j,7,7)FOR(k,5,5)
		{
			int sum = s[i][j][k]
			-s[i-d][j][k]
			-s[i][j-d][k]
			-s[i][j][k-d]
			+s[i-d][j-d][k]+s[i-d][j][k-d]+s[i][j-d][k-d]
			-s[i-d][j-d][k-d] ; 
			;
			// cout<<sum<<el;
			if(sum>=K)
			{
				if(ok)
				{
					FOR(id,1,n)
					{	
						if(i-len<=a[id][1]&&a[id][1]<=i&&j-len<=a[id][2]&&a[id][2]<=j&&k-len<=a[id][3]&&a[id][3]<=k)
						{
							FOR(j,1,3)cout<<a[id][j]-1<<" ";
							cout<<el;
							K--;
						}
						if(K==0)return 1; 
					}
				}
				return 1; 
			}
		}
		return 0; 
	}
	void xuly()
	{
		FOR(i,1,n)
		{
			++a[i][1] ;
			++a[i][2] ; 
			++a[i][3] ;
			s[a[i][1]][a[i][2]][a[i][3]]++ ;
		}
		FOR(i,1,256)FOR(j,1,256)FOR(k,1,256)
		{
			s[i][j][k] += s[i - 1][j][k] + s[i][j - 1][k] + s[i][j][k - 1] 
                           - s[i - 1][j - 1][k] - s[i][j - 1][k - 1] - s[i - 1][j][k - 1] 
                          + s[i - 1][j - 1][k - 1] ; 
		}
		int l = 0  ;
		int r = 255 ; 
		int ans = 0 ; 
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid,0))ans=mid,r=mid-1 ;
			else l=mid+1 ; 
		}
		cout<<ans<<el;
		check(ans,1) ; 
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
        freopen("text.OUT","w",stdout) ;   
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