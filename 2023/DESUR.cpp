/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
***************************************************************/

#define TASK "DESUR"
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
const int N = 2e5+5, oo = 2e9, LO = 17, CH = 26 ; 
// end of macros and constant  

int n  ,q ; 

struct DL
{
	int t,u,v; 
} Q[N] ;
 
map<pii,vi>E; 
int End[N];
void doc()
{
	cin>>n >>q ; 
	FOR(i,1,q)
	{
		int u ,v , t ;cin>>t>>u>>v ; 
		if(u>v)swap(u,v) ; 
		Q[i]={t,u,v};  
		if(u==v)continue ; 
		if(t==1)
		{ 
			E[mp(u,v)].pb(i);
			End[i] = q ; 
		}
		if(t==2)
		{
			if(E.find(mp(u,v))==E.end())continue ;
			if(E[mp(u,v)].empty())continue;
			End[E[mp(u,v)].back()]= i-1; 
			E[mp(u,v)].pk();
		}
	}
}
ve<pii>st[4*N] ; 
void up(int id ,int l, int r, int t ,int p ,pii A )
{
	if(t<=l&&r<=p)
	{
		st[id].pb(A) ; 
		return ; 
	}
	if(r<t||p<l)return ; 
	int mid=(l+r)/2 ; 
	up(id*2,l,mid,t,p,A);  
	up(id*2+1,mid+1,r,t,p,A) ; 
}
int pa[N] , sz[N] ; 
stack<pii>S ; 
int goc(int u )
{
	return pa[u] == u ? u: goc(pa[u]);
}
void merge(int u ,int v )
{
	int chau =goc(u) ; 
	int chav =goc(v) ; 
	if(chau==chav)return ;  
	if(sz[chau]>sz[chav])swap(chau,chav); 
	sz[chav]+=sz[chau];
	pa[chau] = chav ; 
	S.push({chau,chav}) ;
}
void roll_back(int len)
{	
	while((int)S.size()>len)
	{
		int u ,v; 
		tie(u,v) = S.top() ; 
		pa[u] = u ; 
		sz[v]-=sz[u] ;
		S.pop() ;
	}	
}
int res[N] ;
void solve(int id, int l ,int r)
{
	int len = S.size() ; 
	for(auto v : st[id])merge(v.fi,v.se);
	if(l==r)
	{
		if(Q[l].t==3)res[l]=(goc(Q[l].u)==goc(Q[l].v)) ;
		roll_back(len); 
		return ; 
	}
	int mid =(l+r)/2; 
	solve(id*2,l,mid) ; 
	solve(id*2+1,mid+1,r) ; 
	roll_back(len) ;
}
void xuly()
{
	FOR(i,1,q)if(Q[i].t==1)up(1,1,q,i,End[i],mp(Q[i].u,Q[i].v)) ; 
    FOR(i,1,n)pa[i] = i,sz[i]=1; 
    solve(1,1,q); 
    FOR(i,1,q)if(Q[i].t==3)
    {
    	// cout<<(res[i]==1?"YES":"NO")<<el;
    	cout<<res[i];
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