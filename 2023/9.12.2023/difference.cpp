/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "difference"
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
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
ve<vi>a; 

void doc()
{
	cin>> n >> m ;
    a.resize(n+2,vi(m+2,0));  
    FOR(i,1,n)FOR(j,1,m)
    {
    	cin>>a[i][j] ;
    }
}

namespace sub1
{
	int C(int x, int y)
	{
		return m*(x-1)+y; 
	}
	ve<pii> same[2*N] ;  
	int pa[N],sz[N] ;
	int goc(int u )
	{
		return pa[u] == u ? u : pa[u] = goc(pa[u]) ;
	}
	int res , res_d , res_st ;
	void hop(int u ,int v,int d )
	{
		int chau = goc(u) ; 
		int chav = goc(v) ;
		if(chau==chav)return;
		if(chau<chav)swap(chau,chav) ;   
		pa[chau] = chav; 
		sz[chav]+=sz[chau] ; 
		if(res<sz[chav]||(res==sz[chav]&&res_d>d)||(res==sz[chav]&&res_d==d&&res_st>v))
		{
			res=sz[chav] ;
			res_d = d ; 
			res_st = chav ; 
		}
	}
    void xuly()
    {
    	vi V ; 
    	FOR(i,1,n)FOR(j,1,m)
    	{	
    		if(i>1)V.pb(abs(a[i][j]-a[i-1][j])) ;
    		if(j>1)V.pb(abs(a[i][j]-a[i][j-1])) ;
    	}
    	uni(V) ; 
    	FOR(i,1,n)FOR(j,1,m)
    	{
    		if(i>1)
    		{
    			int pos = UB(all(V),abs(a[i][j]-a[i-1][j]))-V.begin() ; 
    			same[pos].pb(mp(C(i,j),C(i-1,j))) ; 
    		}
    		if(j>1)
    		{
				int pos = UB(all(V),abs(a[i][j]-a[i][j-1]))-V.begin() ; 
    			same[pos].pb(mp(C(i,j),C(i,j-1))); 
    		}
    	}
    	FOR(i,1,n*m)pa[i] = i ,sz[i]=1;
    	res=1,res_d=0,res_st=1;
    	FOR(i,1,SZ(V))
    	{
    		for(auto e: same[i])
    		{
    			hop(e.fi,e.se,V[i-1]) ;
    		}
    		for(auto e :same[i])
    		{
    			pa[e.fi] = e.fi ;
    			sz[e.fi] =1 ;
    			pa[e.se] = e.se ;
    			sz[e.se] =1 ; 
    		}
    	} 
    	assert(res!=0&&res_d!=-1) ; 
    	cout<<res<<" "<<res_d<<" "<<res_st/m+(res_st%m>0)<<" "<<(res_st%m==0?m:res_st%m)<<el;
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
    int sub ; cin>>sub ; 
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}