#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m ; 
int a[N][N] , g[N][N] , dd[N][N];
int xx[]=  {1,-1,0,0} ;
int yy[] = {0,0,-1,1} ;
int u , v  ,cnt= 0 ;
int ans ; 
bool in(int x,int y )
{
    return (1<=x&&x<=n&&1<=y&&y<=m);  
} 
void dfs(int x , int y  , int val)
{
     if(g[x][y])
    {
        ans++ ; 
    }
    dd[x][y] = 1 ; 
    for(int i =0 ; i<4;i++)
    {
        int nx = x+xx[i] ; 
        int ny = y+yy[i] ; 
        if(in(nx,ny)&&dd[nx][ny]==0&&abs(a[nx][ny]-a[x][y])<=val)
        {
           
            dfs(nx,ny,val) ; 
        }
    }
}
void np()
{
    int  l = 0; 
    int  r=  oo;
    int res ;  
    while(l<=r)
    {
        ll mid=(l+r)/2;
        for(int i= 1 ;i<=n;i++)
        {
            for(int  j=1 ;j<=m;j++)
            {
                dd[i][j]= 0 ; 
            }
        }
        ans= 0 ; 
        dfs(u,v,mid);
        if(ans==cnt)
        {
            res= mid ;  
            r=mid-1; 
        }
        else 
        {
            l=mid+1; 
        }
    }
    cout<<res; 
} 
void inp()
{
    cin>> n>> m ; 
    for(int i= 1 ;i<=n;i++)
    {
        for(int j =1 ;j<=m;j++)
        {
            cin>>a[i][j] ; 
        }
    }   
    for(int i=1 ;i<=n;i++)
    {
        for(int j= 1;j<=m;j++)
        {
            cin>>g[i][j] ; 
            if(g[i][j])
            {
                u = i  ; 
                v = j ;  
                cnt++;
            }
        }
    }
    np();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("GOLF.INP","r",stdin); 
    freopen("GOLF.OUT","w",stdout); 
    inp();
    return 0;
}