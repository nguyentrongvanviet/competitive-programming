#include<bits/stdc++.h>
#define fi "QTREEX.INP"
#define fo "QTREEX.OUT"
#define ll long long
#define pb push_back
#define FOR(i,a,b) for( int i=a;i<=b;i++)
#define FORN(i,a,b) for( int i=a;i<b;i++)
#define FORG(i,a,b) for( int i=a;i>=b;i--)
using namespace std;
const int oo=1e9;
const int N=1e5+5;

int n,s[N],p[N],deep[N],head[N],pos[N],id,E[N],d[4*N];
vector<int> g[N];
struct IT{
	int mi,ma;
};
IT t[4*N];
struct bg{
	int x,y,w;
};
bg c[N];
void doc(){
    cin>>n;
    FOR(i,1,n)g[i].clear();
    int x,y,w;
    FOR(i,1,n-1)cin>>x>>y>>w,g[x].pb(y),g[y].pb(x),c[i]={x,y,w};
    
}
void dfs(int u, int cha)
{
	s[u]=1;
	int smax=0,jmax=0;
	
	FORN(j,0,g[u].size())
	{
		int v=g[u][j];
		if(v!=cha)
		{
			p[v]=u;
			dfs(v,u);
			if(smax<s[v])smax=s[v],jmax=j;
			s[u]+=s[v];
		}
	}
	swap(g[u][0],g[u][jmax]);
}
void hld(int u, int cha)
{
	pos[u]=++id;
	
	FORN(j,0,g[u].size())
	{
		int v=g[u][j];
		if(v!=cha)
		{
			if(s[v]*2>=s[u])head[v]=head[u],deep[v]=deep[u];
			else head[v]=v,deep[v]=deep[u]+1;
			hld(v,u);
		}
	}
}
void QHDHLD()
{
	id=0;p[1]=1;head[1]=1;deep[1]=1;
	dfs(1,0);
	hld(1,0);
	
}
int get(int k, int l, int r, int u, int v)
{
	if(d[k]==1)
	{
		d[2*k]=!d[2*k];
		d[2*k+1]=!d[2*k+1];
		int mi=t[k].mi;
		int ma=t[k].ma;
		t[k].mi=-ma;
		t[k].ma=-mi;
		d[k]=0;
	}
	if(r<u||v<l)return -oo;
	if(u<=l&&r<=v)return t[k].ma;
	int mid=(l+r)>>1;
	return max(get(2*k,l,mid,u,v),get(2*k+1,mid+1,r,u,v));
}
void update(int k, int l, int r, int u, int v, int value)
{
	if(d[k]==1)
	{
		d[2*k]=!d[2*k];
		d[2*k+1]=!d[2*k+1];
		int mi=t[k].mi;
		int ma=t[k].ma;
		t[k].mi=-ma;
		t[k].ma=-mi;
		d[k]=0;
	}
	if(r<u||v<l)return;
	if(u<=l&&r<=v)
	{
		t[k].mi=t[k].ma=value;
		return;
	}
	int mid=(l+r)>>1;
	update(2*k,l,mid,u,v,value);
	update(2*k+1,mid+1,r,u,v,value);
	
	t[k].mi=min(t[2*k].mi,t[2*k+1].mi);
	t[k].ma=max(t[2*k].ma,t[2*k+1].ma);
}
void daodau(int k, int l, int r, int u, int v)
{
	if(d[k]==1)
	{
		d[2*k]=!d[2*k];
		d[2*k+1]=!d[2*k+1];
        int mi=t[k].mi;
        int ma=t[k].ma;
        t[k].ma=-mi;
        t[k].mi=-ma;
        d[k]=0;
	}
	if(r<u||v<l)return;
	if(u<=l&&r<=v)
	{
		int mi=t[k].mi;
		int ma=t[k].ma;
		t[k].ma=-mi;
		t[k].mi=-ma;
		d[2*k]=!d[2*k];
		d[2*k+1]=!d[2*k+1];
		return;
	}
	int mid=(l+r)>>1;
	daodau(2*k,l,mid,u,v);
	daodau(2*k+1,mid+1,r,u,v);
	
	t[k].mi=min(t[2*k].mi,t[2*k+1].mi);
	t[k].ma=max(t[2*k].ma,t[2*k+1].ma);
	
}
void negative(int u, int v)
{
	if(deep[u]<deep[v])swap(u,v);
	while(deep[u]>deep[v])
	{
		daodau(1,1,n,pos[head[u]]+1,pos[u]);
		u=head[u];
		E[u]=-E[u];
		u=p[u];
	}
	while(head[u]!=head[v])
	{
		daodau(1,1,n,pos[head[u]]+1,pos[u]);
		u=head[u];
		E[u]=-E[u];
		u=p[u];
		daodau(1,1,n,pos[head[v]]+1,pos[v]);
		v=head[v];
		E[v]=-E[v];
		v=p[v];
	}
	if(pos[u]<pos[v])daodau(1,1,n,pos[u]+1,pos[v]);
	else daodau(1,1,n,pos[v]+1,pos[u]);
	
}
int query(int u, int v)
{
    int ans=-oo;
	if(deep[u]<deep[v])swap(u,v);
	while(deep[u]>deep[v])
	{
	   ans=max(ans,get(1,1,n,pos[head[u]]+1,pos[u]));
	   u=head[u];
	   ans=max(ans,E[u]);
	   u=p[u];
	}
	while(head[u]!=head[v])
	{
	   ans=max(ans,get(1,1,n,pos[head[u]]+1,pos[u]));
	   u=head[u];
	   ans=max(ans,E[u]);
	   u=p[u];
	   ans=max(ans,get(1,1,n,pos[head[v]]+1,pos[v]));
	   v=head[v];
	   ans=max(ans,E[v]);
	   v=p[v];	   	
	}
	if(pos[u]<pos[v])ans=max(ans,get(1,1,n,pos[u]+1,pos[v]));
	else ans=max(ans,get(1,1,n,pos[v]+1,pos[u]));
	
	return ans;	
}
void xuly()
{
    QHDHLD();
    FOR(i,1,n-1)
    {
    	int u=c[i].x, v=c[i].y,cost=c[i].w;
    	if(p[u]==v)swap(u,v);
    	if(deep[u]==deep[v])update(1,1,n,pos[u]+1,pos[u]+1,cost);
    	else E[v]=cost;
	}
	while(1)
	{
		string k;
		cin>>k;
		if(k[0]=='C')
		{
			int id,value;
			cin>>id>>value;
			int u=c[id].x, v=c[id].y ;
		    if(p[u]==v)swap(u,v);
		    if(deep[u]==deep[v])update(1,1,n,pos[u]+1,pos[u]+1,value);
		    else E[v]=value;
		}
		if(k[0]=='N')
		{
			int u,v;
			cin>>u>>v;
			negative(u,v);
		}
		if(k[0]=='Q')
		{
			int u, v;
			cin>>u>>v;
			if(u==v)cout<<'0'<<'\n';
			else cout<<query(u,v)<<'\n';
		}
		if(k[0]=='D')break;
	}
}
int main()
{
 	freopen( fi, "r" , stdin );
 	freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int test;
    cin>>test;
    while(test--)
	{
	doc();
	xuly();
    }
	return 0;
}