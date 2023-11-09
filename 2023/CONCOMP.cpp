/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
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
const int N = 5e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , q; 
struct Edge
{ 
	int u ,v ;
}E[30005]; 
void doc()
{	
    cin>> n >> m; 
    FOR(i,1,m)
    {
    	int u ,v ; cin>>u>>v; 
    	E[i] = {u,v} ; 
    }
}

namespace sub1
{
	int pa[N] ;
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u] = goc(pa[u]) ;
	}
	bool hop(int u ,int v)
	{
		int chau = goc(u) ; 
		int chav = goc(v) ;
		if(chau==chav)return 0 ; 
		pa[chau] = chav; 
		return 1 ; 
	}
    void xuly()
    {
    	cin>>q; 
    	FOR(_,1,q)
    	{
    		int l ,r ; cin>>l>>r; 
    		FOR(i,1,n)pa[i] = i  ; 
    		int cnt = n ; 
    		FOR(i,1,l-1)if(hop(E[i].u,E[i].v))cnt-- ; 
    		FOR(i,r+1,m)if(hop(E[i].u,E[i].v))cnt-- ;
    		cout<<cnt<<el;
    	}    
    }
}
namespace sub2
{
	int pa[N] ; 
	vi L ,R ; 
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u] =goc(pa[u]) ; 
	}
	void xuly()
	{	
		FOR(i,1,n)pa[i] = i ;
		FOR(i,1,m)
		{	
			int u = E[i].u ; 
			int v = E[i].v ; 
			int chau = goc(u) ; 
			int chav = goc(v) ;
			if(chau!=chav)L.pb(i) ; 
		}
		FOR(i,1,n)pa[i] = i ; 
		FORD(i,m,1)
		{	
			int u = E[i].u ; 
			int v = E[i].v ;
			int chau = goc(u) ; 
			int chav = goc(v) ;
			if(chau!=chav)R.pb(i) ;  
		}
		cin>>q ;
		while(q--)
		{
			int l, r; cin>>l>>r ; 
			FOR(i,1,n)pa[i] = i ;  
			int res= n ;
			for(auto id:L)
			{
				if(id>=l)break;
				int u = E[id].u ;
				int v = E[id].v ;
				u = goc(u) ; 
				v = goc(v) ;
				if(u!=v)--res,pa[u]=v;
			}
			for(auto id:R)
			{	
				if(id<=r)break;
				int u = E[id].u ;
				int v = E[id].v ;
				u = goc(u) ; 
				v = goc(v) ;
				if(u!=v)--res,pa[u] = v; 
			}
			cout<<res<<el;
		}
	}	
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
   		sub2::xuly() ; 
  	}
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}