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
const ll inf = 1e18, cs = 10, sm = 1e9+7; 
const ll  CS = 137 , SM = 1e6+1 ; 
const int N = 1e6+5, oo = 2e9, LO = 17, CH = 26 ; 

int n , m;  
vi g[N] ; 
void doc()
{
	cin>> n >> m ; 
	FOR(i,1,m)
	{
		int u ,v ; cin>>u>>v ; 
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}
namespace sub1
{
	vll ha[N] ; 
	vll HA[N] ; 
	map<pll,int>sl ;
	ll mu[N]  ; 
	ll MU[N] ; 
	ll get(int u ,int l, int r)
	{
		if(l>r)return 0 ;
		return (ha[u][r]-ha[u][l-1]*mu[r-l+1]%sm+sm)%sm;
	}
	ll GET(int u ,int l ,int r)
	{
		if(l>r)return 0 ; 
		return (HA[u][r]-HA[u][l-1]*MU[r-l+1]%SM+SM)%SM;
	}
	pll trans(int u ,int v)
	{
		int x=LB(all(g[u]),v)-g[u].begin()+1; 
		ll tmp = (ha[u][x-1]*mu[g[u].size()-x]%sm+get(u,x+1,g[u].size()))%sm;
		ll TMP = (HA[u][x-1]*MU[g[u].size()-x]%SM+GET(u,x+1,g[u].size()))%SM;
		return mp(tmp,TMP) ; 
	}
    bool check(int u ,int v)
    {
    	if(g[u].size()!=g[v].size())return 0 ; 
    	pll x = trans(u,v) ; 
    	pll y =trans(v,u) ; 
    	return x==y ;  
    }
    void xuly()
    {
    	mu[0] = 1; 
    	MU[0] = 1; 
    	FOR(i,1,n)
    	{
    		mu[i] = mu[i-1]*cs%sm ;
    		MU[i] = MU[i-1]*CS%SM ;
    	}
    	FOR(i,1,n)
    	{
    		sort(all(g[i])); 
    		ha[i].pb(0) ; 
    		HA[i].pb(0) ;
    		for(auto j:g[i])
    		{
    			ha[i].pb((ha[i].back()*cs+j)%sm);
    			HA[i].pb((HA[i].back()*CS+j)%SM);    		
    		}
    	}
    	ll res= 0 ;    
    	FOR(u,1,n)
    	{	
    		res+=sl[mp(ha[u].back(),HA[u].back())]; 
    		for(auto v :g[u])if(v<u)
    		{
    			res+=check(u,v) ;
    		}
    		sl[mp(ha[u].back(),HA[u].back())]++; 
    	}	
    	cout<<res<<el;
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