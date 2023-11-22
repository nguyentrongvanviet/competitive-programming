/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "V"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ;
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


int n ; 
ll T ; 
vi g[N] ;
int p[N] ;
ll w[N] , b[N] , tt[N] ;
void doc()
{
    cin>> n >>T ; 
    FOR(i,2,n)
    {
    	cin>>p[i] ; 
    	g[p[i]].pb(i) ; 
    }
    FOR(i,1,n)
    {
    	cin>>w[i];
    }
    FOR(i,1,n)
    {
    	cin>>b[i] ; 
    }
    FOR(i,1,n)
    {
    	cin>>tt[i] ; 
    }
}

namespace sub1
{
	int P[N][LO+3] ;
	int h[N] ; 
	void build_lca()
	{
		FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1] ; 
	}
	int lca(int u ,int v)
	{
		if(h[u]<h[v])swap(u,v) ;  
		FORD(i,LO,0)if(h[u]-(1<<i)>=h[v])u=P[u][i] ;
		if(u==v)return u ; 
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
	void dfs(int u ,int p)
	{
		for(auto v: g[u])if(v!=p)
		{
			P[v][0] = u ; 
			h[v]=h[u]+1;
			dfs(v,u) ; 
		}
	}
    void xuly()
    {
    	dfs(1,0) ;
    	build_lca() ; 
    	ll res = 0 ; 
    	int res_k = 0 ; 
    	vi res_tot ; 
    	FORN(msk,1,Mask(n))
    	{
    		int c = 0 ; 
    		ll sw = 0 ;
    		int k = btpc(msk) ;
    		vi tot ; 
    		FOR(i,1,n)if(BIT(msk,i-1))
    		{
    			if(!c)c=i;
    			else c=lca(c,i) ;
    			sw+=w[i] ;  
    			tot.pb(tt[i]) ; 
    		}
    		sort(all(tot)) ;
    		ll tmp = 0 ; 
    		while(c)
    		{
    			maxi(tmp,b[c]+sq(k)) ;
    			c=p[c] ; 
    		}
    		if(sw<=T)
    		{
    			if(maxi(res,tmp))
    			{
    				res_k = k  ; 
    				res_tot = tot ;
    			}
    			else if(res==tmp)
    			{
    				if(mini(res_k,k))
    				{
    					res_tot = tot ; 
    				}
    				else if(res_k==k)
    				{
    					FORN(i,0,min(SZ(res_tot),SZ(tot)))
    					{
    						if(res_tot[i]<tot[i])break;
    						else if(res_tot[i]>tot[i])
    						{
    							res_tot=tot; 
    							break;
    						}
    					}
    				}
    			}
    		}
    	}
    	cout<<res<<" "<<res_k<<el;
    	prv(res_tot) ;
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
    int sub ;  cin>>sub ;
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}