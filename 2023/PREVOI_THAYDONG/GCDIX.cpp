/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "GCDIX"
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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , q ;
int a[N] ; 
vi g[N] ;

void doc()
{
    cin>> n >>q ;
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n-1)
    {
    	int u ,v; cin>> u >>v ;
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int bit[N] ; 
	int st[4*N] ; 
	void up(int id, int val)
	{
		for(int i=id;i<=n;i+=i&-i)bit[i]+=val;
	}
	int get(int id)
	{
		int ans = 0; 
		for(int i=id;i;i-=i&-i)ans+=bit[i];
		return ans; 
	}
	void update(int id , int l ,int r ,int pos , int val)
	{
		if(l==r&&l==pos)
		{
			st[id]+=val;
			return ; 
		}
		if(r<pos||pos<l)return ; 
		int mid = (l+r)>>1 ;
		update(id<<1,l,mid,pos,val) ; 
		update(id<<1|1,mid+1,r,pos,val) ; 
		st[id] = gcd(st[id<<1],st[id<<1|1]) ;
	}
	int GET(int id , int l ,int r ,int t ,int p )
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return 0 ; 
		int mid = (l+r)>>1;
		return gcd(GET(id<<1,l,mid,t,p),GET(id<<1|1,mid+1,r,t,p)) ; 
	}	
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		up(i,a[i]-a[i-1]) ;
    		update(1,1,n,i,a[i]-a[i-1]) ;
    	} 
    	FOR(i,1,q)
    	{
    		int type ; cin>>type ;
    		if(type==1)
    		{
    			int u , v , k ;cin>> u >> v >> k;
    			if(u>v)swap(u,v) ;
    			up(u,k) ;
    			up(v+1,-k) ; 
    			update(1,1,n,u,k) ;
    			update(1,1,n,v+1,-k) ;
    		}
    		else
    		{
    			int u ,v ;cin>> u >>v ;
    			if(u>v)swap(u,v) ; 
    			cout<<abs(gcd(get(u),GET(1,1,n,u+1,v)))<<el;
    		}
    	}
    }
}
namespace sub2
{
	void xuly()
	{
		FOR(i,1,q)
    	{
    		int type ; cin>>type ;
    		if(type==1)
    		{
    			int u , v , k ;cin>> u >> v >> k;
    			if(u>v)swap(u,v) ;
    			FOR(j,u,v)a[j]+=k;
    		}
    		else
    		{
    			int u ,v ;cin>> u >>v ;
    			if(u>v)swap(u,v) ; 
    			int ans =0 ;
    			FOR(j,u,v)ans=gcd(ans,a[j]) ;
    			cout<<ans<<el;
    		}
    	}
	}
}
namespace sub0
{
	int pa[N] ; 
	int h[N] ;
	int tt = 0 ;
	void dfs(int u ,int p)
	{
		for(auto v:g[u])if(v!=p)
		{
			h[v] = h[u]+1 ;
			dfs(v,u) ;
			pa[v] = u; 
		}
	}
	void up(int u ,int v , int val)
	{
		while(u!=v)
		{
			if(h[u]<h[v])swap(u,v) ;
			a[u]+=val;
			u=pa[u] ;
		}
		a[u]+=val;
	}
	int get(int u ,int v)
	{
		int ans = 0 ;
		while(u!=v)
		{
			if(h[u]<h[v])swap(u,v) ;
			ans=gcd(ans,a[u]) ;
			u=pa[u] ;
		}
		ans=gcd(ans,a[u]) ;
		return ans;  
	}
	void xuly()
	{
		dfs(1,0) ; 
		while(q--)
		{
			int type  , u, v; cin>>type>>u>>v;
			if(type==1)
			{
				int val ;cin>>val;
				up(u,v,val) ;
			}
			else
			{
				cout<<get(u,v)<<el;
			}
		}
	}
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/
bool check1()
{
	FOR(i,1,n-1)if(count(all(g[i]),i+1)==0)return 0 ;
	return 1;
}
namespace sub3	
{
	int h[N] ; 
	int pa[N] , sz[N] , heavy[N] ; 
	void dfs(int u ,int p)
	{
		sz[u] = 1 ; 
		for(auto v:g[u])if(v!=p)
		{
			h[v] = h[u]+1;
			dfs(v,u) ; 
			pa[v] = u ;
			sz[u]+=sz[v] ;
			if(sz[heavy[u]]<sz[v])
			{
				heavy[u] = v; 
			}
		}
	}
	int head[N] , at[N] , pos[N] ;
	int tt = 0 ;
	void build_HLD()
	{
		FOR(i,1,n)if(heavy[pa[i]]!=i)
		{
			for(int u = i ; u!=0;u=heavy[u])
			{
				head[u] = i ;
				pos[u] = ++tt ;
				at[tt] = u ; 
			}
		}
	}
	struct seg
	{
		int n; 
		vi st ; 
		seg(int _n=0)
		{
			n=_n ;
			st.resize(4*n,0) ; 
		}

		void up(int id , int l ,int r, int pos , int val)
		{
			if(l==r&&l==pos)
			{
				st[id]+=val;
				return ; 
			}
			if(r<pos||pos<l)return ; 
			int mid = (l+r)>>1; 
			up(id<<1,l,mid,pos,val) ; 
			up(id<<1|1,mid+1,r,pos,val) ; 
			st[id] = gcd(st[id<<1],st[id<<1|1]) ;
		}
		void up(int pos ,int val)
		{
			up(1,1,n,pos,val) ; 
		}
		int get(int id ,int l ,int r , int t ,int p )
		{
			if(t<=l&&r<=p)return st[id] ; 
			if(r<t||p<l)return 0 ;
		  	int mid = (l+r)>>1 ;
			return gcd(get(id<<1,l,mid,t,p),get(id<<1|1,mid+1,r,t,p)) ; 
		}
		int get(int t ,int p )
		{
			return get(1,1,n,t,p) ; 
		}
	}IT ;
	struct fen
	{
		int n; 
		vi bit ;
		fen(int _n=0)
		{
			n=_n ;
			bit.resize(n+1,0) ; 
		}
		void up(int id ,int val)
		{
			for(int i= id;i<=n;i+=i&-i)bit[i]+=val;
		}
		int get(int id)
		{
			int ans =0 ; 
			for(int i=id;i;i-=i&-i)ans+=bit[i] ; 
			return ans;  
		}
		int get(int l ,int r)
		{
			return get(r)-get(l-1) ;
		}
	}BIT ; 
	void up(int u ,int v,int val)
	{
		while(head[u]!=head[v])
		{
			if(h[head[u]]<h[head[v]])swap(u,v) ;
			IT.up(pos[head[u]],val) ; 
			IT.up(pos[u]+1,-val) ;
			BIT.up(pos[head[u]],val) ;
			BIT.up(pos[u]+1,-val) ;
			u=pa[head[u]] ; 
		}
		if(pos[u]>pos[v])swap(u,v) ;
		BIT.up(pos[u],val) ;
		BIT.up(pos[v]+1,-val) ;
		IT.up(pos[u],val) ;
		IT.up(pos[v]+1,-val) ;
	}
	int get(int u ,int v)
	{
		int ans = 0 ;
		while(head[u]!=head[v])
		{	
			if(h[head[u]]<h[head[v]])swap(u,v) ;
			ans=gcd(ans,gcd(BIT.get(pos[head[u]]),IT.get(pos[head[u]]+1,pos[u]))) ;
			u=pa[head[u]] ;
		}
		if(pos[u]>pos[v])swap(u,v) ;
		ans=gcd(ans,gcd(BIT.get(pos[u]),IT.get(pos[u]+1,pos[v]))) ;
		return abs(ans) ;
	}
	void xuly()
	{		
		dfs(n/2,0) ; 
		build_HLD() ; 
		assert(n==tt) ;
		IT = seg(n) ; 
		BIT = fen(n) ; 
		FOR(i,1,n)
		{
			IT.up(i,a[at[i]]-a[at[i-1]]) ;
			BIT.up(i,a[at[i]]-a[at[i-1]]) ;
		}
		FOR(i,1,q)
		{
			int type , u , v; cin>> type>>u>>v;
			if(type==1)
			{
				int val; cin>>val; 
				up(u,v,val) ;
			}
			else
			{
				cout<<get(u,v)<<el;
			}
		}
	}	
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    // if(fopen(INPUT,"r"))
    // {
    //     freopen(INPUT ,"r",stdin) ;
    //     freopen(OUTPUT,"w",stdout);
    // }
    // else 
    if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // if(check1())sub1::xuly() ; 
       	// else
       	 sub3::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}