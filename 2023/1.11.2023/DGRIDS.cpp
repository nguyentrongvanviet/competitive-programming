/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "DGRIDS"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool mtt = 1 ;
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
const int N = 2*45+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m; 
int a[N] , b[N] ;
vi g[N] ; 
int C[N][N] ; 
void doc()
{
	cin>> n >>m ; 
	FOR(i,0,n+m+1)g[i].clear();
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,m)cin>>b[i] ; 
}

namespace sub1
{
	vi g[N] ;
	ll C[N][N] ;
	int pa[N] ; 
	bool bfs(int s ,int t){
		queue<int>q; 
		FOR(i,0,n+m+1)pa[i] = -1 ;
		q.push(s) ; 
		while(!q.empty())
		{
			int u = q.front() ;
			q.pop() ;
			for(auto v:g[u])if(pa[v]==-1&&C[u][v]>0)
			{	
				pa[v] = u ;  
				q.push(v) ; 
				if(v==t )return 1 ; 
			}
		}
		return 0 ; 
	}
	ll flow(int s, int t )
	{
    	ll res = 0 ; 
        while(bfs(s,t))
        {
        	ll mi = inf ;
        	for(int u = t ; u!=s ; u=pa[u])
        	{
        		int v= pa[u] ; 
        		mini(mi,C[v][u]) ;
        	}
        	res+=mi ; 
        	for(int u = t ; u!=s ; u=pa[u])
        	{
        		int v = pa[u] ; 
        		C[v][u]-=mi ; 
        		C[u][v]+=mi ;
        	}
        }
        return res ; 
	}
	int res[N][N] ;
	void solve(int x,int y )
	{
		FORN(i,0,SZ(g[x]))
		{
			if(g[x][i]==n+y)
			{
				g[x].erase(g[x].begin()+i);
				break;
			}
		} 
		FORN(i,0,SZ(g[n+y]))if(g[n+y][i]==x)
		{
			g[n+y].erase(g[n+y].begin()+i) ; 
			break;
		}
		FOR(val,0,4)
		{
			a[x]-=val ; 
			b[y]-=val ;
			FOR(i,0,n+m+1)FOR(j,0,n+m+1)C[i][j] = 0 ; 
			FOR(i,1,n)FOR(j,1,m)
			{
				C[i][j+n]=4;
			} 
			FOR(i,1,n)
			{
				C[0][i] = a[i] ; 
			}
			FOR(j,1,m)
			{
				C[j+n][n+m+1] = b[j] ;  
			}
			int sum = flow(0,n+m+1) ;
			FOR(i,1,m)
			{
				sum-=b[i] ; 
			}
			if(sum==0)
			{
				res[x][y] = val; 
				return ; 
			}
			else
			{
				a[x]+=val ;  
				b[y]+=val; 
			}
		}
	}
    void xuly()
    {    
    	FOR(i,1,n)a[i]-= m ;
    	FOR(j,1,m)b[j]-= n; 
    	FOR(i,1,n)FOR(j,1,m)
    	{
    		g[i].pb(j+n) ; 
    		g[j+n].pb(i) ;
    	}
    	FOR(i,1,n)
    	{
    		g[0].pb(i) ; 
    		g[i].pb(0) ; 
    	}
    	FOR(j,1,m)
    	{
    		g[j+n].pb(n+m+1) ;
    		g[n+m+1].pb(j+n) ; 
    	}
    	FOR(i,1,2)FOR(j,1,2)solve(i,j) ;
    	FOR(i,1,n)
    	{
    		FOR(j,1,m)
    		{
	    		if(i<=2&&j<=2)cout<<res[i][j]+1<<" ";
	    		else
	    		{
	    			cout<<1+4-C[i][j+n]<<" ";
	    		}
    		}
    		cout<<el;	
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
    if(mtt)cin>>  test;
    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}