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
tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
tct void prt(T a[],int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
tct void prv(ve<T>a ){for(auto v: a)cout<<v<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e18, cs = 331, sm = 1e9+7; 
const int N = 4e3+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n; 

vi g[N] ; 
ll mu[N*2] ; 
int sz[N] ; 
int dd[N] ;
void doc()
{
	cin>> n; 
	FOR(i,1,n-1) 
	{
		int u ,v ;cin>>u>>v  ; 
		g[u].pb(v) ;
		g[v].pb(u) ;
	}
}
void DFS_SZ(int u , int p)
{
	sz[u]=1 ; 
	for(auto v: g[u])if(v!=p&&dd[v]==0)
	{
		DFS_SZ(v,u) ; 
		sz[u]+=sz[v]; 
	}
}

void FIND(int u ,int p ,int sz_root,vi& CEN  )
{
	bool ok = 1 ; 
	for(auto v: g[u])if(v!=p&&dd[v]==0)
	{
		if(sz[v]>sz_root/2)ok = 0 ; 
		FIND(v,u,sz_root,CEN) ;
	}
	
	if(sz_root-sz[u]>sz_root/2)ok=0 ; 
	
	if(ok)CEN.pb(u) ;
}
struct DL
{
	int len ;
	ll value ; 
	bool operator<(const DL&a)const
	{
		return len<a.len||(len==a.len&&value<a.value) ; 
	}
} ;
ll DFS_Hash(int u ,int p)
{
	ve<DL>q ; 
	sz[u]=1;  
	for(auto v: g[u])if(v!=p&&dd[v]==0)
	{
		ll value = DFS_Hash(v,u) ; 
		sz[u]+=sz[v] ; 
		q.pb({2*sz[v],value}) ; 
	}
	sort(all(q)) ; 
	
	ll hash = '{';
	for(auto v:q)hash=(hash*mu[v.len]+v.value)%sm;  
	hash=(hash*cs+'}')%sm ;
	return hash ; 
}
void solve(int u,pll &Hash)
{
	DFS_SZ(u,0) ; 
	vi CEN ;
	FIND(u,0,sz[u],CEN);
	// prv(CEN);
	for(auto v: CEN)
	{		
		ll tmp = DFS_Hash(v,0) ; 
		if(Hash.fi==-1)Hash.fi=tmp ; 
		else Hash.se=tmp ; 
	}
	if(Hash.fi<Hash.se)swap(Hash.fi,Hash.se);
}
void xuly()
{
	mu[0] = 1 ; 
	FOR(i,1,2*n) mu[i] = mu[i-1]*cs%sm ;

	DFS_SZ(1,0) ; 
	vi CEN ;
	
	FIND(1,0,n,CEN) ;  
	if(CEN.size()!=1)return void(cout<<-1);
	dd[CEN[0]]=1;
	pll tmp = {-1,-1} ; 
	for(auto v :g[CEN[0]] )
	{
		pll Hash={-1,-1} ;
		solve(v,Hash);
		if(tmp.fi==-1)tmp=Hash; 
		else if(Hash!=tmp)return void(cout<<-1); 
	}
	cout<<g[CEN[0]].size();
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