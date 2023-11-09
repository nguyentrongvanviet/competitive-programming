#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,l,r) for(ll i= l;i<=r;i++)
const ll N =3e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

struct ke
{
    ll v,c;
};
ll n , m ,  s, t ;
ll dd[N];
ll used[N];
ll low[N],id[N] ;
ll res= 0 ;
vector<ke>c[N];
vector<ll>g[N] ;
stack<ll>st;
ll tt=0 ;
void dfs(ll u)
{
    dd[u]=1;
    for(ll i= 0 ;i<c[u].size();i++)
    {
        ll v= c[u][i].v;
        ll id= c[u][i].c;
        if(used[id]==1)continue;
        g[u].pb(v);
        used[id]=1;
        if(dd[v])continue;
        dfs(v);
    }
}
void dfs1(ll u )
{
    low[u]=id[u]=++tt;
    st.push(u) ;
    for(ll i= 0 ;i<g[u].size();i++)
    {
        ll v=g[u][i];
        if(dd[v])continue;
        if(id[v]==0)
        {
            dfs1(v);
            low[u]=min(low[u],low[v]);
        }else
        {
            low[u]=min(low[u],id[v]);
        }
    }
    if(low[u]==id[u])
    {
        ll t ;
        ll ans= 0 ;
        do
        {
            ans++;
            t=st.top();
            st.pop();
            dd[t]=1;
        }while(t!=u);
        res=max(res,ans);
    }
}
void inp()
{
    cin>>n>> m ;
    FOR(i,1,m)
    {
        ll u , v ;
        cin>>u>>v;
        c[u].pb({v,i});
        c[v].pb({u,i});
    }
    dfs(1);
    for(ll i= 1;i<=n;i++)
    {
        cout<<i<<endl;
        cout<<g[i].size()<<" ";
        for(auto v:g[i])
        {
            cout<<v<<" " ;
        }
        cout<<endl;
    }
    for(ll i=1;i<=n;i++)dd[i]=0;
    for(ll i=1;i<=n;i++)
    {
        if(id[i]==0)dfs1(i);
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
