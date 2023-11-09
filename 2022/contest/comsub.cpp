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

int n ; 
int a[N] , b[N] ; 
int f[N][N] ; 
int m ;
void inp()
{
    cin>>n>>m ; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    for(int i = 1;i<=m;i++)
    {
        cin>>b[i] ; 
    }
    for(int i= 0;i<=max(n,m);i++)
    {
        f[i][0]=1;
        f[0][i] = 1; 
    }
    for(int i= 1 ;i<=n;i++)
    {
        for(int j= 1; j<=m;j++)
        {
            if(a[i]!=b[j])
            {
                f[i][j] = (f[i-1][j]+f[i][j-1]-f[i-1][j-1]+sm)%sm; 
            }
            else
            {
                f[i][j] = ((f[i-1][j]+f[i][j-1]-f[i-1][j-1]+sm)+f[i-1][j-1])%sm;
            }
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