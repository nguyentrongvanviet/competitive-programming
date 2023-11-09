#include<bits/stdc++.h>
#define faster  ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define int long long 
#define pii pair<int,int>
#define X first 
#define Y second
const int N =5e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e15;
int n  ; 
int k  ;
vector<int>g[N] ;
bool dd[N] ; 
ll res=inf ; 
ll bfs(int u  )
{
    int cnt = 0 ; 
    for(int i= 1;i<=n;i++)
    {
        dd[i] =  0 ;
    }
    queue<pii>q; 
    q.push({u,1}) ;
    dd[u] = 1;  
    ll ans = k ; 
    cnt = 1;  
    while(!q.empty())
    {
        int u = q.front().X ;
        int h = q.front().Y ;  
        q.pop() ; 
        for(int i = 0 ;i<g[u].size();i++)
        {
            int v= g[u][i] ; 
            if(dd[v])continue ;
            dd[v] =1 ; 
            q.push({v,h+1}) ; 
            ans+=(h+1)*k;
            cnt++ ; 
            if(cnt==n)
            {
                return ans; 
            }
            if(ans>res)
            {
                return inf ;
            } 
        }
    }
    if(cnt<n)return inf ;
    return ans;  
}
void inp()
{       
    cin>> n>> k ;  
    for(int i =1 ;i<=n;i++)
    {
        int t ,v;
        cin>>t; 
        for(int j = 1;j<=t;j++)
        { 
            cin>>v ; 
            g[v].pb(i) ; 
        }
    }
    for(int i= 1 ;i<=n;i++)
    {
        res=min(res,bfs(i)); 
    }
    cout<<res; 
}

signed  main()
{
    faster;
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}