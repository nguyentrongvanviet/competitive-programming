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
const int N = 5e2+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m , T ;
struct Edge
{
	int x , y , u , v , val; 
	bool operator<(const Edge&a)const
	{
		return val<a.val; 
	}
} ; 
int a[N][N] ;
int tt = 0 ;
Edge E[2*N*N] ;
void doc()
{
	cin>> n >> m >>T ;
	FOR(i,1,n)FOR(j,1,m)
	{
		cin>>a[i][j] ; 
	} 
	FOR(i,1,n)FOR(j,1,m)
	{	
		FORN(t,0,2)
		{
			int ni = i+xx[t] ;
			int nj = j+yy[t] ; 
			if(ni==0||nj==0)continue;
			E[++tt]={ni,nj,i,j,abs(a[i][j]-a[ni][nj])};
		}
	}
}

namespace sub1
{
	pii pa[N][N] ; 
	int sz[N][N] ;
	pii Q[N*N] ; 
	int L[N*N] , R[N*N] , res[N*N] ;
	vi tmp[2*N*N] ;
	inline pii goc(int x ,int y )
	{
		return pa[x][y] == mp(x,y) ? mp(x,y):pa[x][y]=goc(pa[x][y].fi,pa[x][y].se) ;
	}
	inline void hop(int x, int y ,int u ,int v)
	{
		pii X = goc(x,y) ;
		pii U = goc(u,v) ;
		if(X==U)return ; 
		pa[X.fi][X.se] = U ;
		sz[U.fi][U.se]+=sz[X.fi][X.se] ;
	}
    void xuly()
    {	
    	int q= 0 ; 
    	FOR(i,1,n)FOR(j,1,m)
    	{
    		int TYPE ; cin>>TYPE ;
    		if(TYPE==1)
    		{
    			Q[++q] = {i,j} ;
    			L[q] = 1 ;
    			R[q]= tt ; 
    		}
    	}
    	sort(E+1,E+tt+1) ;
    	while(1)
    	{
    		FOR(i,1,n)FOR(j,1,m)
    		{
    			pa[i][j] ={i,j} ; 
    			sz[i][j] = 1; 
    		}
    		FOR(i,1,tt)tmp[i].clear();
    		bool ok = 0 ; 
    		FOR(i,1,q)
    		{
    			if(L[i]<=R[i])
    			{
    				ok = 1; 
    				int mid=(L[i]+R[i])/2;
    				tmp[mid].pb(i) ;
    			}
    		}
    		if(!ok)break;
    		FOR(i,1,tt)
    		{
    			hop(E[i].x,E[i].y,E[i].u,E[i].v) ;
    			for(auto id : tmp[i])
    			{
    				int x = Q[id].fi ; 
    				int y = Q[id].se; 
    				pii X = goc(x,y) ;
    				if(sz[X.fi][X.se]>=T)
    				{
    					res[id] = E[i].val;
    					R[id] =i-1 ;
    				}
    				else
    				{
    					L[id]=i+1; 
    				}
    			}
    		}
    	}
    	ll tot = 0; 
    	FOR(i,1,q)
    	{
    		tot+=res[i] ; 
    	}
    	cout<<tot;
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