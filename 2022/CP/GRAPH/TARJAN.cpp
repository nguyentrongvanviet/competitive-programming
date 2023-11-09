#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll tplt = 0 ;
ll n , m ;
vector<ll>g[N] ;
ll low[N] ,id[N] ;
ll tt= 0 ;
vector<ll> st;
ll dd[N];
void dfs(ll u )
{
    low[u] = id[u] =++tt;
    st.pb(u) ;
    for(ll v : g[u] )
    {
        if(dd[v]!=0)continue;
        if(id[v]==0)
        {
            dfs(v) ;
            low[u] =min(low[u] ,low[v] );
        }
        else
        {
            low[u]=min(low[u],id[v]) ;
        }
    }
    if(low[u] ==id[u])
    {
        tplt++ ;
        ll t ;
        do
        {
            t=st.back();
            dd[t]=tplt ;
            st.pk();
        }while(t!=u);
    }
}

void inp()
{
    cin>> n>>m ;
    for(ll i=1 ;i<=m;i++)
    {
        ll u , v;
        cin>>u>> v;
        g[u].pb(v) ;
    }
    for(ll i=1;i<=n;i++)
    {
        if(id[i]==0) dfs(i) ;
    }
//    for(ll i=1;i<=n;i++) cout<<low[i]<<" " <<id[i]<<endl;
    cout<<tplt;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    inp() ;
}
