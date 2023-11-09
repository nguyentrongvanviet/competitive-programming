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

int n , m ; 
vector<int>g[N] ; 
int dd[N] ;
int ok ;
vector<int>res; 
int on[N] ;  
void dfs(int u )
{
    dd[u] =1 ; 
    res.pb(u) ; 
    for(auto v :g[u])
    {
        if(dd[v])
        {
            ok =0 ; 
            return  ; 
        }
        else dfs(v) ; 
    }
}

void inp()
{
    cin>> n >> m ;
    for(int i= 1 ;i<=m;i++)
    {
        int u , v; 
        cin>>u>>v; 
        g[u].pb(v) ; 
        on[v]++ ; 
    }
    int x= 0 ; 
    for(int i=1 ;i<=n;i++)
    {
        if(dd[i]==0&&on[i]==0)
        {
            ok = 1 ; 
            dfs(i) ;
            x= 1;  
            if(ok==0)
            {
                // cout<<"IMPOSSIBLE" ; 
                // return ; 
            }
        }
    }   
    if(x==0)cout<<"IMPOSSIBLE"; 
    else
    {
        for(auto v :res)
        {
            cout<<v<<" " ; 
        }   
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}