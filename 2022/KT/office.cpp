#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first     
#define Y second
#define vvi vector<vector<int>>  
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n  , k ; 
vector<int>g[N];
int res=  0 ; 
int tmp[N] ; 
void dfs1(int u , int p ,vvi & f )
{
    f[u][0] =1 ; 
    for(int i = 0 ;i<g[u].size();i++)+
    {
        int  v =g[u][i] ; 
        if(v==p)continue ;
        dfs1(v,u,f) ;  
    }
    int t= 0 ; 
    for(int i= 0 ;i<g[u].size();i++)
    {
        int v = g[u][i] ; 
        if(v==p)continue ;
        if(t==0)
        {
            ++t;  
            f[u][0] +=f[v][k-1];
            for(int j = 1;j<=k;j++)
            {
                f[u][j] = f[v][j-1];
            }   
        }
        else 
        {
            f[u][0]+=f[v][k-1]; 
            for(int j = 1;j<=k;j++)
            {   
                tmp[j] = max(f[v][j-1]+f[u][max(j,k-j)],f[u][j]+f[v][max(j-1,k-j-1)]);   
            }
            for(int j=1;j<=k;j++)
            { 
                f[u][j] =tmp[j] ;
                tmp[j] = 0 ; 
            }
        }
    }
    for(int i=k-1;i>=0;i--) 
    {
        f[u][i] =max(f[u][i],f[u][i+1]) ; 
    }
    for(int i= 0  ;i<=k;i++)
    {
        res=max(res,f[u][i]) ;  
    }
}
void inp()
{
    cin>> n>>  k ;
    vvi f(n+1,vector<int>(k+1,0));
    for(int i= 1 ;i<=n-1;i++)
    {
        int u , v ;
        cin>>u>>v ; 
        g[u].pb(v) ; 
        g[v].pb(u) ; 
    }
    dfs1(1,0,f);
    cout<<res; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
} 