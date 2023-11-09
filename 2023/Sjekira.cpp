#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll a[N];
struct edge
{
    ll u , v;
    bool operator<(edge t )
    {
        return max(a[u],a[v])<max(a[t.u],a[t.v]);
    }
};
ll n , pa[N]  ;
ll ma[N];
edge q[N];
ll goc(ll u )
{
    return (pa[u]==u? u : pa[u] =goc(pa[u]));
}
void inp()
{
    cin>> n;
    for(ll i= 1;i<=n;i++)
    {
        cin>>a[i] ;
    }
    for(ll i=1 ;i<=n-1;i++)
    {
        ll u ,v ;
        cin>>u>>v;
        q[i] = {u,v};
    }
    for(ll i= 1 ;i<=n;i++)
    {
        pa[i] = i;
        ma[i] = a[i];
    }
    sort(q+1,q+n);
    ll res= 0 ;
    for(ll i= 1 ;i<=n-1;i++)
    {
        ll u= q[i].u ;
        ll v= q[i].v ;
        ll chau = goc(u);
        ll chav =goc(v) ;
        res+=ma[chau]+ma[chav];
        pa[chau]=chav ;
        ma[chav] = max(ma[chau],ma[chav]);
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp();
}
