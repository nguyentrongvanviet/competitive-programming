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

int n , m; 
ll a[N] ; 

struct Edge
{
	int u ,v ; 
	ll w; 
	bool operator<(const Edge&a)const
	{
		return w<a.w ; 
	}
} ; 
Edge E[2*N] ; 
void doc()
{
	cin>> n >> m ; 
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,m)
	{
		int u ,v ; 
		ll w ; cin>>u>>v>>w; 
		E[i] = {u,v,w} ; 
	}
}
namespace sub1
{
	int pa[N] ; 
	int goc(int u )
	{
		return pa[u]==u ? u : pa[u] = goc(pa[u]) ; 
	}
	bool hop(int u ,int v)
	{
		int chau =goc(u) ; 
		int chav= goc(v) ; 
		if(chau==chav)return 0 ; 
		pa[chau] = chav; 
		return 1; 
	}
    void xuly()
    {
    	int root = 1 ;
    	FOR(i,1,n)
    	{	
    		if(a[root]>a[i])root=i ; 
    	}
    	FOR(i,1,n)if(i!=root)
    	{
    		E[++m] = {root,i,a[root]+a[i]} ; 
    	}
    	sort(E+1,E+m+1) ; 
    	FOR(i,1,n)pa[i] = i ; 
    	ll res= 0 ; 
    	FOR(i,1,m)
    	{		
    		if(hop(E[i].u,E[i].v))res+=E[i].w ; 
    	}
    	cout<<res ; 
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