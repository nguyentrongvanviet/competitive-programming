#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second

const int N =2e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , k ; 
ll a[N];
ll f[N][N]; 
void inp()
{
    cin>> n>> k; 
    for(int i=1 ;i<=n;i++)
    {
        cin>>a[i] ;  
    }
    for(int i = 0 ;i<=n;i++)
    {
        for(int j= 0 ;j<=3*k;j++)
        {
            f[i][j] =-inf ;
        }
    }
    for(int i= 0;i<=n;i++)
    {
        f[i][0] = 0 ; 
    }
    for(int i=1 ;i<=n;i++)
    {
        for(int j= 1;j<=3*k;j++)
        {
            f[i][j]  =max(f[i-1][j],f[i-1][j-1]+(j%3==2?-a[i]:a[i])) ; 
        }
    }
    cout<<f[n][3*k] ; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    while(t--)
    {
        inp();
    }
    return 0;
}