/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "toys"
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
const ll inf = 1e16 , cs = 331 , sm = 1e9+7; 
const int N = 5e5+5 , oo = 10+(int)2e9 , LO = 20 , CH = 26 ; 


int n; 
struct DL
{
	int c, s ; 
	bool operator<(const DL&a)const
	{
		return c<a.c ; 
	}
} ; 
DL a[N] ; 
void doc()
{
	cin>> n;
	FOR(i,1,n)cin>>a[i].c>>a[i].s ;
	sort(a+1,a+n+1) ; 	
}

namespace sub1
{
	int miR[N] ,miL[N] ,maL[N] ,maR[N]  ;
	int st[4][N][LO+1];
	void rmq()
	{
		st[1][1][0] = st[2][1][0] = st[3][1][0] = oo ;
		FOR(i,2,n)
		{
			st[1][i][0] = -a[i].c+maL[i-1]-miL[i-1] ;
			st[2][i][0] = -a[i].c-miL[i-1]; 
			st[3][i][0] = -a[i].c+maL[i-1];
		}
		FOR(j,1,lg(n))
		{
			FOR(i,1,n-(1<<j)+1)
			{
				FOR(TYPE,1,3)st[TYPE][i][j]=min(st[TYPE][i][j-1],st[TYPE][i+(1<<(j-1))][j-1]);
			}
		}
	}
	int get(int id ,int l, int r )
	{
		if(l>r)return oo ; 
		int k = lg(r-l+1) ; 
		return min(st[id][l][k],st[id][r-(1<<k)+1][k]) ; 
	}
	void xuly()
    {   
    	miL[0] = oo ; 	
    	miR[n+1] = oo ; 
    	FOR(i,1,n)
    	{
    		miL[i] = min(miL[i-1],a[i].s) ; 
    		maL[i] = max(maL[i-1],a[i].s) ; 
    	}
    	FORD(i,n,1)
    	{
    		miR[i] = min(miR[i+1],a[i].s) ; 
    		maR[i] = max(maR[i+1],a[i].s) ; 
    	}
    	rmq() ;
    	ll res =oo ; 
    	FOR(i,1,n)
    	{
    		int x = 0; 
    		int l =1 , r = i ; 
    		while(l<=r)
    		{
    			int mid=(l+r)/2; 
    			if(maL[mid-1]<=maR[i+1])x=mid,l=mid+1 ;
    			else r=mid-1 ;
    		}
    		int y = 0 ; 
    		l = 1 ; 
    		r =  i; 
    		while(l<=r)
    		{
    			int mid=(l+r)/2; 
    			if(miL[mid-1]>=miR[i+1])y =mid ,l=mid+1 ;
    			else r=mid-1 ; 
    		}
    		int u = min(x,y) ; 
    		if(u&&!(i==n&&u==1))
    		{
    			mini(res,1LL*a[i].c-a[u].c-miR[i+1]+maR[i+1]);
    		}
    		u = max(x+1,y+1) ; 
    		mini(res,1ll*a[i].c+get(1,u,i)) ;
    		mini(res,1ll*a[i].c+maR[i+1]+get(2,y+1,x)) ; 
    		mini(res,1ll*a[i].c-miR[i+1]+get(3,x+1,y)) ; 
    	}
    	cout<<res<<el;
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
