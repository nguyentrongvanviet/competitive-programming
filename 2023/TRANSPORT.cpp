/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
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

#define int long long 
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
#define            tct  template<class T>
#define             LB  lower_bound
#define             UB  upper_bound 
#define     BIT(msk,i)  (msk>>(i)&1)
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 22, oo = 2e9, LO = 17, CH = 26 ; 
const int DAY = 100+5 ; 
int day , n ,  m ; 
ll COST ;
struct ke
{
	int v;  
	int w; 
} ;
ve<ke>g[N] ; 
int ok[DAY] ;
void doc()
{
	cin>> day >> n >> COST >> m; 
	FOR(i,1,m)
	{
		int u ,v, w; cin>>u>>v>>w; 
		--u ; 
		--v 	; 
		g[u].pb({v,w}) ; 
		g[v].pb({u,w}) ; 
	}
	int d ; 
	cin>>d ;
	while(d--)
	{
		int P , l ,r ; 
		cin>>P>>l>>r ;
		--P ; 
		FOR(i,l,r)
		{
			ok[i]|=(1<<P) ; 
		}
	}
	FOR(i,1,day)
	{
		ok[i] = (((1<<n)-1)^ok[i]) ;   
	}
}
namespace sub1
{	
	ll f[(1<<N)+5] ; 
	ll d[N] ;	
	ll dp[DAY]; 
	struct DL
	{
		int u ; 
		ll val ; 
	} ; 
	struct cmp
	{
		bool operator()(const DL&a,const DL&b)const
		{
			return a.val>b.val; 
		}
	};
	ll dij(int msk) 
	{
		if(BIT(msk,0)==0||BIT(msk,n-1)==0)return inf ;  
		FOR(i,0,n-1)d[i]  = inf; 
		priority_queue<DL,ve<DL>,cmp>q ; 	
		q.push({0,d[0]=0}) ; 
		while(!q.empty())
		{
			int u = q.top().u ; 
			ll val = q.top().val ; 
			q.pop() ; 
			if(d[u]<val)continue ;
			for(auto x : g[u])
			{
				int v = x.v ; 
				if(BIT(msk,v)==0)continue;
				int w= x.w; 
				if(mini(d[v],d[u]+w))
				{
					q.push({v,d[v]}) ; 
				}
			}
		}
		// cout<<d[n-1]<<el;
		return d[n-1];  
	}
    void xuly()
    {  
		FORN(msk,0,1<<n)f[msk] = dij(msk) ; 
		FOR(i,0,n-1)
		{
			FORN(msk,0,(1<<n))
			{
				if(BIT(msk,i))mini(f[msk],f[msk^(1<<i)]) ;
			}	
		}
		FOR(i,1,day)dp[i]=inf ; 
		dp[0] = 0 ; 
		FOR(i,1,day)
		{
			int msk = (1<<n)-1;
			FORD(j,i,1)
			{
				msk&=ok[j];
				if(f[msk]==inf)break;
				mini(dp[i],dp[j-1]+(j-1?COST:0)+1LL*(i-j+1)*f[msk]);
			}	
		}
		prt(dp,day); 
		// cout<<dp[day] ; 
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}