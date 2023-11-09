/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "building"
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

struct HCN
{
	int x,y,u,v ;
	int id ; 
}a[N] ;
int n; 
vi V ;

void doc()
{
    cin>> n ;
    FOR(i,1,n)
    {
    	int x, y , u , v; cin>>x>>y>>u>>v; 
    	swap(y,v) ;
    	a[i]={x,y,u,v,i}; 
    	V.pb(x) ; 
    	V.pb(y) ; 
    	V.pb(u) ; 
    	V.pb(v) ; 
    }
    uni(V) ; 
}

namespace sub1
{
	int trans(int val)
	{
		return UB(all(V),val)-V.begin() ; 
	}
	bool cmpL(HCN a , HCN b)
	{
		return a.y<b.y ; 
	}
	bool cmpD(HCN a , HCN b )
	{
		return a.x<b.x ;
	}
	bool giao(int x ,int y ,int u ,int v)
	{
		int l = max(x,u) ; 
		int r = min(y,v) ;
		return l<=r ;
	}
	ve<HCN>L[N],D[N] ; 
	vi g[N] ;
	int id[N] , low[N] , tp[N] , sz[N] , tt = 0 , tplt = 0 ;
	stack<int>st;
	int f[N] ;
	void dfs(int u ,int p)
	{
		st.push(u) ; 
		id[u] = low[u] = ++ tt ; 
		for(auto v: g[u])if(v!=p)
		{
			if(id[v])mini(low[u],id[v]);
			else dfs(v,u) , mini(low[u],low[v]) ;
		}
		if(id[u]==low[u])
		{
			int t ;
			++tplt ;
			do
			{
				t=st.top() ; 
				st.pop() ; 
				tp[t]=tplt ;
				sz[tplt]++ ;
			}while(t!=u);
		}
	}
	set<int>adj[N] ;
	int R[N] ;
	void solve(int u,int p ,int root)
	{
		R[u] = root; 
		f[u] = sz[u] ; 
		for(auto v:adj[u])if(v!=p)
		{
			solve(v,u,root) ;
			f[u]+=f[v] ;
		}
	}
    void xuly()
    {
        FOR(i,1,n)
        {
        	int x = trans(a[i].x) ;
        	int y = trans(a[i].y) ; 
        	int u = trans(a[i].u) ; 
        	int v = trans(a[i].v) ;
        	a[i]={x,y,u,v,i} ;
        	L[u].pb(a[i]) ; 
        	D[v].pb(a[i]) ; 
        }
        int len = SZ(V) ;
        FOR(i,1,len)
        {
        	sort(all(L[i]),cmpL) ;
        	sort(all(D[i]),cmpD) ;
        }
        sort(a+1,a+n+1,cmpD) ; 
        FOR(i,1,n)
        {	
        	int x = a[i].x ;
        	int y = a[i].y ;
        	int u = a[i].u ; 
        	int v = a[i].v ; 
        	int id =a[i].id ;
        	int p = LB(all(L[x]),y,[&](HCN a ,int val){return a.y<val;})-L[x].begin();
        	if(p!=0)--p ;
        	// cout<<x<<" "<<SZ(L[x])<<el;
        	FORN(i,p,SZ(L[x]))
        	{
        		auto tmp = L[x][i] ; 
        		int xx = tmp.x; 
        		int yy = tmp.y ; 
        		int uu = tmp.u ; 
        		int vv = tmp.v;
        		int idid = tmp.id ; 
        		if(yy>v)break;
        		if(giao(y,v,yy,vv))
        		{	
        			g[id].pb(idid);
        			g[idid].pb(id); 
        		}
        	}
        }
        sort(a+1,a+n+1,cmpL) ;

    	FOR(i,1,n)
        {	
        	int x = a[i].x ;
        	int y = a[i].y ;
        	int u = a[i].u ; 
        	int v = a[i].v ; 
        	int id =a[i].id ;
        	int p = LB(all(D[y]),x,[&](HCN a ,int val){return a.x<val;})-D[y].begin();
        	if(p!=0)--p ;
        	FORN(i,p,SZ(D[y]))
        	{
        		auto tmp = D[y][i] ; 
        		int xx = tmp.x; 
        		int yy = tmp.y ; 
        		int uu = tmp.u ; 
        		int vv = tmp.v;
        		int idid = tmp.id ; 
        		if(xx>u)break;
        		if(giao(x,u,xx,uu))
        		{	
        			g[id].pb(idid);
        			g[idid].pb(id); 
        		}
        	}
        }
        // FOR(u,1,n)
        // { 
        // 	for(auto v: g[u])
        // 	{
        // 		cout<<u<<" "<<v<<el;
        // 	}
        // }
        FOR(i,1,n)if(id[i]==0)
        {
        	dfs(i,0) ; 
        }
        FOR(u,1,n)for(auto v:g[u])
        {
        	int tpu = tp[u] ; 
        	int tpv = tp[v] ;
        	if(tp[u]!=tp[v])
        	{
        		adj[tpu].insert(tpv) ;
        	}
        }
        FOR(i,1,tplt)if(f[i]==0)solve(i,0,i);
        int res = oo  ;
        FOR(i,1,tplt)if(i!=R[i])
        {
        	mini(res,abs(f[i]-(f[R[i]]-f[i])));
        }
        if(res==oo)cout<<-1<<el;
        else cout<<res;
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