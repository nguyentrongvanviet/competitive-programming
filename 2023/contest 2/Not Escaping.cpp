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

bool mtt = 1 ;
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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , k ;
struct Edge
{
	int a , b , c, d,h ; 
} ;
Edge E[N] ; 
struct ke
{
	int v ,row ; 
	ll w; 
} ; 
ve<ke>g[N] ;
int x[N] ;
int node  ; 
void doc()
{
	node = 0; 
	map<pii,int>q ;
	cin>> n >> m >> k; 
	FOR(i,1,n)
	{
		cin>>x[i] ; 
	}	
	q[{1,1}]=0 ; 
	q[{n,m}]=0  ;
	FOR(i,1,k)
	{
		int a,b,c,d,h; cin>>a>>b>>c>>d>>h; 
		E[i] = {a,b,c,d,h} ;
		q[{a,b}]=0 ; 
		q[{c,d}]=0 ;
	}
	pii pre ; 
	for(auto &v : q)
	{
		v.se=++node;
		if(pre.fi&&pre.se)
		{
			if(pre.fi==v.fi.fi)
			{
				g[node].pb({node-1,pre.fi,1LL*abs(pre.se-v.fi.se)*x[pre.fi]}) ;
				g[node-1].pb({node,pre.fi,1LL*abs(pre.se-v.fi.se)*x[pre.fi]}) ;
			}
		}
		pre=v.fi ;
	}
	FOR(i,1,k)
	{
		int u = q[{E[i].a,E[i].b}] ; 
		int v = q[{E[i].c,E[i].d}] ;
		g[u].pb({v,E[i].c,-E[i].h}) ;
	}
}

namespace sub1
{
	struct BG
	{
		int u ; 
		int row ; 
		ll val ; 
	} ; 
	struct cmp
	{
		bool operator()(const BG&a , const BG&b)const
		{
			return (a.row>b.row)||(a.row==b.row&&a.val>b.val); 
		}
	} ;
	ll f[N] ; 
	void dij()
	{
		priority_queue<BG,ve<BG>,cmp>q ; 
		FOR(i,1,node)
		{
			f[i] = inf ; 
		}
		q.push({1,1,f[1]=0}); 
		while(!q.empty())
		{
			int u= q.top().u ; 
			ll val = q.top().val;
			q.pop() ;
			if(f[u]<val)continue ; 
			for(auto x:g[u])
			{
				int v = x.v ;
				int row = x.row; 
				ll w = x.w ;
				if(mini(f[v],val+w))
				{
					q.push({v,row,f[v]}) ; 
				}
			}
		}
		if(f[node]==inf)cout<<"NO ESCAPE"<<el;
		else cout<<f[node]<<el;
	}
    void xuly()
    {
    	dij() ;	
    	FOR(i,1,node)g[i].clear()  ;
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
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}