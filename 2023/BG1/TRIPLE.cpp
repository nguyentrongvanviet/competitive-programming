/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "TRIPLE"
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
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 3e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n;
struct pt
{
	int x,y; 
	bool operator<(const pt &a)const
	{
		return x<a.x||(x==a.x&&y<a.y) ; 
	}
} ;
pt a[N] ; 
void doc()
{
    cin>> n; 
    FOR(i,1,n)
    {
    	cin>>a[i].x>>a[i].y;
    }
}	

namespace sub1
{
	const int N = 3e3+5 ;
	int near[N] ;
	int dis(pt a , pt b)
	{
		return abs(a.x-b.x)+abs(a.y-b.y) ;
	} 
	bitset<N>ans[N] ;	
    void xuly()
    {
    	FOR(i,1,n)near[i] = oo ; 
    	FOR(i,1,n)FOR(j,1,n)if(i!=j)
    	{
    		mini(near[i],dis(a[i],a[j])) ; 
    	}
    	FOR(i,1,n)FOR(j,i+1,n)if(near[i]==near[j]&&dis(a[i],a[j])==near[i])
    	{
    		ans[i][j] = 1; 	
    	}
    	int res = 0 ;
    	FOR(i,1,n)FOR(j,i+1,n)if(near[i]==near[j]&&dis(a[i],a[j])==near[i])
    	{	
    		res+=(ans[i]&ans[j]).count() ; 
    	}
    	cout<<res<<el;
    }
}
namespace sub2
{
	
	struct IT
	{
		vi st ; 
		int n ; 
		IT(int _n=0)
		{
			n=_n ;
			st=vi(4*n+5,oo) ;
		}
		void up(int id ,int l ,int r, int pos ,int val)
		{
			if(l==r&&l==pos)
			{
				mini(st[id],val) ;
				return ; 
			}
			if(r<pos||pos<l)return ; 
			int mid =(l+r)>>1 ;
			up(id<<1,l,mid,pos,val) ; 
			up(id<<1|1,mid+1,r,pos,val) ; 
			st[id] = min(st[id<<1],st[id<<1|1]) ;
		}
		int get(int id ,int l, int r, int t ,int p )
		{
			if(t<=l&&r<=p)return st[id] ; 
			if(r<t||p<l)return oo ; 
			int mid = (l+r)>>1; 
			return min(get(id<<1,l,mid,t,p),get(id<<1|1,mid+1,r,t,p)) ; 
		}
	} ; 
	ll near[N] ; 
	map<ll,vi>list ; 
	map<int,ve<pii>>row ; 
	vi ke[N] ; 
	void add(int u , ve<pii>&a ,int l ,int r )
	{
		int L = LB(all(a),l,[](pii x ,int val){return x.se<val;})-a.begin();
		int R = UB(all(a),r,[](int val , pii x){return val<x.se;})-a.begin()-1 ;
		FOR(i,L,R)if(a[i].fi!=u)ke[u].pb(a[i].fi) ; 
	}
	void solve(int d )
	{
		for(auto x:row)
		{
			ve<pii> UP  , DOWN ;
			if(row.count(x.fi-d))UP=row[x.fi-d] ; 
			if(row.count(x.fi+d))DOWN=row[x.fi+d] ; 	
			for(auto u : x.se)
			{
				int id = u.fi ;
				add(id,UP,u.se-d,u.se+d);
				add(id,DOWN,u.se-d,u.se+d) ; 
			}
		}
		row.clear() ;
	}
	int dis(pt a, pt b)
	{
		return abs(a.x-b.x)+abs(a.y-b.y) ;
	}
	void xuly()
	{
		vi V; 
		FOR(i,1,n)V.pb(a[i].y);
		uni(V) ;
		int m =SZ(V) ; 
		sort(a+1,a+n+1) ;
		FOR(i,1,n)near[i] = oo ; 
		IT LOW(m) , HIGH(m) ; 
		FOR(i,1,n)
		{
			int u = UB(all(V),a[i].y)-V.begin() ;
			if(i>1)
			{
				mini(near[i] , 1ll*a[i].x + a[i].y + LOW.get(1,1,m,1,u)) ; 
				mini(near[i] , 1ll*a[i].x - a[i].y + HIGH.get(1,1,m,u+1,m)) ; 
			}
			LOW.up(1,1,m,u,-a[i].x-a[i].y) ;
			HIGH.up(1,1,m,u,-a[i].x+a[i].y) ; 
		}
		LOW = IT(m) ; 
		HIGH = IT(m) ; 
		FORD(i,n,1)
		{
			int u = UB(all(V),a[i].y)-V.begin() ; 
			if(i!=n)
			{
				mini(near[i],-1ll*a[i].x + a[i].y + LOW.get(1,1,m,1,u))  ;
				mini(near[i],-1ll*a[i].x - a[i].y + HIGH.get(1,1,m,u+1,m)) ; 
			}
			LOW.up(1,1,m,u,a[i].x-a[i].y) ;
			HIGH.up(1,1,m,u,a[i].x+a[i].y) ; 
		}

		FOR(i,1,n)
		{
			list[near[i]].pb(i) ; 
		}
		for(auto x:list)
		{ 
			// prv(x.se) ;
			for(auto p : x.se)
			{
				row[a[p].x-a[p].y].pb(mp(p,a[p].x+a[p].y)) ; 
			}
			solve(x.fi) ;
			for(auto p : x.se)
			{
				row[a[p].x+a[p].y].pb(mp(p,a[p].x-a[p].y)) ; 
			}
			solve(x.fi) ; 
		}
		int res = 0 ;
		FOR(i,1,n)
		{
			uni(ke[i]) ; 
			for(auto u : ke[i]) for(auto v: ke[i])if(u<v)
			{
				if(dis(a[u],a[v])==near[i])res++ ; 
			}
		}
		cout<<res/3;	
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
        // sub3::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}