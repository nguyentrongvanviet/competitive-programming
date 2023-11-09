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

struct pt 
{
    int x ,  y ; 
}; 
int dis(pt a ,pt b  )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)  ;
}
int n , m ; 
pt a[N] , b[N] ; 
int f[N][N][2] ;  
void inp()
{
    cin>>n>> m ; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y; 
    }
    for(int i= 1 ;i<=m;i++)
    {
        cin>>b[i].x>>b[i].y; 
    }
    for(int i=0;i<=n;i++)
    {
        for(int j= 0  ; j<=m;j++)
        {
            f[i][j][1] = f[i][j][0] =oo; 
        }
    }
    f[1][0][0]=  0 ;
    for(int i = 1;i<=n;i++)
    {
        for(int j=  0 ;j<=m;j++)
        {
            if(i==1&&j==0)continue ; 
            if(i>0)f[i][j][0] = min(f[i-1][j][1]+dis(b[j],a[i]),f[i-1][j][0] +dis(a[i],a[i-1])); 
            if(j>0)f[i][j][1] = min(f[i][j-1][0]+dis(b[j],a[i]),f[i][j-1][1]+dis(b[j],b[j-1])); 
        }
    }
    cout<<f[n][m][0];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}