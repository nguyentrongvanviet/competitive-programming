#include<bits/stdc++.h>
#define fi "nkflow.INP"
#define fo "nkflow.OUT"
#define ll long long
#define pb push_back
#define FOR(i,a,b) for( int i=a;i<=b;i++)
#define FORN(i,a,b) for( int i=a;i<b;i++)
#define FORG(i,a,b) for( int i=a;i>=b;i--)
using namespace std;
const int oo=1e9;
const int N=1e3+5;

int n,m,s,t,a[N][N],f[N][N],c[N][N],dd[N],tr[N],d[N];
vector<int> g[N];
void doc(){
	cin>>n>>m>>s>>t;
	FOR(i,1,n)
	FOR(j,1,n)f[i][j]=c[i][j]=0;	
	FOR(i,1,m)
	{
		int u,v; ll w;
		cin>>u>>v>>w;
		g[u].pb(v);
		g[v].pb(u);
		c[u][v]=w;
	}
}
void dfs(int u)
{
	dd[u]=1;
	FOR(v,1,n)
	if(v!=u)
	{
		if(!dd[v]&&c[u][v]-f[u][v]>0)tr[v]=u,dfs(v);
	}
}
struct bg{
	int x,ts;
};
struct cmp{
	bool operator()(bg a, bg b)
	{
		return a.ts<b.ts;
	}
};
void dij(int s)
{
	priority_queue< bg, vector<bg> , cmp> h;
	FOR(i,1,n)dd[i]=0,d[i]=-oo;
	d[s]=oo;
	h.push({s,d[s]});
	while(!h.empty())
	{
		int u=h.top().x;h.pop();
		if(dd[u]==1)continue;
		dd[u]=1;
        FORN(j,0,g[u].size())
        {
        	int v=g[u][j];
        	if(dd[v]==1)continue;
        	if(c[u][v]-f[u][v]<=0)continue;
        	if(d[v]<min(d[u],c[u][v]-f[u][v]))
        	{
        		d[v]=min(d[u],c[u][v]-f[u][v]);
        		tr[v]=u;
        		h.push({v,d[v]});
			}
		}
	}
}
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	dd[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		FOR(v,1,n)
		if(v!=u)
		{
			if(dd[v]==1)continue;
			if(c[u][v]-f[u][v]<=0)continue;
			dd[v]=1;
			tr[v]=u;
			q.push(v);
		}
	}
}
int check(int s, int t)
{
	FOR(i,1,n)dd[i]=0;
//	dfs(s);
    dij(s);
//    bfs(s);
	return dd[t];
}
void xuly()
{
	ll res=0;
    while(!!check(s,t))
    {
    	int v=t;
    	int mi=oo;
    	while(v!=s)
    	{
    		int u=tr[v];
            mi=min(mi,c[u][v]-f[u][v]);
    		v=u;
		}
    	v=t;
    	while(v!=s)
    	{
    		int u=tr[v];
    		f[u][v]+=mi;
    		f[v][u]-=mi;
    		v=u;
		}
		res+=mi;
	}
	cout<<res;
}
int main()
{
//  	freopen( fi, "r" , stdin );
//  	freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	doc();
	xuly();

	return 0;
}