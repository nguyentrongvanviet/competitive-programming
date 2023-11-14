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

int n , k; 
void doc()
{

}

namespace sub1
{
	vi V ; 
	ve<pii>E ; 
	int dd[N] ; 
	vi g[N] ;
	int root = 0 ; 
	int cnt = 0 ; 
	void dfs(int u ,int p)
	{
		dd[u] = 1 ; 
		for(auto v:g[u])if(v!=p)
		{
			if(v==root)cnt++ ; 
			else if(dd[v]==0)dfs(v,u) ; 
		}
	}
    void xuly()
    { 	
    	FOR(i,1,SZ(V))g[i].clear(),dd[i]=0 ;
    	V.clear() ; 
    	E.clear() ; 
		FOR(i,1,k)
		{
			int u ,v;  cin>> u >>v ; 
			E.pb({u,v}) ; 
			V.pb(u) ; 
			V.pb(v) ; 
		} 
		uni(V) ; 
		for(auto x:E)
		{
			int u = UB(all(V),x.fi) - V.begin() ; 
			int v = UB(all(V),x.se) - V.begin() ; 
			g[u].pb(v) ; 
			g[v].pb(u) ; 
		}
		FOR(i,1,SZ(V))
		{
			uni(g[i]); 
			if(SZ(g[i])>2)
			{
				return void(cout<<'N'<<el) ;
			}
		}
		cnt = 0 ;
		int d = 0 ;
		FOR(i,1,SZ(V))if(dd[i]==0)
		{
			root = i ; 
			dfs(i,0) ;
			d++ ; 
		}
		if(cnt==0||(cnt==1&&d==1&&SZ(V)==n))return void(cout<<'Y'<<el) ;
		cout<<'N'<<el;
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
    while(cin>>n>>k)
    {
    	if(n==0&&k==0)return 0 ; 
    	sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}