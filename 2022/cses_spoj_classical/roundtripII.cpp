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
int found  ;
vector<int>g[N] ; 
int dd[N] , pa[N] ; 
vector<int>res;  
int en=0; 
void dfs(int u  )
{
    if(found == 1)return;  
    dd[u] =1 ;
    for(auto v : g[u])
    {
        if(found==1)return; 
        if(dd[v]==1)
        {
            en =v; 
            found =1;
            res.pb(en) ; 
            while(u!=en)
            {
                res.pb(u) ; 
                u=pa[u] ; 
            }
            res.pb(en);
            cout<<res.size()<<endl;
            reverse(res.begin(),res.end()) ;
            for(auto v : res)
            {
                cout<<v<<" "; 
            }
            return ;     
        }
        else if(dd[v]==0)
        {
            pa[v]=u; 
            dfs(v);
        }
    }
    dd[u] = 2;
}
void inp()
{
    cin>> n>> m ; 
    for(int i=1 ;i<=m;i++)
    {
        int u , v ;
        cin>>u>>v ;
        g[u].pb(v) ; 
    }
    for(int i= 1 ;i<=n;i++)
    {
        if(dd[i]==0)
        {
            dfs(i); 
            if(found==1)return ; 
        }
    }
    cout<<"IMPOSSIBLE"; 
}   
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}