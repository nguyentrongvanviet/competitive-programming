#include<bits/stdc++.h>
using namespace std;

#define TASK "Reachability_query"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=(int)a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
const int N =5e4+5 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct Q 
{
	int u ,v ; 
};
int n , m , q  ; 
vector<int>g[N] ; 
Q query[N*10] ;

int tt= 0  , tplt = 0 ;
int dd[N] , low[N] ,id[N] ;   
stack<int>st ;

vector<int>adj[N] ;
int d[N] ; 
bitset<N>able[N] ; 
 
void doc()
{	
    cin>>n>>m>>q;  
    FOR(i,1,m)
    {
    	int u , v; cin>>u>>v ; 
    	g[u].pb(v) ; 
    }
    FOR(i,1,q)
    {
    	cin>>query[i].u>>query[i].v ; 
    }
}
void predfs(int u )
{
	st.push(u) ; 
	low[u] = id[u] =++tt; 
	FOR(i,0,(int)g[u].size()-1)
	{
		int v= g[u][i] ; 
		if(dd[v])continue ; 
		if(id[v])
		{
			low[u] = min(low[u],id[v]) ; 
		}
		else 
		{
			predfs(v) ; 
			low[u] =min(low[u],low[v]) ;
		}
	}
	if(low[u]==id[u])
	{
		int t; 
		tplt++;
		do
		{
			t=st.top() ; 
			st.pop() ; 
			dd[t] =tplt; 
		}while(t!=u);
	}
}
void dfs(int u   )
{
	if(d[u])return ;
	d[u] =1 ;
	able[u].set(u,1) ; 
	FOR(i,0,(int)adj[u].size()-1)
	{
		int v= adj[u][i];
		dfs(v) ;
		able[u]|=able[v]; 
	}
}
void xuly()
{
	FOR(i,1,n)if(dd[i]==0)predfs(i);
	FOR(u,1,n)FOR(i,0,(int)g[u].size()-1)
	{
		int v =g[u][i] ; 
		if(dd[u]!=dd[v])
		{
			adj[dd[u]].pb(dd[v]);
		}
	}
	FOR(i,1,tplt)
	{
		dfs(i);
	}
	FOR(i,1,q)
	{
		int u =query[i].u ;
		int v =query[i].v ;
		if(able[dd[u]].test(dd[v]))cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
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
        xuly();
    }
    return 0;
}