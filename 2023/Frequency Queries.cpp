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
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e6+5 , oo = 2e9 , LO = 19 , CH = 26 ; 

int n , q ; 
int a[N] ;
vi g[N]; 
struct Query
{
	int id ,l , k; 
} ; 
ve<Query>Q[N] ; 

void doc()
{
  	cin>> n >>q; 
  	FOR(i,1,n)
  	{
  		cin>>a[i] ; 
  	}
  	FOR(i,2,n)
  	{
  		int u ; cin>>u ; 
  		g[u].pb(i) ; 
  	}
  	FOR(i,1,q)
  	{
  		int u , l , k; 
  		cin>>u>>l>>k ;

  		Q[u].pb({i,l,k}) ; 
  	}
}

namespace sub1
{
	int cnt[N] , bit[N] ; 
	set<int>c[N] ; 
	int res[N] ; 
	void up(int idx, int val)
	{
		for(int i=idx;i<=n;i+=i&-i)
		{
			bit[i]+=val;  
		}
	}
	int get(int idx)
	{
		int ans = 0 ; 
		for(int i=idx;i;i-=i&-i)ans+=bit[i] ; 
		return ans ; 
	}
	int find(int k)
	{		
		int pos = 0 , val = 0; 
		FORD(i,LO,0)
		{		
			if(pos+(1<<i)<=n&&val+bit[pos+(1<<i)]<k)
			{
				pos+=(1<<i) ; 
				val+=bit[pos] ;
			}
		}
		return (pos==n?-1:*c[pos+1].begin()) ; 
	}
	void change(int color ,int val )
	{	
		int &sl = cnt[color] ; 
		if(sl)
		{
			up(sl,-1) ; 
			c[sl].erase(color) ; 
		}
		sl+=val;
		if(sl)
		{
			up(sl,1);
			c[sl].insert(color) ;  
		}
	}
	int solve(int l ,int k)
	{
		int d = get(l-1) ; 
		k+=d; 
		return find(k);
	}	
	inline void dfs(int u ,int p)
	{
		change(a[u],1) ; 
		for(auto q : Q[u])res[q.id] = solve(q.l,q.k);
		for(auto v:g[u])dfs(v,u) ; 
		change(a[u],-1) ; 
	}
    void xuly()
    {
    	dfs(1,0);  
    	FOR(i,1,q)cout<<res[i]<<" ";
    	cout<<el;
    	FOR(i,1,n)
    	{
    		g[i].clear() ; 
    		Q[i].clear() ; 
    	}
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

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}