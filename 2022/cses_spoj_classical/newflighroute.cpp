#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

ll n  , m;   
ll low[N] , id[N] ; 
vector<ll>g[N] ; 
stack<ll>st ; 
ll tt =0  ; 
ll tplt= 0 ; 
ll dd[N] ;
void dfs(ll u)
{
    low[u] = id[u]=++tt; 
    st.push(u) ;
    for(int i = 0;i<g[u].size();i++)
    {
        ll v = g[u][i] ;
        if(dd[v])continue; 
        if(id[v])
        {
            low[u]=min(low[u],id[v]) ; 
        }
        else 
        {
            dfs(v) ; 
            low[u]=min(low[u],low[v]) ; 
        }
    } 
    if(low[u]==id[u])
    {
        ll t;  
        ++tplt ; 
        do{
            t= st.top() ; 
            dd[t]=tplt; 
            st.pop() ; 
        }while(t!=u);
    }
}
void inp()
{
    cin>>n>>m ; 
    for(ll i= 1;i<=m;i++)
    {
        int u ,v  ; 
        cin>>u>>v ; 
        g[u].pb(v) ; 
    }
    for(int i= 1;i<=n;i++)
    {
        if(id[i]==0)
        {
            dfs(i); 
        }
    }
    for(int i =1;i<=n;i++)
    {
        cout<<dd[i]<<" ";
    }
    cout<<tplt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}