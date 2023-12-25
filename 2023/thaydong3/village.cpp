/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "village"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 0 ;
int test = 1 ;  

#include<bits/stdc++.h>
using namespace std; 

#define ll unsigned long long 
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        M(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
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
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 
int n ,q ; 
vi g[N] ; 

void doc()
{
	cin>> n >>q ;
	FOR(i,1,n-1)
	{
		int u ,v; cin>> u >>v ;
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
}

namespace sub2 
{
	int h[N] , sz[N] ; 
	int pa[N] ; 
	int heavy[N] ; 
	void dfs(int u, int p)
	{
		sz[u] = 1; 
		for(auto v : g[u])if(v!=p)
		{
			h[v] =h[u]+1;
			dfs(v,u) ;
			sz[u]+=sz[v] ;
			pa[v] = u; 
			if(sz[v]>sz[heavy[u]])heavy[u] = v;   
		}
	}
	int tt = 0  ;
	int head[N] , pos[N] ; 
	void HLD()
	{
		FOR(i,1,n)if(heavy[pa[i]]!=i)
		{
			for(int u=i;u;u=heavy[u])
			{
				pos[u] = ++tt;  
				head[u] = i;
			}
		}
	}
	struct DL
	{
		ll val; 
		bool ok ; 
		friend DL operator+(DL a , DL b)
		{
			if(a.ok&&b.ok&&a.val==b.val)
			{
				return DL{a.val,1} ;
			}
			return {5748,0} ;
		}
	};
	DL st[8*N] ;
	ll lazy[8*N] ; 
	void dolazy(int id)
	{
		(st[id].val*=lazy[id])%=sm ; 
		(lazy[id<<1]*=lazy[id])%=sm ;
		(lazy[id<<1|1]*=lazy[id])%=sm ; 
		lazy[id] = 1;
	}
	void up(int id, int l, int r, int t ,int p ,ll val)
	{
		dolazy(id) ;
		if(t<=l&&r<=p)
		{
			lazy[id] = val; 
			dolazy(id) ; 
			return ; 
		}
		if(r<t||p<l)return ; 
		int mid = (l+r)>>1; 
		up(id<<1,l,mid,t,p,val) ; 
		up(id<<1|1,mid+1,r,t,p,val) ;
		st[id] = (st[id<<1]+st[id<<1|1]) ;  
	}
	DL get(int id ,int l, int r, int pos )
	{
		dolazy(id); 
		if(l==r)
		{
			return st[id] ;
		}
		int mid = (l+r)>>1 ;
		if(pos<=mid)return get(id<<1,l,mid,pos) ; 
		return get(id<<1|1,mid+1,r,pos) ;
	}
	bool check(int id ,int l ,int r, int t, int p ,ll same)
	{
		dolazy(id) ;
		if(t<=l&&r<=p)
		{
			return st[id].ok&&st[id].val==same ;
		}
		if(r<t||p<l)return 1; 
		int mid = (l+r)>>1 ;
		if(check(id<<1,l,mid,t,p,same)==0)return 0 ;
		return check(id<<1|1,mid+1,r,t,p,same) ;
	}
	void up(int u ,int v,int VAL)
	{
		while(head[u]!=head[v])
		{
			if(h[head[u]]<h[head[v]])swap(u,v) ;
			up(1,1,n,pos[head[u]],pos[u],VAL) ; 
			u=pa[head[u]] ;
		}
		if(pos[u]>pos[v])swap(u,v) ;
		up(1,1,n,pos[u],pos[v],VAL) ;
	}
	bool check(int u ,int v)
	{
		ll tmp = get(1,1,n,pos[u]).val ;
		while(head[u]!=head[v])
		{
			if(h[head[u]]<h[head[v]])swap(u,v) ; 
			if(check(1,1,n,pos[head[u]],pos[u],tmp)==0)return 0 ;
			u=pa[head[u]] ;
		}
		if(pos[u]>pos[v])swap(u,v) ;
		return check(1,1,n,pos[u],pos[v],tmp) ;
	}	
	vi snt; 
	int nt[N] ; 
	void sieve()  
	{
		FOR(i,2,1e3)if(nt[i]==0)
		{
			nt[i] = i; 
			snt.pb(i) ; 
			FOR(j,i,1e3/i)nt[i*j] = i ;
		}
	}
	void xuly()
	{
		map<int,int>color ; 
		sieve() ;
		dfs(1,0) ; 
		HLD() ;
		FOR(i,1,4*n)st[i]=DL{1,1},lazy[i]=1 ;
		int x = 0 ;
		FOR(i,1,q)
		{
			int type ; cin>>type ;
			if(type==1)
			{
				int u ,v , t; cin>>u >>v >>t ;
				if(color.count(t)==0)
				{
					if(x==SZ(snt))exit(3) ; 
					color[t] = snt[x++];
				}
				up(u,v,color[t]) ;
			}
			else
			{
				int u ,v; cin>>u >>v ;
				cout<<check(u,v)<<el; 
			}
		}
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        // sub1::xuly() ; 
        sub2::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}
