/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "haichutrinh"
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


int n ;
vi g[N] ; 
void doc()
{
    cin>> n; 
    FOR(i,1,2*n-3)
    {
    	int u , v; cin>> u >>v ;
    	g[u].pb(v) ;
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int dd[N] ; 
	int pa[N] ; 
	int h[N] ; 
	pii res[N] ; 
	void in(int u ,int v)
	{
		while(1)
		{
			cout<<u<<" ";
			if(u==v)break; 
			u=pa[u] ; 
		}
	}
	int la = 0 ;
	vi Q[N] ; 
	void dfs(int u ,int p)
	{
		dd[u] = 1; 
		for(auto v:g[u])if(v!=p)
		{
			if(dd[v]&&h[v]<h[u])
			{
				if(res[h[u]-h[v]+1]!=mp(0,0))
				{
					cout<<h[u]-h[v]+1<<el;
					in(res[h[u]-h[v]+1].fi,res[h[u]-h[v]+1].se) ;
					cout<<el;
					in(u,v) ;
					exit(0) ; 
				}

				Q[u].pb(v) ; 
				res[h[u]-h[v]+1]=mp(u,v) ;
			}
			else if(dd[v]==0)
			{
				// cout<<u<<" "<<v<<el;
				h[v] = h[u]+1 ;
				pa[v] = u ; 
				dfs(v,u) ;
			} 
		}
	}
    void xuly()
    {	
    	FOR(i,1,n)if(dd[i]==0)dfs(i,0) ;
    	cout<<3<<el;
    	in(res[3].fi,res[3].se) ;
    	cout<<el;
    	cout<<1<<" ";
    	int v = find(h+1,h+n+1,n-1)-h;
    	cout<<v<<" ";
    	for(auto x:g[1])if(h[x]==n-2)return void(cout<<x<<el) ; 
    	for(auto x:g[v])if(h[x]==1)return void(cout<<x<<el);
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