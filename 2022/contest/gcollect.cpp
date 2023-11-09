#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define int long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e6+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
struct ke
{
    int v ,c ; 
};
int n , m;  
vector<ke>g[N];
vector<ke>adj[N]; 
int tplt= 0,tt = 0  ;  
int tp[N] ,f[N], id[N]  , low[N] ;
stack<int>st ; 
void dfs(int u )
{
    id[u]=low[u]=++tt ;
    st.push(u) ; 
    for(auto x : g[u])
    {
        int v =x.v; 
        int c =x.c;
        if(tp[v]!=0)continue;
        if(id[v]!=0)
        {
            low[u]=min(low[u],id[v]);
        }
        else
        {
            dfs(v); 
            low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==id[u])
    {
        int t;  
        tplt++ ;
        do
        {
            t=st.top(); 
            st.pop();
            tp[t]=tplt;
        }while(t!=u);
    }
}  
int dfs2(int u )
{
    int res=0;
    for(auto v:adj[u])
    {
        int val = v.c; 
        val+=dfs2(v.v);
        res=max(res,val);  
    }
    return res+f[u]; 
}
int np(int val)
{
    int l =0; 
    int r = 1e8+5; 
    int ans=0; 
    while(l<=r)
    {
        int mid =(l+r)/2;
        if(mid*(mid+1)/2<=val)
        {
            ans=  mid ;
            l=mid+1;  
        }
        else
        {
            r=mid-1;  
        }
    }
    return ans; 
}
void inp()
{
    cin>> n >> m ; 
    for(int i =1 ;i<=m;i++)
    {
        int u , v ,c ; 
        cin>>u>>v>>c;
        g[u].pb({v,c}); 
    }
    for(int i= 1 ;i<=n;i++)
    {
        if(!id[i])
        {
            dfs(i);
        }
    }
    for(int i =1 ;i<=n;i++)
    {
        for(auto v:g[i])
        {
            if(tp[i]==tp[v.v])
            {
                int ti =np(v.c); 
                f[tp[i]]+=v.c*(ti+1)-ti*(ti+1)*(ti+2)/6;
            }
            else adj[tp[i]].pb({tp[v.v],v.c});
        }
    }
    int s  ; 
    cin>> s; 
    int t = tp[s] ; 
    cout<<dfs2(t);  
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}