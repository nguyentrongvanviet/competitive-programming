#include<bits/stdc++.h>
using namespace std;
#define TASK "CENTROID"
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ; 
vector<int>g[N] ;  
int sz[N] ;
void predfs(int u ,int p)
{
	sz[u]=1 ; 
	for(int i = 0 ; i<g[u].size();i++)
	{
		int v =g[u][i] ; 
		if(v==p)continue ; 
		predfs(v,u) ;  
		sz[u] +=sz[v] ; 
	}
}
int  centroid(int u  , int p , int n )
{
	for(int i= 0;i<g[u].size();i++)
	{
		int v= g[u][i] ;
		if(v==p)continue ; 
		if(sz[v]>n/2)
		{
			return centroid(v,u,n) ; 
		}
	}
	return u ;
}
void doc()
{
    cin>>n ; 
    for(int i=1;i<=n-1;i++)
    {
    	int u  ,v ;  cin>>u>>v ; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
    predfs(1,0) ; 
    cout<<centroid(1,0,n); 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}