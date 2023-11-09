#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
int f[505][100005] ;
int n ; 
int su =0 ; 
int a[N] ; 
void inp()
{
    cin>> n ; 
    for(int i= 1 ;i<=n;i++)
    {
        cin>>a[i] ; 
        su+=a[i] ; 
    }   
    memset(f,-1,sizeof(f));
    f[0][0] =0 ;  
    for(int i= 1 ;i<=n;i++)
    {
        for(int j=0;j<=su;j++)
        {
            f[i][j]  = f[i-1][j];
            if(f[i-1][j+a[i]]!=-1)
            {
                f[i][j] =max(f[i][j],f[i-1][j+a[i]]+a[i]) ; 
            }
            if(f[i-1][abs(j-a[i])]!=-1)
            {
                f[i][j] =max(f[i][j],f[i-1][abs(j-a[i])]+a[i]) ; 
            }
        }
    }
    cout<<su-f[n][0]/2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}