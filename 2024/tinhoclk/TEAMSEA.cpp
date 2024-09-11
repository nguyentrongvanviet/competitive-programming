#include<bits/stdc++.h>
using namespace std ; 

const int N = 2e3+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 
const int xx[4] = {1,-1,0,0};
const int yy[4] = {0,0,1,-1};
int a[N][N] ;
int sl[(int)5e3+1] ;
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n , m ;
    cin>> n >> m; 
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        cin>>a[i][j] ;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        int sum = a[i][j] ; 
        for(int k=0;k<4;k++)
        {
            sum+=a[i+xx[k]][j+yy[k]];
        }
        sl[sum]++ ;
    }
    int ma = 0 ,value = 0 ;
    for(int i=5e3;i>=0;i--)
    {
        if(ma<sl[i])value=i,ma=sl[i] ;
    }
    cout<< value ;
    return 0;
}