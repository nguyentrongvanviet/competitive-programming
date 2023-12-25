/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "PIC"
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
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ;
struct hcn
{
	int x, y , u ,v ; 
}a[N] ;
vi V ;
void doc()
{
   	cin>> n; 
   	FOR(i,1,n)
   	{
   		int x, y ,u,v ; cin>>x>>y>>u>>v;
   		V.pb(x) ; 
   		V.pb(y) ; 
   		V.pb(u) ;
   		V.pb(v) ;
   		a[i] = {x,y,u,v} ;
   	} 
}

namespace sub1
{
	int ID(int val)
	{
		return UB(all(V),val)-V.begin() ; 
	}
	struct query
	{
		int l, r; 
	};
	const int MAX = 4e5+5;
	ve<query>inc[MAX+5] , dec[MAX+5] ;
	ll res = 0;
	int st[8*MAX] ;
	int cover[4*MAX] ;
	void up(int id ,int l ,int r, int t ,int p ,int c)
	{
		if(r<t||p<l)return ;
		if(t<=l&&r<=p)
		{
			cover[id]+=c;
			if(cover[id]==0)st[id]=st[id<<1]+st[id<<1|1] ;
			else st[id] = V[r-1]-V[l-1]; ;
			return ;  
		}
		if(l+1==r)return ; 
		int mid= (l+r)>>1 ;
		up(id<<1,l,mid,t,p,c) ;
		up(id<<1|1,mid,r,t,p,c) ; 
		if(cover[id])st[id]=V[r-1]-V[l-1];
		else st[id] = st[id<<1]+st[id<<1|1] ;
	}
	void solve()
	{
		FOR(i,1,n)
		{
			int t = a[i].x ;
			int p = a[i].u ;
			int l = a[i].y ;
			int r = a[i].v ;
			inc[t].pb({l,r}) ;
			dec[p].pb({l,r}) ;
		}
		FOR(i,1,SZ(V))
		{
			ll pre =st[1] ;
			for(auto x:inc[i])
			{
				int l = x.l; 
				int r = x.r; 
				up(1,1,SZ(V),l,r,1) ;
			}
			res+=st[1]-pre ;
			pre=st[1] ; 
			for(auto x:dec[i])
			{
				int l =x.l; 
				int r= x.r; 
				up(1,1,SZ(V),l,r,-1) ;
			}
			assert(pre>=st[1]) ;
			res+=pre-st[1] ;
		}
		FOR(i,1,SZ(V))
		{
			inc[i].clear() ;
			dec[i].clear() ;-
		}
		FOR(i,1,4*SZ(V))st[i]=cover[i] = 0 ;
	}
    void xuly()
    {
    	uni(V) ; 
    	FOR(i,1,n)
    	{
    		a[i].x=ID(a[i].x) ;
    		a[i].y=ID(a[i].y) ; 
    		a[i].u=ID(a[i].u) ;
    		a[i].v=ID(a[i].v) ;
    	}
    	solve() ;
    	FOR(i,1,n)swap(a[i].x,a[i].y),swap(a[i].u,a[i].v);
    	solve() ;
    	cout<<res<<el;
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
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}