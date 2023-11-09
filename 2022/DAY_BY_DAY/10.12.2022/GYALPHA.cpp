#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct bg 
{
    int u  ; 
    ll val ;  
    bool operator<(const bg&a )const
    {
        return val>a.val ; 
    }
};  
struct ke 
{
    int v ; 
};
int n  , m;  
ll f[N][N]; 
int dd[N] ; 
int z[N];
vector<ke>g[N] ; 
void input()
{
 	cin>> n >> m ; 
 	for(int i= 1;i<=n;i++)
 	{
 		char x ; 
 		cin>>x ; 
 		z[i] =(x=='G'); 
 	}
    for(int i= 1;i<=m;i++)
    {
        int u , v ; 
        cin>>u>>v ; 
        g[u].pb({v}) ; 
        g[v].pb({u}) ; 
    }
}
void dij(int u)
{
    for(int i= 1;i<=n;i++)
    {
        f[u][i] = inf ;
        dd[i] = 0 ; 
    }
    f[u][u] =0;
    priority_queue<bg>q ;  
    q.push({u,f[u][u]}) ; 
    while(!q.empty())
    {
        int t = q.top(). u; 
        int val = q.top().val; 
        q.pop() ; 
        if(dd[t])continue ; 
        for(int i= 0;i<_sz(g[t]);i++)
        {
            int v = g[t][i].v ; 
            if(dd[v])continue; 
            if(f[u][v]>val+1+(z[u]==z[v]?0:3))
            {
                f[u][v] = val+1+(z[u]==z[v]?0:3) ; 
                q.push({v,f[u][v]}) ; 
            }
        }   
    }
}
void output()
{
    for(int i =1;i<=n;i++)
    {
        dij(i) ;
    }
    ll res1 = 0 , res2= 0 ; 
    for(int i = 1;i<=n;i++)
    {   
        for(int j= 1;j<=n;j++)
        {
            if(z[i]==z[j]&&z[i]==1)
            {
                res1+=f[i][j] ; 
            }
            if(z[i]==z[j]&&z[i]==0)
            {
                res2+=f[i][j] ; 
            }
        }
    }
    cout<<res1/2<<" "<<res2/2;  
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout);    
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}