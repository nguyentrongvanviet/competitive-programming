#include<bits/stdc++.h>
using namespace std;

#define TASK "MLGT"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
void IOS()  
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =4e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m , k ; 
vector<int>g[N] ; 
int f[N] ; 
void doc()
{
    cin>>n>>k>>m;
    int node= n ; 
    FOR(i,1,m)
    {
        ++node;  
        FOR(j,1,k)
        {
            int x ; 
            cin>>x ; 
            g[node].pb(x) ;
            g[x].pb(node) ;
        }
    }   
    queue<int>q;
    FOR(i,1,node)
    {
        f[i] =-1; 
    }  
    q.push(1);
    f[1] =0 ; 
    while(!q.empty())
    {
        int u =q.front();  
        q.pop() ; 
        for(auto v : g[u])
        {
            if(f[v]!=-1)continue ; 
            f[v] = f[u] +1 ; 
            q.push(v) ;
            if(v==n)
            {
                cout<<f[n]/2+1  ; 
                return ; 
            } 
        }
    }
    cout<<-1 ; 
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}