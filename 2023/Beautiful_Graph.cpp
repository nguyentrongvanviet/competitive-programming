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

bool mtt = 1 ;
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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 998244353; 
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m; 
vi g[N] ; 
ll mu[N] ; 
int dd[N] ;
void doc()
{
    cin>> n >> m; 

    FOR(i,1,n)g[i].clear(),dd[i]=0 ; 
    FOR(i,1,m)
    {
    	int u ,v; cin>>u>>v ;
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int black = 0 , white=  0 ; 
	bool ok = 1 ; 
	void dfs(int u)
	{
		if(dd[u]==1)
		{
			black++ ;
		}
		else if(dd[u]==2)
		{
			white++ ;
		}
		for(auto v:g[u])
		{
			if(dd[v]==0)
			{
				dd[v] = 3-dd[u] ; 
				dfs(v) ; 
			}
			else if(dd[v]!=3-dd[u])ok = 0 ; 
		}
	}
    void xuly()
    {
    	ll res = 1 ; 
    	ok = 1;
    	FOR(i,1,n)if(dd[i]==0)
    	{
    		black = 0 , white= 0 ; 
    		dd[i] = 1; 
    		dfs(i) ;
    		if(ok==0)
    		{
    			cout<<0<<el;
    			return ; 
    		}
    		(res*=(mu[white]+mu[black])%sm)%=sm; 
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
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;
    mu[0] = 1; 
    FOR(i,1,3e5)
    {
    	mu[i] = mu[i-1]*2%sm; 
    }
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much ! " << clock() <<"ms"<<el;
}