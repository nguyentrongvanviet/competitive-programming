#include<bits/stdc++.h>
using namespace std;

#define TASK "E"

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

const int N =4e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n ; 
int a[N][N] ;
int cnt= 0 ;
int dd[N] ; vector<int>g[N] ; 
void dfs(int u )
{
	cnt++;
	dd[u] =1 ; 
	for(auto v : g[u])
	{
		if(dd[v]==0)dfs(v);
	}
}
void doc()
{
    cin>>n ; 
    FOR(i,1,n)dd[i] = 0 , g[i].clear() ; 
    FOR(i,1,n)
    {
    	FOR(j,1,n)
    	{
    		char x; cin>>x;  
    		a[i][j] = (x=='1'); 
    		if(a[i][j]==1)
    		{
    			g[i].pb(j) ; 
    		}
    	}
    }
    cnt =0 ; 
   	dfs(1); 
   	if(cnt==n)
   	{
   		cout<<0<<"\n"; 
   		return ; 
   	}
  	int ans=oo ; 
  	int node=  0 ; 
  	FOR(i,1,n)
  	{
  		if(ans>(int)g[i].size())
  		{
  			ans= g[i].size() ;
  			node= i ;  
  		}
  	}
  	cout<<ans+1<<"\n";
  	for(auto v : g[node])cout<<v<<" "; 
  	cout<<node;
  	cout<<"\n";
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    cin>>t ; 
    while(t--)
    {
    	// cout<<"TEST"<<" ";
        doc();
    }
}