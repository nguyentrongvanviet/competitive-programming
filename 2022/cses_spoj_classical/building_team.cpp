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

int n  , m ; 
vector<int>g[N] ; 
int ok ;
int c[N] ;  
void dfs(int u ,int cl)
{
    c[u] = cl ; 
    for(auto v : g[u])
    {
        if(c[v])
        {
            if(c[v]==c[u])
            {
                ok = 0 ; 
                return  ; 
            }
        }
        else
        {
            if(cl==1)
            {
                dfs(v,2); 
            }
            else
            {
                dfs(v,1) ; 
            }
        }
    }
}
void inp()
{
    cin>>n >> m ;
    for(int i =1 ;i<=m;i++)
    {
        int u , v ;
        cin>>u>>v ;   
        g[u].pb(v) ; 
        g[v].pb(u) ; 
    }   
    for(int i= 1 ;i<=n;i++)
    {
        if(c[i]==0)
        {
            ok=1 ; 
            dfs(i,1);
            if(ok==0)
            {
                cout<<"IMPOSSIBLE" ; 
                return ; 
            } 
        }
    }
    for(int i = 1;i<=n;i++)
    {
        cout<<c[i]<< " " ; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout); 
    inp();
    return 0;
}