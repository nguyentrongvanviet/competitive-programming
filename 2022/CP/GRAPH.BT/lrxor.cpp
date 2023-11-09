#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5  , INF = 1e17  , C =256 , MOD =  1e9+7 ;

ll n ,  k;

ll l[N] ,r[N]  ,ti[N*60];
ll T[N*60][2] ;
ll s[N] ;
ll a[N] ;
ll node=1 ;
void add(ll val, ll c )
{
    ll r= 1;
    for(ll i= 30;i>=0;i--)
    {
        ll j =((val&(1<<i))!=0) ;
        if(T[r][j]==0)
        {
            node++;
            T[r][j] = node;
        }
        r=T[r][j];
        ti[r]=(ti[r]+c)%MOD;
    }

}
ll get(ll val,ll up  )
{
    ll r= 1;
    ll ans= 0 ;
    for(ll i =30;i>=0;i--)
    {
     //   if(up==1)cout<<r<<" "<<ans<<endl ;
        ll j =((val&(1<<i))!=0) ;
        ll t= ((up&(1<<i))!=0);
        if(j==0&&t==0)
        {
            r =T[r][j] ;
        }
        else if(j==0&&t==1)
        {
            ans=(ans+ti[T[r][j]])%MOD;
            r=T[r][j^1];
        }
        else if(j==1&&t==0)
        {
            r=T[r][j];
        }
        else if(j==1&&t==1)
        {
            ans=(ans+ti[T[r][j]])%MOD;
            r=T[r][j^1];
        }
    }
    return (ans+ti[r])%MOD;
}
void inp()
{
    cin>> n>> k ;
    ll f[n+100][k+100];
    for(ll i =0 ;i<=n;i++)
    {
        for(ll j= 0;j<=k;j++)
        {
            f[i][j] =0 ;
        }
    }
    for(ll i =1 ;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
    for(ll i= 1;i<=k;i++)
    {
        cin>>l[i]>>r[i] ;
    }
    for(ll i= 1 ;i<=n;i++)
    {
        f[i][1]= (s[i]>=l[1]&&s[i]<=r[1] ? 1 : 0 );
        add(s[i],0);
    }
    for(ll j =2 ;j<=k;j++)
    {
        for(ll i = 1 ;i<=node;i++)
        {
            ti[i] = 0 ;
        }
        for(ll i =1 ;i<=n;i++)
        {
            f[i][j] = get(s[i],r[j]);
            if(l[j]>0)
            {
                f[i][j] =(f[i][j]-get(s[i],l[j]-1)+MOD)%MOD;
            }
            add(s[i],f[i][j-1]);
        }
    }
    cout<<f[n][k];
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    inp();
}
