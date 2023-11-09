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
const int N =5e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q ;  
vi g[N] ;

void doc()
{
    cin>> n; 
    FOR(i,1,n-1)
    {
    	int u ,v; cin>>u>>v ;
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}

namespace sub1
{
	int in[N] , out[N] ; 
	int tt = 0 ;
	int pa[N] ; 
	void dfs(int u ,int p)
	{
		in[u]=++tt ;
		for(auto v:g[u])if(v!=p)
		{
			pa[v] = u; 
			dfs(v,u) ; 
		}
		out[u]=tt;  
	}
	struct IT
	{
		ve<short> lazy ;
		ve<bool> st;
		int n; 
		IT(int _n)
		{
			n=_n ;
			lazy = ve<short>(4*n,-1) ; 
			st   = ve<bool>(4*n,0) ; 
		}
		void dolazy(int id,int l, int r )
		{
			if(lazy[id]==-1)return ;
			st[id]=lazy[id] ; 
			if(l!=r)
			{
				lazy[id<<1]=lazy[id] ; 
				lazy[id<<1|1]=lazy[id] ; 
			}
			lazy[id] = -1 ;
		}	
		void up(int id, int l ,int r, int t ,int p , bool val)
		{
			dolazy(id,l,r) ;
			if(t<=l&&r<=p)
			{
				lazy[id] = val; 
				dolazy(id,l,r) ; 
				return;  
			}
			if(r<t||p<l)return ;
			int mid=(l+r)>>1; 
			up(id<<1,l,mid,t,p,val) ; 
			up(id<<1|1,mid+1,r,t,p,val) ; 
			st[id] = (st[id<<1]&st[id<<1|1]) ;
		}
		bool get(int id , int l, int r, int t , int p)
		{
			dolazy(id,l,r) ;
			if(r<t||p<l)return 1 ; 
			if(t<=l&&r<=p)return st[id] ;
			int mid=(l+r)>>1 ;
			if(get(id<<1,l,mid,t,p)==0)return 0 ;
			return get(id<<1|1,mid+1,r,t,p);
		}
	} ;  
    void xuly()
    {
    	dfs(1,0) ; 
        IT st(n) ; 
        cin >> q ; 
        FOR(_,1,q)
        {
        	int TYPE,u ; cin>> TYPE >> u ;
        	if(TYPE==1)
        	{
        		if(u!=1&&st.get(1,1,n,in[pa[u]],out[pa[u]])==0)
        		{
        			st.up(1,1,n,in[pa[u]],in[pa[u]],0) ;  
        		}
        		st.up(1,1,n,in[u],out[u],1) ; 
        	}
        	else if(TYPE==2)
        	{
        		st.up(1,1,n,in[u],in[u],0);
        	}
        	else if(TYPE==3)
        	{
        		cout<<st.get(1,1,n,in[u],out[u])<<el;
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}