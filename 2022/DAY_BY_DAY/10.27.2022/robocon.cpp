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

const int N =5e2+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DL
{
	int x, y; 
	int dis ; 
}; 
struct cmp
{
	bool operator()(DL a, DL b)
	{
		return a.dis>b.dis ;
	}
};
int n  , k; 
int dd[N][N];
int f1[N][N],fn[N][N], A[N][N],B[N][N]; 
int xx1[] ={0,1,1}; 
int yy1[] ={1,0,1};
int xxn[] ={0,1,1};
int yyn[] ={-1,0,-1}; 
void doc()
{
    cin>> n >> k; ; 
    FOR(i,1,k)
    {
    	int x, y; cin>>x>>y ;
    	dd[x][y]=1 ; 
    }	
}
bool in(int x , int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=n ;  
}
void xuly()
{	
    priority_queue<DL,vector<DL>,cmp>q1 ; 
    priority_queue<DL,vector<DL>,cmp>qn ;  
   	q1.push({1,1,0}) ; 
   	qn.push({1,n,0}) ; 
   	while(1)
   	{
   		DL X = (q1.empty()?DL{oo,oo}:q1.top());
   		DL Y = (qn.empty()?DL{oo,oo}:qn.top());
   		int AA = X.dis;  
   		int BB = Y.dis; 
   		if(AA<=BB)
   		{
   			q1.pop() ;
   			int x=X.x; 
   			int y=X.y; 
   			// cout<<x<<" "<<y<<" " <<"A"<<endl;
   			A[x][y]= X.dis; 
   			FOR(i,0,2)
   			{
   				int nx =x+xx1[i] ; 
   				int ny =y+yy1[i] ;
   				if(dd[nx][ny]==1||!in(nx,ny))continue;
   				A[nx][ny]=A[x][y]+1; 
   				q1.push({nx,ny,A[nx][ny]});	
   				if(A[nx][ny]==B[nx][ny])
   				{
   					// cout<<nx<<" "<<ny<<endl;
   					cout<<A[nx][ny]; 
   					return ;
   				}
   			}
   		}
   		else 
   		{
   			qn.pop() ;

   			int x= Y.x; 
   			int y= Y.y;
   			// cout<<x<<" "<<y<<" "/ <<"B"<<endl;
   			B[x][y]=Y.dis;
   			FOR(i,0,2)
   			{
   				int nx =x+xxn[i] ; 
   				int ny =y+yyn[i] ; 
   				if(dd[nx][ny]==1||!(in(nx,ny)))continue;
   				B[nx][ny]=B[x][y]+1;
   				qn.push({nx,ny,B[nx][ny]}); 
   				if(A[nx][ny]==B[nx][ny])
   				{
   					// cout<<nx<<" "<<ny<<endl;
   					cout<<B[nx][ny]; 
   					return ;
   				}
   			}
   		}
   	}
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}	