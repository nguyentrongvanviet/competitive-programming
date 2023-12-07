/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "tree_3"
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
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ,q ;
struct Edge
{
	int u , v ;
}E[N] ; 
int pa[N] ;
int goc(int u )
{
	return pa[u]==u?u:pa[u]=goc(pa[u]) ; 
}
bool hop(int u ,int v)
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return 0; 
	pa[chau]=chav ; 
	return 1; 
}
int ID[N] ;
void doc()
{
    cin>> n >> m >>q; 
    FOR(i,1,n)pa[i] = i; 
    int cnt = 0 ;
    FOR(i,1,m)
    {
    	int u ,v ; cin>> u >>v ;
    	if(hop(u,v))E[++cnt] = {u,v} ,ID[cnt]=i; 
    }
    assert(cnt==n-1) ;
    m=cnt; 
}

namespace sub1
{ 
	int val[N] ;
	ll B[N] ;
	struct BIT
	{
		int n ; 
		BIT(int _n = 0)
		{
			n=_n ; 
		}
		void up(int id , int val)
		{
			for(int i=id;i<=n;i+=i&-i)B[i]+=val; 
		}
		ll get(int id)
		{
			ll ans = 0  ;
			for(int i=id;i;i-=i&-i)ans+=B[i] ; 
			return ans; 
		}
		ll get(int l ,int r)
		{
			return get(r)-get(l-1) ;
		}
		void init()
		{
			FOR(i,1,n)B[i] = 0 ;
			FOR(i,1,n)up(i,val[i]) ; 
		}
	}bit ;
	int pa[N] , now[N] ;
	vi S[N] ; 
	struct DSU
	{
		int n; 
		DSU(int _n=0)
		{
			n=_n; 
		}
		int goc(int u)
		{
			return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
		}
		void hop(int u ,int v)
		{
			int chau = goc(u) ;
			int chav = goc(v) ;
			if(chau==chav)return ;
			if(SZ(S[chau])>SZ(S[chav]))swap(chau,chav) ;  
			pa[chau] = chav ; 
			S[chav].insert(S[chav].end(),all(S[chau])) ; 
			for(auto u : S[chau])
			{
				bit.up(u,val[chav]-now[u]) ;
				now[u]=val[chav] ; 
			}
			// S[chau].clear() ; 
		}
		void init()
		{
			FOR(i,1,n)S[i]={i},pa[i]=i,now[i]=val[i];
			bit.init() ;	
		}
		bool check(int l ,int r)
		{
			return bit.get(l,r)==1ll*now[l]*(r-l+1) ;
		}
	}dsu ; 
	struct Query
	{
		int l ,r; 
	}Q[2*N] ; 
	int L[2*N] ,R[2*N] ;
	vi ques[N] ;
	int res[2*N] ; 
    void xuly()
    {
    	FOR(i,1,n)val[i] = rd(1,1e9) ;
    	dsu=DSU(n) ; 
    	bit=BIT(n) ;
    	FOR(i,1,q)
    	{
    		cin>>Q[i].l>>Q[i].r ;
    		L[i] = Q[i].r-Q[i].l ; 
    		R[i] = m ;
			res[i] = -1 ;
    	}
    	while(1)
    	{
    		bool ok = 0  ; 
    		FOR(i,0,m)ques[i].clear();
    		dsu.init() ;
    		FOR(i,1,q)
    		{
    			int l = L[i] ;
    			int r = R[i] ; 
    			if(l<=r)
    			{
    				ok=1; 
    				int mid=(l+r)>>1; 
    				ques[mid].pb(i) ;
    			}
    		}
    		if(!ok)break;
    		FOR(i,0,m)
    		{
    			if(i)dsu.hop(E[i].u,E[i].v) ;
    			for(auto id:ques[i])
    			{
    				int l = Q[id].l ; 
    				int r = Q[id].r ; 
    				if(dsu.check(l,r))res[id]=i,R[id]=i-1 ;
    				else L[id]=i+1; 
    			}
    		}
    	}	
    	FOR(i,1,q)cout<<ID[res[i]]<<" ";
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
