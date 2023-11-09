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
#define int long long 
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n; 
ll a[N] ; 
pii E[N] ;
ll res =0 ; 
vi g[N] ; 
void doc()
{
   	cin>> n; 
   	FOR(i,1,n)cin>>a[i] ; 
   	FOR(i,2,n)
   	{
   		int u ; cin>>u ; 
   		E[i-2].fi = u ; 
   		E[i-2].se = i ; 
   		g[u].pb(i) ;
   		g[i].pb(u); 
   	}
}

namespace sub1
{
	ll tmp = 0 ; 
	int res_msk ; 
	void dfs(int u,int root )
	{
		if(u!=root)tmp+=1ll*a[root]*a[u];
		else tmp+=1ll*a[root]*(a[root]-1);
		for(auto v :g[u])
		{	
			dfs(v,root) ;
		}
	}
    void xuly()
    {
    	FOR(msk,0,(1<<(n-1))-1)
    	{
    		FOR(i,1,n)g[i].clear() ; 
    		FORN(i,0,n-1)
    		{
    			int id = BIT(msk,i) ; 
    			if(id)
    			{
    				g[E[i].fi].pb(E[i].se) ;
    			}
    			else
    			{
    				g[E[i].se].pb(E[i].fi) ; 
    			}
    		}
    		FOR(i,1,n)
    		{
    			dfs(i,i) ; 
    		}
    		if(maxi(res,tmp))res_msk = msk ; 
    		tmp = 0 ; 
    	}
    	FORN(i,0,n-1)
    	{
    		int id = BIT(res_msk,i) ; 
			if(id)
			{
				g[E[i].fi].pb(E[i].se) ;
				// cout<<E[i].fi<<" "<<E[i].se<<el;
			}
			else
			{
				g[E[i].se].pb(E[i].fi) ; 
				// cout<<E[i].se<<" "<<E[i].fi<<el;
			}
		}
    	cout<<res<<el;
    	exit(0) ; 
    }
}
namespace sub2
{
	ll sum =0 , S = 0 ;
	ll f[N] ,sz[N] ;
	void dfs(int u ,int p)
	{
		sz[u] = a[u] ;
		f[u] = 0;  
		for(auto v: g[u])if(v!=p)
		{	
			dfs(v,u) ;
			sz[u]+=sz[v] ; 
			f[u]+= a[u]*sz[v]+f[v] ; 
		}
	}
	void solve(int u )
	{
		dfs(u,0) ;
		ll tmp =0;
		vll q ; 
		for(auto v: g[u])
		{	
			tmp+=f[v] ; 
			q.pb(sz[v]) ; 
		}
		tmp+=1ll*a[u]*(S-a[u]);
		int n = q.size() ; 
		FORN(msk,0,1ll<<n)
		{
			ll sum=0 ; 
			FORN(j,0,n)if(BIT(msk,j))
			{	
				sum+=q[j];
			}
			maxi(res,tmp+sum*(S-a[u]-sum));
		} 
	}
	void xuly()
	{
		res= 0 ; 
		FOR(i,1,n)S+=a[i],sum+=1ll*a[i]*(a[i]-1) ; 
		FOR(i,1,n)
		{
			solve(i) ; 
		}
		cout<<res+sum;
		exit(0) ; 
	}
}
namespace sub3
{
	ll S = 0 ;
	ll f[N] ; 
	ll sz[N] ; 
	ll d[N] ; 
	void dfs(int u ,int p)
	{
		sz[u] = a[u] ;
		for(auto v: g[u])if(v!=p)
		{
			dfs(v,u) ; 
			f[u]+=f[v]+a[u]*sz[v]; 
			sz[u]+=sz[v] ; 
		}
	}
	ll res = 0 ; 
	ll kill(vll&val,ll S)
	{
		int n = val.size() ;
		vll V ;    
		FORN(msk,0,1ll<<(n/2))
		{
			ll sum = 0 ; 
			FORN(i,0,n/2)if(BIT(msk,i))
			{
				sum+=val[i] ; 
			}
			V.pb(sum);
		}	
		uni(V);
		ll ma = 0 ;
		FORN(msk,0,1ll<<(n-n/2))
		{
			ll sum = 0 ; 
			FORN(i,0,n-n/2)if(BIT(msk,i))
			{
				sum+=val[i+n/2]; 
			}
			ll v = UB(all(V),S/2-sum)-V.begin()-1;
			if(v!=-1)
			{
				maxi(ma,(sum+V[v])*(S-(sum+V[v])));
			}
		}	
		return ma ;
	}
	void solve(int u ,int p)
	{
		vll q ; 
		for(auto v : g[u])
		{
			if(v!=p)q.pb(sz[v]) ; 
			else q.pb(S-a[u]-sz[v]);
		} 
		maxi(res,f[u]+d[u]+kill(q,S-a[u])) ; 
		for(auto v:g[u])if(v!=p)
		{ 
			d[v] = d[u]+a[v]*(S-sz[v])+f[u]-(f[v]+a[u]*sz[v]);
			solve(v,u) ; 
		}
	}
	void xuly()
	{
		FOR(i,1,n)S+=a[i] ; 

		dfs(1,0) ; 
		solve(1,0); 
		FOR(i,1,n)
		{
			res+=a[i]*(a[i]-1) ;
		}
		cout<<res;  
		exit(0) ; 
	}
}
namespace sub4
{
	vll V ; 
	void xuly()
	{
		int root ; 
		FOR(i,1,n)if(g[i].size()==36)root = i; 
		ll S = 0 ; 
		FOR(i,1,n)
		{
			res+=1ll*a[i]*(a[i]-1) ; 
		}
		vll val; 
		FORN(i,0,g[root].size())
		{
			S+=a[g[root][i]] ; 
			res+=a[root]*a[g[root][i]] ;
			val.pb(a[g[root][i]]) ; 
		}
		FORN(msk,0,1<<18)
		{
			ll sum = 0 ; 
			FORN(i,0,18)if(BIT(msk,i))
			{
				sum+=val[i] ; 
			}
			V.pb(sum);
		}	
		uni(V);
		ll ma = 0 ;
		FORN(msk,0,1<<18)
		{
			ll sum = 0 ; 
			FORN(i,0,18)if(BIT(msk,i))
			{
				sum+=val[i+18]; 
			}
			ll v = UB(all(V),S/2-sum)-V.begin()-1;
			if(v!=-1)
			{
				maxi(ma,(sum+V[v])*(S-(sum+V[v])));
			}
		}	
		cout<<res+ma ;
		exit(0) ; 
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
       	if(n<=10)sub1::xuly() ; 
        if(n==37)
        {
        	sub4::xuly();
       		exit(0) ; 
       	}
       	FOR(i,1,n)
       	{
       		if(g[i].size()>10)
       		{
       			sub3::xuly() ; 
       		}
       	}
       	sub2::xuly();
    	// sub3::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}