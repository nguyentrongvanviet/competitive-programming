/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "CTAB"
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
#define prt(a,n) {FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;}
#define prv(a) {for(auto _v:a)cout<<_v<<" "; cout<<el;} 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1} ; 
int yy[] = {-1,0,1,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e5+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n; 
ve<vi>a ;
void doc()
{
    cin>> n;
    a.resize(n,vi(n)) ;  
    FORN(i,0,n)FORN(j,0,n)
    {
    	cin>>a[i][j] ;
    }
}

namespace sub1
{
	map<ve<vi>,pair<pii,pii>> exist;
	bool in(int x, int y)
	{
		return 1<=x&&x<=n&&1<=y&&y<=n ; 
	}
    void xuly()
    {
    	exist[a]={{0,0},{0,0}} ;
    	queue<ve<vi>>q; 
    	q.push(a) ;
    	while(!q.empty())
    	{
    		ve<vi>cur = q.front() ;
    		// FORN(i,0,n)
    		// {
    		// 	FORN(j,0,n)
    		// 	{
    		// 		cout<<cur[i][j]<<" ";
    		// 	}
    		// 	cout<<el;
    		// }
    		// cout<<el;
    		q.pop()  ;
    		FORN(x,0,n)FORN(y,0,n)if(cur[x][y]==n*n)
			{
				FORN(d,0,4)
				{
					int nx = x +xx[d] ;
					int ny = y +yy[d] ; 
					if(in(nx+1,ny+1))
					{
						swap(cur[nx][ny],cur[x][y]) ; 
						if(exist.count(cur)==0)
						{
							exist[cur] = {{nx,ny},{x,y}} ;
							q.push(cur) ;
						}
						swap(cur[x][y],cur[nx][ny]) ;
					}
				}
    		}
    	}
    	ve<vi> cur(n,vi(n)) ;
    	FORN(i,0,n)FORN(j,0,n)cur[i][j] = i*n+(j+1) ; 
    	// FORN(i,0,n)
    	// {
    	// 	FORN(j,0,n)cout<<cur[i][j]<<" ";
    	// 	cout<<el;
    	// }
    	ve<pair<pii,pii>>res;
    	while(1)
    	{
    		pair<pii,pii>trace = exist[cur] ;
    		int x = trace.fi.fi ;
    		int y =trace.fi.se ;
    		int u =trace.se.fi ;
    		int v =trace.se.se ; 
    		if(max({x,y,u,v})==0)break;
    		res.pb({{x+1,y+1},{u+1,v+1}}) ;
    		swap(cur[x][y],cur[u][v]) ; 
    	}
    	reverse(all(res)) ;
    	cout<<SZ(res)<<el;
    	for(auto x:res)
    	{
    		cout<<x.fi.fi<<" "<<x.fi.se<<" "<<x.se.fi<<" "<<x.se.se<<el;
    	}
    }
}
namespace sub2
{
	map<ve<vi>,pair<pii,pii>> exists,existe;
	map<ve<vi>,int>fs , fe ;
	bool in(int x, int y)
	{
		return 1<=x&&x<=n&&1<=y&&y<=n ; 
	}
	void bfs(ve<vi>a,int dis, map<ve<vi>,pair<pii,pii>>& exist , map<ve<vi>,int>& f ) 
	{
		exist[a]={{0,0},{0,0}} ;
    	queue<ve<vi>>q; 
    	q.push(a) ;
    	while(!q.empty())
    	{
    		ve<vi>cur = q.front() ;
    		q.pop() ;
    		if(f[cur]==dis)continue ;
    		FORN(x,0,n)FORN(y,0,n)if(cur[x][y]==n*n)
			{
				FORN(d,0,4)
				{
					int nx = x +xx[d] ;
					int ny = y +yy[d] ; 
					if(in(nx+1,ny+1))
					{
						swap(cur[nx][ny],cur[x][y]) ; 
						if(exist.count(cur)==0)
						{
							exist[cur] = {{nx,ny},{x,y}} ;
							q.push(cur) ;
						}
						swap(cur[x][y],cur[nx][ny]) ;
					}
				}
    		}
    	}
	}
	ve<pair<pii,pii>>trace(ve<vi>cur , map<ve<vi>,pair<pii,pii>>exist)
	{
		ve<pair<pii,pii>>res;
    	while(1)
    	{
    		pair<pii,pii>trace = exist[cur] ;
    		int x = trace.fi.fi ;
    		int y =trace.fi.se ;
    		int u =trace.se.fi ;
    		int v =trace.se.se ; 
    		if(max({x,y,u,v})==0)break;
    		res.pb({{x+1,y+1},{u+1,v+1}}) ;
    		swap(cur[x][y],cur[u][v]) ; 
    	}
    	return res ;
	}
	void xuly()
	{
		bfs(a,12,exists,fs) ; 
		ve<vi>e(n,vi(n)) ;
		FORN(i,0,n)FORN(j,0,n)e[i][j]=i*n+j+1 ;
		bfs(e,13,existe,fe) ;
		for(auto u : exists )
		{
			if(existe.count(u.fi))
			{
				ve<pair<pii,pii>>S = trace(u.fi,exists) ; 
				ve<pair<pii,pii>>T = trace(u.fi,existe) ;
				reverse(all(S)) ;
				cout<<SZ(S)+SZ(T)<<el;
				for(auto x:S)
		    	{
		    		cout<<x.fi.fi<<" "<<x.fi.se<<" "<<x.se.fi<<" "<<x.se.se<<el;
		    	} 
		    	for(auto x:T)
		    	{
		    		cout<<x.fi.fi<<" "<<x.fi.se<<" "<<x.se.fi<<" "<<x.se.se<<el;
		    	} 
				break; 
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
    else if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.OUT","w",stdout) ;   
    }
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        if(n<=3)sub1::xuly() ; 
        else sub2::xuly(); 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}