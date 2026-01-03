#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

// --- Dữ liệu Cây & HLD ---
int n, q;
long long init_a[MAXN]; // Mảng A ban đầu
vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int cur_pos;

// --- Dữ liệu Segment Tree ---
// Cần lưu Sum để in kết quả và Max để tối ưu cắt nhánh
long long tree_sum[4 * MAXN];
long long tree_max[4 * MAXN];

// --- PHẦN 1: HLD ---
int dfs_sz(int u, int p) {
    int size = 1;
    int max_sz = 0;
    heavy[u] = -1;
    parent[u] = p;
    depth[u] = depth[p] + 1;
    
    for (int v : adj[u]) {
        if (v != p) {
            int c_sz = dfs_sz(v, u);
            size += c_sz;
            if (c_sz > max_sz) {
                max_sz = c_sz;
                heavy[u] = v;
            }
        }
    }
    return size;
}

void dfs_hld(int u, int h) {
    head[u] = h;
    pos[u] = ++cur_pos; // Gán vị trí trên Segment Tree
    
    if (heavy[u] != -1) {
        dfs_hld(heavy[u], h);
    }
    
    for (int v : adj[u]) {
        if (v != parent[u] && v != heavy[u]) {
            dfs_hld(v, v);
        }
    }
}

// --- PHẦN 2: SEGMENT TREE ---
void build(int node, int l, int r, const vector<long long>& flat_a) {
    if (l == r) {
        tree_sum[node] = flat_a[l];
        tree_max[node] = flat_a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid, flat_a);
    build(2 * node + 1, mid + 1, r, flat_a);
    tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
    tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
}

void update_mod(int node, int l, int r, int ql, int qr, int w) {
    // Optimization: Nếu đoạn này max value < w thì mod w không đổi gì cả -> Bỏ qua
    if (l > qr || r < ql || tree_max[node] < w) return;
    
    if (l == r) {
        tree_sum[node] %= w;
        tree_max[node] %= w;
        return;
    }
    
    int mid = (l + r) / 2;
    update_mod(2 * node, l, mid, ql, qr, w);
    update_mod(2 * node + 1, mid + 1, r, ql, qr, w);
    
    tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
    tree_max[node] = max(tree_max[2 * node], tree_max[2 * node + 1]);
}

// --- PHẦN 3: XỬ LÝ TRUY VẤN HLD ---
void hld_update(int u, int v, int w) {
    while (head[u] != head[v]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        // Update đoạn từ head[v] đến v trên SegTree
        update_mod(1, 1, n, pos[head[v]], pos[v], w);
        v = parent[head[v]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    update_mod(1, 1, n, pos[u], pos[v], w);
}

void solve() {
    if (!(cin >> n >> q)) return;

    for (int i = 1; i <= n; ++i) cin >> init_a[i];

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Xây dựng HLD
    cur_pos = 0;
    dfs_sz(1, 0);
    dfs_hld(1, 1);

    // Map mảng A ban đầu vào vị trí mới trên SegTree
    vector<long long> flat_a(n + 1);
    for (int i = 1; i <= n; ++i) {
        flat_a[pos[i]] = init_a[i];
    }
    
    // Xây dựng SegTree
    build(1, 1, n, flat_a);

    // Xử lý truy vấn
    for (int i = 0; i < q; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        hld_update(x, y, w); // Modulo trên đường đi
        cout << tree_sum[1] << "\n"; // In tổng toàn bộ cây (Root của SegTree lưu tổng [1..N])
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}