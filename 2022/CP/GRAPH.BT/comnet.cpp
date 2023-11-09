#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e6+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n , m , q ;
ll u[N],v[N] ,w[N],ww[N]  ;
ll pa[N] ;

ll goc(ll  u )
{
    return (pa[u]==u ? u : pa[u] =goc(pa[u]));
}
void inp()
{
    cin>> n>>m>>q ;
    for(ll i =1; i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    while(q--)
    {
        for(ll i= 1 ;i<=m;i++)ww[i] = w[i] ;
        ll k , s;
        cin>> k >> s ;
        for(ll i= 1;i<=s;i++)
        {
            ll t , c;
            cin>>t>>c;
            ww[t]= c;
        }
        for(ll i= 1 ;i<=n;i++)
        {
            pa[i]=i;
        }
        for(ll i =1 ;i<=m;i++)
        {
            if(ww[i]<ww[k])
            {
                ll uu =u[i] ;
                ll vv=v[i];
                ll chau =goc(uu) ;
                ll chav = goc(vv) ;
                if(chau==chav)
                {
                    continue;
                }
                pa[chau]=chav ;
            }
        }
        if(goc(u[k])==goc(v[k]))cout<<"YES"<<"\n" ;
        else cout<<"NO"<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll test ;
    cin>>test ;
    while(test--)
    {
        inp();
    }
}
