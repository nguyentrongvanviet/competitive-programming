#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

const int N = 5e5 + 10;
const long long INF = 1e17 + 7;

int a, b, c, d, e;
int n;
vector<pair<int, int>> adj[N];
vector<long long> distA, distB, distC;

void Dijkstra(int src, vector<long long> &d, int n){
    d = vector<long long>(n + 10, INF); 
    d[src] = 0;  
    priority_queue<pair<long long , int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
    Q.push(make_pair(d[src], src));
    while(!Q.empty()){
        pair<long long, int> p = Q.top(); Q.pop();
        long long du = p.first;
        int u = p.second;
        if(du != d[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first, w = adj[u][i].second;
            if(d[v] > du + w){
                d[v] = du + w;
                Q.push(make_pair(d[v], v));
            }
        }
    }
}

void solve(){
    cin >> a >> b >> c >> d >> e;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(make_pair(v + 1, v - u + 1));
        adj[v + 1].push_back(make_pair(u, v - u + 1));
    }
    int N = a + b + c + d + e;
    Dijkstra(a + 1, distA, N);
    Dijkstra(a + b + 1, distB, N);
    Dijkstra(a + b + c + 1, distC, N);
    long long ans = INF;
    ans = min(ans, distA[a + b + 1] + distC[a + b + c + d + 1]);
    ans = min(ans, distA[a + b + c + 1] + distB[a + b + c + d + 1]);
    ans = min(ans, distA[a + b + c + d + 1] + distB[a + b + c + 1]);
    if(ans == INF) ans = -1;
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}