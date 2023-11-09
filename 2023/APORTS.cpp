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
#define     BIT(msk,i)  (msk>>i&1)
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
const int N = 5e2+5, oo = 2e9, LO = 17, CH = 26 ; 

int n,m; 
int C[N][N] ;
struct Flight
{
int u ,v , Ti; 
bool operator<(const Flight a)const
{
	return Ti<a.Ti ; 
} 
} ; 
Flight FL[N] ; 
int P[N] ; 
int E[N][N];
void doc()
{
cin>> n >> m ; 
FOR(i,1,n) cin>> P[i] ; 
FOR(i,1,n)FOR(j,1,n)
{
	cin>>C[i][j] ; 
	E[i][j] = C[i][j] ; 
	if(i!=j)C[i][j]+=P[j];
}
FOR(i,1,m)
{
	int u , v , Ti ; cin>>u>>v>>Ti ; 
	FL[i] = {u,v,Ti} ;
}
}
namespace sub1
{
int dd[N*2] ; 
int Tr[N*2] ;
vi g[N*2] ; 

int dfs(int u,int root )
{
	if(dd[u]==root)return 0;
	dd[u] = root ; 
	for(auto v : g[u])
	{
		if(Tr[v]==0||dfs(Tr[v],root))
		{
			Tr[v] = u ; 
			return 1; 
		}
	}
	return 0 ; 
}
void xuly()
{
	// floyd 
	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)
	{
		mini(C[i][j],C[i][k]+C[k][j]) ; 
	}
	sort(FL+1,FL+m+1) ; 
	FOR(i,1,m)
	{
		FOR(j,i+1,m)
		{
			int u =FL[i].u ; 
			int v = FL[i].v ; 

			int V = FL[i].Ti + E[u][v] + P[v] + C[v][FL[j].u];
			
			if(V<=FL[j].Ti)g[i].pb(j+m); 
		}
	}
	// konig 
	int res = 0 ;
	FOR(i,1,m)
	{
		res+=dfs(i,i) ; 
	}
	cout<<m-res;
}
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),sxrand(time(0)); 
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