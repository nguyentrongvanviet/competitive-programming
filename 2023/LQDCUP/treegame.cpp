/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "treegame"
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
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m;
struct Edge
{
	int u ,v; 
}E[N] ; 
void doc()
{
	cin>> n >> m; 
	FOR(i,1,n-1)
	{
		int p ;cin>> p ; 
	}
	FOR(i,1,m)
	{
		int u ,v ;cin>> u>>v ; 
		E[i] = {u,v} ;
	}
}

namespace sub1
{
	int color[N] ; 
	bool ok ;
	struct ke
	{
		int v, type ; 
	} ; 
	ve<ke>g[N] ;
	void dfs(int u ,int c)
	{
		color[u] = c ;
		for(auto [v,type]:g[u])
		{
			if(color[v]==-1)
			{
				dfs(v,c^type) ; 
			}
			else 
			{
				if(color[v]!=(c^type))
				{
					ok = 0; 
					return ; 
				}
			}
		}
	}
	ll check(int id)
	{
		FOR(i,1,n)g[i].clear() ;
		FOR(i,1,id)
		{
			g[E[i].u].pb({E[i].v,0}) ;
			g[E[i].v].pb({E[i].u,0}) ;
		}
		FOR(i,id+1,m)
		{
			g[E[i].u].pb({E[i].v,1}) ; 
			g[E[i].v].pb({E[i].u,1}) ; 
		} 
		FOR(i,1,n)color[i] = -1 ; 
		ll tmp = 1; 
		ok =1 ; 
		FOR(i,1,n)if(color[i]==-1)
		{
			dfs(i,0) ; 
			if(i!=1)(tmp*=2)%=sm ;
		}
		if(ok==0)return 0 ;
		return tmp ; 
	}
    void xuly()
    {
    	ll res = 0 ;
    	FOR(i,0,m)
    	{
    		(res+=check(i))%=sm ; 
    	}
    	cout<<res<<el;
    }
}
namespace sub2
{
	pii pa[N] ;   
	int sz[N] ; 
	pii goc(int u )
	{
		int c= 0 ; 
		while(pa[u].fi!=u)
		{
			c^=pa[u].se;
			u=pa[u].fi ; 
		}
		return mp(u,c) ;
	}
	bool ok ; 
	bool merge(int i, int type)
	{
		int u =E[i].u ; 
		int v =E[i].v ; 
		pii U = goc(u) ;
		
		pii V = goc(v) ;  
		int chau = U.fi ; 
		int du = U.se ;  

		int chav = V.fi ;
		int dv = V.se ;  
		if(sz[chau]>sz[chav])swap(chau,chav),swap(du,dv) ; 
		if(chau!=chav)
		{	
			sz[chav]+=sz[chau] ; 
			pa[chau].fi=chav; 
			pa[chau].se = type^du^dv;
			return 1 ; 
		}
		ok&=((du^dv)==type);
		return 0 ;
	}
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm ;
	}
	ll check(int id)
	{
		ok = 1 ; 
		FOR(i,1,n)pa[i] = {i,0},sz[i]=1 ; 
		int tplt = n; 
		FOR(i,1,id)
		{
			tplt-=merge(i,0) ; 
		}
		FOR(i,id+1,m)
		{
			tplt-=merge(i,1); 
		}
		if(ok==0)return 0 ;
		return pw(2,tplt-1) ;
	}
	void xuly()
	{
		ll res =0 ; 
		FOR(i,0,m)
		{
			(res+=check(i))%=sm; 
		}
		cout<<res<<el;
	}
}
namespace sub3
{
	struct DL
	{
		int u ,v , ok ; 
	} ;
	int sz[N] ; 
	pii pa[N] ; 
	stack<DL>st ;
	pii goc(int u)
	{
		int c = 0 ;
		while(pa[u].fi!=u)
		{
			c^=pa[u].se;
			u=pa[u].fi ;  
		}
		return mp(u,c) ;
	} 
	void roll_back(int len)
	{
		while(SZ(st)>len)
		{
			int u =st.top().u ;
			int v= st.top().v; 
			st.pop() ; 
			pa[u].fi= u ;
			pa[u].se = 0 ; 
			sz[v]-=sz[u] ; 
		}
	}
	bool merge(int i ,int type)
	{
		int u =E[i].u ; 
		int v =E[i].v ; 
		pii U = goc(u) ;
		pii V = goc(v) ;
		int chau = U.fi ; 
		int du = U.se ;
		int chav = V.fi ;
		int dv = V.se ;
		if(sz[chau]>sz[chav])
		{
			swap(chau,chav) ; 
			swap(du,dv) ; 
		}
		if(chau!=chav)
		{
			sz[chav]+=sz[chau] ; 
			pa[chau].fi =chav; 
			pa[chau].se = du^dv^type ;
			int nok = (!st.empty()?st.top().ok:1); 
			st.push({chau,chav,nok});
			return 1 ; 
		}
		int nok = (!st.empty()?st.top().ok:1); 
		if((du^dv)!=type)nok=0;
		st.push({0,0,nok}) ;
		return 0 ; 
	} 	
	ll tmp = 0 ;
	ll pw(ll a, ll n)
	{
		if(n==0) return 1;   
		ll b = pw(a,n/2); 
		if(n&1)return b*b%sm*a%sm;
		return b*b%sm ;
	}
	ll res = 0 ; 
	void solve(int l ,int r)
	{
		if(l>r)return ; 
		int mid=(l+r)>>1;
		int ST = SZ(st) ;  
		FOR(i,l,mid)merge(i,0) ;
		FOR(i,mid+1,r)merge(i,1) ; 

		if(st.top().ok)(res+=tmp)%=sm; 
		roll_back(ST) ;
		
		FOR(i,l,mid)merge(i,0);
		
		solve(mid+1,r) ; 
		roll_back(ST) ; 
		
		FOR(i,mid,r)merge(i,1) ;
		solve(l,mid-1);
		roll_back(ST) ; 
	
	}
	void xuly()
	{
		int tplt = n ;
		FOR(i,1,n)
		{
			pa[i] = {i,0};  
			sz[i] = 1; 
		}
		FOR(i,1,m)if(merge(i,0))tplt--; 
		tmp = pw(2,tplt-1) ;
		roll_back(0) ; 
		// FOR(i,1,n)cout<<pa[i].fi<<" "<<pa[i].se<<" "<<sz[i]<<el;
		solve(0,m) ; 
		cout<<res;
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
        // sub1::xuly() ; 
        // sub2::xuly() ; 
        sub3::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}