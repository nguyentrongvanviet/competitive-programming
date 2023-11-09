#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =5e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n , m ; 
int a[N] , b[N] ; 
int f[N][N] ; 
void inp()
{
    cin>>n>>m;  
    for(int i =1;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    for(int j =1;j<=m;j++)
    {
        cin>>b[j] ; 
    } 
    for(int i= 1 ;i<=n;i++)
    {
        int ma= 0 ; 
        for(int j= 1 ;j<=m;j++)
        {
            f[i][j] =f[i-1][j];
            if(a[i]==b[j])
            {
                f[i][j]  =f[i-1][ma]+1; 
            }
            else
            {
                if(b[j]<a[i])
                {
                    if(f[i-1][j]>f[i-1][ma])
                    {
                        ma= j; 
                    }
                }
            } 
        }
    }
    int res= 0 ; 
    for(int i= 1 ;i<=m;i++)
    {
        res=max(res,f[n][i]);
    }
    cout<<res; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}