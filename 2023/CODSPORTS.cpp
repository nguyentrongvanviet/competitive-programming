/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "CODSPORTS"
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
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n;
int pos[N] ; 
int theluc[N] ;
void doc()
{	
    cin>> n; 
    FOR(i,1,n)cin>>pos[i] ; 
    FOR(i,1,n)cin>>theluc[i] ; 
}

namespace sub1
{
	vi g[N] ;
	int dd[N] , pa[N]; 
	bool dfs(int u)
	{
		if(dd[u])return 0 ;
		dd[u] =1 ;
		for(auto v :g[u])
		{
			if(pa[v]==0||dfs(pa[v]))
			{
				pa[v] =u ; 
				return 1; 
			}
		}
		return 0 ; 
	}
    void xuly()
    {
    	int q; cin>>q; 
    	FOR(_,1,q)
    	{
			int kg; cin>>kg;  
    		FOR(i,1,n)
    		{
    			int d = theluc[i]/kg;
    			FOR(j,max(1,pos[i]-d),min(n,pos[i]+d))g[i].pb(j) ; 
    		}	
    		FOR(i,1,n)
    		{
    			FOR(j,1,n)dd[j] = 0 ;
    			dfs(i) ;
    		}
    		int res =0 ; 
    		FOR(i,1,n)if(pa[i])res++ ; 
    		cout<<(res==n)<<" ";
    		FOR(i,1,n)g[i].clear(),pa[i]=0;
    	}
    }
}
namespace sub2
{
	struct query
	{
		int id ;
		int val; 
		bool operator<(const query&a)const
		{
			return val<a.val; 
		} 
	}; 
	query Q[N] ;
	vi g[N] ; 
	bool check(int val)
	{
		FOR(i,1,n)g[i].clear() ;
		priority_queue<int,vi,greater<int>>q ;
		FOR(i,1,n)
		{
			int d = theluc[i]/val; 
			int l = max(1,pos[i]-d) ;
			int r = max(1,pos[i]+d) ; 
			g[l].pb(r) ; 
		}
		FOR(i,1,n)
		{	
			for(auto R : g[i])q.push(R) ; 
			if(q.empty()||q.top()<i)return 0 ;
			q.pop() ; 
		}
		return 1 ; 
	}
	int res[N] ; 
	void xuly()
	{
		int q; 
		cin>>q ;
		FOR(i,1,q)
		{
			cin>>Q[i].val ; 
			Q[i].id = i ;
		}
		sort(Q+1,Q+q+1) ; 
		int l =1  ; 
		int r =q ; 
		int ans = 0;
		while(l<=r)
		{
			int mid=(l+r)/2 ;
			if(check(Q[mid].val))ans=mid,l=mid+1; 
			else r=mid-1 ;
		}
		FOR(i,1,ans)
		{
			res[Q[i].id]= 1; 
		}
		prt(res,q) ; 
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
        // sub1::xuly() ;
        sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}