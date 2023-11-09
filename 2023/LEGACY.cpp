/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool multitest = 0;

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
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll       
#define            tct  template<typename T>

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
// end of template
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const int N = 1e5+5, oo = 2e9, LO = 17; 
struct ke
{
	int v; 
	int w;  
} ;
int n , Q , earth ; 
int numnode =0 ; 
int ID[8*N][2] ; 
ve<ke>g[8*N] ; 
ll f[8*N] ;
void add(int u ,int v ,int w , int ok)
{
	if(ok)swap(u,v) ; 
	g[u].pb({v,w}) ; 
}
void build(int id , int l ,int r ,int ok )
{
	ID[id][ok]=++numnode;
	if(l==r)
	{
		add(ID[id][ok],l,0,0) ; 
		add(ID[id][ok],l,0,1) ; 
		return ; 
	} 
	int mid =(l+r)/2;
	build(id*2,l,mid,ok) ;
	build(id*2+1,mid+1,r,ok) ; 
	add(ID[id][ok],ID[id*2][ok],0,ok) ; 
	add(ID[id][ok],ID[id*2+1][ok],0,ok) ;
} 
void add(int id ,int l, int r, int t ,int p ,int ok,int u ,int w )
{	
	if(t<=l&&r<=p)
	{
		int v = ID[id][ok] ; 
		add(u,v,w,ok);
		return ; 
	}
	if(r<t||p<l)return ;  
	int mid =(l+r)/2;
	add(id*2,l,mid,t,p,ok,u,w) ; 
	add(id*2+1,mid+1,r,t,p,ok,u,w) ; 
}
void doc()
{	
    cin>> n >> Q  >> earth ;
    numnode = n ; 
    build(1,1,n,0);
    build(1,1,n,1); 
    FOR(i,1,Q)
    {
    	int t , u ,v , l,r,w ; 
    	cin>>t ; 
    	if(t==1)
    	{	
    		cin>>u>>v>>w;
    		add(u,v,w,0) ; 
    	}
    	if(t==2)
    	{
    		cin>>u>>l>>r>>w; 
    		add(1,1,n,l,r,0,u,w); 
    	}
    	if(t==3)
    	{
    		cin>>u>>l>>r>>w ; 
    		add(1,1,n,l,r,1,u,w);
    	}
    }	
}
struct DL
{
	int u ; 
	ll w;  
} ; 
struct cmp
{
	bool operator()(DL a, DL b)
	{
		return a.w>b.w ; 
	}
}; 
void xuly()
{	
    FOR(i,1,numnode)f[i]=inf ;
    priority_queue<DL,ve<DL>,cmp>q ;  
    q.push({earth,f[earth]=0});
    while(!q.empty())
    {
    	int u =q.top().u ; 
    	ll val = q.top().w; 
    	q.pop() ;
    	if(f[u]!=val)continue ; 
    	for(auto x: g[u])
    	{
    		int v= x.v;
    		int w= x.w; 
    		if(mini(f[v],f[u]+w))
    			q.push({v,f[v]}) ; 
    	}
    }
    FOR(i,1,n)
    {
    	cout<<(f[i]==inf?-1:f[i])<<" ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(multitest)cin>>test ;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Duyen yeu Viet nhieu lam ! "<<el<<"Time elapsed : " << clock() <<"ms"<<el;
}