#include<bits/stdc++.h>
using namespace std ;
#define ll int
#define pb push_back
#define pk pop_back
const ll N =1e4+5 , INF =1e9+7 , C= 330  , MOD = 1e9+7 ;

ll l , n ;
ll a[1000005] ;
pair<ll,ll>dp[N][5005];
ll B(ll bit , ll pos) {return (((1<<pos)&bit)!=0);}
void solve()
{
    for(ll i =1;i<=n;i++)
    {
        for(ll j = 0 ;j<=l;j++)
        {
            dp[i][j]= {INF,INF};
        }
    }
    dp[0][0]= {0,0};
    for(ll i=0;i<=n;i++)
    {
        for(ll j= 0;j<=l;j++)
        {
            if(dp[i][j].first&&dp[i][j].second==INF)continue;
            if(j+a[i+1]<=l)
            {
                dp[i+1][j+a[i+1]]=min(dp[i+1][j+a[i+1]],dp[i][j]);
            }
            dp[i+1][a[i+1]]=min(dp[i+1][a[i+1]],{dp[i][j].first+1,dp[i][j].second});
            if(dp[i][j].second+a[i+1]<=l)
            {
                dp[i+1][j]=min(dp[i+1][j],{dp[i][j].first,dp[i][j].second+a[i+1]});
            }
            dp[i+1][j]=min(dp[i+1][j],{dp[i][j].first+1,a[i+1]});
        }
    }
    ll res =INF ;
    for(ll i= 0 ;i<=l;i++)
    {
        if(dp[n][i].second!=INF)
        {
            res=min(res,dp[n][i].first+2);
        }
    }
    cout<<res;
}
void inp()
{
    cin>>l>>n ;
    if(n<=20)
    {
        ll a[n+6];
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ll res=INF ;
        for(ll i = 0 ;i<(1<<n);i++)
        {
            ll s0= 0 ;
            ll s1= 0 ;
            ll ans = 2 ;
            for(ll j= 0  ;j<n;j++)
            {
                if(B(i,j))
                {
                    if(s1+a[j+1]>l)
                    {
                        ans++;
                        s1=a[j+1];
                    }else
                    {
                        s1+=a[j+1];
                    }
                }else
                {
                    if(s0+a[j+1]>l)
                    {
                        ans++;
                        s0=a[j+1] ;
                    }else
                    {
                        s0+=a[j+1];
                    }
                }
            }
            res =min(res,ans) ;
        }
        cout<<res<<endl;
    }else
    {
        solve();
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
