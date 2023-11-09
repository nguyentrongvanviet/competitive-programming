/***********************************************************************************
*             Author : Nguyen Trong Van Viet                                       *
*                        Age : 17                                                  *
*      School : 11T2 Le Khiet High School for the Gifted                           *
*            Hometown :  Quang Ngai , Viet Nam .                                   *
* Khanh An is my lover :) the more I code  , the nearer I am                       *
***********************************************************************************/
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
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n ,q ; 
struct Edge
{
	int u ,v , c; 
	bool operator<(const Edge&a)const
	{
		return c>a.c; 
	}
}; 

Edge E[N] ; 
Edge Q[N] ;
int pa[N] , sz[N] ; 
int goc(int u)
{
	return pa[u] == u ? u : pa[u] = goc(pa[u]) ; 
}
void hop(int u ,int v)
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return ; 
	pa[chau] = chav; 
	sz[chav]+=sz[chau]; 
}
void doc()
{
	cin>> n >> q ; 
	FOR(i,1,n-1)
	{
		int u ,v , c; 
		cin>>u>>v>>c ; 
		E[i] = {u,v,c}; 
	}
	
	FOR(i,1,q)
	{
		Q[i].u = i ; 
		cin>>Q[i].c>>Q[i].v; 
	}
}
int res[N] ;
void xuly()
{
	sort(E+1,E+n-1+1) ;
	sort(Q+1,Q+q+1) ;
	int it =1 ; 
    FOR(i,1,n)pa[i] = i , sz[i]=1 ; 
    FOR(i,1,q)
    {
    	while(it<=n-1&&E[it].c>=Q[i].c)
    	{
    		hop(E[it].u,E[it].v) ; 
    		++it ; 
    	}
    	int d = sz[goc(Q[i].v)];
   		res[Q[i].u] = d-1 ; 
    }
    FOR(i,1,q)cout<<res[i]<<el;
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
    int test = 1;
    if(mtt)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"KA is closer now !!"<<el; 
    cerr<< "Time elapsed : " << clock() <<"ms"<<el;
}