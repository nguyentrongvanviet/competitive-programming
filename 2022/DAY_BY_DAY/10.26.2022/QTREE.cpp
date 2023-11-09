#include<bits/stdc++.h>
using namespace std;

#define TASK "QTREE"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =1e4+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;
const int LO  = 18 ;
struct ke 
{
	int v  ; 
	int w ; 
};
int n ; 
vector<ke>g[N];

int tt = 0; 
int sz[N];
int node[N],id[N] ,h[N], pa[N][20] ,head[N];
int a[N];
map<int,int>canh[N];
int st[4*N];
pii q[N];
void predfs(int u , int p)
{
	sz[u] =1 ;
	if(g[u][0].v==p)swap(g[u][0],g[u][g[u].size()-1]);

	for(int i= 0 ;i<g[u].size();i++)
	{
		int v= g[u][i].v;
		if(v==p)continue ;
		h[v]=h[u]+1;
		pa[v][0]=u ; 
		predfs(v,u) ; 
		sz[u]+=sz[v];
		if(sz[v]>sz[g[u][0].v])
		{
			swap(g[u][0],g[u][i]);
		}
	}
}
void doc()
{
 	cin>> n   ; 
	for(int i= 1;i<=n-1;i++)
	{
		int u , v,c ;
		cin>>u>>v>>c ; 
		q[i]={u,v};
		g[u].pb({v,c}) ; 
		g[v].pb({u,c}) ;
		canh[u][v]=canh[v][u]=c; 
	} 	  
}
void HLD(int u , int p)
{
	++tt;  
	id[u]=tt;
	node[tt]=u; 
	if(sz[u]==1)return ;
	head[g[u][0].v]=head[u];
	HLD(g[u][0].v,u);
	for(int i=1;i<g[u].size();i++)
	{
		int v= g[u][i].v ; 
		if(v==p)continue; 
		head[v] =v;
		HLD(v,u);
	} 
}
void build(int id , int l ,int r )
{
	if(l==r)
	{
		st[id] = a[l] ; 
		return ; 
	}
	int mid=(l+r)>>1; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ; 
	st[id] =max(st[id*2],st[id*2+1]) ;
}
int get(int id ,int l ,int r,int t, int p  )
{
	if(t<=l&&r<=p)return st[id]; 
	if(r<t||p<l)return -oo ;
	int mid =(l+r)>>1;
	return max(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p));
}	
void up(int id , int l ,int r ,int pos , int val )
{
	if(l==r&&l==pos)
	{
		st[id] =val; 
		return ; 
	}
	int mid=(l+r)/2; 
	if(pos<=mid)
	{
		up(id*2,l,mid,pos,val) ;  
	}
	else 
	{
		up(id*2+1,mid+1,r,pos,val) ; 
	}
	st[id] =max(st[id*2],st[id*2+1]);
}
void init()
{
	for(int j = 1;j<=LO;j++)
	{
		for(int i = 1 ;i<=n;i++)
		{
			pa[i][j] = pa[pa[i][j-1]][j-1];
		}
	}
	for(int i=1 ;i<=n-1;i++)
	{
		a[i]=canh[node[i]][node[i+1]];
	}
	build(1,1,n-1);
}
int lca(int u , int v)
{
	if(h[u]<h[v])swap(u,v) ; 
	int dis = h[u]-h[v] ; 
	for(int i= 0;i<=LO;i++)
	{
		if(dis>>i&1)
		{
			u=pa[u][i] ; 
		}
	}
	if(u==v)return u ; 
	for(int i =LO;i>=0;i--)
	{
		int nu = pa[u][i]; 
		int nv=  pa[v][i]; 
		if(nu==nv)continue ;
		u=nu ;
		v=nv ;
	}
	return pa[u][0];
}
int query(int x  ,int u )
{
	int ans= -oo;
	while(h[head[u]]>h[x])
	{
		ans=max(ans,get(1,1,n-1,id[head[u]],id[u]-1));
		ans=max(ans,canh[head[u]][pa[head[u]][0]]);
		u=pa[head[u]][0];
	}
	ans=max(ans,get(1,1,n-1,id[x],id[u]-1));
	return ans ;
}	
void xuly()
{
	string tmp ; 
	while(cin>>tmp)
	{
		if(tmp=="DONE")return ; 
		if(tmp=="QUERY")
		{
			int u ,v ; cin>>u>>v ; 
			int x= lca(u,v) ;
			int res=max(query(x,u),query(x,v));
			cout<<res<<"\n";
		}
		else
		{
			int b , c ; 
			cin>> b  >> c;
			int u = q[b].fi;  
			int v= q[b].se; 
			canh[u][v]=c; 
			canh[v][u]=c;
			if(h[u]<h[v])swap(u,v); 
			if(id[v]+1==id[u])up(1,1,n-1,id[v],c);
		}
	}
}
void clear()
{
	for(int i=1 ;i<=n;i++)
	{
		for(int j=0;j<=LO;j++)
		{
			pa[i][j] = 0 ;
		}
		g[i].clear();
		h[i]=0;
		sz[i] =0;
		head[i] = 0;
		node[i]=0;
		a[i] = 0 ;
		canh[i].clear();
		id[i]=0;
		tt= 0;
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
    cin>>t;
    while(t--)
    {
        doc();
        predfs(1,0);
        HLD(1,0);
        init();
        xuly();
        clear();
    }
    return 0;
}
