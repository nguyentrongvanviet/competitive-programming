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
const int N = 50+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int TYPE , n , k   ;
vi g[N] ; 
int a[N][N] ;
void doc()
{		
    cin>> n >> k; 
    FOR(i,1,k)
    {
    	int u ,v ; cin>>u >>v; 
    	g[u].pb(v)  ; 
    	a[u][v] = 1; 
    }
}

namespace sub1
{
	int pa[N] ,dd[N] ; 
	bool dfs(int u)
	{
		if(dd[u])return 0 ;
		dd[u] =1 ; 
		for(auto v:g[u])if(pa[v]==0||dfs(pa[v]))
		{
			pa[v] = u; 
			return 1; 
		}
		return 0 ;
	}
    void xuly()
    {
        FOR(i,1,n)
        {
        	FOR(j,1,n)dd[j] = 0 ;
        	dfs(i) ; 
        }
        int res = 0;
        FOR(i,1,n)
        {
        	res+=(pa[i]>0)  ;
        }
        cout<<res;
    }
}
namespace sub2
{
	int s[N][N] ; 
	int get(int x, int y ,int u ,int v)
	{
		return s[u][v] - s[u][y-1]-s[x-1][v]+s[x-1][y-1] ; 
	}
	int f[N][N][N][N] ; 
	int tinh(int x, int y ,int u ,int v)
	{
		if(x>u||y>v)return 0 ; 
		if(x==u&&y==v)
		{
			return a[x][y] == 1; 
		}
		int &val = f[x][y][u][v] ;
		if(val!=-1)return val; 
		val = max(u-x+1,v-y+1) ; 
		FOR(j,y,v)
		{
			if(get(x,j,u,j)==0) 
			{
				mini(val,tinh(x,y,u,j-1)+tinh(x,j+1,u,v)) ; 
			}
		}
		FOR(i,x,u)
		{
			if(tinh(i,y,i,v)==0)
			{
				mini(val,tinh(x,y,i-1,v)+tinh(i+1,y,u,v)); 
			}
		}
		return val; 
	}
	void xuly()
	{	
		FOR(i,1,n)FOR(j,1,n)s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j] ; 
		FOR(x,1,n)FOR(y,1,n)FOR(u,1,n)FOR(v,1,n)f[x][y][u][v] =-1 ; 
		cout<<tinh(1,1,n,n)<<el;
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
        cin>>TYPE ;
        doc() ; 
        if(TYPE==1)sub1::xuly() ; 
        else sub2::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}