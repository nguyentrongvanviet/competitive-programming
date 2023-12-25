/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "poly"
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
#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n ;	
struct pt
{
	int x,y ;
};
bool cmpx(pt a , pt b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y) ;
}
bool cmpy(pt a, pt b)
{
	return a.y<b.y||(a.y==b.y&&a.x<b.x) ;
};
ve<pt>P[N] ;
void doc()
{
    cin>> n;
    FOR(i,1,n)
    {
    	int node ; cin>>node ; 
    	while(node--)
    	{
    		int x,y ;
    		cin>>x>>y;
    		P[i].pb({x,y}) ;
    	}
    }
}

namespace sub1
{
	struct HCN
	{
		int x,y,u,v; 
	}a[N] ;
	int M ; 
	vi V; 
	int VAL[N] ; 
	int ID(int val)
	{
		return UB(all(V),val)-V.begin() ; 
	}
	int st[8*N] , cover[4*N] ; 
	void up(int id , int l, int r,int t, int p ,int val)
	{
		if(t<=l&&r<=p)
		{
			cover[id]+=val; 
			if(cover[id])st[id]  = VAL[r]-VAL[l] ;
			else st[id] = st[id<<1]+st[id<<1|1] ;
			return ; 
		}
		if(l+1==r)return ;
		if(r<t||p<l)return ;
		int mid = (l+r)>>1 ;
		up(id<<1,l,mid,t,p,val) ; 
		up(id<<1|1,mid,r,t,p,val) ;
		if(cover[id])st[id] = VAL[r]-VAL[l] ; 
		else st[id] = st[id<<1]+st[id<<1|1] ; 
	}
	struct Query
	{
		int l , r, val ; 
	} ;
	ve<Query>Q[N] ; 
	ll area()
	{
		ll res = 0 ;
		FOR(i,1,M)
		{
			res+=st[1]*(VAL[i]-VAL[i-1]) ;
			for(auto q:Q[i])
			{
				int l=q.l ;
				int r=q.r ;
				int val=q.val ;
				up(1,1,M,l,r,val) ;
			}
		}
		return res; 
	}
    void xuly()
    {
    	FOR(i,1,n)
    	{
    		int x = oo ,y =oo , u = -oo , v =-oo ;
    		FORN(j,0,4)
    		{
    			mini(x,P[i][j].x) ;
    			mini(y,P[i][j].y) ;
    			maxi(u,P[i][j].x) ; 
    			maxi(v,P[i][j].y) ;
    		}
    		a[i] = {x,y,u,v}  ; 
    	}
    	FOR(i,1,n)
    	{
    		V.pb(a[i].x) ;
    		V.pb(a[i].y) ;
    		V.pb(a[i].u) ;
    		V.pb(a[i].v) ;
    	}
    	uni(V) ;
    	M = SZ(V) ; 
    	FOR(i,1,M)
    	{
    		VAL[i] = V[i-1] ; 
    	}
    	FOR(i,1,n)
    	{
    		int x=ID(a[i].x) ;
    		int y=ID(a[i].y) ;
    		int u=ID(a[i].u) ;
    		int v=ID(a[i].v) ;	
    		Q[x].pb({y,v,1}) ;
    		Q[u].pb({y,v,-1}) ;
    	}
    	cout<<area()<<el;
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