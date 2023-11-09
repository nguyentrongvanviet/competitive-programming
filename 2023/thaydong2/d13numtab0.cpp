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
const int N = 2e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n; 
int a[N][N] ; 
vi g[N] ; 
void doc()
{
   	cin>> n; 
   	FOR(i,1,n)FOR(j,1,n)cin>>a[i][j]; 
	FOR(i,1,n)FOR(j,1,n)
	{
		if(a[i][j]==1)
		{
			g[i].pb(j) ; 
		}
	}
}

namespace sub1
{
	int dd[N] ; 
	int pa[N] ; 
	bool dfs(int u)
	{
		if(dd[u])return 0 ;
		dd[u] = 1; 
		for(auto v: g[u])
		{
			if(pa[v]==0||dfs(pa[v]))
			{
				pa[v] = u ; 
				return 1; 
			}
		}
		return 0 ; 
	}
	int ne[N] ; 
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		FOR(j,1,n)dd[j] = 0; 
    		dfs(i) ; 
    	}
    	int tmp= 0 ;
    	FOR(i,1,n)
    	{
    		tmp+=(pa[i]!=0) ;
    		ne[pa[i]] = i;
    	}
    	if(tmp!=n)return void(cout<<-1<<el) ;
    	ve<pii>res;
    	FOR(i,1,n)
    	{ 
    		int u = pa[i] ; 
    		if(u==i)continue ;
    		res.pb({u,i}) ;   
    		int v= ne[i] ; 
    		pa[v] = u ; 
    		ne[u] = v ;
    	}
    	cout<<SZ(res)<<el;
    	for(auto x : res)cout<<1<<" "<<x.fi<<" "<<x.se<<el;
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
