// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "robocon"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =5e2+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m; 
int xx1[]={1,1,0}; 
int yy1[]={0,1,1}; 
int xx2[]={1,1,0};
int yy2[]={0,-1,-1};  
pii q1[11*N*N] ;
pii q2[11*N*N] ;
int cnt1[N][N] ;
int cnt2[N][N] ;
bool dd[N][N] ; 
bool check(int x, int y )
{
	return !dd[x][y] && 1<=x&&x<=n&&1<=y&&y<=n;
}
void doc()
{
    cin>> n >> m; 
    FOR(i,1,m)
    {
    	int x, y; 
    	cin>>x>>y; 
    	dd[x][y] = 1;  
    }
    int d1 , c1 , d2  ,c2;  
   	d1=c1=1; 
   	d2=c2=1;
   	q1[1]={1,1};
   	q2[1]={1,n};
   	int ans =0  ;
   	while(1)
   	{
   		int nc=c1 ; 
   		++ans ; 
   		FOR(i,d1,c1)
   		{
   			int x= q1[i].fi ; 
   			int y= q1[i].se ; 
   			FORN(j,0,3)
   			{
   				int nx= x+xx1[j] ; 
   				int ny= y+yy1[j] ; 
   				if(!check(nx,ny))continue ;
   				if(cnt1[nx][ny]!=ans)
   				{
   					cnt1[nx][ny]=ans ; 
   					++nc; 
   					q1[nc]={nx,ny};
   				}
   			}
   		}  	
   		d1=c1+1; 
   		c1=nc;
   		nc = c2 ; 
   		FOR(i,d2,c2)
   		{
   			int x= q2[i].fi ;
   			int y= q2[i].se ;
   			FORN(j,0,3)
   			{
   				int nx = x+xx2[j] ; 
   				int ny = y+yy2[j] ; 
   				if(!check(nx,ny))continue ;
   				if(cnt1[nx][ny]==ans)
   				{
   					cout<<ans; 
   					return ; 
   				}
   				if(cnt2[nx][ny]!=ans)
   				{	
   					cnt2[nx][ny]=ans; 
   					++nc ;
   					q2[nc]={nx,ny}; 
   				}
   			}
   		}
   		d2=c2+1; 
   		c2=nc;
   	}
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    // xuly();
}