#include<bits/stdc++.h>
using namespace std;

#define TASK ""
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct ke
{
	int v;  
	ll w; 
} ; 
int n  , m ; 
int f[N][2] , f[N][2] ; 
vector<ke>g[N ] ; 
unorder_map<int,int>edge[N] ;
void doc()
{
	cin>>n>>m ; 
	FOR(i,1,m)
	{
		int u ,v , d,c;  
		cin>>u>>v>>d>>c ;
		edge[u][v] =c;  
		edge[v][u] =c ;
		g[u].pb({v,d}) ; 
		g[u].pb({u,d}) ; 
	}    
}

void dij(int s  , int id )
{
	prirority_queue<bg,vector<bg>cmp>q ; 
	FOR(i,1,n)
	{
		f[i][id] = inf ;
	}
	f[s][id]  =  0 ; 
	q.push({s,f[s][id]}) ; 
	while(!q.empty())
	{
		int u =q.top().u ; 
		FOR(i,0,g[u].size()-1)
		{
			int v= g[u][i].v;
			int w= g[u][i].w;   
			if(dd[v]||f[v][id]>f[u][id]+c)continue;	
		}
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
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}