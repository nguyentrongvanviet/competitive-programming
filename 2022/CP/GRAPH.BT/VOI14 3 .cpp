#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =2e6+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;
struct edge
{
    ll u , v , c ;
};
ll n , m , a[N] , b[N] ;
ll pa[N] ,dd[N] ;
edge q[2*N] ;
ll goc(ll u)
{
    return (pa[u]==u? u : pa[u] = goc(pa[u]));
}
void init()
{
    for(ll i=1 ;i<=n;i++) pa[i]=i ;
}
void inp()
{
    cin>>n>> m ;
    ll z= 0 ;
    init();
    for(ll i=1;i<=m;i++)dd[i]= 0;
    ll A = 0 ;
    for(ll i =1 ;i<=n-1;i++)
    {
        cin>>a[i] ;
    }
    for(ll j =1 ;j<=n-1;j++)
    {
        cin>>b[j] ;
    }
    for(ll i =1;i<=m;i++)
    {
        cin>>q[i].u>>q[i].v>>q[i].c;
        if(q[i].c==1) z++ ;
    }

    for(ll i= 1;i<=m;i++)
    {
        if(q[i].c==2){
            ll u = q[i].u ;
            ll v = q[i].v ;
            ll chau = goc(u);
            ll chav =goc(v) ;
            if(chau==chav)continue ;
            pa[chau] =chav;
        }
    }
    for(ll i=1;i<=m;i++)
    {
        if(q[i].c==1)
        {
            ll u = q[i].u ;
            ll v =q[i].v  ;
            ll chau =goc(u);
            ll chav =goc(v);
            if(chau==chav) continue ;
            pa[chau]= chav;
            dd[i] =1 ;
            A++;
        }
    }
    init();
    ll mi = INF ;
    ll pos ;
    for(ll i=A;i<=min(z,n-1);i++)
    {
        if(mi>a[i]+b[n-1-i])
        {
            pos = i ;
            mi= a[i]+b[n-1-i];
        }
    }
    ll tt= 0 ;
    for(ll i= 1 ;i<=m;i++)
    {
        if(dd[i])
        {
            tt++;
            ll u = q[i].u ;
            ll v = q[i].v ;
            ll chau = goc(u) ;
            ll chav =goc(v)  ;
            if(chau==chav)continue ;
            pa[chau]=chav;
        }
    }
    for(ll i=1 ;i<=m&&tt!=pos;i++)
    {
        if(dd[i]==0&&q[i].c==1)
        {
            ll u =q[i].u ;
            ll v= q[i].v;
            ll chau =goc(u) ;
            ll chav = goc(v) ;
            if(chau==chav) continue ;
            pa[chau]=chav ;
            dd[i] =1 ;
            tt++;
        }
    }
    for(ll i= 1;i<=m;i++)
    {
        if(q[i].c==2)
        {
            ll u =q[i].u ;
            ll v= q[i].v;
            ll chau =goc(u) ;
            ll chav = goc(v) ;
            if(chau==chav) continue ;
            pa[chau]=chav ;
            dd[i] =1 ;
        }
    }
    for(ll i= 1 ;i<=m;i++)
    {
        if(dd[i]==1)cout<<i<<" " ;
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll test ;
    cin>>test ;
    while(test--)inp() ;
}
