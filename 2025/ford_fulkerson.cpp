bool bfs(vector<vector<int>>& resGraph, vector<int>& parent, 
    int s, int t, int V) {
vector<bool> visited(V, false);
queue<int> q;
q.push(s);
visited[s] = true;
parent[s] = -1;

while (!q.empty()) {
   int u = q.front();
   q.pop();

   for (int v = 0; v < V; v++) {
       if (!visited[v] && resGraph[u][v] > 0) {
           if (v == t) {
               parent[v] = u;
               return true;
           }
           q.push(v);
           parent[v] = u;
           visited[v] = true;
       }
   }
}
return false;
}
// Returns maximum flow from s to t in the given graph
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
int V = graph.size();
vector<vector<int>> resGraph = graph; // Residual graph
vector<int> parent(V);
int max_flow = 0;
// Augment the flow while there's path from source to sink
while (bfs(resGraph, parent, s, t, V)) {
   int path_flow = INT_MAX;
   // Find minimum residual capacity of the path
   for (int v = t; v != s; v = parent[v]) {
       int u = parent[v];
       path_flow = min(path_flow, resGraph[u][v]);
   }
   // Update residual capacities and reverse edges
   for (int v = t; v != s; v = parent[v]) {
       int u = parent[v];
       resGraph[u][v] -= path_flow;
       resGraph[v][u] += path_flow;
   }
   max_flow += path_flow;
}
return max_flow;
}