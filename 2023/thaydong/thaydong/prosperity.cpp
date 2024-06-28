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

#define int long long 
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
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q; 
vi g[N] ; 
int a[N] ;
void doc()
{
    cin>> n >>q ;
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n-1)
    {
    	int u ,v ; cin>>u>>v  ;
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int l[N] , r[N] ; 
	int pa[N] ; 
	int tt = 0 ; 
	ll st[(1<<20)+5] , lazy[(1<<20)+5] ;
	int tmp[N]; 
	void dolazy(int id, int l, int r)
	{
		st[id]+=1ll*(r-l+1)*lazy[id] ; 
		if(l!=r)
		{
			lazy[id<<1]+=lazy[id] ; 
			lazy[id<<1|1]+=lazy[id] ; 
		}
		lazy[id] = 0; 
	}
	void up(int id ,int l ,int r, int t, int p ,int val)
	{
		if(lazy[id])dolazy(id,l,r) ; 
		if(t<=l&&r<=p)
		{
			lazy[id]+=val; 
			dolazy(id,l,r) ;
			return ; 
		}
		if(r<t||p<l)return ; 
		int mid = (l+r)>>1 ;
		up(id<<1,l,mid,t,p,val) ; 
		up(id<<1|1,mid+1,r,t,p,val) ; 
		st[id] = st[id<<1]+st[id<<1|1] ; 
	}
	ll get(int id ,int l, int r, int t, int p)
	{
		if(lazy[id])dolazy(id,l,r) ; 
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return 0; 
		int mid = (l+r)>>1 ;
		return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ; 
	}
	int pos[N] ; 
	void build(int id, int l ,int r)
	{
		if(l==r)
		{
			st[id] =tmp[l] ;
			return ; 
		}
		int mid =(l+r)>>1; 
		build(id<<1,l,mid) ; 
		build(id<<1|1,mid+1,r) ; 
		st[id]=  st[id<<1]+st[id<<1|1] ; 
	}
	void bfs()
	{
		queue<int>q; 
		q.push(1) ; 
		while(!q.empty())
		{
			int u = q.front() ;
			q.pop() ; 
			pos[u]=++tt; 
			for(auto v: g[u])if(v!=pa[u])
			{
				pa[v] = u ;
				q.push(v) ; 
			}
		}
	}
    void xuly()
    {
    	bfs() ;  
    	FOR(i,1,n)tmp[pos[i]] = a[i] ;  
    	build(1,1,n) ; 
    	FOR(u,1,n)
    	{
    		l[u] = oo , r[u] = 0 ; 
    		for(auto v :g[u])if(pa[u]!=v)
	    	{
	    		mini(l[u],pos[v]) ;
	    		maxi(r[u],pos[v]) ; 
	    	}
	    }
    	FOR(i,1,q)
    	{
    		int TYPE ; cin>>TYPE  ; 
    		if(TYPE==1)
    		{
    			int u ,val ; cin>>u>>val; 
    			up(1,1,n,pos[u],pos[u],2*val);
    			if(r[u])up(1,1,n,l[u],r[u],val);
    			if(u>1)up(1,1,n,pos[pa[u]],pos[pa[u]],val) ;
    		}			
    		else	
    		{
    			int u ; cin>> u; 
    			ll res = get(1,1,n,pos[u],pos[u])+(r[u]==0?0:get(1,1,n,l[u],r[u]))+(u==1?0:get(1,1,n,pos[pa[u]],pos[pa[u]])) ; 
    			cout<<res<<el;
    		}
    	}
    }		
}
namespace subtrau
{   
    void xuly()
    {   
    }
}
/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}
