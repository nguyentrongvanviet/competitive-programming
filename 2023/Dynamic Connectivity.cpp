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

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(i,1,n)cout<<a[i]<<" ";cout<<el;
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m ,q ; 
stack<pii> st;

int pa[N] ; 
int sz[N] ;
struct Query
{
	int TYPE , u , v; 
} ; 
Query E[N] ;
int goc(int u)
{
	return pa[u] == u ? u : goc(pa[u]) ; 
} 
void roll_back(int len)
{
	while((int)st.size()>len)
	{
		int u = st.top().fi ;
		int v = st.top().se ; 
		sz[v]-=sz[u] ; 
		pa[u] = u ; 
		st.pop() ; 
	}
}
void hop(int u ,int v)
{
	int chau = goc(u) ;
	int chav = goc(v) ;
	if(chau==chav)return; 
	if(sz[chau]>sz[chav])swap(chau,chav) ; 
	pa[chau] = chav; 
	sz[chav]+=sz[chau] ;
	st.push({chau,chav}) ; 
}
void doc()
{
    cin>> n >> m >> q ;
    FOR(i,1,m)
    {	
    	int u ,v ; cin>>u>>v ; 
    	if(u>v)swap(u,v) ;
    	E[i] = {1,u,v} ;
    }
    FOR(i,1,q)
    {
    	int TYPE , u , v ; cin>>TYPE>>u>>v; 
    	if(u>v)swap(u,v);
    	E[m+i]={TYPE,u,v} ;
    }
}

namespace sub1
{
	ve<pii> T[4*N] ; 
    void up(int id , int l ,int r ,int t, int p,int u ,int v)
    {
    	if(t<=l&&r<=p)
    	{
    		T[id].pb({u,v}) ; 
    		return ; 
    	}
    	if(r<t||p<l)return ; 
    	int mid =(l+r)/2; 
    	up(id*2,l,mid,t,p,u,v) ;
    	up(id*2+1,mid+1,r,t,p,u,v) ;
    }
    int res[N] ;
    void solve(int id ,int l, int r )
    {	
    	int len = st.size() ; 
    	for(auto v: T[id])
    	{
    		hop(v.fi,v.se) ;
    	}
    	if(l==r)
    	{
    		res[l] = n-st.size() ; 
	    	roll_back(len) ;
    		return ; 
    	}
    	int mid =(l+r)/2; 
    	solve(id*2,l,mid) ;
    	solve(id*2+1,mid+1,r) ; 
    	roll_back(len) ;
    }
    map<pii,int>start ; 
    void xuly()
    {
	    FOR(i,1,n)pa[i] = i,sz[i] = 1 ; 
    	FOR(i,1,m+q)
    	{
    		if(E[i].TYPE==1)
    		{
    			start[{E[i].u,E[i].v}]=i ;
    		}
    		else
    		{
    			int begin = start[{E[i].u,E[i].v}] ; 
    			up(1,1,m+q,begin,i-1,E[i].u,E[i].v);
    			start[{E[i].u,E[i].v}]=0 ; 
    		}
    	}	
    	for(auto x : start)
    	{
    		if(x.se)up(1,1,m+q,x.se,m+q,x.fi.fi,x.fi.se) ;
    	}
    	solve(1,1,m+q) ; 
    	FOR(i,m,m+q)cout<<res[i]<<" ";
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