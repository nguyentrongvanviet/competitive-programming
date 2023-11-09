/*

	author: Nguyen Vo Tan Duy
	solu:

*/
#include<bits/stdc++.h>
using namespace std;
#define TASK "test1"
#define fi first
#define se second
#define ll long long
#define pb push_back
#define el '\n'

const double pi=acos(-1);
ll sq(ll a){return (ll)a*a;}
struct point{ll x, y;};

struct bg {ll id, t, gt;};

const ll sz=5e3+2; 
const ll szz=1e6+10; 
const ll MOD=1e9+7;
const ll oo=1e18;

ll n, m, c[sz], d[sz], dd[sz][sz], f[sz][sz], res=oo;
vector<int> g[sz];
struct cmp
{
	bool operator()(bg a, bg b)
	{
		return a.gt>b.gt;
	}
};

void Dijkstra()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			f[i][j]=oo;dd[i][j]=0;
		}
	}
	priority_queue<bg, vector<bg>, cmp> h;
	h.push({1,d[1],c[1]});
	f[1][d[1]]=c[1];
	while(!h.empty())
	{
		int u=h.top().id;
		int t=h.top().t;
		h.pop();
		if(dd[u][t]) continue;
		dd[u][t]=1;
		if(f[u][d[u]] > f[u][t]+c[u])
		{
			f[u][d[u]]=f[u][t]+c[u];
			h.push({u, d[u], f[u][d[u]]});
		}
		for(auto v: g[u])
		{
			if(f[v][t-1]> f[u][t]) 
			{
				f[v][t-1]=f[u][t];
				h.push({v, t-1, f[v][t-1]});
			}
		}
	}
}

void doc()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	Dijkstra();
	for(int i=0; i<=n;i++)
	{
		res=min(res, f[n][i]);
	}
	cout<<res<<el;
}

signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	if(fopen(TASK".INP","r")){
		freopen(TASK".INP","r",stdin);
		freopen(TASK".OUT","w",stdout);
	}

	int test;
	test=1;
	//cin>>test;

	while(test--)
	{
		doc();
	}
	// cout<<"\nTime: "<<clock()/(double)1000<<" sec\n";
	return 0;
}