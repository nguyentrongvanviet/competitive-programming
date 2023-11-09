/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "durian"
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

int n , d ; 
vi g[N] ;
void doc()
{
    cin>>n>> d; 
    FOR(i,1,n-1)
    {
    	int u ,v ;cin>>u>>v; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ;
    }
}

namespace sub1
{
	int dis[30][30] ; 
	bool check(int msk)
	{
		for(int i=msk;i;i-=i&-i)
		{
			int u = __builtin_ctz(i); 
			for(int j= msk;j;j-=j&-j)
			{
				int v= __builtin_ctz(j) ; 
				if(u!=v&&dis[u][v]<d)return 0 ; 
			}
		}
		return 1; 
	}
	void dfs(int u ,int p ,int root)
	{
		for(auto v: g[u])if(v!=p)
		{
			dis[root][v] = dis[root][u]+1; 
			dfs(v,u,root) ; 
		}
	}
    void xuly()
    {
    	int res= 0 ; 
    	FOR(i,1,n)dfs(i,0,i) ; 
    	FORN(i,1,1<<n)if(btpc(i)>res)
    	{
    		if(check(i))maxi(res,btpc(i)) ; 
    	}
    	cout<<res ;
    }
}
namespace sub2
{
	const int N = 5e3+5 ; 
	int tmp[N] ; 
	int f[N][N] ; 
	int res= 0 ; 
	void dfs(int u ,  int p )
	{
		for(auto v:g[u])
    	{ 
        	if(v==p)continue  ;
        	dfs(v,u) ; 
    	}
	    f[u][0]=1 ; 
	    int t=  0 ; 
	    for(auto v :g[u])
	    {
	        if(v==p)continue ; 
	        if(t==0)
	        {
	            ++t ; 
	            f[u][0]+=f[v][d-1] ; 
	            for(int j=1;j<=d;j++)
	            {
	                f[u][j] =f[v][j-1]; 
	            } 
	        }
	        else 
	        {
	            f[u][0]+=f[v][d-1] ; 
	            for(int j =1 ;j<=d;j++)
	            {
	                tmp[j]= max(f[u][j]+f[v][max(j-1,d-j-1)],f[v][j-1]+f[u][max(j,d-j)]); 
	            }
	            for(int j=1;j<=d;j++)
	            {
	                f[u][j] =tmp[j] ;  
	                tmp[j]= 0 ;
	            }
      		}
	    }
	    for(int i =d-1;i>=0;i--)
	    {
	        f[u][i]=max(f[u][i],f[u][i+1]);
	    }
	    for(int i=0;i<=d;i++)
	    {
	        res=max(res,f[u][i]);
	    }  
	}
	void xuly()
	{
		dfs(1,0) ; 
		cout<<res;
	}
}
namespace sub3
{ 
	int tmp[N] ; 
	int f[N][22] ; 
	int res= 0 ; 
	void dfs(int u ,  int p )
	{
		for(auto v:g[u])
    	{ 
        	if(v==p)continue  ;
        	dfs(v,u) ; 
    	}
	    f[u][0]=1 ; 
	    int t=  0 ; 
	    for(auto v :g[u])
	    {
	        if(v==p)continue ; 
	        if(t==0)
	        {
	            ++t ; 
	            f[u][0]+=f[v][d-1] ; 
	            for(int j=1;j<=d;j++)
	            {
	                f[u][j] =f[v][j-1]; 
	            } 
	        }
	        else 
	        {
	            f[u][0]+=f[v][d-1] ; 
	            for(int j =1 ;j<=d;j++)
	            {
	                tmp[j]= max(f[u][j]+f[v][max(j-1,d-j-1)],f[v][j-1]+f[u][max(j,d-j)]); 
	            }
	            for(int j=1;j<=d;j++)
	            {
	                f[u][j] =tmp[j] ;  
	                tmp[j]= 0 ;
	            }
      		}
	    }
	    for(int i =d-1;i>=0;i--)
	    {
	        f[u][i]=max(f[u][i],f[u][i+1]);
	    }
	    for(int i=0;i<=d;i++)
	    {
	        res=max(res,f[u][i]);
	    }  
	}
	void xuly()
	{
		dfs(1,0) ; 
		cout<<res;
	}
}
namespace sub4
{
	int pa[N][LO] ;
	int sz[N] , dd[N] ; 
	map<int,int>D[N] ; 
	int P[N] ; 
	int Near[N] ; 
	int h[N] ;
	struct DL
	{
		int u  ;
		int h ;
		bool operator<(const DL& a)const
		{
			return h>a.h; 
		}
	} ; 
	ve<DL>q; 
	int go(int u ,int k)
	{
		FORN(i,0,LO)if(k>>i&1)u=pa[u][i] ; 
		return u ; 
	}
	void dfsz(int u ,int p)
	{
		sz[u] =  1 ; 
		for(auto v: g[u])if(v!=p&&dd[v]!=1)
		{
			dfsz(v,u) ;
			sz[u]+=sz[v] ; 
		}
	}
	int cen(int u ,int p ,int n )
	{
		for(auto v: g[u])if(v!=p&&dd[v]!=1)
		{
			if(sz[v]>n/2)return cen(v,u,n) ; 
		}
		return u ;
	}
	void dfs1(int u ,int p ,int root, int d)
	{
		D[root][u] = d  ;
		for(auto v: g[u])
		{
			if(dd[v]==0&&v!=p)dfs1(v,u,root,d+1) ; 
		}
	}
	void build(int u, int p )
	{
		D[u][u] = 0 ;
		P[u] = p ; 
		dd[u] = 1; 
		for(auto v: g[u])
		{
			if(dd[v]==0)dfs1(v,u,u,1) ; 
		}
		for(auto v :g[u])if(dd[v]==0)
		{
			dfsz(v,u) ; 
			build(cen(v,u,sz[v]),u) ; 
		}
	}
	void up(int u)
	{
		for(int cha = u ; cha!=0;cha=P[cha])
		{
			mini(Near[cha],D[cha][u]);
		}
	}
	int check(int u)
	{
		int dis = oo ; 
		for(int cha = u ; cha!=0;cha=P[cha]) 
		{
			mini(dis,D[cha][u]+Near[cha]) ;
		}	
		return dis<d ;
	}

	void DFS(int u ,int p)
	{
		q.pb({u,h[u]}) ; 
		for(auto v :g[u])if(v!=p)
		{
			pa[v][0]=u ; 
			h[v]=h[u]+1; 
			DFS(v,u) ;
		}
	}	
	void xuly()
	{			
		FOR(i,1,n)Near[i] = oo ; 
		dfsz(1,0); 
		build(cen(1,0,n),0);
		DFS(1,0) ; 
		sort(all(q));
		int res= 0 ;	
		FORN(j,1,LO)FOR(i,1,n)pa[i][j]=pa[pa[i][j-1]][j-1];
		for(auto v: q)
		{
			if(check(v.u))continue ; 
			up(v.u);
			++res;   
		}
		cout<<res; 
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
        if(n<=20)sub1::xuly() ; 
    	else if(n<=5e3)sub2::xuly() ; 
    	else if(d<=20) sub3::xuly() ; 
    	else sub4::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}