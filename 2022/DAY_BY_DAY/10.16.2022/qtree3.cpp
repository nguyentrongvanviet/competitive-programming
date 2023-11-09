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

int n  , q; 

vector<int>g[N] ;  

void input()
{
 	cin>> n>> q; 
 	for(int i= 1;i<=n-1;i++)
 	{
 		int u , v ; 
 		cin>>u>>v ; 
 		g[u].pb(v); 
 		g[v].pb(u) ;  
 	}
}	
void predfs(int u ,int p)
{
	int ma = 0 ; 
	for(int i= 0 ;i<(int)g[u].size();i++)
	{
		int v = g[u][i] ; 
		if(v==p)continue  ; 
		predfs(v,u); 
		if(sz[g[u][0]]<sz[g[u][i]])
		{
			swap(g[u][0],g[u][i]);
		}
	}
}
int pos[N];
int tt= 0 ; 
void HLD(int u ,int p)
{
	pos[u]=++tt ; 
	if(sz[u]==1)return ; 
	HLD(g[u][0],u);
	for(int i=1 ;i<g[u].size();i++)
	{
		int v= g[u][i] ; 
		if(v==p)continue ;
		
	}
}
void output()
{
    predfs(1,0) ; 
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