/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 12T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
* Khanh An is my lover :) the more I code  , the nearer I am   *
****************************************************************/
#define TASK "gotoschool"
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
const int N = 2e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n , m ,k ;
void doc()
{
	cin>> n >> m >> k; 
}

namespace sub1
{
	bool a[N][N] ;
	int change[257];
	int st_x , st_y , en_x, en_y ; 
	int build(char x)
	{
		if('0'<=x&&x<='9')return x-'0';
		if('A'<=x&&x<='Z')return (x-'A'+10);
		if('a'<=x&&x<='z')return (x-'a'+36) ;
		if(x=='#')return 62 ; 
		if(x=='$')return 63 ; 
		return -1 ; 
	}	
	int f[N][N][4] ;
	struct BG
	{
		int x ,y , d; 
	}P[N][N][4] ; 
	struct DL
	{
		int x , y ,d , val ;
	}; 
	bool in(int x , int y)
	{
		return 1<=x&&x<=n&&1<=y&&y<=m; 
	}
	DL dij()
	{
		deque<DL>q; 
		FOR(i,1,n)FOR(j,1,m)FORN(d,0,4)f[i][j][d] = oo ; 
		FORN(i,0,4)
		{
			P[st_x][st_y][i] ={-1,-1,-1};
			q.pb({st_x,st_y,i,f[st_x][st_y][i]=0}) ; 
		}
		while(!q.empty())
		{
			int x = q.front().x ; 
			int y = q.front().y ;
			int d = q.front().d ;
			int val = q.front().val ; 
			if(x==en_x&&y==en_y)
			{
				return q.front() ;
			}
			q.pop_front() ;
			FORN(i,0,4)
			{
				int nx =x+xx[i] ; 
				int ny =y+yy[i] ; 
				if(!in(nx,ny)||a[nx][ny])continue; 
				int &tmp= f[nx][ny][i] ; 
				if(val+(d!=i)==k+1)continue;
				if(mini(tmp,val+(d!=i))){
					P[nx][ny][i] = {x,y,d} ;
					if(d!=i)q.pb({nx,ny,i,tmp}) ;
					else q.push_front({nx,ny,i,tmp}) ;  
				}	
			}
		}
		return DL{-1,-1,-1,-1} ; 
	}
	int t = 0 ; 
	void trace(int x ,int y,int d)
	{
		++t; 
		int u = P[x][y][d].x ;
		int v = P[x][y][d].y ;
		int D = P[x][y][d].d ; 
		if(u==-1&&v==-1)
		{
			cout<<st_x<<" "<<st_y<<el; 
			return ;
		}
		if(d!=D)
		{
			cout<<u<<" "<<v<<el;
			if(u==st_x&&v==st_y)return ; 
		}
		trace(u,v,D) ;
	}
    void xuly()
    {
    	FOR(i,0,255)change[i]=build(i) ;
    	cin>>st_x>>st_y ;
    	cin>>en_x>>en_y ;  
    	swap(st_x,en_x) ; 
    	swap(st_y,en_y) ; 
    	FOR(i,1,n)
    	{
    		int id= 0 ; 
    		FOR(j,1,m/6+(m%6>0))
    		{
    			char x; cin>>x ;
    			assert(change[(int)x]!=-1) ; 
    			FORN(t,0,6)
    			{
    				a[i][++id] = BIT(change[(int)x],t) ;
    			}
    		}
    	}
    	DL res = dij() ; 
    	if(res.val==-1)return void(cout<<-1<<el); 
    	cout<<res.val<<el; 
    	cout<<en_x<<" "<<en_y<<el;
    	trace(res.x,res.y,res.d) ; 
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