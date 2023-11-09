#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =5e2+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;
ll s[N][N];
ll dp[N][N][2];
ll dd[N][N][2];
ll tinh(ll n , ll m , ll turn )
{
    if(n==0||m==0)return 0 ;
    ll ok=0;
    ll ans =INF;
    if(dd[n][m][turn]==1)return dp[n][m][turn];
    if(n>0)
    {
        ll su1=s[n][m]-s[n-1][m];
        if(su1%2==0)
        {
            ans = tinh(n-1,m,turn^1);
            ok=1;
        }
    }
    if(m>0)
    {
        ll su2 = s[n][m]-s[n][m-1];
        if(su2%2==0)
        {
            ans = min(ans,tinh(n,m-1,turn^1));
            ok=1;
        }
    }
    dd[n][m][turn]=1;
    if(ok==0||ans==1)return dp[n][m][turn]=0;
    return dp[n][m][turn]=1;
}
void inp()
{
    ll n ;
    cin>> n ;
    for(ll i =1 ;i<=n;i++)for(ll j =1;j<=n;j++)cin>>s[i][j],s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    for(ll i=0;i<=n;i++)
    {
        for(ll j= 0;j<=n;j++)
        {
            dd[i][j][1]=dd[i][j][0]=0;
            dp[i][j][1]=dp[i][j][0]=0;
        }
    }
    if(tinh(n,n,1))cout<<"YES";
    else cout<<"NO";
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll test  ;
    cin>>test;
    while(test--)inp() ;
}
