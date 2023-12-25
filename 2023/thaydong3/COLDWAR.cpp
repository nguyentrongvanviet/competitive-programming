/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "COLDWAR"
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
	int id , u ,v , w ; 
	bool operator<(const Edge&a)const
	{
		return w <a.w ;
	}
}E[N] ;
int val[N] ;
void doc()
{
	cin>> n >> m; 
	FOR(i,1,m)
	{
		int u , v ,w ; 
		cin>> u >> v >> w ; 
		E[i] = {i,u,v,w} ;
		val[i] = w ;
	}
}

namespace sub1
{
	int pa[N] ;
	int used[N] ;
	struct ke
	{
		int v, id ;
	} ;
	ve<ke>g[N] ; 
	int h[N] ;	
	ll res = 0; 
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
	}
	int mi[N] ;
	int ID[N] ; 	
	int in[N] , out[N] ; 
	int tt = 0 ;	
	int P[N] ; 
	void dfs(int u ,int p)
	{
		in[u] = ++tt; 
		for(auto x:g[u])
		{
			int v = x.v ; 
			if(v==p)continue ;
			h[v] = h[u] + 1 ; 
			P[v] = u; 
			ID[v] = x.id ;
			dfs(v,u) ; 
		}
		out[u]=++tt ;
	}
	int con(int u ,int v)
	{
		return in[v]<=in[u]&&out[u]<=out[v] ;
	}
	bool hop(int u ,int v)
	{
		int chau = goc(u) ;
		int chav = goc(v) ;
		if(chau==chav)return 0; 
		pa[chau] =chav; 
		return 1; 	
	}
	void up(int u ,int v, int w)
	{
		int oldu = u; 
		int oldv = v; 
		while(1)	
		{
			u = goc(u) ; 
			if(con(oldu,u)&&con(oldv,u))break;
			mi[ID[u]]=w;
			pa[u] = P[u] ; 
		}
		while(1)
		{
			v = goc(v) ; 
			if(con(oldu,v)&&con(oldv,v))break;
			mi[ID[v]]=w;
			pa[v] = P[v] ; 
		}
	}
    void xuly()
    { 
    	sort(E+1,E+m+1) ; 
    	FOR(i,1,n)pa[i] = i ; 
    	int cnt = 0 ;
    	FOR(i,1,m)
    	{
    		if(hop(E[i].u,E[i].v))
    		{
    			used[E[i].id] = 1; 
    			g[E[i].u].pb({E[i].v,E[i].id}) ;
    			g[E[i].v].pb({E[i].u,E[i].id}) ;
    			res+=E[i].w ; 	
    			++cnt; 
    		}
    	}
    	if(cnt<n-1)
    	{
    		FOR(i,1,m)cout<<-1<<el;
    		exit(0) ;
    	}
    	FOR(i,1,m)mi[i] = oo;
    	FOR(i,1,n)pa[i] = i ;  
    	dfs(1,0) ;
    	FOR(i,1,m)if(used[E[i].id]==0)
    	{
    		up(E[i].u,E[i].v,E[i].w) ; 	
    	}
    	FOR(i,1,m)
    	{
    		if(used[i]==0)
    		{
    			cout<<res<<el;		
    		}
    		else
    		{	
    			if(mi[i]==oo)
    			{
    				cout<<-1<<el;
    			}
    			else
    			{
    				cout<<res-val[i]+mi[i]<<el;
    			}
    		}
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
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}