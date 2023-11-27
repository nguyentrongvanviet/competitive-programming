/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "thaydoimau"
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
const int N = 2e5+5 , oo = 1e9+5 , LO = 17 , CH = 26 ; 


int n ,q ; 
int a[N] ;
vi g[N] ; 

void doc()
{
    cin>> n >> q ; 
    FOR(i,1,n)cin>>a[i] ;
    FOR(i,1,n-1)
    {
    	int u ,v; cin>> u >>v; 
    	g[u].pb(v) ;
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int h[N] ;
	int pa[N] ; 
	void dfs(int u ,int p )
	{
		for(auto v:g[u])if(v!=p)
		{
			h[v] = h[u] + 1;
			pa[v] = u ;  
			dfs(v,u) ; 
		}
	}
	void solve(int u ,int v, int c)
	{
		int x = 0 , y= 0 ;
		if(a[u]==c)x=u ; 
		if(a[v]==c)y=v ;  
		int res = oo ; 
		while(u!=v)
		{
			if(h[u]<h[v])
			{
				v=pa[v] ;
				if(a[v]==c)
				{
					if(y)mini(res,h[y]-h[v]) ; 
					y=v;
				}	
			}
			else
			{
				u=pa[u] ; 
				if(a[u]==c)
				{
					if(x)mini(res,h[x]-h[u]) ;  
					x=u ;  
				}
			}
		}
		if(x&&y&&(x!=y))mini(res,h[x]+h[y]-2*h[u]) ;
		if(res>n-1)cout<<-1<<el ;
		else cout<<res<<el;
	}
    void xuly()
    {
    	assert(n<=5e3) ;
       	dfs(1,0) ;
       	FOR(_,1,q)
       	{
       		char x ;cin>>x ;
       		if(x=='Q')
       		{
       			int u , v, c ; 
       			cin>>u >> v>> c;
       			solve(u,v,c) ; 
       		}
       		else
       		{
       			int u , c; cin>> u >>c; 
       			a[u] =c ;
       		}
       	} 
    }
}
namespace sub2
{
	int h[N] , pa[N] , sz[N], heavy[N] ; 
	int root[N] ,pos[N] ,at[N]; 
	struct Query
	{
		int id ; 
		char TYPE ; 
		int sign , a, b ;
	} ;
	ve<Query> Q[N] ;
	int tmp[N] ;
	int res[N] ; 
	void dfs(int u ,int p)
	{
		sz[u] = 1;  
		for(auto v:g[u])if(v!=p)
		{
			h[v] = h[u]+1 ; 
			pa[v] = u ;
			dfs(v,u) ;
			sz[u]+=sz[v] ;
			if(sz[v]>sz[heavy[u]])
			{
				heavy[u] = v; 
			}
		}
	}
	void build_hld()
	{
		int tt = 0; 
		FOR(i,1,n)if(heavy[pa[i]]!=i)
		{
			for(int u = i ; u;u=heavy[u])
			{
				++tt; 
				root[u] = i ; 
				at[tt] = u ;
				pos[u] = tt ; 
			}
		}
		// cout<<"at"<<el;
		// prt(at,tt) ;
		// cout<<"root"<<el;
		// prt(root,tt) ; 
		// cout<<"h"<<el;
		// prt(h,tt) ;
		// cout<<"pos"<<el;
		// prt(pos,n) ;
	}
	struct DL
	{
		int L , R; 
		int ans ;
		DL(int _L=2*n,int _R=-2*n,int _ans=oo)
		{
			L=_L ;
			R=_R;
			ans=_ans;
		}
	} ;
	DL merge(DL L , DL R)
	{
		int l = min(L.L,R.L); 
		int r = max(L.R,R.R); 
		int ans = min({L.ans,R.ans,R.L-L.R});
		return DL(l,r,ans) ;
	}
	struct SEG
	{
		int n ; 
		ve<DL>st; 
		SEG(int _n = 0)
		{
			n=_n ;
			st.resize(4*n+5) ;  
		}
		void up(int id  ,int l , int r, int pos  ,int sign)
		{
			if(l==r&&l==pos)
			{
				if(sign==1)
					st[id] =DL(h[at[l]],h[at[l]],oo) ; 
				else
					st[id] =DL();
				return ; 
			}
			if(r<pos||pos<l)return ;

			int mid =(l+r)>>1; 
			
			up(id<<1,l,mid,pos,sign) ;
			up(id<<1|1,mid+1,r,pos,sign) ;
			
			st[id] = merge(st[id<<1],st[id<<1|1]) ; 
		}	
		DL get(int id ,int l ,int r, int t  ,int p)
		{
			if(t<=l&&r<=p)return st[id] ;
			
			if(r<t||p<l)return DL() ;
			
			int mid = (l+r)>>1; 
			
			return merge(get(id<<1,l,mid,t,p),get(id<<1|1,mid+1,r,t,p)) ; 
		}
		void up(int u , int sign)
		{
			up(1,1,n,pos[u],sign) ; 
		}
		DL get(int u, int v)
		{
			return get(1,1,n,pos[u],pos[v]) ; 
		}
	} IT ;
	int get(int u ,int v)
	{
		DL U , V ; 
		while(root[u]!=root[v])
		{
			if(h[root[u]]>h[root[v]])
			{
				U= merge(IT.get(root[u],u),U) ;
				u=pa[root[u]] ; 
				// cout<<"X"<<el;
			}
			else
			{
				V= merge(IT.get(root[v],v),V) ;
				v=pa[root[v]] ;
				// cout<<"Y"<<el;
			} 
			// cout<<"V"<<el;
			// cout<<U.L<<" "<<U.ans<<el;
			// cout<<V.L<<" "<<V.ans<<el;
			// cout<<"A"<<el;
		}
		int c= 0 ;
		if(h[u]>h[v])
		{
			U=merge(IT.get(v,u),U) ; 
			c=v ; 
		}
		else
		{
			V=merge(IT.get(u,v),V) ; 
			c = u ;
		}
		int res = min(U.ans,V.ans) ; 
		if(U.L>0&&V.L>0)
		{
			mini(res,U.L+V.L-2*h[c]) ; 
		}
		return res; 
	}
	void solve(ve<Query>&Q)
	{
		FORN(i,0,SZ(Q))
		{
			char TYPE = Q[i].TYPE ; 
			if(TYPE=='Q')
			{				
				int a = Q[i].a ;
				int b = Q[i].b ; 
				int id = Q[i].id; 
				res[id] = get(a,b) ; 
				// cout<<TYPE<<" "<<a<<" "<<b<<el;
			}	
			else
			{	
				int a = Q[i].a; 
				int sign = Q[i].sign; 
				// cout<<TYPE<<" "<<a<<" "<<sign<<el;
				IT.up(a,sign) ; 
			}
		}
		FORN(i,0,SZ(Q))
		{
			char TYPE = Q[i].TYPE ; 
			if(TYPE=='Q')
			{				

			}	
			else
			{	
				int a = Q[i].a; 
				int sign = Q[i].sign; 
				IT.up(a,-sign) ; 
			}
		}
	}
	void xuly()
	{
		FOR(i,1,n)tmp[i] = a[i] ; 
		FOR(i,1,n)
		{
			Q[a[i]].pb({0,'U',1,i,0});
		}
		dfs(1,0) ; 
		build_hld() ; 
		IT = SEG(n) ; 
		FOR(i,1,q)
		{
			char TYPE ;
			cin>>TYPE ;
			if(TYPE=='Q')
			{
				int a, b, c; cin>>a>>b>>c ;
				Q[c].pb({i,TYPE,0,a,b}) ; 
			}
			else
			{
				int a, c; cin>> a >> c; 
				Q[tmp[a]].pb({i,TYPE,-1,a,0}) ;
				Q[c].pb({i,TYPE,1,a,0}); 
				tmp[a] = c; 
			}
		}
		FOR(i,1,n)
		{
			solve(Q[i]) ; 
		}
		FOR(i,1,q)if(res[i])
		{
			if(res[i]>n-1)cout<<-1<<el;
			else cout<<res[i]<<el;
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.ANS","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
        // sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}