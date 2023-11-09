#include<bits/stdc++.h>
using namespace std;

#define TASK "vungdatmoi"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#define all(a) a.begin(),a.end()
const int N =5e5+5e4+100 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct  Q 
{
	int t; 
	int u , v;  
}; 
int n , m , q; 
vector<int>g[N] ; 
Q query[N];  
void doc()
{
    cin>> n >> m;  
    FOR(i,1,m)
    {
    	int u ,v ; 
    	cin>>u>>v ; 
    	g[u].pb(v) ; 
    }
   	cin>>q ; 
   	FOR(i,1,q)
   	{
   		cin>>query[i].t>>query[i].u>>query[i].v ;
   		if(query[i].t==1)
   		{
   			int u = query[i].u ; 
   			int a = query[i].v ; 
   			if(a==0)
   			{
   				g[u].pb(++n) ;
   			}
   			else 
   			{
   				g[++n].pb(u); 
   			}
   		}	 
   	}
}
int tplt =  0;  
int tt = 0 ;
int id[N] , low[N] ; 
stack<int>st ; 
int dd[N] ; 
void dfs(int u )
{
	st.push(u) ; 
	id[u] = low[u] =++tt;
	for(auto v :g[u])
	{
		if(dd[v])continue ; 
		if(id[v])
		{
			low[u] = min(low[u],id[v]) ;  
		}
		else 
		{
			dfs(v) ; 
			low[u] = min(low[u],low[v]); 
		}
	} 
	if(low[u]==id[u])
	{
		int t ; 
		++tplt ; 
		do
		{
			t=st.top() ; 
			st.pop() ; 
			dd[t]=tplt ; 
		}while(t!=u);
	}
}
vector<int>adj[N] ; 
int d[N] ; 
bitset<50005>able[50005]; 
void dfs1(int u  )
{
	if(d[u])return ; 
	d[u]=1 ; 
	able[u].set(u,1);
	for(int v : adj[u])
	{	
		dfs1(v) ; 
		able[u]|=able[v] ; 
	}
}
bool res[N] ; 	
void xuly()
{

	for(int i= 1;i<=n;i++)if(id[i]==0)dfs(i) ; 
	for(int u=1;u<=n;u++)
	{
		for(int v :g[u])
		{
			if(dd[v]!=dd[u])
			{
				adj[dd[u]].pb(dd[v]) ;
			}
		}
	}
	for(int i=1 ;i<=tplt;i++)
	{
		dfs1(i) ; 
	}
	for(int i= q;i>=1;i--)
	{	
		if(query[i].t==1)
		{
			n-- ; 
		}
		else 
		{
			int u = query[i].u ; 
			int v = query[i].v ; 
			if(u>n||v>n)continue;
			res[i] = able[dd[u]].test(dd[v]);
		}
	}	
	for(int i=1 ;i<=q;i++)if(query[i].t==2)cout<<(res[i]?"Yes":"No")<<"\n" ;
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