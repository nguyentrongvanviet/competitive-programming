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

struct ke 
{
    int u ; 
    int c;  
}; 
int n  , m  ,st ,en ; 
vector<ke>g[N]  ; 

void inp()
{
    cin>>n>>m ; 
    cin>>st >>en ; 
    for(int i= 1;i<=m;i++)
    {
        int u , v ,c ;
        cin>>u>>v>>c ; 
        g[u].pb({v,c}) ; 
        g[v].pb({u,c}); 
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