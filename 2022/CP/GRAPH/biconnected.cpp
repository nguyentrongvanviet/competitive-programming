#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n , m;
vector<ll>g[N] ;
vector<ll> st ;
ll pa[N] ,dd[N] , ne[N];
ll c[N] ;
ll goc(ll u )
{
    return (pa[u]==u? u : pa[u] =goc(pa[u]));
}

void dfs(ll u ,  ll  p)
{
    dd[u]=1 ;
    pa[u]= u ;
    st.pb(u) ;
    for(ll v : g[u] )
    {
        if(v==p)continue ;
        if(dd[v])
        {
            ll t= goc(ne[v]);
            while(st.back()!=t)
            {
                pa[goc(st.back())]=t;
                st.pk();
            }
        }
    }
    for(ll  v : g[u])
    {
        if(v==p)continue ;
        if(dd[v]==0)
        {
            ne[u]=v;
            dfs(v,u);
        }
    }
    if(st.back()==u)st.pk();
}
void inp()
{
    cin>>n>> m;
    if(m==0)
    {
        cout<<1;
        return ;
    }
    for(ll i= 1; i<=m;i++)
    {
        ll u , v;
        cin>>u>>v;
        g[u].pb(v) ;
        g[v].pb(u) ;
    }
    for(ll i= 1 ;i<=n;i++)
    {
        if(dd[i]==0)
        {
            dfs(i,0) ;
        }
    }
    for(ll i= 1;i<=n;i++)
    {
        c[goc(i)]++;
    }
    ll res=0 ;
    for(ll i=1 ;i<=n;i++)
    {
        res=max(res,c[i]);
    }
    cout<<1+res ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
    return 0 ;
}
