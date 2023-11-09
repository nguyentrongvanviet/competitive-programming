#include<bits/stdc++.h>
using namespace std;

#define TASK "planet_cycles"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
const int LO = 20 ; 
int n ; 
vector<int>g[N] ; 
int after[N] ; 
int d[N]  , dd[N] ; 
int pa[N][LO] ;
int sz[N] ; 
void bfs(int u)
{
	queue<int>q; 
	q.push(u) ; 
	d[u] = 1 ; 
	while(!q.empty())
	{
		int u= q.front();  
		q.pop() ; 
		for(auto v: g[u])
		{
			d[v] = d[u]+1; 
			q.push(v) ; 
		}
	}
}
void doc()
{
    cin>> n;  
    FOR(i,1,n)
    {
    	int u ; 
    	cin>> u;  
    	g[u].pb(i) ; 
    	after[i]  = u ;  
    	pa[i][0] = u ;
    }
    FOR(i,1,n)dd[i] =-2 ; 
    FOR(i,1,n)
    {
    	int u = i ;
    	if(dd[u]!=-2)continue; 
    	vector<int>q; 
    	q.pb(u) ; 
    	dd[u] =-3 ;
    	while(dd[after[u]]==-2)
    	{	
    		u =after[u]  ;
    		dd[u] = -3   ; 
    		q.pb(u) ; 
    	}	
    	int cycle= 0 ; 
    	int node= 0 ;
    	for(auto v : q)
    	{
    		if(after[u]==v)
    		{
    			cycle=1 ; 
    		}
    		if(cycle)
    		{
    			dd[v] =1; 
    			node++ ;   
    		}
    		else 
    		{
    			dd[v] = -1 ; 
    		}
    	}
    	for(auto v  : q)
    	{
    		if(dd[v]>0)
    		{
    			sz[v] = node; 
    		}
    	}
    }
    FOR(j,1,LO-1)
    {
    	FOR(i,1,n)
    	{
    		pa[i][j] = pa[pa[i][j-1]][j-1] ; 
    	}
    }
    auto goup = [&](int u ,int dis)
    {
    	FOR(i,0,LO-1)
    	{
    		if(dis>>i&1)
    		{
    			u= pa[u][i] ; 
    		}
    	}
    	return  u ;
    };
    FOR(i,1,n)
    {
    	if(dd[i]==-1&&dd[after[i]]>0)
    	{
    		// cout<<i<<endl;
    		bfs(i);
    	}
    }
    FOR(i,1,n)
    {
    	int u= i ;
    	int x= d[u] ;
    	u =goup(u,x) ;
    	cout<<x+sz[u]<<" ";
    }	
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
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}