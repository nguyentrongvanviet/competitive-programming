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
ll a[N] ;
ll f[N][N] ; 
ll s[N] ;
ll opt[N][N] ; 
void inp()
{   
    cin>> n ; 
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i] ; 
        s[i] =s[i-1]+a[i] ; 
    }       
    for(int i= 1;i<=n;i++)
    {
        for(int j= i;j<=n;j++)
        {
            f[i][j] = -oo ; 
        }
    }
    for(int i=1;i<=n;i++)
    {
        f[i][i] = 0 ;  
        opt[i][i] = i ; 
    }
    for(int l=2;l<=n;l++)
    {
        for(int i =1;i<=n-l+1;i++)
        {
            int j = (i+l-1); 
            for(int k=opt[i][j-1];k<=opt[i+1][j];k++)
            {
                if(f[i][j]<min(f[i][k]+s[k]-s[i-1],f[k+1][j]+s[j]-s[k]))
                {
                    f[i][j] = min(f[i][k]+s[k]-s[i-1],f[k+1][j]+s[j]-s[k]); 
                    opt[i][j] = k ; 
                }
            }
        }
    }
    cout<<f[1][n]; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}