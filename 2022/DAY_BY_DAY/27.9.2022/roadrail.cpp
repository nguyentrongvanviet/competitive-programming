#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =1e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
// #define int long long 
struct bg
{
    int u ;
    int sl ; 
    int id ;   
    ll val ; 
    bool operator <( const bg&  x )const 
    {
        return val>x.val;  
    }
};  
struct ke 
{
    int v  ; 
    ll w;  
    int id  ; 
};  

int n , m , l , q;
int dd[N][N][3];  
ll f[N][N][3]; 
vector<ke>g[N] ;
void dij()
{
    for(int i= 1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            f[i][j][1] = f[i][j][2] = inf ; 
        }
    }
    priority_queue<bg>q; 
    f[1][0][1] = 0 ; 
    f[1][0][2] =0  ;
    q.push({1,0,1,0}) ; 
    q.push({1,0,2,0});
    while(!q.empty())
    {
        int u =q.top().u;
        int sl=q.top().sl;
        int x=  q.top().id;  
        q.pop(); 
        if(dd[u][sl][x])continue; 
        dd[u][sl][x]=1; 
        for(int i=0;i<g[u].size();i++)
        {
            int v= g[u][i].v ; 
            int id= g[u][i].id; 
            int w= g[u][i].w;
            int nsl = sl+(id!=x);
            if(nsl==n)continue; 
            if(dd[v][nsl][id])continue ; 
            if(f[v][nsl][id]>f[u][sl][x]+w)
            {
                f[v][nsl][id] = f[u][sl][x]+w; 
                q.push({v,nsl,id,f[v][nsl][id]});
            }
        }
    }
}
void inp()
{   
    cin>> n >> m >> l >> q; 
    for(int i= 1;i<=m;i++)
    {
        int u , v  , w;  
        cin>>u>>v >> w ; 
        ++u; 
        ++v; 
        g[u].pb({v,w,1}); 
    }
    for(int i= 1;i<=l;i++)
    {
        int u , v,  w; 
        cin>>u>>v>> w;
        ++u ; 
        ++v ;  
        g[u].pb({v,w,2}) ; 
    }
    dij() ; 
    while(q--)
    {
        ll res=inf ; 
        ll  x , c; 
        cin>>c>>x ;
        ++x; 
        for(int i=0 ;i<=n;i++)
        {
            res=min(res,min(f[x][i][1],f[x][i][2])+i*c); 
        }
        cout<<(res==inf?-1:res)<<"\n"; 
    }
}   

signed  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}