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
int a[N] ; 
ll s[N] ; 
ll sum = 0; 
ll AVE ,hi ; 
void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i],sum+=a[i] ;
    AVE = sum/n ;
    hi  = sum%n ; 
}

namespace sub1
{
	const int N = 2e3+5 ;
	ll f[N][N];
    void xuly()
    {
    	FOR(i,0,n)FOR(j,0,n)f[i][j] = inf; 
    	f[0][0] =  0 ;
    	FOR(i,1,n)
        {
        	s[i] = s[i-1]+a[i] ; 
        	FOR(j,0,i-1)
        	{
        		mini(f[i][j],f[i-1][j]+abs(s[i]-AVE*i-j));
        		mini(f[i][j+1],f[i-1][j]+abs(s[i]-AVE*i-j-1));
        	}	
        }
        cout<<f[n][hi]<<el;
    }
}
namespace sub2
{
	map<int,ll>st[4*N][2] ; 
	void solve(int id, int l ,int r )
	{
		if(l==r)
		{
			st[id][0][0] = abs(AVE-a[l]) ; 
			st[id][0][1] = abs(AVE+1-a[l]) ;
			st[id][1][0] = abs(AVE-a[l]) ;
			st[id][1][1] = abs(AVE+1-a[l]) ; 
			return ; 
		}
		int mid=(l+r)/2;
		solve(id*2,l,mid) ; 
		solve(id*2+1,mid+1,r) ;
		int L = mid-l+1 ;
		int R = r-mid ; 
		FOR(i,0,L+R)st[id][0][i]=st[id][1][i]=inf;
		FOR(i,0,L)FOR(j,0,R)
		{
			mini(st[id][0][i+j],st[id*2][0][i]+st[id*2+1][0][j]+L*abs(s[mid]-s[l-1]-AVE*(mid-l+1)-j));
			mini(st[id][1][i+j],st[id*2][1][i]+st[id*2+1][1][j]+R*abs(s[r]-s[mid]-AVE*(r-mid)-i)) ; 
		}
	}
	void xuly()
	{
		solve(1,1,n) ; 
		cout<<min(st[1][1][hi],st[1][0][hi]) ; 
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
        // if(n<=2e3)sub1::xuly() ;
        sub2::xuly(); 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}