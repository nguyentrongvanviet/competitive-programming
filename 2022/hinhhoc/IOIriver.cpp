#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =100+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct ke 
{
    int v , d ; 
};  
int n  , k ;
int a[N] ; 
vector<ke>g[N];
int f[N][N][N] ;
int dd[N][N];
int tmp[N] ; 
void dfs(int u , int p , int d )
{   
    if(dd[u][p])return; 
    dd[u][p]= 1;
    f[u][p][0] = d*a[u]; 
    // cout<<u<<" "<<d<<endl;
    // cout<<d*a[u]<<endl;
    for(int t= 0;t<g[u].size();t++)
    {
        int v= g[u][t].v ; 
        int w =g[u][t].d ; 
        dfs(v,p,d+w);
        for(int i=0;i<=k;i++)
        {
            tmp[i] = oo ; 
        } 
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<=k-i;j++)
            {
                tmp[i+j]=min(tmp[i+j],f[u][p][i]+f[v][p][j]); 
            }
        }
        for(int i=0;i<=k;i++)
        {
            // cout<<tmp[i]<<endl;vi
            f[u][p][i] = tmp[i];
        }
    }
    if(u!=p)
    {
        dfs(u,u,0) ; 
        for(int i=1;i<=k;i++)
        {
            f[u][p][i] =min(f[u][p][i],f[u][u][i-1]); 
        }
    }
}
void inp()
{
    cin>> n >> k ;  
    for(int i =1 ;i<=n;i++)
    {
        int v , d ; 
        cin>>a[i]>>v>>d ; 
        g[v].pb({i,d}); 
    }
    for(int i=0;i<=n;i++)
    {
        for(int j= 0 ;j<=n;j++)
        { 
            dd[i][j] = 0;  
            for(int t = 0 ;t<=k;t++)f[i][j][t]=oo;
        }
    }
    dfs(0,0,0);
    // cout<<f[1][0][0]<<endl;
    cout<<f[0][0][k];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}