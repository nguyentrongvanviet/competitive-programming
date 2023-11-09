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
const int N =30+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  , m ;
int a[N][N] ;
int s[N][N] ; 
int dd[N][N] ;
int f[N][N] ;
int xx[] = {1,-1,0,0};  
int yy[] = {0,0,1,-1}; 
void doc()
{
	cin>> m>>n; 
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			char u ; 
			cin>>u ; 
			a[i][j]= (u=='#') ; 
			s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j] ; 
		}
	}    
}
void dfs(int i , int j ,int x , int y , int u ,int v )
{
	dd[i][j]=1;
	FOR(t,0,3)
	{
		int ni = i+xx[t] ; 
		int nj = j+yy[t] ; 
		if(dd[ni][nj]||a[ni][nj]==1||ni<1||ni>n||nj<1||nj>m||(x<=ni&&ni<=u&&y<=nj&&nj<=v))continue ;
		dfs(ni,nj,x,y,u,v);
	}
}
int tknp(int i , int j )
{ 
	FOR(x,0,min(i,j))
	{
		if(a[i][j]==1)continue;
		if(i-x+1==1&&j-x+1==1)continue; 
		if(i-x+1==n&&j-x+1==m)continue;
		if(i-x+1<1||j-x+1<1)continue;
		if(s[i][j] -s[i-x][j]-s[i][j-x]+s[i-x][j-x])break;  
		memset(dd,0,sizeof(dd));  
		dfs(1,1,i-x+1,j-x+1,i,j);
		if(dd[n][m]==0)
		{
			return x;  
		}
	}
	return oo; 
}
void xuly()
{
	int res =oo ;  
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if((i==1&&j==1)||(i==n&&j==m))continue;
			res=min(res,tknp(i,j));
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
        freopen(TASK".OUT","w",stdout); 
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