#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second

const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
#define int long long 
ll n , m ; 
ll f[30][30] ; 
void inp()
{
    cin>>n>> m;
    for(int i= 1;i<=n;i++)f[i][i] = 1 ;
    for(int i=1 ;i<=n;i++)f[i][1] = 1  ; 
    for(int i =1;i<=n;i++)
    {
        for(int j =2;j<=i-1;j++)
        {
            f[i][j]=f[i-1][j-1]+j*f[i][j-1] ; 
        }
    }
    cout<<f[n][m]<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t =1 ; 
    // cin>>t ; 
    while(t--)
    {
        inp();
    }
    return 0;
}