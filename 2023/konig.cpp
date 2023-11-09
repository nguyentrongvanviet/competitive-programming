#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define FOV(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define FOD(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
#define file "FMATCH"
typedef long long ll;
typedef pair<int,int> ii;
const int N=109;
int n,m,dd[N],cur=0,Tr[N];
vector <int> Ke[N];
void read()
{
	cin>>m>>n;
	int u,v;
	while(cin>>u>>v)
	{
		Ke[u].pb(v);
	}
}
int DFS(int u)
{
	if(dd[u]==cur) return 0;
	dd[u]=cur;
	FOV(i,0,Ke[u].size())
	{
		int v=Ke[u][i];
		if(Tr[v]==0 || DFS(Tr[v]))
		{
			Tr[v]=u;
			return 1;
		}
	}
	return 0;
}
void solve()
{
	int res=0;
	for(cur=1;cur<=m;cur++)
	{
		res+=DFS(cur);
	}
	cout<<res<<endl;
	FOR(i,1,n) if(Tr[i]!=0) cout<<Tr[i]<<" "<<i<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//  	freopen(file".inp","r",stdin);
//  	freopen(file".out","w",stdout);
	read();
	solve();
	return 0;
}