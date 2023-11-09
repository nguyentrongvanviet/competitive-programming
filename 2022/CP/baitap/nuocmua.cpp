#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 
#define X first 
#define Y second 

const int N =1e3+5 , oo = 1e9 ; 
const ll inf = 1e17 , cs = 330 , sm = 1e9+7 ; 

int n  , m ; 
int a[N][N] ;
int dd[N][N] ;  
int xx[]={1,-1,0,0};  
int yy[]={0,0,1,-1} ;  
ll res=0 ; 
struct bg 
{
	int x,  y  , val ; 	
};
struct cmp
{
	bool operator()(bg a, bg b )
	{
		return a.val>b.val;  
	}
};	
void inp()
{
	cin>> n >> m;  
	for(int i=1 ;i<=n;i++)
	{
		for(int j= 1;j<=m;j++)
		{
			cin>>a[i][j]; 
		}
	}
}
bool in(int x , int y )
{
	return (1<=x&&x<=n&&1<=y&&y<=m);
}
void solve()
{
	
	priority_queue<bg,vector<bg>,cmp> q ; 
	for(int i =1 ;i<=m;i++)q.push({1,i,a[1][i]}),q.push({n,i,a[n][i]}),dd[1][i]=1,dd[n][i]=1; 
	for(int i = 2;i<=n-1;i++)q.push({i,1,a[i][1]}),q.push({i,m,a[i][m]}),dd[i][1]=1,dd[i][m]=1; 
	while(!q.empty())
	{
		int x= q.top().x;  
		int y = q.top().y ; 
		int val = q.top().val ; 
		q.pop() ; 
		for(int i=0 ;i<4;i++)
		{
			int nx = x+xx[i] ; 
			int ny = y+yy[i] ; 
			if(dd[nx][ny]||in(nx,ny)==0)continue ; 
			if(a[nx][ny]<val)
			{
				res+=val-a[nx][ny]; 
				a[nx][ny]=val; 
			}
			dd[nx][ny]=1;
			q.push({nx,ny,a[nx][ny]});
		}
	}
	cout<<res;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ;  
	freopen("o.txt","w",stdout) ; 
	int t = 1; 
	while(t--)
	{
		inp() ; 
		solve() ; 
	}
}
