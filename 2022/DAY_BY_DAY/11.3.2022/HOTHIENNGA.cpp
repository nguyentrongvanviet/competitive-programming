#include<bits/stdc++.h>
using namespace std;

#define TASK "HOTHIENNGA"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N =1500+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
int xx[4] = {1,-1,0,0};  
int yy[4] = {0,0,1,-1};
int n  , s, t , m; 
int f[N][N] ; 
int ma =0 ;
bool ok ;  
char a[N][N] ; 
bool dd[N][N] ; 
bool in(int x , int y)
{
	return (1<=x&&x<=n&&1<=y&&y<=m);
}
void bfs()
{
	queue<pii>q; 
	FOR(i,1,n)
	{
		FOR(j,1,m) 
		{
			if(a[i][j]!='X')
			{
				q.push({i,j});
				dd[i][j]=1; 
			}
		}
	}
	while(!q.empty())
	{
		int x  =q.front().fi; 
		int y = q.front().se; 
		q.pop();
		for(int i=0  ;i<4;i++)
		{
			int nx=  x+xx[i] ; 
			int ny=  y+yy[i] ;
			if(a[nx][ny]!='X'||!in(nx,ny)||dd[nx][ny])continue ;
			f[nx][ny] = f[x][y]+1;  
			ma=max(ma,f[nx][ny]);
			dd[nx][ny] = 1; 
			q.push({nx,ny}); 
		}
	}
}
void dfs(int x , int y,int val )
{
	dd[x][y] = 1 ;
	for(int i=0  ;i<4;i++)
	{
		int nx = x+xx[i] ; 
		int ny = y+yy[i] ; 
		if(dd[nx][ny]||!in(nx,ny))continue; 
		if(f[nx][ny]<=val)
		{
			if(a[nx][ny]=='L')
			{
				ok =1; 
				return ; 
			}
			dfs(nx,ny,val);
		}
	}
	if(ok)return ; 
}
void doc()
{
 
 	cin>> n>> m; 
 	FOR(i,1,n)
 	FOR(j,1,m) 
 	{
 		cin>>a[i][j] ;
 		if(a[i][j]=='L')
 		{
 			s= i ; 
 			t = j ; 
 		}
 	} 
 	bfs(); 
 	int l = 0 ; 
 	int r = ma; 
 	int ans =0 ; 
 	while(l<=r)
 	{
 		int mid =(l+r)/2 ;
 		ok = 0 ;  
 		for(int i=1 ;i<=n;i++)
 		{
 			for(int j= 1;j<=m;j++)
 			{
 				dd[i][j] = 0 ;
 			}
 		}
 		dfs(s,t,mid) ;
 		if(ok)
 		{
 			ans =mid ; 
 			r=mid-1 ; 
 		}
 		else 
 		{
 			l=mid+1; 
 		}
 	}
 	cout<<ans; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}