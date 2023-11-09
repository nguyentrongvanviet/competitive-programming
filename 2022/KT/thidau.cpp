#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+9,cs=330 ,inf = 1e17;

int n , m ,  k ;
ll f[N][N][12] ; 
int a[N] , b[N] ; 
void inp()
{
    cin>> n>> m >> k ; 
    for(int i=  1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    for(int j= 1 ;j<=m;j++)
    {
        cin>>b[j] ; 
    }
    sort(a+1,a+n+1) ; 
    sort(b+1,b+m+1) ; 
    for(int i= 0 ;i<=n;i++)
    {
        for(int j = 0 ;j<=m;j++)
        {
            f[i][j][0]=1; 
        }
    }
    for(int t= 1;t<=k;t++)
    {
        for(int  i=1 ;i<=n;i++)
        {
            for(int j= 1 ;j<=m;j++)
            {
                if(a[i]>b[j])
                {
                    f[i][j][t]  = (f[i][j-1][t]+f[i-1][j][t]-f[i-1][j-1][t]+f[i-1][j-1][t-1]+5*sm)%sm;  
                }
                else
                {
                    f[i][j][t]= (f[i-1][j][t]+f[i][j-1][t]-f[i-1][j-1][t]+sm)%sm; 
                }
            }
        }
    }
    cout<<f[n][m][k];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}