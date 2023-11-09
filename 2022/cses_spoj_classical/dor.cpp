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

int n  ,k ; 
vector<int>g[N] ;
int dd[N]  ; 
int a[N] ;  
int res= 0 ; 
void predfs(int u ,int p )
{
    for(int i = 0 ;i<g[u].size();i++)
    {
        int v=  g[u][i] ; 
        if(v==p)continue ; 
        predfs(v,u);
        if(dd[v])dd[u]=1,res++ ; 
    }
} 
void inp()
{
    cin>> n>> k; 
    for(int i =1 ;i<=k;i++)
    {
        cin>>a[i];
        dd[a[i]]=1; 
    }
    for(int i=1; i<=n-1;i++)
    {
        int u , v ; 
        cin>>u>>v ; 
        g[u].pb(v) ;
        g[v].pb(u) ; 
    }  
    predfs(a[1],0); 
    cout<<2*res; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}