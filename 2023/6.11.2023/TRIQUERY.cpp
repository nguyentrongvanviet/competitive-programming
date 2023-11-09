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
const int N = 3e5+5 , oo = 2e9 , LO = 19 , CH = 26 ; 


int n , q ;
struct pt
{
	int x,y ; 
	bool operator<(const pt&a)const
	{
		return x+y<a.x+a.y ;
	}
} ;  
pt a[N] ; 
vi P[N] ; 
struct Query
{
	int x ,y ,d ; 
	int id ;
	bool operator<(const Query&a)const
	{
		return x+y+d<a.x+a.y+a.d ;
	}
} ; 
Query Q[200005] ;
int res[200005];
void doc()
{
	cin>> n >>q ;
	FOR(i,1,n)
	{
		cin>>a[i].x>>a[i].y ;
		P[a[i].x].pb(a[i].y) ; 	
	}
	FOR(i,1,q)
	{
		cin>>Q[i].x>>Q[i].y>>Q[i].d ;
		Q[i].id =i ; 
	}
}

namespace sub1
{	
	struct tree_bit
	{
		vi bit ;
		int n  ; 
		tree_bit(int _n)
		{
			n = _n ;
			bit=vi(n+1,0) ; 
		}	
		void up(int id ,int val)
		{
			for(int i=id;i<=n;i+=i&-i)bit[i]+=val; 
		}
		int get(int id)
		{
			int ans = 0 ;
			for(int i=id;i;i-=i&-i)ans+=bit[i] ;
			return ans ;
		}
		int get(int l ,int r)
		{
			return get(r)-get(l-1) ;
		}
	} ; 
	int H[N*(LO+1)] ;
	int st[N*(LO+1)] ;  
	int L[N*(LO+1)] ; 
	int R[N*(LO+1)] ;
	int node = 0; 
	int up(int old, int l ,int r, int pos)
	{
		int cur = ++node;   
		if(l==r)
		{
			st[cur] = st[old]+1; 
			return cur ;
		}
		int mid=(l+r)/2 ;
		if(pos<=mid)
		{
			R[cur] = R[old] ;
			L[cur] = up(L[old],l,mid,pos) ;
		}
		else
		{
			L[cur] = L[old] ;
			R[cur] = up(R[old],mid+1,r,pos) ; 
		}
		st[cur] = st[L[cur]]+st[R[cur]] ; 
		return cur ;
	}
	int get(int id ,int l, int r , int t, int p)
	{
		if(r<t||p<l||id==0)return 0; 
		if(t<=l&&r<=p)return st[id] ; 
		int mid = (l+r)/2 ;
		return get(L[id],l,mid,t,p)+get(R[id],mid+1,r,t,p) ;
	}
    void xuly()
    {
    	tree_bit X(3e5) ;
    	tree_bit Y(3e5) ;  
    	FOR(i,1,3e5)
    	{
    		H[i] = H[i-1] ; 
    		for(auto y : P[i])
    		{
    			H[i]=up(H[i],1,3e5,y) ;
    		}
    	}
    	sort(a+1,a+n+1) ;
    	int it= 1; 
    	sort(Q+1,Q+q+1) ;
    	FOR(i,1,q)
    	{
    		int x=  Q[i].x; 
    		int y = Q[i].y; 
    		int d = Q[i].d; 
    		int val =x+y+d; 
    		while(it<=n&&a[it].x+a[it].y<=val)
    		{
    			X.up(a[it].x,1) ; 
    			Y.up(a[it].y,1) ;
    			++it;
    		}
    		int id = Q[i].id ; 
    		int T = X.get(x-1) ; 
    		int D = Y.get(y-1) ; 
    		int TD = get(H[x-1],1,3e5,1,y-1); 
    		res[id] = (it-1) - T - D + TD ;
    	}
    	FOR(i,1,q)cout<<res[i]<<el;
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