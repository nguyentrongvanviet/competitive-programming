/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "key"
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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , k; 
char a[50][50] ; 
void doc()
{
    cin>> n >> m >> k; 
    if(k==10)abort() ;
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ; 
}

namespace sub1
{
	set<ve<pii>>exist[11] ;
	ve<ve<pii>>S;
	bool cmp(pii x , pii y)
	{
		return x.fi<y.fi||(x.fi==y.fi&&x.se<y.se) ; 
	}
	int cnt = 0; 
	void dfs(ve<pii> cur )
	{
		int len = SZ(cur) ; 
		if(len==k)
		{
			S.pb(cur) ; 
			return ; 
		}
		for(auto u : cur)
		{	
			int x = u.fi ;
			int y = u.se ; 
			FORN(i,0,4)
			{
				ve<pii>ne=cur ;
				int nx = x+xx[i] ;
				int ny = y+yy[i] ;
				bool ok = 1 ;
				for(auto u : cur)if(u==mp(nx,ny))
				{
					ok =0 ;
					break;
				}
				if(ok==0)continue;
				ne.pb(mp(nx,ny)) ; 
				FORD(j,SZ(ne)-1,1)
				{
					if(cmp(ne[j],ne[j-1]))swap(ne[j],ne[j-1]) ;
					else break;
				}
				if(nx<0)for(auto &u :ne)u.fi++;
				if(ny<0)for(auto &u :ne)u.se++;
				if(exist[len+1].count(ne)==0)
				{
					exist[len+1].insert(ne) ;
					dfs(ne) ;  
				}
			}
		}

	} 
	bool in(int x ,int y)
	{
		return 1<=x&&x<=n&&1<=y&&y<=m ;
	}
    void xuly()
    {
    	ve<pii> cur={mp(0,0)} ; 
    	exist[1].insert(cur) ;
    	dfs(cur) ; 
    	int res = 0; 
    	for(auto x:exist[k])
    	{
    		FOR(i,1,n)FOR(j,1,m)
    		{	
    			bool ok = 1; 
    			for(auto u : x)
    			{	
    				if(in(u.fi+i,u.se+j)==0 || a[u.fi+i][u.se+j] == '.')
    				{
    					ok = 0;
    					break;
    				}
    			}
	    		res+=ok ;
    		}
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
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}