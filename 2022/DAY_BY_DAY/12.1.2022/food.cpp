#include<bits/stdc++.h>
using namespace std;

#define TASK "food"

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

const int N =5e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m , b , r  ; 
queue<int>q; 
vector<int>g[N] ; 
int f[N] ;
int dd[N] ; 
int go[N] ;
void doc()
{
  	cin>> n>>m>>b>>r; 
  	FOR(i,1,b)	
  	{
  		int x; 
  		cin>>x;  	
  		dd[x] = 1; 
  	}
  	vector<int>node; 
  	FOR(i,1,r)
  	{
  		int x;  
  		cin>>x ; 
  		node.pb(x) ;
  	}
  	FOR(i,1,m)
  	{
  		int u ,v;  cin>>u>>v ; 
  		g[u].pb(v) ; 
  		g[v].pb(u) ; 
  	}
  	FOR(i,1,n)if(dd[i]==1)q.push(i),go[i] = 1;   
  	while(!q.empty())
  	{
  		int u =q.front() ; 
  		q.pop() ; 
  		for(auto v : g[u])
  		{
  			if(go[v])continue ; 
  			go[v] = 1; 
  			f[v] =f[u]+1;  
  			q.push(v) ;
  		}
  	}
  	for(auto u : node)cout<<f[u]<<" ";
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