#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll a[N] ;
ll dd[N] ;
ll n ;
void inp()
{
    cin>> n ;
    for(ll i = 1;i<=n;i++)
    {
        cin>>a[i];
        dd[a[i]]=0;
    }
    ll i = n ;
    ll en = 0 ;
    a[n+1]=INF ;
    for(ll i =n;i>=1;i--)
    {
        if(a[i]>a[i+1])
        {
            en=  i;
            break ;
        }
        dd[a[i]]=max(dd[a[i]],i);
    }
    if(en==0)
    {
        cout<<0;
        return ;
    }
    ll res =0 ;
    ll nen=0 ;
    for(ll i=en;i>=1;i--)
    {
        nen = max(nen,dd[a[i]]);
    }
    if(nen==0)
    {
        for(ll i= 1;i<=n;i++)dd[a[i]]= 0 ;
        for(ll i= 1;i<=en;i++)
        {
            if(dd[a[i]]==0)
            {
                dd[a[i]]=1 ;
                res++ ;
            }
        }
        cout<<res;
        return;
    }
    for(ll i=1;i<=n;i++)dd[a[i]]=0 ;
    for(ll i =1;i<=nen;i++)
    {
         if(dd[a[i]]==0)
        {
            dd[a[i]]=1 ;
            res++ ;
        }
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll t;
    cin>>t ;
    while(t--)
    {
        inp() ;
        cout<<"\n";
    }
}
