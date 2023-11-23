/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "SHEEP"
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
const int N = 5e5 +5 , oo = 2e9 , LO = 20 , CH = 26 ; 


int n , k ; 
int f[N][2] ; 
vi g[N] ;
int spec[N] ; 
void doc()
{
    cin>> n >> k; 
    FOR(i,1,n-1)
    {
    	int u ,v  ;cin>> u>>v ;
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
    FOR(i,1,k)cin>>spec[i] ; 
}
bool check1()
{ 
	FORN(i,1,n)
	{
		int nok = 0 ;
		for(auto v:g[i])if(v==i+1)nok=1 ;
		if(nok==0)return 0 ; 
	}
	return 1; 
}
namespace sub1
{
	int f[N] ;
	void trace(int k)
	{
		while(k)
		{
			if(f[k]==f[k-1]+1)
			{
				cout<<spec[k]<<" ";
				--k;
			}
			else
			{
				cout<<(spec[k-1]+spec[k])/2<<" ";
				k-=2;
			}
		}
	}
    void xuly()
    {
		sort(spec+1,spec+k+1) ;	
		FOR(i,1,k)
		{
			f[i] =f[i-1]+1; 
			if(i>=2&&(spec[i]-spec[i-1])%2==0)mini(f[i],f[i-2]+1) ;  
		}
    	cout<<f[k]<<el ;
    	trace(k) ; 
    }	
}
namespace sub2
{	 
	int h[N] ; 
	int P[N][LO+2] ; 
	void dfs(int u ,int p)
	{
		for(auto v: g[u])if(v!=p)
		{
			h[v] = h[u]+1; 
			P[v][0] = u ; 
			dfs(v,u) ; 
		}
	}
	int lca(int u ,int v)
	{
		assert(u&&v);
		if(h[u]<h[v])swap(u,v) ;
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])u=P[u][i] ; 
		if(u==v)return u; 
		FORD(i,LO,0)
		{
			int nu = P[u][i] ; 
			int nv = P[v][i] ;
			if(nu!=nv)
			{
				u=nu ; 
				v=nv ; 
			}
		}
		return P[u][0] ; 
	}
	int near[N];
	void bfs()
	{
		queue<int>q ; 
		FOR(i,1,n)near[i] = oo ; 
		FOR(i,1,k)q.push(spec[i]),near[spec[i]]= 0; 
		while(!q.empty())
		{
			int u =q.front() ;
			q.pop();
			for(auto v:g[u])if(mini(near[v],near[u]+1))
			{
				q.push(v) ;
			}
		} 
	}
	int DIS(int u ,int v)
	{
		int c = lca(u,v) ;
		return h[u]+h[v]-2*h[c] ; 
	}
	int cen[N] ; 
	int mid(int u, int v)
	{
		if(h[u]<h[v])swap(u,v) ; 
		int d = DIS(u,v)/2 ; 
		FORD(i,LO,0)if(BIT(d,i))u=P[u][i] ;
		return u ;
	}
	int build(int msk)
	{
		int u = spec[ctz(msk)+1] ; 

		int dis = -5;
		int ans = 0 ; 
		assert(u) ;
		FORN(i,0,k)if(BIT(msk,i))
		{	
			if(maxi(dis,DIS(u,spec[i+1])))
			{
				ans = spec[i+1] ; 
			}
		}
		u = ans;  
		dis = -5 ;  
		ans = 0 ;
		FORN(i,0,k)if(BIT(msk,i))
		{
			if(maxi(dis,DIS(u,spec[i+1])))
			{
				ans = spec[i+1] ; 
			}
		}
		int v= ans; 
		assert(u&&v) ;
		int d = mid(u,v) ; 
		assert(d) ; 
		FORN(i,0,k)if(BIT(msk,i))
		{
			if(near[d]!=DIS(d,spec[i+1]))return 0 ;
		}
		return d; 
	}
	ll f[N] ;
	int trace[N] ; 
	void truyvet(int msk)
	{
		assert(trace[msk]) ;
		if(trace[msk] == msk)return void(cout<<cen[msk]<<" ") ; 
		truyvet(trace[msk]) ;
		truyvet(msk^trace[msk]) ;
	}
	void xuly()
	{
		dfs(1,0); 
		FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1]; 
		bfs() ; 
		FORN(msk,1,Mask(k))
		{
			cen[msk] = build(msk) ;
		}
		FORN(msk,1,Mask(k))
		{
			f[msk] = oo  ; 
			if(cen[msk])f[msk] = 1,trace[msk]=msk; 
			else
			{
				for(int ss = msk ; ss!=0;ss=(ss-1)&msk)
				{
					if(mini(f[msk],f[ss]+f[msk^ss]))
					{
						trace[msk] = ss ; 
					} 
				}
			}
		}
		cout<<f[Mask(k)-1]<<el;
		truyvet(Mask(k)-1) ; 
	}
}
namespace sub4
{
	int near[N]  ;
	void bfs()
	{
		queue<int>q; 
		FOR(i,1,n)near[i] = oo ;
		FOR(i,1,k)
		{
			q.push(spec[i]) ; 
			near[spec[i]]= 0 ; 
		}
		while(!q.empty())
		{
			int u = q.front() ; 
			q.pop() ;
			for(auto v:g[u])if(mini(near[v],near[u]+1))
			{
				q.push(v) ; 
			}
		}
	}
	int h[N] ; 
	int pa[N] ; 
	int dd[N] ;
	void dfs(int u ,int p)
	{
		for(auto v:g[u])if(v!=p)
		{
			pa[v] = u ;  
			h[v] = h[u]+1 ;
			dfs(v,u) ; 
		}
	}
	void go(int u ,int len)
	{
		dd[u] =1 ;
		if(len-1>=0)
		{
			for(auto v:g[u])
			{	
				go(v,len-1) ; 
			}
		}
	}
	void xuly()
	{
		bfs() ; 
		dfs(1,0) ; 
		sort(spec+1,spec+k+1,[&](int u ,int v){return h[u]>h[v];}) ; 	
		vi res; 
		
		FOR(i,1,k)
		{		
			int u =spec[i] ;
			if(dd[u])continue ; 
			int ans=u ;
			int tmp = pa[u] ; 
			while(tmp)
			{
				if(near[tmp]==h[u]-h[tmp]) 	
				{
					ans=tmp ; 
				}
				tmp = pa[tmp] ;

			}
			// cout<<u<<" "<<ans<<" "<<h[u]-h[ans]<<el;
			go(ans,h[u]-h[ans]) ;
			res.pb(ans) ;  	

		}
		cout<<SZ(res)<<el; 
		for(auto v: res)cout<<v<<" "; 
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
    else 
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        if(check1())sub1::xuly() ; 
        else
        if(k<=15)
        sub2::xuly() ;
   		else 
   		sub4::xuly() ;
     	// else abort() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}