/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "war"
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
const int N = 16e4+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n  , q; 
vi g[N] ;
int deg[N] ;

void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n-1)
    {
    	int u ,v; cin>> u>>v; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    	deg[u]++ ; 
    	deg[v]++ ; 
    }
}

namespace sub1
{
	int h[N] ; 
	void dfs(int u ,int p)
	{
		for(auto v:g[u])if(v!=p)
		{
			h[v]=h[u]+1;
			dfs(v,u) ; 
		}
	}
	vi a[N] ;
	ll s[N] ;  
	int sum[N] ;
	int tp[N] ; 
	struct cmp
	{
		bool operator()(const int&u , const int&v)const
		{
			return (deg[u]<deg[v])||(deg[u]==deg[v]&&u<v) ; 
		}
	} ; 
	void count(int u ,int p ,int ma,int root)
	{
		if(h[u]==ma)
		{
			sum[u] = 1; 
			tp[u]=root; 
			a[root].pb(u);
		}
		for(auto v:g[u])if(v!=p)
		{
			count(v,u,ma,root) ; 
		}
	}
	void solve(int u)
	{
		dfs(u,0) ; 
		int ma = *max_element(h+1,h+n+1) ; 
		ll tot = 0; 	
		for(auto v:g[u])if(v!=u)
		{
			count(v,u,ma,v) ; 
			tot+=SZ(a[v]) ;
			sort(all(a[v])) ;
			// prv(a[v]) ;
		}
		FOR(i,1,n)
		{ 
			s[i] =s[i-1]+(sum[i]?tot-SZ(	a[tp[i]]):0) ;
			sum[i]+=sum[i-1];  
		}
		cout<<s[n]<<el;
		// prt(s,n) ; 
		// prt(sum,n) ; 
		while(q--)
		{
			ll val; cin>>val;
			if(s[n]<val)cout<<0<<" "<<0<<el; 
			else
			{
				int u = LB(s+1,s+n+1,val)-s ; 
				val-=s[u-1] ;
				int l =0 ; 
				int r =SZ(a[tp[u]]) ; 
				int ans = 0 ;
				while(l<=r)
				{
					int mid=(l+r)/2; 
					int sl  = (mid==SZ(a[tp[u]])?sum[n]:sum[a[tp[u]][mid]-1])- mid ; 
					if(sl>=val)
					{		
						ans=mid ; 
						r=mid-1 ;
					}
					else
					{
						l=mid+1; 
					}
				}  
				val+=ans; 
				int v =LB(sum+1,sum+n+1,val)-sum; 
				cout<<u<<" "<<v<<el;				
			}
		}	
	}
	void SOL(int u ,int v)
	{
		dfs(u,v) ;
		int ma = *max_element(h+1,h+n+1) ;
		count(u,v,ma,u) ;  
		dfs(v,u) ;  
		count(v,u,ma,v) ;
		sort(all(a[u])) ; 
		sort(all(a[v])) ; 
		cout<<2ll*SZ(a[u])*SZ(a[v])<<el ;
		FOR(i,1,n)
		{
			s[i] =s[i-1] ;
			if(tp[i]==u)s[i]+=SZ(a[v]) ;
			else if(tp[i]==v)s[i]+=SZ(a[u]) ; 
		}
		while(q--)
		{
			ll val; cin>>val; 
			if(s[n]<val)cout<<0<<" "<<0<<el;
			else
			{
				int x =LB(s+1,s+n+1,val)-s ;
				val-=s[x-1];
				if(tp[x]==u)
				{
					cout<<x<<" "<<a[v][val-1]<<el;
				}
				else
				{
					cout<<x<<" "<<a[u][val-1]<<el;
				}
			}
		}
	}
    void xuly()
    {
		set<int,cmp>S; 
	    FOR(i,1,n)S.insert(i) ;
	    while(1)
	    {
	    	if(SZ(S)<=2)break;
	    	vi tmp ; 
	    	while(1)
	    	{ 
	    		int u = *S.begin();
	    		if(deg[u]==1)
	    		{
	    			tmp.pb(u);
	    			S.erase(u) ; 
	    		}
	    		else break;
	    	}
	    	for(auto u : tmp)
	    	{
	    		deg[u]-- ; 
		    	for(auto v : g[u])if(deg[v])
		    	{
		    		S.erase(v);
		    		deg[v]--;
		    		S.insert(v);
		    	}
	    	}
	    }
	    if(S.size()==1)
	    { 
	    	solve(*S.begin()) ;
		}
		else
		{
			SOL(*S.begin(),*S.rbegin()) ;
		}
    }
}
namespace subtrau
{
	const int N = 205 ;
	int C[N][N] ;
	ve<pii>res;
	void xuly()
	{
		FOR(i,1,n)FOR(j,1,n)C[i][j] = oo ; 
		FOR(u,1,n)
		{
			C[u][u] = 0 ;
			for(auto v : g[u])C[u][v] = 1;
		} 
		FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)mini(C[i][j],C[i][k]+C[k][j]) ; 
		int ma = 0; 
		int cnt = 0; 
		FOR(i,1,n)FOR(j,1,n)
		{
			if(ma==C[i][j])cnt++ ;
			else if( maxi(ma,C[i][j]))cnt=1; 
		}
		if(ma&1)return;   
		cout<<cnt<<el;
		FOR(i,1,n)FOR(j,1,n)if(C[i][j]==ma)res.pb({i,j}); 
		sort(all(res)) ;
		while(q--)
		{
			int val; cin>>val; 
			if(val>SZ(res))cout<<0<<" "<<0<<el;
			else cout<<res[val-1].fi<<" "<<res[val-1].se<<el;
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
        FOR(i,1,n)
        {
        	g[i].clear() ;
        	a[i].clear() ;
        	tp[i] = h[i] =  s[i] = deg[i] = sum[i] = 0 ; 
        }
        // subtrau::xuly(); 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}