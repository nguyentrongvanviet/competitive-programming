/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "dichuyennhonhat"
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


int n , q , k ; 
ll a[N] ,b[N] ;
void doc()
{	
    cin>> n >> q >> k; 	
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n)cin>>b[i] ; 
}

namespace sub1
{
	const int N = 105; 
	int C[N][N] ; 
    void xuly()
    {
    	FOR(i,1,n) 	
    	{
    		FOR(j,1,n)
    		{
    			C[i][j] = (a[i]-a[j]<=k?1:1+b[j]) ; 
    		}
    	}
    	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)
    	{
    		mini(C[i][j],C[i][k]+C[k][j]) ;
    	}
    	while(q--)
    	{
    		int u ,v ;cin>> u >> v ; 
    		if(u<v)
    		{
    			cout<<1<<el;
    			continue ;
    		}
    		else
    		{
    			cout<<C[u][v]<<el;
    		}
    	}
    }
}
namespace sub2
{
	ll st[N][LO+2] ;
	int best[N] ; 
	ll mi[N] ;
	void build()
	{
		FOR(i,1,n)
		{
			st[i][0] = LB(a+1,a+n+1,a[i]-k)-a ;
		}
		FOR(j,1,LO)FOR(i,1,n)
		{
			st[i][j] = st[st[i][j-1]][j-1] ; 
		}
	} 
	ll go(int u ,int v)
	{
		ll ans =0 ; 
		FORD(i,LO,0)
		{
			if(st[u][i]>v)
			{
				ans+=M(i) ; 
				u=st[u][i];
			}
		}
		u = st[u][0] ; 
		if(u>v)return inf ;
		++ans; 
		return ans; 
	}
	void xuly()
	{
		mi[0] = oo ; 
		FOR(i,1,n)mi[i] = min(b[i]+1,mi[i-1]) ; 
		best[n] = n ; 
		build() ;
		FORD(i,n-1,1) 
		{ 
			best[i] = best[i+1] ; 
			if(b[best[i]]+1+go(best[i],i)>b[i]+1)
			{
				best[i] = i ; 
			}
		}
		while(q--)
		{
			int u ,v; cin>> u >> v;
			if(u<v)
			{
				cout<<1<<el;
				continue ; 
			}
			else
			{
			 	ll res = min({mi[v-1]+1,b[v]+1,go(u,v)}) ; 
				mini(res,b[best[v]]+1+go(best[v],v)) ;
				cout<<res<<el;
			}
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}