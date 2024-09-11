/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "TRAVEL"
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
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        Mask(i)  (1ll<<(i))
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


int n , q ; 
ll W ;
struct Edge
{
	int u ,v ; 
	ll  w; 
}E[N] ; 
struct ke
{
	int v  ; 
	ll w; 
} ; 
ve<ke>g[N] ; 
void doc()
{
    cin>> n >> q ;
    FOR(i,1,n-1)
    {
    	cin>>E[i].u>>E[i].v>>E[i].w; 
    }

}

namespace sub1
{
	ll dep[N] ; 
	void dfs(int u ,int p)
	{
		for(auto [v,w] :g[u])if(v!=p)
		{
			dep[v] = dep[u]+w;
			dfs(v,u) ; 
		}
	}
    void xuly()
    {
    	ll last = 0; 
        while(q--)
        {
        	ll d , e; cin>>d>>e; 
        	E[d+1].w=e ; 
        	FOR(i,1,n)g[i].clear() ; 
        	FOR(i,1,n-1)
        	{
        		int u =E[i].u ; 
        		int v =E[i].v; 
        		ll w =E[i].w ;
        		g[u].pb({v,w}) ;
        		g[v].pb({u,w}) ; 
        	}
        	dep[1] = 0 ; 
        	dfs(1,0) ; 
        	int st = max_element(dep+1,dep+n+1)-dep ; 
        	dep[st] = 0 ;
        	dfs(st,0) ; 
        	last=*max_element(dep+1,dep+n+1) ; 
        	cout<<last<<el;
        	FOR(i,1,n)g[i].clear() ;
        }
    }
}

bool check2()
{
	FOR(i,1,n-1)
	{
		if(E[i].u!=1&&E[i].v!=1)return 0 ;
	}
	return 1 ; 
}
namespace sub2
{
	void xuly()
	{
		multiset<ll>VAL;
		FOR(i,1,n-1)
		{	
			VAL.insert(E[i].w) ;
		}

		ll last = 0; 
        while(q--)
        {
        	ll d , e; cin>>d>>e; 
        	d=(d+last)%(n-1) ; 
        	e=(e+last)%W ;
        	VAL.erase(VAL.find(E[d+1].w)) ; 
        	VAL.insert(E[d+1].w=e) ; 
        	auto it = VAL.rbegin() ; 
        	last = (*it) ; 
        	if(SZ(VAL)!=1)
        	{
        		++it; 
        		last+=*it ; 
        	}
        	cout<<last<<el;
        }
	}
}
namespace sub3
{
	int in[N] , out[N] ; 
	int tt = 0 ;
	int at[N] ; 
	int P[N][LO+2] ; 
	vi g[N] ;
	void dfs(int u ,int p)
	{
		in[u] = ++tt ;
		at[tt] =u  ;  
		for(auto v :g[u])if(v!=p)
		{
			P[v][0] = u ; 
			dfs(v,u) ;
		}
		out[u]=++tt ;
		at[tt] = u ; 
	}
	int go(int v)
	{
		FORD(i,LO,0)if(P[v][i]>1)
		{
			v=P[v][i] ; 
		}
		return v; 
	}
	struct DL
	{
		ll sum , ma ;
		int pos ; 
	} ; 
	DL st[8*N] ; 
	DL merge(DL L , DL R)
	{
		ll sum = L.sum+R.sum; 
		ll ma = max(L.ma,L.sum+R.ma) ; 
		int pos ;  
		if(ma==L.ma)pos=L.pos ;
		else pos = R.pos; 
		return DL{sum,ma,pos} ; 
	}
	void up(int id ,int l, int r, int pos ,ll val)
	{
		if(l==r&&l==pos)
		{
			st[id]={val,max(0ll,val),pos} ;
			return ; 
		}
		if(r<pos||pos<l)return; 
		int mid=(l+r)>>1; 
		up(id<<1,l,mid,pos,val) ; 
		up(id<<1|1,mid+1,r,pos,val) ;
		st[id] = merge(st[id*2],st[id*2+1]) ; 
	}
	DL get(int id ,int l ,int r, int t, int p)
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return{st[id].sum,-inf,0} ; 
		int mid =(l+r)>>1;
		return merge(get(id<<1,l,mid,t,p),get(id<<1|1,mid+1,r,t,p)) ; 
	}
	void xuly()
	{
		FOR(i,1,n-1)
		{
			int u =E[i].u ; 
			int v=  E[i].v ;
			g[u].pb(v) ; 
			g[v].pb(u) ; 
		}
		dfs(1,0) ; 
		FOR(i,1,n)
		{
			int u =E[i].u ; 
			int v=  E[i].v ;
			if(in[u]>in[v])
			{
				swap(u,v) ;
				swap(E[i].u,E[i].v) ;
			}
			up(1,1,2*n,in[v],E[i].w) ; 
			up(1,1,2*n,out[v],-E[i].w) ;
		}
		FOR(j,1,LO)FOR(i,1,n)P[i][j]=P[P[i][j-1]][j-1];
		ll last = 0; 
        while(q--)
        {
        	ll d , e; cin>>d>>e; 
        	d=(d+last)%(n-1) ; 
        	e=(e+last)%W ;
        	int v = E[d+1].v ; 
        	E[d+1].w = e ; 
        	up(1,1,2*n,in[v],e) ; 
        	up(1,1,2*n,out[v],-e) ; 
        	int dau = at[st[1].pos]  ; 
        	int cha = go(dau) ;
        	DL cl = merge(get(1,1,2*n,1,in[cha]-1),get(1,1,2*n,out[cha]+1,2*n)) ;
        	last =  st[1].ma+max(0ll,cl.ma); 
        	cout<<last<<el;
        }
	}
}
namespace subfull
{
	int in[N] , out[N] ;
	int tt = 0; 
	int h[N] ; 
	vi g[N] ;
	void dfs(int u ,int p)
	{
		in[u]=++tt ; 
		for(auto v:g[u])if(v!=p)
		{
			h[v] = h[u]+1 ;
			dfs(v,u) ; 
			++tt;
		}
		out[u] = tt ; 
	}
	struct DL
	{
		ll a[3][3] ;
		DL()
		{
			FOR(i,0,2)FOR(j,0,2)a[i][j] = 0 ; 
		} 
	}st[8*N] ;
	ll lazy[8*N] ;
	DL merge(DL L , DL R)
	{
		DL ans; 
		FOR(i,0,2)FOR(j,i,2)
		{
			ans.a[i][j] = max(L.a[i][j],R.a[i][j]) ;
			FOR(k,i,j-1)
			{
				maxi(ans.a[i][j],L.a[i][k]+R.a[k+1][j]) ; 
			}
		}
		return ans ;
	} 
	void dolazy(int id)
	{	
		FOR(i,0,2)FOR(j,i,2)
		{
			ll inc = 0;  
			if(i<=1&&1<=j)inc-=2*lazy[id] ; 
			if(i==0)inc+=lazy[id] ; 
			if(j==2)inc+=lazy[id] ; 
			st[id].a[i][j]+=inc ;
		}
		lazy[id<<1]+=lazy[id] ; 
		lazy[id<<1|1]+=lazy[id] ; 
		lazy[id] = 0 ; 
	}
	void up(int id , int l, int r, int t ,int p ,ll val)
	{
		dolazy(id) ; 
		if(t<=l&&r<=p)
		{
			lazy[id] = val ;
			dolazy(id) ;
			return ; 
		}
		if(r<t||p<l)return ; 
		int mid=(l+r)>>1; 
		up(id<<1,l,mid,t,p,val) ; 
		up(id<<1|1,mid+1,r,t,p,val) ;
		st[id] = merge(st[id<<1],st[id<<1|1]) ;
	}
	void xuly()
	{
		FOR(i,1,n-1)
		{
			g[E[i].u].pb(E[i].v) ;
			g[E[i].v].pb(E[i].u) ;
		} 
		dfs(1,0) ; 
		FOR(i,1,n-1)
		{
			int u =E[i].u ;
			int v =E[i].v ;
			if(h[u]<h[v])
			{
				swap(u,v) ; 
				swap(E[i].u,E[i].v) ; 
			}
			up(1,1,tt,in[u],out[u],E[i].w) ;
		}
		ll res = 0 ;
		while(q--)
		{
			ll d ,e ;
			cin>> d >> e; 
			d = (d+res)%(n-1)+1; 
			e = (e+res)%W; 
			up(1,1,tt,in[E[d].u],out[E[d].u],e-E[d].w) ;
			E[d].w=e; 
			res=st[1].a[0][2] ; 
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
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    else 
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
    	subfull::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}