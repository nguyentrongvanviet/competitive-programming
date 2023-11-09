#include<bits/stdc++.h>
using namespace std;

#define TASK "B"
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;
const int LO = 20 ;
struct e
{
	int u , v,  c; 
	bool operator<(const e& a )const
	{
		return c>a.c;
	}
};	
struct ke 
{
	int v , w; 
};
int n , m ;
map<int,int>gt[N];
vector<e>q;  
e edge[N]  ; 
int truyvan ;
int h[N] ;
e bandau[N]  ;
vector<ke>g[N] ; 
int p[N]; 
int pa[N][LO] ; 
int mi[N][LO];
int goc(int u )
{
	return (p[u]==u?u:p[u]=goc(p[u]));
} 
void hop(int u ,int v )
{
	p[u] = v;  
}
int lca(int  u ,int v )
{
	int ans = oo ; 
	if(h[u]<h[v])swap(u,v);  
	int  dis=  h[u]-h[v] ;
	for(int i= 0 ;i<=18;i++)
	{
		if(dis>>i&1)
		{
			ans= min(ans,mi[u][i]) ; 
			u=pa[u][i] ; 
		}
	} 	
	if(u==v)return ans; 
	for(int i =18;i>=0;i--)
	{
		int nu = pa[u][i] ; 
		int nv=  pa[v][i] ; 
		if(nu!=nv)
		{
			ans= min({ans,mi[u][i],mi[v][i]});
			u=nu ; 
			v=nv ;
		}
	}
	return min({ans,mi[u][0],mi[v][0]});
}
void dfs(int u , int p )
{
	for(int i =0 ;i<g[u].size();i++)
	{
		int v =g[u][i].v ; 
		if(v==p)continue ; 
		h[v] =h[u]+1;
		pa[v][0] = u  ; 
		mi[i][0] = g[u][i].w ; 
	}
}
void doc()
{
    cin>> n >>m>>truyvan ;  
    for(int i =1 ;i<=m;i++)
    {
    	int u , v , c;  
    	cin>>u>>v>>c ; 
    	bandau[i]={u,v,c}  ; 
    	edge[i]= {u,v,c} ;
    	gt[u][v]=gt[v][u]=c;  
    } 
   	sort(edge+1,edge+n+1); 
   	for(int i=1;i<=n-1;i++)
   	{
   		q.pb(edge[i]) ; 	
   	}
   	while(truyvan--)
   	{
   		char c; 
   		cin>>c;  
   		if(c=='C') 
   		{
   			int id  , x ; 
   			cin>>id>>x;  
   			int u =  bandau[id].u ; 
   			int v= bandau[id].v ;
   			gt[u][v]=gt[v][u] = x; 
   			q.pb({u,v,x}) ; 
   		}
   		else 
   		{	
   			int  u , v , w ; 
   			cin>>u>>v>>w; 
   			for(int i= 1 ;i<=n;i++)
   			{
   				p[i]=i  ; 
   				g[i].clear();
   				h[i] =  0 ;
   				for(int j= 0 ;j<=18;j++)
   				{
   					pa[i][j] = 0 ; 
   				}
   			}
   			for(int i= 0 ; i<q.size();i++)
   			{
   				int u  = q[i].u ; 
   				int v  = q[i].v ; 
   				int c=  q[i].c;  
   				if(gt[u][v]!=c)continue ; 
   				int chau = goc(u) ; 
   				int chav = goc(v) ; 
   				if(chau==chav)continue; 
   				g[u].pb({v,c}) ; 
   				g[v].pb({u,c}) ; 
   				p[chau]=chav;  
   			}
   			dfs(1,0) ; 
   			for(int j = 1;j<=18;j++)
   			{
   				for(int i= 1 ;i<=n;i++)
   				{
   					pa[i][j] =  pa[pa[i][j-1]][j-1] ; 
   					mi[i][j] =  min(mi[i][j-1],mi[pa[i][j-1]][j-1]); 
   				}
   			}
   			int x = lca(u,v) ; 
   			if(x<w)
   			{
   				cout<<"NO"<<"\n";
   			}
   			else 
   			{
   				cout<<"YES"<<"\n";
   			}
   		}	
   	}
}	
void init()
{

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