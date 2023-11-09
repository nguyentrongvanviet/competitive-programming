#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
#define int long long 
const int N =1e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
struct ke 
{
    int v ;
    int c;  
};  
struct bg 
{
    int u , val ; 
};
struct cmp
{
    bool operator()(bg a , bg b  )
    {
        return a.val>b.val ; 
    }
}; 
struct edge
{
    int u , v,  c , w;  
    bool operator<(const edge& x )
    {
        return w>x.w;  
    }
};  
int  n , m ; 
edge e[N] ; 
int dd[N]; 
vector<ke>g[N] ; 
int f1[N] , fn[N] ; 
void dij(int st , int f[] )
{
    for(int i= 1;i<=n;i++)
    {
        f[i]  =oo ;
        dd[i] = 0 ;  
    }
    priority_queue<bg,vector<bg>,cmp> q;
    f[st]  = 0 ; 
    q.push({st,f[st]}) ; 
    while(!q.empty())
    {
        int u = q.top().u ; 
        q.pop() ; 
        if(dd[u])continue ;
        dd[u] =1 ;
        for(int i=  0;i<g[u].size();i++)
        {
            int v = g[u][i].v ; 
            int c= g[u][i].c;
            if(dd[v])continue; 
            if(f[v]>f[u]+c)
            {
                f[v] = f[u]+c; 
                q.push({v,f[v]}) ; 
            } 
        } 
    } 
}
void inp()
{
    cin>>n>>m ; 
    for(int i= 1 ;i<=m;i++)
    {
        int u , v , c ,w  ; 
        cin>>u>>v>>c>>w; 
        e[i]={u,v,c,w} ;  
    }   
    sort(e+1,e+m+1);
    int it = 1 ; 
    vector<edge>canh;
    ll res= 0 ;   
    while(it<=m)
    {
        canh.pb(e[it]) ; 
        int u = e[it].u ; 
        int v= e[it].v;
        g[u].pb({v,e[it].c}); 
        g[v].pb({u,e[it].c});
        while(e[it+1].w==e[it].w&&it+1<=m)
        {
            it++; 
            canh.pb(e[it]);
            int u = e[it].u ; 
            int v= e[it].v;
            g[u].pb({v,e[it].c}); 
            g[v].pb({u,e[it].c});
        }
        dij(1,f1) ; 
        dij(n,fn); 
        while(!canh.empty())
        {
            int u = canh.back().u ; 
            int v =canh.back().v; 
            if(f1[u]!=oo&&fn[v]!=oo)res=max(res,canh.back().w*1000000/(f1[u]+fn[v]+canh.back().c)); 
            if(fn[u]!=oo&&f1[v]!=oo)res=max(res,canh.back().w*1000000/(fn[u]+f1[v]+canh.back().c)); 
            canh.pk() ; 
        }
        // cout<<res<<endl;
        it++ ; 
    } 
    cout<<res;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}