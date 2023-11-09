/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "EQUAKE"
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
const int N = 3e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n  ; 
ll C ; 
ll a[N] ; 
struct ke
{
	int v ; 
	ll w; 
} ;
ve<ke>g[N]; 
ll sum =0 ; 
ll AVE ; 
void doc()	
{
    cin>> n >> C; 
    FOR(i,1,n)cin>>a[i] ,sum+=a[i]; 
    AVE = sum/n ;
    FOR(i,1,n-1)
    {
    	int u ,v ,w ;cin>>u>>v>>w; 
    	g[u].pb({v,w}) ; 
    	g[v].pb({u,w}) ; 
    }
}

namespace sub1
{
	ll Sum[N] ;
	ll f[N][N] ;
	int sz[N] ; 
	int d;
	int HI[N][N];
	map<int,map<int,int>>trace[N] ; 
	void dfs(int u ,int p)
	{
		Sum[u] = a[u] ; 
		for(auto [v,w] : g[u])if(v!=p)
		{
			dfs(v,u);
			Sum[u]+=Sum[v];
		} 
		vll pre(n+3,inf) ;
		pre[0] = 0 ; 
		vll cur(n+3,inf) ;
		for(auto [v,w] :g[u])if(v!=p)
		{
			FOR(i,0,sz[u])FOR(j,0,sz[v])
			{
				ll tot = abs(Sum[v]-(j+sz[v]*AVE)); 
				ll cost = (tot/C+(tot%C>0))*w;
				if(mini(cur[i+j],pre[i]+f[v][j]+cost))
				{
					trace[u][v][i+j]=j;
				}
			}
			sz[u]+=sz[v]; 
			FOR(i,0,sz[u])
			{ 
				pre[i] = cur[i] ; 
				cur[i] = inf ;
			}
		} 
		FOR(i,0,sz[u])
		{
			f[u][i]=pre[i];
		}
		sz[u]++;
		FORD(i,sz[u],1)
		{
			if(mini(f[u][i],f[u][i-1]))
			{
				HI[u][i] = 1 ;
			}
		}
	}
	struct DL
	{
		int v,j; 
		ll tot; 
		bool operator<(const DL&a)const
		{
			return tot>a.tot ;  
		}
	} ; 
	ve<DL>res;
	void truyvet(int u ,int p,int i)
	{
		if(HI[u][i])i-- ;
		reverse(all(g[u]));
		ve<DL>q;
		for(auto [v,w]:g[u])if(v!=p)
		{
			int j = trace[u][v][i] ;
			ll tot = Sum[v]-(j+sz[v]*AVE); 
			q.pb({v,j,tot}) ;
			i-=j ; 
		}
		sort(all(q)) ; 
		for(auto [v,j,tot]:q)
		{
			if(tot>0)
			{
				truyvet(v,u,j);
				res.pb({v,u,tot}) ; 
			}
			else if(tot<0)
			{
				res.pb({u,v,abs(tot)});
				truyvet(v,u,j) ;
			}
			else
			{
				truyvet(v,u,j) ;
			}
		}
	}
    void xuly()
    {	
    	d= sum%n; 
    	FOR(i,1,n)FOR(j,0,n)f[i][j] = inf ;
    	dfs(1,0) ; 
    	cout<<f[1][d]<<el;
    	truyvet(1,0,d) ;
    	cout<<SZ(res)<<el;
    	for(auto [u,v,tot]:res)cout<<u<<" "<<v<<" "<<tot<<el;
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