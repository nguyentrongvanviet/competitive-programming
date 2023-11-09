#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1500+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct bg
{
    char u; 
    int sl ; 
};
int n , m ;
bg a[N][N] ; 
int f[N][N] ; 
int c[N][N] ; 
int b[N][N] ; 
void inp()
{
    cin>> n >> m ;
    for(int i= 1;i<=n;i++)
    {
        for(int j= 1;j<=m;j++)
        {
            cin>>a[i][j].u>>a[i][j].sl; 
        }
    }  
    a[1][1].sl = 0 ; 
    a[n][m].sl =0 ;
    
    for(int i= 1;i<=n;i++)
    {
        for(int j= 1;j<=m;j++)
        {
            if(a[i][j].u=='B')
            {
                c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+a[i][j].sl ; 
                b[i][j]=b[i][j-1]+b[i-1][j]-b[i-1][j-1] ; 
            }
            else
            {
                b[i][j] = b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j].sl ;
                c[i][j] =c[i-1][j]+c[i][j-1]-c[i-1][j-1];
            }
        }
    }
    for(int i= 0;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            f[i][j] =-oo ;
        }
    }
    f[1][1] = 0 ;
    for(int i= 1;i<=n;i++)
    {
        for(int j =1 ;j<=m;j++)
        {
            if(i==1&&j==1)continue; 
            f[i][j] = max(f[i-1][j-1]+b[i][j-1]-b[i-1][j-1]+c[i-1][j]-c[i-1][j-1],max(f[i-1][j]+b[i][j-1]-b[i-1][j-1],f[i][j-1]+c[i-1][j]-c[i-1][j-1]));
        }
    }
    cout<<f[n][m]; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}