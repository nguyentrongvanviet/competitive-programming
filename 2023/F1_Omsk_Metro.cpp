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

bool mtt = 1 ; 

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
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n; 
int a[N] ; 
vi g[N] ;
ve<pii> question ; 
void doc()
{
	question.clear();
	FOR(i,1,n)g[i].clear(); 
	n = 1 ;
	a[1] = 1;
	int event ;cin>>event ;
	while(event--)
	{
		char t ; cin>>t ; 
		if(t=='+')
		{
			int u ,v , id ; 
			v=++n; 
			cin>>u>>id ; 
			g[u].pb(v) ; 
			a[v] = id ; 
		}
		else
		{
			int u ,v,k; cin>> u>>v>> k ; 
			question.pb({v,k}) ; 
		}
	}
}
int mi[N][2] ,ma[N][2] ; 
void dfs(int u ,int p)
{
	mi[u][0] = ma[u][0]=a[u]; 
	if(p)
	{
		mini(mi[u][0],mi[p][0]+a[u]) ; 
		maxi(ma[u][0],ma[p][0]+a[u]) ; 
	}
	mi[u][1] = mi[u][0] ;
	ma[u][1] = ma[u][0] ;
	if(p)mini(mi[u][1],mi[p][1]);  
	if(p)maxi(ma[u][1],ma[p][1]) ;	
	for(auto v :g[u])if(v!=p)
	{
		dfs(v,u) ; 
	}
}
void xuly()
{	
	dfs(1,0) ; 
	for(auto q : question)
	{
		int u = q.fi ; 
		int k = q.se ; 
		if(mi[u][1]<=k&&k<=ma[u][1]||k==0)cout<<"YES"<<el;
		else cout<<"NO"<<el;
	}
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