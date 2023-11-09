#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =5e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll m , n  ;
ll b[N] , c[N] , f[N]  ;
ll T[N][2];
ll dd[N];
ll node=1 ;
ll res = 0 ;
void up(string s )
{
    ll r =1 ;
    for(ll i= 0 ;i<s.size();i++)
    {
        ll j = s[i] - '0';
        if(T[r][j] ==0)
        {
            T[r][j]=++node;
        }
        r=T[r][j];
        f[r]++ ;
    }
    dd[r]++;
}
ll get(string s )
{
    ll ans= 0;
    ll r = 1;
    for(ll i=0;i<s.size();i++)
    {
        ll j= s[i] -'0' ;
        if(T[r][j]==0)
            return ans;
        r=T[r][j] ;
        ans+=dd[r];
    }
    ans+=f[r];
    if(dd[r]!=0)
    {
        ans-=dd[r];
    }
    return ans;
}
void inp()
{
    cin>>m>>n ;
    for(ll i =1 ;i<=m;i++)
    {
        ll x;
        cin>>x;
        string s;
        for(ll j = 0 ; j<x;j++)
        {
            char u ;
            cin>> u;
            s=s+u;
        }
        up(s);
    }
    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin>>x ;
        string s ;
        for(ll j = 0 ; j<x;j++)
        {
            char u ;
            cin>>u ;
            s=s+u;
        }
        cout<<get(s);
        cout<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
