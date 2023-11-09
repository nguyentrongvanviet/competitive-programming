/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "d13mst"
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
const ll inf = 1e12 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ,q ; 
struct DL
{
	int l ,r , val; 
} ; 
ve<DL>Q[N] ;

void doc()
{
 	cin>> n >> q ;
 	FOR(i,1,q)
 	{
 		int u ,v , l ,r,val ; cin>>u>>v>>l>>r>>val; 
 		Q[u].pb({l,r,val}) ; 
 		Q[v+1].pb({l,r,-val}) ; 
 		Q[l].pb({u,v,val}) ; 
 		Q[r+1].pb({u,v,-val}) ;
 	}   
}

namespace sub1
{
	int dd[N] ;
	int pa[N] ;
	ll res = 0;   
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
		return 1; 
	}
	struct BG
	{
		int root ;
		int val; 
	} ; 
	struct Node
	{
		BG A ; 
		BG B ;
	} ; 
	Node st[8*N] ; 
	ll lazy[8*N] ;
	void up(Node& L , BG tmp)
	{
		if(L.A.root==tmp.root)
		{
			mini(L.A.val,tmp.val) ;
		}
		else if(L.A.val>=tmp.val)
		{
			L.B = L.A ;
			L.A = tmp; 
		}
		else if(mini(L.B.val,tmp.val))
		{	 
			L.B=tmp ;
		}	
	} 
	Node merge(Node L , Node R)
	{
		up(L,R.A) ;
		up(L,R.B) ; 
		return L; 
	}
	void build(int id ,int l ,int r)
	{
		lazy[id] = 0 ; 
		if(l==r)
		{
			st[id] = 
			{
				{goc(l),0},
				{0,oo} 
			};  
			return ; 
		}
		int mid=(l+r)/2 ;
		build(id*2,l,mid) ;
		build(id*2+1,mid+1,r) ;
		st[id] = merge(st[id*2],st[id*2+1]) ;
	}
	void dolazy(int id)
	{
		if(lazy[id]==0)return ; 
		st[id].A.val+=lazy[id]  ; 
		st[id].B.val+=lazy[id]  ;
		lazy[id*2]+=lazy[id] ; 
		lazy[id*2+1]+=lazy[id] ; 
		lazy[id] = 0 ;
	}
	void up(int id, int l ,int r, int t, int p,int val )
	{
		dolazy(id) ; 
		if(t<=l&&r<=p)
		{
			lazy[id]+=val; 
			dolazy(id) ;
			return ; 
		}
		if(r<t||p<l)return ;
		int mid=(l+r)/2; 
		up(id*2,l,mid,t,p,val) ; 
		up(id*2+1,mid+1,r,t,p,val) ; 
		st[id] =merge(st[id*2],st[id*2+1]) ; 
	}	
	Node get(int id ,int l, int r, int t, int p )
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return
		{
			{0,oo},{0,oo}
		};
		int mid=(l+r)/2 ;
		return merge(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
	}
	struct Edge
	{
		int u ,v , w  ; 
		bool operator<(const Edge&a)const
		{
			return w<a.w ; 
		}	
	} ; 
    void xuly()
    {
    	int comp = n ;
    	
    	FOR(i,1,n)pa[i] = i ;
    	while(comp>1)
    	{
    		build(1,1,n) ; 
			ve<Edge>E ;
    		FOR(i,1,n)
    		{
    			for(auto x : Q[i])
    			{
    				int l = x.l ; 
    				int r = x.r ;
    				int val = x.val; 
    				up(1,1,n,l,r,val) ; 
    			}
    			Node C=st[1] ;

    			if(C.A.root&&goc(C.A.root)!=goc(i))
				{
					E.pb({i,C.A.root,C.A.val}) ; 
				}
				else if(C.B.root&&goc(C.B.root)!=goc(i))
				{
					E.pb({i,C.B.root,C.B.val}) ; 
				}
    		}
			sort(all(E)) ; 
			for(auto [u,v,w]:E)
			{
				if(hop(u,v))comp--,res+=w; 
			}
    	}
    	cout<<res; 
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