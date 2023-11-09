/***************************************************************
*             Author : Nguyen Trong Van Viet                   *
*                        Age : 17                              *
*      School : 11T2 Le Khiet High School for the Gifted       *
*            Hometown :  Quang Ngai , Viet Nam .               *
*code for dream,code for Truong Thi My Duyen :) yeu nhieu lam !*
***************************************************************/

#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"

bool multitest = 0;

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
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define    FORN(i,a,b)  for(int i=(int)(a);i<(int)(b);i++)
#define         all(a)  a.begin(),a.end()  
#define           btpc  __builtin_popcountll       
#define            tct  template<typename T>

ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
// end of template
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};

const db PI = acos(-1), EPS = 1e-9;
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const int N = 3e2+5, oo = 2e9, LO = 17; 

int n , m; 
char a[N][N] ;
int f[N][N][5] ; 
int dd[N][N][5] ; 
void doc()
{
    cin>> n >> m ; 
    FOR(i,1,n)FOR(j,1,m)
    {
    	cin>>a[i][j] ; 
    }
}
struct BG
{
	int x, y ; 
	int ok ;   
} ; 
bool bfs(int len )
{
	queue<BG>q ;
	FOR(i,1,n)FOR(j,1,m)FOR(ok,1,4)dd[i][j][ok]= 0 ; 
	FOR(i,1,n)
	{
		if(f[i][1][4]>=len)
		{
			q.push({i,1,4}) ;
			dd[i][1][4] =1 ; 	
		}
	} 
	while(!q.empty())
	{	
		int x= q.front().x; 
		int y =q.front().y ;
		int ok = q.front().ok ; 
		q.pop();
		if(y==m&&ok%2==0)return 1 ; 
		
		{
			int nok = ok ; 
			FOR(i,1,2)
			{
				int nx = x+xx[nok] ; 
				int ny = y+yy[nok] ; 
				if(f[nx][ny][nok]>=len&&dd[nx][ny][nok]==0)
				{
					dd[nx][ny][nok] = 1; 
					q.push({nx,ny,nok}) ; 
				}
				if(nok<=2)nok+=2; 
				else nok-=2 ; 
			}
		} 
		
		{
			int nx = x+xx[ok]*len-(xx[ok]) ; 
			int ny = y+yy[ok]*len-(yy[ok]) ;
			int nok = (ok<=2?ok+2:ok-2) ; 
			if(dd[nx][ny][nok]==0)dd[nx][ny][nok]=1,q.push({nx,ny,nok}) ;
		}

		{
			int nok=(ok&1?2:1) ; 
			FOR(i,1,2)
			{
				if(f[x][y][nok]>=len&&dd[x][y][nok]==0)
				{
					dd[x][y][nok] =1 ; 
					q.push({x,y,nok}) ; 
				}
				nok+=2; 
			}
		}	
	}
	return 0 ; 
}
void xuly()
{   	
	FOR(i,1,n)FOR(j,1,m)if(a[i][j]=='.')
	{
		f[i][j][1]=f[i][j-1][1]+1; 			

		f[i][j][2]=f[i-1][j][2]+1;
	}
	FORD(i,n,1)FORD(j,m,1)if(a[i][j]=='.')
	{
		f[i][j][3] = f[i][j+1][3]+1; 
		f[i][j][4] = f[i+1][j][4]+1; 
	}
	int ans= 0 ; 
	int l =1 ;
	int r =min(n,m) ;
	while(l<=r)
	{
		int mid =(l+r)/2; 
		if(bfs(mid))ans=mid,l=mid+1; 
		else r=mid-1 ;
	}
	cout<<ans; 
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test = 1;
    if(multitest)cin>>test ;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Duyen yeu Viet nhieu lam ! "<<el<<"Time elapsed : " << clock() <<"ms"<<el;
}