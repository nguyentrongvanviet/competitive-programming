#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n ,m ;
ll res ;
vector<ll>g[N];
ll pa[N] ;
ll goc(ll u )
{
    return (pa[u]==u? u : pa[u]=goc(pa[u]));
}
void inp()
{
    cin>> n>> m ;
    for(ll i =1;i<=n;i++) pa[i] = i ;
    res =  n ;
    while(m--)
    {
        char t ;
        cin>>t;
        if(t=='F')
        {
            ll u , v;
            cin>>u>>v;
            ll chau = goc(u) ;
            ll chav =goc(v)  ;
            if(chau==chav) continue ;
            res-- ;
            pa[chau] =chav ;
        }else
        {
            ll u , v ;
            cin>>u>>v ;
            for(ll i=  0 ;i<g[u].size();i++)
            {
                ll chav= goc(v) ;
                ll chau = goc(g[u][i]);
                if(chau!=chav)
                {
                    pa[chau] =chav ;
                    res-- ;
                }
            }
            for(ll i = 0 ;i<g[v].size();i++)
            {
                ll chau=goc(u) ;
                ll chav= goc(g[v][i]);
                if(chau!=chav)
                {
                    pa[chau]= chav ;
                    res--;
                }
            }
            g[u].pb(v) ;
            g[v].pb(u) ;
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
