/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "PAINT"
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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 6e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , q; 
int W , H ; 
struct pt
{
	int x,y; 
};
ve<pt>a[N] ; 
pt Q[N] ;
vi V ;
int m ;
void doc()
{
	cin>>W >> H>>n>>m>>q; 
	V.pb(0) ; 
	V.pb(W) ; 
	V.pb(H) ; 
	a[0].pb({0,0}) ;
	a[0].pb({0,H}) ; 
	a[0].pb({W,H}) ;
	a[0].pb({W,0}) ;  
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			int x, y; cin>>x>>y ;
			a[i].pb({x,y}) ;
			V.pb(x) ; 
			V.pb(y) ;
		}
	}
	FOR(i,1,q)
	{
		int x,y ;cin>>x>>y ;
		Q[i] = {x,y} ;
		V.pb(x) ; 
		V.pb(y) ;
	}
}

namespace sub3
{
	int VAL[N] ; 
	ll area[N] ; 
	int ID(int val)
	{
		return UB(all(V),val)-V.begin() ; 
	}
	struct Query
	{
		int type ;
		int id , high ,pos ;
	} ;
	ve<Query>ADD[N] ;
	int BOUND[N] ; 
	struct DL
	{
		int id , l ,r ; 
	} ; 
	ve<DL>GET[N]  ;
	ve<Query>list[N] ;
	int st[4*N] ; 
	void up(int id, int l ,int r, int pos ,int val)
	{
		if(l==r&&l==pos)
		{
			st[id] = val ; 
			return ; 
		}	
		if(r<pos||pos<l)return ; 
		int mid = (l+r)>>1; 
		up(id<<1,l,mid,pos,val) ; 
		up(id<<1|1,mid+1,r,pos,val) ; 
		st[id] =max(st[id<<1],st[id<<1|1]) ;
	}
	ll tot_area  ; 
	vi cur ;
	ll res[N] ;
	void walk(int id ,int l, int r, int t, int p , int bound)
	{
		if(r<t||p<l||st[id]<bound)return ; 
		if(l==r)
		{
			assert(!list[l].empty());
			
			while(!list[l].empty()&&list[l].back().high>=bound)
			{
				int type= list[l].back().type ;
				int id= list[l].back().id ;
				if(type==0)cur.pb(id) ;
				else tot_area+=area[id] ;
				list[l].pk() ; 
			}
			if(list[l].empty())st[id]=0;
			else st[id] = list[l].back().high ;
			return ; 
		}
		int mid = (l+r)>>1;
		walk(id<<1,l,mid,t,p,bound) ;
		walk(id<<1|1,mid+1,r,t,p,bound) ;
		st[id] = max(st[id<<1],st[id<<1|1]) ; 
	}
    void xuly()
    {
    	uni(V) ; 
    	FOR(i,1,SZ(V))VAL[i] = V[i-1] ; 
    	FOR(i,0,n)
    	{
    		for(auto &p : a[i])
    		{
    			p.x=ID(p.x) ; 
    			p.y=ID(p.y) ;
    		}
    	}
    	FOR(i,1,q)
    	{
    		Q[i].x=ID(Q[i].x) ; 
    		Q[i].y=ID(Q[i].y) ; 
    		ADD[Q[i].y].pb({0,i,Q[i].y,Q[i].x}) ;
    	}
    	FOR(i,0,n)
    	{
    		int l = oo ; 
    		int r = 0 ; 
    		int d = oo ;  
    		int u = 0 ; 
    		for(auto p : a[i])
    		{
    			mini(l,p.x) ,maxi(r,p.x) ;
    			mini(d,p.y) ,maxi(u,p.y) ;
    		}
    		BOUND[i] = d; 
    		area[i] = 1ll*(VAL[u]-VAL[d])*(VAL[r]-VAL[l]);
    		ADD[d].pb({1,i,d,l}) ; 
    		GET[u].pb({i,l,r}) ; 
    	}
    	int LEN = SZ(V) ;
    	FOR(i,1,LEN)
    	{
    		for(auto x : GET[i])
    		{	
    			int id = x.id ;
    			int l = x.l ; 
    			int r = x.r ;
    			int bound = BOUND[id] ;
    			tot_area= 0 ; 
    			cur.clear() ;
    			walk(1,1,LEN,l,r,bound+1);
    			for(auto phu : cur)
    			{
    				res[phu] = area[id] - tot_area ; 
    			}
    		}
    		for(auto x : ADD[i])
    		{
    			int pos = x.pos ;
				up(1,1,LEN,pos,i) ; 
				list[pos].pb(x) ;	
    		}
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub3::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}