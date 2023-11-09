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
#define           btpc  __builtin_popcountll
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()*rand()%(r-l+1);}

#define prt(a,n) FOR(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1}; 
int yy[] = {-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e3 +5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n ; 
int a[N][N] ;
int st_x , st_y , en_x , en_y  ;    
int sum = 0 ;
void doc()
{
	cin>> n ;
	FOR(i,1,n)FOR(j,1,n)cin>>a[i][j],sum+=a[i][j];
	cin>>st_x>>st_y>>en_x>>en_y ; 

}

namespace sub1
{
	struct DL
	{
		int x ,y , ok , val; 
	}; 
	struct cmp
	{
		bool operator()(const DL&a , const DL&b)const
		{
			return a.val>b.val; 
		}
	} ; 
	int f[N][N][4] ; 
	int d[N][N][4] ; 
	void bfs_0_1(int f[N][N][4],int u , int v)
	{
		deque<DL>q ; 
		FOR(i,1,n)FOR(j,1,n)FORN(ok,0,4)f[i][j][ok]=oo ; 
		FORN(ok,0,4)
		{
			q.pb({u,v,ok,f[u][v][ok]=0}) ; 
		} 
		while(!q.empty())
		{
			int x = q.front().x ; 
			int y = q.front().y ;
			int ok =q.front().ok ; 
			int val =q.front().val; 
			q.pop_front() ;
			if(a[x][y])continue;
			if(f[x][y][ok]<val)continue ; 
			FORN(i,0,4)
			{
				int nx = x+xx[i]  ; 
				int ny = y+yy[i] ; 
				int cost = (i!=ok) ;
				if(mini(f[nx][ny][i],val+cost))
				{
					if(cost==0)q.push_front({nx,ny,i,val+cost}) ;
					else q.pb({nx,ny,i,val+cost}) ; 
				}
			}
		}
	}

    void xuly()
    {   	
    	bfs_0_1(f,st_x,st_y) ; 
    	bfs_0_1(d,en_x,en_y) ; 
    	int res = oo ; 
    	FORN(i,0,4)
    	{
    		mini(res,f[en_x][en_y][i]) ;
    	}
    	cout<<res<<" ";
    	int ok = 0;  
    	int cnt = 0 ; 
    	FOR(i,1,n)FOR(j,1,n)if(a[i][j])
    	{
    		bool X = 0 ;
			FORN(x,0,4)FORN(y,0,4)
	    	{
		    	if(f[i][j][x]!=oo&&d[i][j][y]!=oo)
	    		{  
	    			if(res==f[i][j][x]+d[i][j][y]+((x+2)%4!=y))X=1;
					else if(mini(res,f[i][j][x]+d[i][j][y]+((x+2)%4!=y)))
					{
						ok = 1 ; 
						cnt = 1 ; 
					}
	    		}
	    	}
	    	cnt+=X; 
    	}
    	cout<<res<<" ";
    	if(ok)cout<<cnt ; 
    	else cout<<sum;
    }
}

/*  DON'T BELIEVE LOVE WILL INSPIRE YOU ->  TRAIN HARDER ->  YOU WILL GET THE LOVE YOU WANT !!*/

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0)); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)cin>>test;

    FOR(i,1,test)
    {
        doc() ; 
        sub1::xuly() ; 
    }
    cerr<<el<<"Love KA very much !!! " << clock() <<"ms"<<el;
}