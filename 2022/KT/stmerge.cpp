#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m ;
int a[N][N] ;
ll f[N][N][3] ;  
void inp()
{
    cin>> n>> m ; 
    for(int i=1;i<=n;i++)
    {
        for(int j= 1 ;j<=m;j++)
        {
            cin>>a[i][j] ; 
        }
    } 
    for(int i= 1 ;i<=n;i++)
    {
        f[i][0][2]=inf;
        f[i][0][1]=0 ; 
    }
    for(int j= 1;j<=m;j++)
    {
        f[0][j][1]=inf;
        f[0][j][2]=0 ; 
    }
    for(int i= 1 ;i<=n;i++)
    {
        for(int j= 1;j<=m;j++)
        {
            f[i][j][1] = min(f[i-1][j][1],f[i-1][j][2]+a[i][j]) ; 
            f[i][j][2] = min(f[i][j-1][1]+a[i][j],f[i][j-1][2]) ;
        }
    }
    cout<<min(f[n][m][1],f[n][m][2])<<"\n"; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test ;
    cin>>test ;
    while(test--)inp();
    return 0;
}