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
const int N = 5e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q; 
vi g[N] ;
int a[N]; 
void doc()
{	
    cin>> n >> q; 
    FOR(i,1,n)
    {
    	cin>>a[i] ; 
    	if(i!=1)
    	{
    		int u ;cin>>u ; 
    		g[u].pb(i) ; 
    	}
    }
}

namespace sub1
{
	int tt = 0 ;	
	int in[N] , out[N] ;
	int val[N] ;
	void dfs(int u)
	{
		in[u]=++tt; 
		val[tt] = a[u] ; 
		for(auto v:g[u])
		{
			dfs(v) ; 
		}
		out[u]=tt;
	}
	struct treebit
	{
		vll bit ; 
		treebit(int _n)
		{
			n=_n ;
			bit=vll(n+1,0) ; 
		}
		void up(int id, int val)
		{
			for(int i = id;i<=n;i+=i&-i)bit[i]+=val;
		}
		void up(int l ,int r ,int val)
		{
			up(l,val); 
			up(r+1,-val) ;
		}
		ll get(int id)
		{
			ll ans = 0; 
			for(int i=id;i;i-=i&-i)ans+=bit[i] ; 
			return ans ; 
		}
	} ; 
    void xuly()
    {
        dfs(1) ;
        treebit bit(n) ; 
        FOR(i,1,n)bit.up(i,val[i]-val[i-1]) ; 
        FOR(_,1,q)
        {
        	char x; cin>>x ;
        	if(x=='p')
        	{
        		int u , val; cin>>u>>val ; 
        		bit.up(in[u]+1,out[u],val);
        	}
        	else
        	{
        		int u ;cin>> u ; 
        		cout<<bit.get(in[u])<<el;
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}