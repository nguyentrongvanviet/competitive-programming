/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "cay"
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
#define          SZ(_)  (int)(_.size())
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

	
int n , D; 
struct ke
{
	int v, w; 
} ;
ve<ke>g[N] ; 
int a[N] ;
void doc()
{	
    cin>> n  >>D ; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n-1)
    {
    	int u ,v ,w ; cin>>u>>v>>w ;
    	g[u].pb({v,w}) ; 
    	g[v].pb({u,w}) ; 
    }
}

namespace sub1
{
	ll f[N][52] ; 
	ll res =0 ; 
	void dfs(int u ,int p )
	{
		for(auto [v,w] :g[u])if(v!=p)
		{
			dfs(v,u) ; 
		}
		f[u][0] = a[u] ; 
		vll pre(D+2,-inf) ;
		vll cur(D+2,-inf) ; 
		for(auto [v,w] : g[u])if(v!=p)
		{
			FOR(i,0,D+1)
			{
				if(i+w>=D)maxi(res,f[v][i]+a[u]) ;
				maxi(cur[min(D+1,i+w)],f[v][i]);
			}
			FOR(i,0,D+1)
			{
				maxi(cur[min(D+1,i+w)],pre[min(D+1,max({0,D-i-w,i+w}))]+f[v][i]); 
			}
			FOR(j,0,D+1)
			{
				maxi(cur[j],pre[j]+f[v][min(D+1,max({0,D-w-j,j-w}))])  ; 
			}
			FORD(i,D+1,0)
			{
				maxi(pre[i],cur[i]) ; 
				if(i!=D+1)maxi(pre[i],pre[i+1]) ; 
			}
		}
		FORD(i,D+1,0)
		{
			maxi(f[u][i],cur[i]) ;
			if(i!=D+1)maxi(f[u][i],f[u][i+1]) ; 
		}
	}
    void xuly()
    {	
    	FOR(i,1,n)FOR(j,0,D+1)f[i][j] = -inf ;
        dfs(1,0) ; 
        FOR(i,1,n)FOR(j,0,D+1)maxi(res,f[i][j]) ; 
        cout<<res; 
    }
}
namespace SUB1
{
	#define Mask(i) (1<<(i))
	const int N =21 ; 
	ll C[N][N] ;
	bool in(int a ,int b ,int c)
	{
		return (C[a][b]+C[b][c]==C[a][c]); 
	}
	bool check(vi&q , int c )
	{
		FORN(i,0,SZ(q))
		{
			FORN(j,i+1,SZ(q))
			{	
				int a =q[i] ; 
				int b =q[j] ; 
				if(in(a,b,c)||in(a,c,b)||in(c,a,b))return 0 ;
			}
			if(C[q[i]][c]<D)return 0 ;
		}
		return 1; 
	}
	void xuly()
	{
		FOR(i,1,n)FOR(j,1,n)C[i][j] = oo ; 
		FOR(i,1,n)C[i][i] = 0 ;
		FOR(u,1,n)for(auto [v,w]:g[u])C[u][v] = w;
		FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)mini(C[i][j],C[i][k]+C[k][j]) ;
		ll res = 0;
		int res_msk = 0 ;  
		FORN(msk,1,Mask(n))
		{	
			vi q; 
			bool ok = 1;  
			ll sum = 0 ;
			for(int MASK = msk;MASK;MASK-=MASK&-MASK)
			{	
				int u = __builtin_ctz(MASK) ; 
				if(check(q,u+1)==0)
				{
					ok = 0 ;
					break ;
				}
				q.pb(u+1) ;
				sum+=a[u+1] ; 
			}
			if(ok&&maxi(res,sum))res_msk=msk ;
		}	
		cout<<res<<el;
		cout<<btpc(res_msk)<<el; 
		FOR(i,1,n)if(BIT(res_msk,i-1))
		{
			cout<<i<<" ";
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
    if(mtt)cin>>  test;
    int sub ;cin>>sub ; 
    FOR(i,1,test)
    {
        doc() ; 
        if(sub==1)SUB1::xuly() ;
        else sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}