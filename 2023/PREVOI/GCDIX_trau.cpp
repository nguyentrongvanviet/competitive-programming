/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "GCDIX"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"

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


int n  , q ; 
int a[N] ;
vi g[N] ;
void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,n-1)
    {
    	int u , v; cin>> u >>v ;
    	g[u].pb(v) ;
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int h[N] , pa[N] ;
	void dfs(int u ,int p)
	{
		for(auto v:g[u])if(v!=p)
		{
			pa[v] = u ;
			h[v] = h[u]+1 ;
			dfs(v,u) ; 
		}
	}
	void up(int u ,int v ,int val)
	{
		while(1)
		{
			if(h[u]<h[v])swap(u,v); 
			a[u]+=val ;
			if(u==v)break;
			u=pa[u] ; 
		}
	}
	int get(int u, int v)
	{
		int ans = 0 ;
		while(1)
		{
			if(h[u]<h[v])swap(u,v); 
			ans=gcd(ans,a[u]) ;
			if(u==v)break;
			u=pa[u] ; 
		}
		return ans; 
	}
    void xuly()
    {
        dfs(n/2,0) ; 

        while(q--)
        {
        	int type  ; cin>>type ;
    		int u , v, k; 
        	if(type==1)
        	{
        		cin>> u >>v >> k;
        		up(u,v,k) ;  
        	}
        	else
        	{
        		cin>> u >>v  ;
        		cout<<get(u,v)<<el;
        	}
        }
    }
}
namespace sub3
{
	int b[N] ; 
	struct DL
	{
		int uc , val; 
		DL operator += (int x)
		{
			uc+=x; 
			val+=x ;
			return {uc,val} ;
		}
		friend DL operator +(DL a , DL b)
		{
			return DL{gcd(a.uc,b.uc),a.val+b.val} ;
		}
	};
	DL st[4*N] ; 

	void build(int id ,int l, int r)
	{
		if(l==r)
		{
			st[id] ={b[l],b[l]}; 
			return ; 
		}
		int mid= (l+r)>>1; 
		build(id<<1,l,mid) ;
		build(id<<1|1,mid+1,r) ;
		st[id] = st[id<<1]+st[id<<1|1] ; 
	}
	void up(int id ,int l, int r ,int pos ,int val)
	{
		if(l==r&&l==pos)
		{
			st[id]+=val; 
			return ;
		}	
		if(r<pos||pos<l)return ; 
		int mid=(l+r)>>1; 
		up(id<<1,l,mid,pos,val) ;
		up(id<<1|1,mid+1,r,pos,val) ;
		st[id] = st[id<<1]+st[id<<1|1] ; 
	}
	DL get(int id ,int l, int r, int t, int p)
	{
		if(t<=l&&r<=p)return st[id]  ;
		if(r<t||p<l)return {0,0};
		int mid=(l+r)>>1 ;
		return get(id<<1,l,mid,t,p) + get(id<<1|1,mid+1,r,t,p) ; 
	}
	void xuly()
	{
		FOR(i,1,n)
		{
			b[i] = a[i] - a[i-1] ; 
		}
		build(1,1,n) ; 
		while(q--)
		{
			int type , u , v , k ;
			cin>>type ;
			if(u>v)swap(u,v) ; 
			if(type==1)
			{
				cin>> u >>v >> k; 
				up(1,1,n,u,k) ; 
				up(1,1,n,v+1,-k) ; 
			}
			else
			{
				cin>> u >> v ; 
				if(u==v)
				{
					cout<<b[u]-b[u-1]<<el; 	
				}
				else
				{
					cout<<abs(gcd(get(1,1,n,u,u).val,get(1,1,n,u+1,v).uc))<<el;	
				}
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
        sub1::xuly() ; 
        // sub3::xuly() ;
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}