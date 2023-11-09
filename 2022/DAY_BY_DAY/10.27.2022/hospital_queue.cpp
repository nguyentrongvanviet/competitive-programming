#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[y - 1].push_back(x - 1);
    }

    vector<int> ans(n, -1);
    for (int s = 0; s < n; ++s) 
    {
        vector<int> deg(n);
        
        for (int j : g[i]) ++deg[j];
        
        priority_queue<pair<int, int>> q;

        for (int v = 0; v < n; ++v) if (deg[v] == 0 && v != s)q.push({a[v], v});

        for (int i = n; i > 0; --i) 
        {
            if (q.empty() || q.top().first < i) 
            {
                if (deg[s] == 0 && i <= a[s]) ans[s] = i;
                
                break;
            }
            
            int v = q.top().second;
            q.pop();
            
            for (int u : g[v]) 
            {
                --deg[u];
                
                if (deg[u] == 0 && u != s) q.push({a[u], u});
            }
        }
    }

    for (int &x : ans) cout << x << ' ';
}