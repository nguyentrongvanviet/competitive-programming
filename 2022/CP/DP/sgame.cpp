#include<bits/stdc++.h>
using namespace std ;
#define ll int
#define pb push_back
#define pk pop_back

const ll N =355 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n , k ;
char a[N] ;
bool dp[N][N][N][2];
bool dd[N][N][N][2];
ll sl[N];
ll sr[N];
bool tinh(ll l , ll r , ll kk, ll ok)
{
    ll u = sl[l-1]+sr[r+1]-kk;
    if(l>r)
    {
        return false;
    }
    if(dd[l][r][kk][ok])return dp[l][r][kk][ok];
    dd[l][r][kk][ok]=true;
    if(kk==k-1)
    {
        if(a[l]!='R')
        {
            bool x = tinh(l+1,r,u,1-ok);
            if(x==false)
            {
                return dp[l][r][kk][ok]=true;
            }
        }
        if(a[r]!='R')
        {
            bool x = tinh(l,r-1,u,1-ok);
            if(x==false)
            {
                return dp[l][r][kk][ok]=true;
            }
        }
    }else
    {
        bool x = tinh(l+1,r,u,1-ok);
        if(x==false)
        {
            return dp[l][r][kk][ok]=true;
        }
        x= tinh(l,r-1,u,1-ok);
        if(x==false)
        {
            return dp[l][r][kk][ok]=true;
        }
    }
    return dp[l][r][kk][ok]=false;
}
void inp()
{
    cin>>n>>k;
    memset(dp,0,sizeof(dp));memset(dd,0,sizeof(dd));
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        sl[i]=sl[i-1]+(a[i]=='R');
    }
    sr[n+1]=0;
    for(ll i = n ;i>=1;i--)
    {
        sr[i] =sr[i+1]+(a[i]=='R');
    }
    cout<<(tinh(1,n,0,1)==true?"YES":"NO");
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    ll t;
    cin>>t;
    while(t--)
    {
        inp();
    }
}
