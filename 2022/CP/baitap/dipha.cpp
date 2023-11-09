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
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 

void input()
{	
    cin>> n; 
    for(int i= 1;i<=n;i++)
    {
    	int u , v ,w  ; 
    	cin>>u>>v>>w; 
    	g[u].pb({v,w}) ; 
    	adj[v].pb({u,w}) ; 
    }    
}
void dij(int s , int f[])
{
	priority_queue<bg,vector<bg>,cmp>q; 
	for(int i= 1;i<=n;i++)f[i] =oo ; 
	f[s] =0 ;  
	q.pb({s,0});  
	while(!q.empty())
	{
		int u= q.top().u ;
        for(int i=1;i<=n;i++)
        {
            
        } 
	}
}
void output()
{	
    dij(u,f) ; 
    dij(v,f) ;
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