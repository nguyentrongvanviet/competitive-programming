#include<bits/stdc++.h>
using namespace std;

#define TASK "p9robot1"
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
bool ok(int x, int y )
{
	return a[x][y]==0&&dd[x][y]==0&&1<=x&&x<=n&1<=y&&y<=m;
}
// 1 xuong 2 len 3 trai 4 phai  

int dfs1(int x , int y ,int pre)
{	
	if(x==n&&y==m)return able[x][y]=1 ;
	dd[x][y] =1 ; 
	int nx  , ny ;
	int ans= 0  ;
	if(pre==1)
	{	
		// phai 
		nx=  x; 
		ny=  y+1; 
		if(ok(nx,ny))ans=dfs1(nx,ny,4);
		if(ans)return able[x][y]=1;
		
		//  xuong
		nx=  x+1; 
		ny=  y; 
		if(ok(nx,ny))ans=dfs1(nx,ny,1);
		if(ans)return able[x][y]=1;
		
		// trai 
		nx=  x; 
		ny=  y-1; 
		if(ok(nx,ny))ans=dfs1(nx,ny,3);
		if(ans)return able[x][y]=1;
	}
	else if(pre==2)
	{
		// trai 
		nx=  x; 
		ny=  y-1; 
		if(ok(nx,ny))ans=dfs1(nx,ny,3);
		if(ans)return able[x][y]=1;
		// len 
		nx = x-1 ; 
		ny = y  ;  
		if(ok(nx,ny))ans=dfs1(nx,ny,2);
		if(ans)return able[x][y]=1;
		// phai 
		nx=  x; 
		ny=  y+1; 
		if(ok(nx,ny))ans=dfs1(nx,ny,4);
		if(ans)return able[x][y]=1;
	}
	else if(pre==3)
	{
		//  xuong
		nx=  x+1; 
		ny=  y; 
		if(ok(nx,ny))ans=dfs1(nx,ny,1);
		if(ans)return able[x][y]=1;
		// trai 
		nx=  x; 
		ny=  y-1; 
		if(ok(nx,ny))ans=dfs1(nx,ny,3);
		if(ans)return able[x][y]=1;
		// len 
		nx = x-1 ; 
		ny = y  ;  
		if(ok(nx,ny))ans=dfs1(nx,ny,2);
		if(ans)return able[x][y]=1;
	}
	else if(pre==4) 
	{	
		// len 
		nx = x-1 ; 
		ny = y  ;  
		if(ok(nx,ny))ans=dfs1(nx,ny,2);
		if(ans)return able[x][y]=1;
		// phai 
		nx=  x; 
		ny=  y+1; 
		if(ok(nx,ny))ans=dfs1(nx,ny,4);
		if(ans)return able[x][y]=1;
		//  xuong
		nx=  x+1; 
		ny=  y; 
		if(ok(nx,ny))ans=dfs1(nx,ny,1);
		if(ans)return able[x][y]=1;
	}
	return able[x][y] = 0;
} 
int dfs2(int x , int y ,int pre )
{	
	if(x==n&&y==m)return able[x][y] =1 ; 
	if(x==n&&y==m)return able[x][y]=1 ;
	dd[x][y] =1 ; 
	int nx  , ny ;
	int ans= 0  ;
	if(pre==1)
	{	
		// trai 
		nx=  x; 
		ny=  y-1; 
		if(ok(nx,ny))ans=dfs2(nx,ny,3);
		if(ans)return able[x][y]=1;

		//  xuong
		nx=  x+1; 
		ny=  y; 
		if(ok(nx,ny))ans=dfs2(nx,ny,1);
		if(ans)return able[x][y]=1;
		// phai 
		nx=  x; 
		ny=  y+1; 
		if(ok(nx,ny))ans=dfs2(nx,ny,4);
		if(ans)return able[x][y]=1;
	}
	else if(pre==2)
	{
		// phai 
		nx=  x; 
		ny=  y+1; 
		if(ok(nx,ny))ans=dfs2(nx,ny,4);
		if(ans)return able[x][y]=1;

		// len 
		nx = x-1 ; 
		ny = y  ;  
		if(ok(nx,ny))ans=dfs2(nx,ny,2);
		if(ans)return able[x][y]=1;
		// trai 
		nx=  x; 
		ny=  y-1; 
		if(ok(nx,ny))ans=dfs2(nx,ny,3);
		if(ans)return able[x][y]=1;
	}
	else if(pre==3)
	{
		// len 
		nx = x-1 ; 
		ny = y  ;  
		if(ok(nx,ny))ans=dfs2(nx,ny,2);
		if(ans)return able[x][y]=1;
		// trai 
		nx=  x; 
		ny=  y-1; 
		if(ok(nx,ny))ans=dfs2(nx,ny,3);
		if(ans)return able[x][y]=1;

		//  xuong
		nx=  x+1; 
		ny=  y; 
		if(ok(nx,ny))ans=dfs2(nx,ny,1);
		if(ans)return able[x][y]=1;
	}
	else if(pre==4) 
	{	
		//  xuong
		nx=  x+1; 
		ny=  y; 
		if(ok(nx,ny))ans=dfs2(nx,ny,1);
		if(ans)return able[x][y]=1;

		// phai 
		nx=  x; 
		ny=  y+1; 
		if(ok(nx,ny))ans=dfs2(nx,ny,4);
		if(ans)return able[x][y]=1;

		// len 
		nx = x-1 ; 
		ny = y  ;  
		if(ok(nx,ny))ans=dfs2(nx,ny,2);
		if(ans)return able[x][y]=1;

	}
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
	memset(able,0,sizeof(able)) ;
	int u = dfs1(1,1,4); 
	bool ok =  0 ;
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(able[i][j]==1)
			{
				ok =1 ; 
			}
			if(able[i][j])ok=1;
			if(able[i][j]!=1)able[i][j]=0;
			mot[i][j] = mot[i-1][j]+mot[i][j-1]-mot[i-1][j-1]+able[i][j];
		}
	}
	memset(able,0,sizeof(able));  
	memset(dd,0,sizeof(dd));
	dfs2(1,1,1) ; 
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
		cout<<0;
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