#include <bits/stdc++.h>
using namespace std;
#define TASK "gridmst"
const int INF = 1e8;

struct Point {
    int x, y, id;
    int diff_yx() const { return y - x; }
    int sum_xy() const { return x + y; }
};

int manhattan_dist(const Point& u, const Point& v) {
    return abs(u.x - v.x) + abs(u.y - v.y);
}

struct DSU {
    vector<int> par;
    DSU() {}
    DSU(int n): par(n, -1) {}
    
    int find_set(int u) {
        return par[u] < 0 ? u : par[u] = find_set(par[u]);
    }
    
    bool join(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return false;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return true;
    }
};

struct Edge {
    int u, v, cost;
};

bool operator<(const Edge& u, const Edge& v) {
    return u.cost < v.cost;
}

Edge edge_from_point(const Point& u, const Point& v) {
    return {u.id, v.id, manhattan_dist(u, v)};
}

vector<Edge> potential_edges; // Các cạnh tối ưu cần xét
vector<Point> solve_single_recur(vector<Point> p) {
    // for(auto x : p ){cout<<x.x<<" "<<x.y<<" "; cout<<"\n";}
    // cout<<"++++++++\n";
    if (p.size() <= 1){return p;}
    int upper_size = (int)p.size() / 2;
    auto upper = solve_single_recur({p.begin(), p.begin() + upper_size});
    auto lower = solve_single_recur({p.begin() + upper_size, p.end()});
    vector<Point> res;
    
    Point min_diff_yx{0, INF, -1};
    
    int upper_ptr = 0;
    for (auto lo : lower) {
        while (upper_ptr < upper_size and upper[upper_ptr].sum_xy() <= lo.sum_xy()) {
            if (min_diff_yx.diff_yx() > upper[upper_ptr].diff_yx()) {
                min_diff_yx = upper[upper_ptr];
            }
            res.push_back(upper[upper_ptr]);
            ++upper_ptr;
        }
        if (min_diff_yx.id != -1) {
            potential_edges.push_back(edge_from_point(min_diff_yx, lo));
        }
        res.push_back(lo);
    }
    
    res.insert(res.end(), upper.begin() + upper_ptr, upper.end());
    // for(auto x : res)
    // {
    // 	cout<<x.x<<" "<<x.y<<"\n" ; 
    // }
    // cout<<"-----"<<"\n";
    return res;
}

void solve_single(vector<Point> p) { // Giải bài toán với một góc phần tám
    sort(p.begin(), p.end(), [](const Point& u, const Point& v) {
        return u.y == v.y ? u.x < v.x : u.y > v.y;
    });
    solve_single_recur(p);
}

void rotate_90(vector<Point>& p) { // Xoay tất cả các điểm 90 độ
    for (auto& cur: p) {
        int x = cur.x, y = cur.y;
        cur.x = -y;
        cur.y = x;
    }
}
void flip(vector<Point>& p) { // Đối xứng các điểm qua trục Ox
    for (auto& cur: p) {
        cur.y = -cur.y;
    }
}

int solve(vector<Point> p) {
    for (int ft = 0; ft < 2; ++ft) {
        for (int i = 0; i < 4; ++i) {
            solve_single(p);
            rotate_90(p);
        }
        flip(p);
    }

    int ans = 0;
    DSU dsu((int)p.size());
    sort(potential_edges.begin(), potential_edges.end());

    for (const auto& e : potential_edges) {
        if (dsu.join(e.u, e.v)) {
            ans += e.cost;
        }
    }
    // Thuật toán kruskal
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen(TASK".INP","r"))
    {
    	freopen(TASK".INP","r",stdin) ; 
    	freopen(TASK".OUT","w",stdout) ; 
    }
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    solve(p);
    // solve_single(p);
    cout<< "G";
    for(auto x : potential_edges)
    {
        cout<<x.u<<" "<<x.v <<endl;
    }
    // cout << solve(p);
}