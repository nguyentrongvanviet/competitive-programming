#include<bits/stdc++.h>
using namespace std;

#define TASK "ROBOT1"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =1500+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n , m ; 
int s[N][N] ; 
int a[N][N] ;  
int able[N][N] ;
int dd[N][N];
int res=oo ;
int mot[N][N] , hai[N][N];
void doc() 
{
 	cin>> m>> n ; 
 	FOR(i,1,n)
 	{
 		FOR(j,1,m)
 		{
 			char x ; cin>>x ; 
 			a[i][j] = (x=='#');  
 		}
 	}   
}
bool in(int x, int y )
{
	return dd[x][y]==0&&1<=x&&x<=n&1<=y&&y<=m;
}
int dfs1(int x , int y )
{	
	dd[x][y] =1 ;
	if(a[x][y]==1)return able[x][y]=0;
	if(able[x][y]!=-1)return able[x][y]; 
	if(x==n&&y==m)return able[x][y] =1 ; 
	int nx  , ny ,  u= 0;
	nx = x-1; 
	ny = y;
	if(in(nx,ny))u = dfs1(nx,ny) ; 
	if(u==1)return able[x][y] = 1;
	nx= x; 
	ny = y+1;
	if(in(nx,ny))u = dfs1(nx,ny) ; 	
	if(u==1)return able[x][y] = 1 ;

	nx = x+1;  
	ny = y ; 
	if(in(nx,ny))u = dfs1(nx,ny); 
	if(u==1)return able[x][y] = 1; 

	nx = x; 
	ny = y-1  ; 
	if(in(nx,ny))u =dfs1(nx,ny) ; 
	if(u==1) return able[x][y] = 1;

	return able[x][y] = 0;
} 
int dfs2(int x , int y )
{	
	dd[x][y] =1 ;
	if(a[x][y]==1)return able[x][y]=0;
	if(able[x][y]!=-1)return able[x][y]; 
	if(x==n&&y==m)return able[x][y] =1 ; 
	int nx  , ny ,  u= 0;
	nx = x; 
	ny = y-1  ; 
	if(in(nx,ny))u =dfs2(nx,ny) ; 
	if(u==1) return able[x][y] = 1;
	
	nx = x+1;  
	ny = y ; 
	if(in(nx,ny))u = dfs2(nx,ny); 
	if(u==1)return able[x][y] = 1; 

	nx= x; 
	ny = y+1;
	if(in(nx,ny))u = dfs2(nx,ny) ; 	
	if(u==1)return able[x][y] = 1 ;
	nx = x-1; 
	ny = y;
	if(in(nx,ny))u = dfs2(nx,ny) ; 
	if(u==1)return able[x][y] = 1;

	return able[x][y] = 0;
} 
void tknp(int i , int j )
{
	int l = 1; 
	int r = min(i,j); 
	int ans= oo ;
	while(l<=r)
	{
		int mid =(l+r)/2; 
		int s1= s[i][j]  -s[i][j-mid]-s[i-mid][j]+s[i-mid][j-mid]; 
		int s2= mot[i][j]- mot[i][j-mid]-mot[i-mid][j] +mot[i-mid][j-mid];
		int s3 =hai[i][j] -hai[i][j-mid]-hai[i-mid][j] +hai[i-mid][j-mid];
		if(s1)
		{
			r=mid-1;
			continue;
		}
		if(s2&&s3)
		{
			ans=mid  ; 
			r=mid-1 ;
		}
		else
		{
			l=mid+1;
		}
	}
	res=min(res,ans);
}
void xuly()
{
	memset(able,-1,sizeof(able)) ;
	int u = dfs1(1,1); 
	bool ok = 1;
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(able[i][j]!=1)able[i][j]=0;
			mot[i][j] = mot[i-1][j]+mot[i][j-1]-mot[i-1][j-1]+able[i][j];
		}
	}
	memset(able,-1,sizeof(able)) ;  
	memset(dd,0,sizeof(dd));
	dfs2(1,1) ; 
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(able[i][j]!=1)able[i][j]=0;
			hai[i][j]= hai[i-1][j]+hai[i][j-1]-hai[i-1][j-1]+able[i][j]; 
		}
	}
	a[1][1] = 1;  
	a[n][m] = 1; 
	FOR(i,1,n)FOR(j,1,m)s[i][j] =s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	if(ok==0)
	{
		cout<<"Impossible";
		return ;
	}
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(i==1&&j==1)continue ;
			if(i==n&&j==m)continue;
			tknp(i,j);
		}
	}
	if(res==oo)
	{
		cout<<"Impossible"; 
	}
	else 
	{
		cout<<res;
	}
}
int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
        xuly();
    }
    return 0;
}