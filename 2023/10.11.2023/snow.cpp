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
const int N = 1e2+5 , oo = 1e9+5 , LO = 17 , CH = 26 ; 


int n , m , k , TYPE ; 

struct ke
{
	int v, w ; 
}; 
struct Edge
{
	int u ,v ,w ;
	bool operator<(const Edge&a)const
	{
		return w<a.w ; 
	}
} ; 
Edge E[N*N] ;
ve<ke>g[N] ; 
int dd[N] ; 
void doc()
{
   	cin >> n >>k >>m>>TYPE  ;
   	if(TYPE==2)TYPE = 0 ;
   	FOR(i,1,k)
   	{
   		int u ;cin>> u;
   		dd[u] = 1; 
   	}
   	FOR(i,1,m)
   	{
   		int u ,v ,w ;
   		cin>> u>> v>>w ; 
   		g[u].pb({v,w}) ; 
   		g[v].pb({u,w}) ; 
   		E[i] = {u,v,w} ; 
   	}
}
namespace sub1
{
	int pa[N] ; 
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
	}	
	bool hop(int u ,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ;
		if(chau==chav)return 0 ; 
		pa[chau] = chav ; 
		return 1 ;
	}
	void xuly()
	{
		FOR(i,1,n)pa[i] = i; 
		sort(E+1,E+m+1) ; 
		int res = 0 ;
		FOR(i,1,m)
		{
			if(hop(E[i].u,E[i].v))res+=E[i].w ;
		}
		cout<<res;
	}
}
namespace sub23
{
	vi spec ; 
	struct DL
	{
		int u , val; 
	} ;
	struct cmp
	{
		bool operator()(const DL&a,const DL&b)const
		{
			return a.val>b.val; 
		}
	} ; 
	int dis[10][N] ;
	void dij(int id ,int f[])
	{
		priority_queue<DL,ve<DL>,cmp>q  ;
		FOR(i,1,n)f[i] = oo ; 
		q.push({spec[id],f[spec[id]]=0});
		while(!q.empty())
		{
			int u= q.top().u ;
			int val =q.top().val; 
			q.pop() ;  
			if(f[u]<val)continue ; 
			for(auto [v,w]:g[u])
			{
				if(mini(f[v],val+w))
				{
					q.push({v,f[v]});
				}
			}
		}
	}
	struct BG
	{
		int u , msk; 
		int val; 
	} ; 
	struct cmp_BG
	{
		bool operator()(const BG&a , const BG&b)const
		{
			return a.val>b.val;
		}  
	} ; 
	int f[N][1<<5]; 
	void dij_spider_man()
	{
		priority_queue<BG,ve<BG>,cmp_BG>q ;
		FOR(i,1,n)
			FORN(j,0,Mask(k))
				f[i][j] = oo ; 
		q.push({spec[0],Mask(0),f[spec[0]][Mask(0)]=0});
		while(!q.empty())
		{
			int u  = q.top().u ; 
			int msk = q.top().msk  ; 
			int val = q.top().val; 
			q.pop() ; 
			if(f[u][msk]<val)continue ;
			FORN(i,0,k)if(BIT(msk,i)==0)
			{
				int nmsk = msk|Mask(i) ; 
				if(mini(f[u][nmsk],val+dis[i][u]))
				{
					q.push({u,nmsk,f[u][nmsk]}); 
				}
			}
			for(auto [v,w]:g[u])
			{
				if(mini(f[v][msk],val+w))
				{
					q.push({v,msk,val+w}) ; 
				}
			}
		}
		int res = oo ;
		FOR(i,1,n)
		{
			mini(res,f[i][Mask(k)-1]) ; 
		}
		cout<<res ;
	}
    void xuly()
    {
    	FOR(i,1,n)if(dd[i])spec.pb(i) ;
    	FORN(i,0,SZ(spec))
    	{
    		dij(i,dis[i]) ;
    	}
    	dij_spider_man() ; 
    }
}
namespace sub3
{
	int C[N][N] ; 
	int f[N][1<<10] ;
	void xuly()
	{
		FOR(i,1,n)
		{
			FOR(j,1,n)C[i][j] = oo ; 
			C[i][i] = 0 ; 
		}
		FOR(u,1,n)for(auto [v,w]:g[u])
		{
			mini(C[u][v],w) ;
		}
		FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)
		{	
			mini(C[i][j],C[i][k]+C[k][j]) ; 
		}
		FOR(i,1,n)FOR(msk,1,Mask(k))
		{
			f[i][msk]  = oo; 
		}
		vi node ;
		FOR(i,1,n)if(dd[i])
		{
			node.pb(i) ; 
		}
		FORN(i,0,k)
		{
			f[node[i]][Mask(i)] = 0 ; 
		}
		FORN(msk,1,Mask(k))
		{
			FOR(i,1,n)
			{
				for(int ss = msk ; ss>0;ss=(ss-1)&msk)
				{
					mini(f[i][msk],f[i][ss]+f[i][msk^ss]); 
				}
				FOR(j,1,n)
				{
					mini(f[j][msk],f[i][msk]+C[i][j]);
				}
			}
		}
		int res = oo ; 
		FOR(i,1,n)
		{
			mini(res,f[i][Mask(k)-1]) ;
		}
		cout<<res;
	}
}
// dorameon 
namespace sub5
{
	int pa[N] ;
	int goc(int u )
	{
		return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
	}
	bool hop(int u ,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ; 
		if(chau==chav)return 0 ; 
		pa[chau]=chav ; 
		return 1; 
	}
	bool cango[N] ;
	void xuly()
	{
		vi node ;
		FOR(i,1,n)if(dd[i])
		{
			node.pb(i) ; 
		}
		sort(E+1,E+m+1) ; 
		int res = oo ; 
		FORN(msk,0,1<<k)
		{	
			FOR(i,1,n)cango[i] = 0 ;
			FORN(i,0,k)cango[node[i]]=1-BIT(msk,i) ; 
			FOR(i,1,n)pa[i]= i ; 
			int cost =0 ; 
			FOR(i,1,m)
			{
				int u =E[i].u ; 
				int v =E[i].v; 
				if(!cango[u]&&!cango[v])
				{
					if(hop(u,v))cost+=E[i].w; 
				}
			}	
			int root = 0 ;
			bool ok =1 ; 
			FOR(i,1,n)if(dd[i]==0)
			{
				if(root==0)
				{
					root=goc(i) ; 
				}
				else if(root!=goc(i))
				{
					ok = 0; 
					break;
				}
			}
			if(ok)mini(res,cost) ; 
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
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        if(TYPE==1&&k==n)sub1::xuly() ; 
        else if(TYPE==1)sub3::xuly() ; 
        else sub5::xuly()  ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}