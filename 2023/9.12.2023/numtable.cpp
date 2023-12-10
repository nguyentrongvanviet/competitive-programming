/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "numtable"
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
const int N = 1e6+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ;
ve<vi>a ; 
int nt[(int)1e7+5];
int cnt = 0; 
int ID[(int)1e7+5];
int val[664579+5];
void snt()
{
	FOR(i,2,1e7)if(nt[i]==0)
	{	
		nt[i] =i ; 
		FOR(j,i,1e7/i)nt[i*j] = i; 
		cnt++ ; 
		val[cnt]=i;
		ID[i] = cnt; 
	}
}

struct pt
{
	int x , y; 
};
ve<pt>pos[664579+5] ;
void doc()
{
	snt() ;
	cin>> n >> m; 
	a.resize(n+2,vi(m+2,0)) ; 
	FOR(i,1,n)FOR(j,1,m)
	{
		cin>>a[i][j] ;
		int cur = a[i][j] ; 
		while(cur>1)
		{
			int d  = nt[cur] ;
			pos[ID[d]].pb({i,j}) ;  
			while(cur%d==0)cur/=d;
		}
	}
}

namespace sub1
{
	int pa[N],sz[N]; 
	int C(int x ,int y)
	{
		return (x-1)*m+y ; 
	}
	int goc(int u)
	{
		return pa[u] == u ? u : pa[u] = goc(pa[u]) ;
	}
	void hop(int u ,int v)
	{
		int chau = goc(u) ;
		int chav = goc(v) ;
		if(chau==chav)return ; 
		pa[chau] = chav; 
		sz[chav]+=sz[chau] ; 
	}

    void xuly()
    {
    	FOR(i,1,n*m)sz[i]=1,pa[i]=i;
    	int res =0 ; 
    	FOR(i,1,cnt)
    	{
    		for(auto u:pos[i])
    		{
    			int x=u.x; 
    			int y=u.y;
    			FORN(j,0,4)
    			{
    				int nx = x+xx[j] ;
    				int ny = y+yy[j] ; 
    				if(a[nx][ny]&&a[nx][ny]%val[i]==0)
    				{
    					hop(C(nx,ny),C(x,y)) ; 
    				}
    			}
    		}
    		for(auto u :pos[i])
    		{
    			int c = C(u.x,u.y) ;
    			maxi(res,sz[C(u.x,u.y)]) ; 
    			pa[c] = c; 
    			sz[c] = 1; 
    		}
    	}
    	cout<<res<<el ;
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
    int sub ;cin>>sub ;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}