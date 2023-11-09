#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define name ""
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
const int base = 1e6 + 5;
int dis[base], inq[base], dd[base];
int n, m, p, on_stack[base], in_queue[base];
vector <ii> adj[base];
int ind, cnt, num[base], low[base], scc[base];
stack<int> st;
queue <int> q;
vector<int> order;
void tarjan(int u){
	num[u] = low[u] = ++ind;
	st.push(u);
	on_stack[u] = 1;
	for (auto [v, w] : adj[u])
		if (num[v] == 0)
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(on_stack[v])
			low[u] = min(low[u], num[v]);
	if (num[u] == low[u])
	{
		++cnt;
		int v;
		do
		{
			v = st.top();
			st.pop();
			on_stack[v] = 0;
			order.push_back(v);
			scc[v] = u;	
		} while (v != u);
	}
}
void segmented_spfa(int N){
	tarjan(0);
	// std::cerr << "Number of SCCs: " << cnt << std::endl;
	dis[0] = 0;
	for(int i = min(N-1, (int)order.size() - 1); i >= 0;){
		int root = scc[order[i]];
		for (; i >= 0 && scc[order[i]] == root; --i){
			if (dis[order[i]] != 1e18)
			{
				q.push(order[i]);
				in_queue[order[i]] = 1;
			}
		}
		while (!q.empty())
		{
			int u = q.front();
			// std::cout << u << " ";
			q.pop();
			in_queue[u] = 0;
			for (auto [v, w] : adj[u])
				if (dis[u] + w < dis[v])
				{
					dis[v] = dis[u] + w;
					if (scc[v] == root && in_queue[v] == 0)
					{
						q.push(v);
						in_queue[v] = 1;
					}
				}
		}
	}
}
struct bg{
	int v, val;
}len[base];
struct cmp{
	bool operator() (bg a, bg b){
		return a.val > b.val;
	}
};
void ditstra(){
	fod(i,0,n-1) len[i].val = 1e18;
	len[0].val = 0;
	priority_queue <bg, vector<bg>, cmp> dq;
	dq.push({0,0});
	while(!dq.empty()){
		bg t = dq.top(); dq.pop();
		int u = t.v, curw = t.val;
		if(dd[u]) continue;
		dd[u] = 1;
		for(auto edge : adj[u]){
			int v = edge.fi, w = edge.se;
			if(len[v].val > curw + w){
				len[v].val = curw + w;
				dq.push({v,len[v].val});
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> m >> p;
	fod(i,1,m){
		int u, v, c; cin >> u >> v >> c;
		u--;
		v--;
		adj[u].pb({v,c});
		adj[v].pb({u,c});
	}
	if(p == 0){
		ditstra();
		fod(i,0,n-1){
			if(len[i].val != 1e18) cout << len[i].val << " ";
			else cout << -1 << " ";
		}
		return 0;
	}
	fod(i,1,p){
		int u,v,c; cin >> u >> v >> c;
		u--;
		v--;
		adj[u].pb({v,c});
		// e[v].pb({u,c});
	}

	fod(i,0,n-1) dis[i] = 1e18;
	segmented_spfa(n);
	fod(i,0,n-1){
		if(dis[i] != 1e18) cout << dis[i] << " ";
		else cout << -1 << " ";
	}
	return 0;
}
