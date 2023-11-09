/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0;

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
#define            tct  template<typename T>
#define             LB  lower_bound
#define             UB  upper_bound 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 1e6+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n; 
int a[N] ;
vi g[N] ;
void doc()
{
	cin>> n; 
	FOR(i,1,n-1)
	{
		int u ,v ; cin>>u>>v ;
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
}
vi f[N] ; 
int res[N] ;  
int ans[N] ;
void merge(int u ,int v)
{
	if(f[u].size()<f[v].size())
	{
		swap(f[u],f[v]);
		swap(res[u],res[v]) ;  
	}
	for(int i=f[v].size()-1,j=f[u].size()-1;i>=0;i--,j--)
	{
		f[u][j]+=f[v][i] ; 
		if(f[u][res[u]]<f[u][j]||(f[u][res[u]]==f[u][j]&&res[u]<j))res[u]=j;
	}
}
void dfs(int u ,int p)
{
	for(auto v : g[u])if(v!=p)
	{	
		dfs(v,u) ; 
		merge(u,v);
	} 
	f[u].pb(1) ; 
	if(g[u].size()-(p!=0))
	{
		if(f[u][res[u]]==1)res[u]=f[u].size()-1;
	}
	ans[u] = f[u].size()-1-res[u];  
}
void xuly()
{
   	dfs(1,0) ; 
   	FOR(i,1,n)cout<<ans[i]<<el;
}

signed main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Khanh An loves you very much !"<<el;
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}