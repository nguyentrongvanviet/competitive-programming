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
#define prv(a) for(auto v:a)cout<<v<<" "; cout<<el; 

tct bool mini(T& a,T b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,T b){return (a<b)?a=b,1:0;}

int xx[] = {0,-1,0,1}; 
int yy[] = {-1,0,1,0};

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 1e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 

int n , m , q ; 
int a[N][N] ; 

void doc()
{
	cin>>n >> m >> q ;     
	FOR(i,1,n)FOR(j,1,m)
	{
		char x; cin>>x ;
		if(x=='W')a[i][j]=0 ; 
		if(x=='N')a[i][j]=1 ; 
		if(x=='E')a[i][j]=2 ; 
		if(x=='S')a[i][j]=3 ; 
	}
}

namespace sub1
{

	int id[5] ; 
	ve<pii>node[5] ;
	int dd[N][N] ,f[N][N]; 
	bool in(int x ,int y)
	{
		return 1<=x&&x<=n&&1<=y&&y<=m; 
	}  
	void solve(int u ,int v, int en_x, int en_y)	
	{
		FOR(i,1,n)FOR(j,1,m)dd[i][j]=0,f[i][j]=oo ; 
		FOR(i,1,4)node[i].clear() ;
		FOR(i,1,4)id[i] = i ; 
		node[1].pb({u,v}) ;
		f[u][v] = 0 ; 
		while(1)
		{
			if(node[1].empty()&&node[2].empty()&&node[3].empty()&&node[4].empty())break;
			while(node[id[1]].empty())
			{
				swap(id[1],id[2]) ; 
				swap(id[2],id[3]) ; 
				swap(id[3],id[4]) ; 
			}
			pii u = node[id[1]].back() ; 
			node[id[1]].pk() ; 
			int x = u.fi; 
			int y = u.se ;
			if(x==en_x&&y==en_y)return void(cout<<f[x][y]<<el);
			if(dd[x][y])continue ;
			dd[x][y] =1 ;
			FORN(i,0,4)
			{
				int nx =x+xx[i] ; 
				int ny =y+yy[i] ; 
				if(in(nx,ny)&&dd[nx][ny]==0) 
				{
					if(i==a[x][y])
					{
						if(mini(f[nx][ny],f[x][y]+1))node[id[2]].pb({nx,ny}) ;
					}
					else if((i+1)%4==a[x][y]||(i-1+4)%4==a[x][y])
					{
						if(mini(f[nx][ny],f[x][y]+2))node[id[3]].pb({nx,ny});
					}	
					else if((i+2)%4==a[x][y])
					{
						if(mini(f[nx][ny],f[x][y]+3))node[id[4]].pb({nx,ny}) ; 
					}
				}	
			}	
		}
	}
    void xuly()
    {
    	while(q--)
    	{
    		int u ,v ;cin>>u>>v ;
    		int x, y ; cin>>x>>y ; 
    		solve(u,v,x,y) ; 
    	}
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
    cerr<<el<<"Love KA : " << clock() <<"ms"<<el;
}