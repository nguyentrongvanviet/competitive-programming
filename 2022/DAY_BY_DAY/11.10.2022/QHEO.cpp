#include<bits/stdc++.h>
#define fi "CEDGEDES.INP"
#define fo "CEDGEDES.OUT"
#define ll long long
#define pb push_back
#define FOR(i,a,b) for( int i=a;i<=b;i++)
#define FORN(i,a,b) for( int i=a;i<b;i++)
#define FORG(i,a,b) for( int i=a;i>=b;i--)
using namespace std;
const ll oo=1e16;
const int N=1e6+5;

int n,m,dd[N],tr[N],s,t;
ll d[N],d1[N],dn[N],res=0,C[1005][1005],f[1005][1005];
struct canh{
	int x,y;
	ll w,c;
};
canh c[N];
struct bg{
	int x;
	ll ts;
};
vector<bg> g[N];
vector<int> b[N];
void doc(){
	cin>>n>>m;
	int x,y;ll w,d;
	FOR(i,1,m)cin>>x>>y>>w>>d,g[x].pb({y,w}),g[y].pb({x,w}),c[i]={x,y,w,d};

}
struct cmp{
	bool operator()( bg a, bg b)
	{
		return a.ts>b.ts;
	}
};
void dij(int s, ll d[])
{
	priority_queue<bg, vector<bg> , cmp> h;
	FOR(i,1,n)dd[i]=0,d[i]=oo;
	d[s]=0;
	h.push({s,d[s]});
	while(!h.empty())
	{
		int u=h.top().x;h.pop();
		if(dd[u]==1)continue;
		dd[u]=1;
		FORN(j,0,g[u].size())
		{
			int v=g[u][j].x,cost=g[u][j].ts;
			if(dd[v]==1)continue;
			if(d[v]>d[u]+cost)
			{
				d[v]=d[u]+cost;
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
		FORN(j,0,b[u].size())
		{
		   int v=b[u][j];
			if(dd[v]==1)continue;
			if(C[u][v]-f[u][v]<=0)continue;
			dd[v]=1;
			tr[v]=u;
			q.push(v);
		}
	}
}
int check(int s, int t)
{
	FOR(i,1,n)dd[i]=0;
    bfs(s);
	return dd[t];
}
void xuly()
{
    dij(1,d1);
    dij(n,dn);
    ll cp=d1[n];
    FOR(i,1,m)
    {
    	int x=c[i].x,y=c[i].y;
		ll ts=c[i].w;
    	if(d1[x]+ts+dn[y]==cp||d1[y]+ts+dn[x]==cp)
    	{
    		b[x].pb(y);
    		b[y].pb(x);
    		C[x][y]=c[i].c;
    		C[y][x]=c[i].c;
//    		cout<<x<<" "<<y<<" "<<ts<<" "<<c[i].c<<endl;
		}
	}
//	f[1][4]=0;
//	f[4][1]=0;
//	cout<<check
    int s=1,t=n;
    while(check(s,t))
    {
//    	cout<<check(s,t)<<endl;
    	int v=t;
    	ll mi=oo;
    	while(v!=s)
    	{
    		int u=tr[v];
            mi=min(mi,C[u][v]-f[u][v]);
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
//		cout<<mi<<endl;
		if(mi==oo)break;
		res+=mi;
	}
	cout<<res;
}
int main()
{
// 	freopen( fi, "r" , stdin );
// 	freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	doc();
	xuly();

	return 0;
}