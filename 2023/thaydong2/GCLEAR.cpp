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

int xx[] = {0,-1,0,1,0} ; 
int yy[] = {-1,0,1,0,0} ;

const db PI = acos(-1) , EPS = 1e-9;
const ll inf = 1e18 , cs = 331 , sm = 1e9+7; 
const int N = 2e3+5 , oo = 2e9 , LO = 17 , CH = 26 ; 


int n  , m; 
char a[N][N] ; 
map<char,int>TYPE ; 
int X , Y ; 
int U ,V ; 
struct DL
{
	int x ,y ,ok ; 
} ;
DL TMP[N] ; 
str S ;   
void doc()
{
    cin>> n >> m; 
    FOR(i,1,n)FOR(j,1,m)
    {
    	cin>>a[i][j] ;
    }
    cin>>X>>Y ;
    cin>>S ;
    cin>>U>>V ;
    TYPE['L'] = 0 ;
    TYPE['U'] = 1 ;
    TYPE['R'] = 2 ; 
    TYPE['D'] = 3 ; 
    TYPE['C'] = 4 ;  
    FORN(i,0,SZ(S))
    {
    	int d = TYPE[S[i]] ;
		X += xx[d];   
		Y += yy[d]; 
		TMP[i+1]={X,Y,(i+1)&1} ;
    }
}

namespace sub1
{
	int mi[N][N][2] ;
	void bfs() 
	{
		queue<DL>q ;
		FOR(i,1,n)FOR(j,1,m)FOR(ok,0,1)mi[i][j][ok] = oo ; 
		mi[U][V][0] = 0 ; 
		q.push({U,V,0});  
		while(!q.empty())
		{
			int x = q.front().x ;
			int y = q.front().y ;
			int ok = q.front().ok ; 
			q.pop() ;
			FORN(i,0,4)
			{
				int nx = x+xx[i] ; 
				int ny = y+yy[i] ;
				if(a[nx][ny]=='1')continue; 
				if(mini(mi[nx][ny][ok^1],mi[x][y][ok]+1))
				{
					q.push({nx,ny,ok^1}) ; 
				}
			}
		}
	} 
    void xuly()
    {
    	bfs() ; 
    	int res = oo; 
    	FOR(i,1,SZ(S))
    	{
    		int x= TMP[i].x; 
    		int y = TMP[i].y ; 
    		int ok = (i&1) ; 
    		int d = mi[x][y][ok]; 
    		int val = i;
    		if(d>val)continue ; 	
    		mini(res,val);
    	}	
    	if(res==oo)return void(cout<<-1) ;
    	cout<<res ; 
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