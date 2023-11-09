#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2000+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
int f[N][N] ; 
int opt[N][N] ; 
int s[N] ; 
int a[N] ;
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
        for(int j= 1 ;j<=n;j++)
        {
            f[i][j] = oo; 
        }
    }
    for(int i= 1;i<=n;i++)
    {
        f[i][i] = 0 ;
        opt[i][i] = i;  
    }
    for(int le=2;le<=n;le++)
    {   
        for(int i =1 ;i<=n-le+1;i++)
        {   
            int cost = s[i+le-1]-s[i-1]; 
            int j = i+le-1;
            int ans = oo ;  
            for(int k = opt[i][j-1];k<=opt[i+1][j];k++)
            {
                if(f[i][k]+f[k+1][j]+cost<=ans)
                {
                    ans=f[i][k]+f[k+1][j]+cost; 
                    opt[i][j] = k; 
                }
            }
            f[i][j] =ans;  
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