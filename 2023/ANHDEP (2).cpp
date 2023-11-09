#include<bits/stdc++.h>
#define forin(i, a, b) for(int i = a; i <= b; i++)
#define forde(i, a, b) for(int i = a; i >= b; i--)
#define forv(a, b) for(auto & a : b)
#define fi first
#define se second
#define ii pair<int, int>
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int b[N], c[N];
vector<vector<int>> a;
vector<int> v;
 struct node {
    node * left;
    node * right;
    int last, cnt;
    node () {
        left = right = nullptr;
        last = cnt = 0;
    }
    void build(int l, int r) {
        if (l == r) {
            last = b[l]; cnt = c[l];
            return;
        }
        int mid = l + r >> 1;
        if (!left) left = new node();
        if (!right) right = new node();
        left -> build(l, mid);
        right -> build(mid + 1, r);
        if (left -> last == right -> last) {
            last = left -> last;
            cnt = left -> cnt + right -> cnt;
        }
        else {
            if (left -> cnt > right -> cnt) last = left -> last, cnt = left -> cnt - right -> cnt;
            else if (right -> cnt > left -> cnt) last = right -> last, cnt = right -> cnt - left -> cnt;
            else last = 0, cnt = 0;
        }
    }
    pair<int, int> get(int l, int r, int from, int to) {
        if (l > to || r < from) return make_pair(0, 0);
        if (from <= l && r <= to) return make_pair(last, cnt);
        int mid = l + r >> 1;
        pair<int, int> ret1 = left -> get(l, mid, from, to), ret2 = right -> get(mid + 1, r, from, to);
        if (ret1.fi == ret2.fi) return make_pair(ret1.fi, ret1.se + ret2.se);
        if (ret1.se > ret2.se) return make_pair(ret1.fi, ret1.se - ret2.se);
        else if (ret2.se > ret1.se) return make_pair(ret2.fi, ret2.se - ret1.se);
        else return make_pair(0, 0);
    }
 };
 vector<node> tree;
struct BIT {
    vector<int> s;
    vector<int> bit;
    int sz;
    void up(int pos, int val) {
        pos = upper_bound(s.begin(), s.end(), pos) - s.begin();
        while (pos <= sz) {
            bit[pos] += val;
            pos += pos & -pos;
        }
    }
    int get(int pos) {
        pos = upper_bound(s.begin(), s.end(), pos) - s.begin();
        int ret = 0;
        while (pos) {
            ret += bit[pos];
            pos -= pos & -pos;
        }
        return ret;
    }
    int getsum (int l, int r) {
        return get(r) - get(l - 1);
    }
} cnt[N];
int main() {
    freopen("ANHDEP.INP", "r", stdin);
    freopen("ANHDEP.OUT", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int m, n; cin >> m >> n;
    int h, w; cin >> h >> w;
    a = vector<vector<int>> (m + 2, vector<int> (n + 2));
    tree.resize(m + 1);
    for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) cin >> a[i][j], v.push_back(a[i][j]);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) {
        a[i][j] = upper_bound(v.begin(), v.end(), a[i][j]) - v.begin();
        cnt[a[i][j]].s.push_back(i);
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) b[j] = a[i][j], c[j] = 1;
        tree[i].build(1, n);
    }
    for(int i = 1; i <= v.size(); i++) {
        sort(cnt[i].s.begin(), cnt[i].s.end());
        cnt[i].s.resize(unique(cnt[i].s.begin(), cnt[i].s.end()) - cnt[i].s.begin());
        cnt[i].sz = cnt[i].s.size();
        cnt[i].bit.resize(cnt[i].sz + 1);
    }
    int res = 0;
    for(int j = 1; j < w; j++) for(int i = 1; i <= m; i++) cnt[a[i][j]].up(i, 1);
    for(int j = w; j <= n; j++) {
        for(int i = 1; i <= m; i++) {
            tie(b[i], c[i]) = tree[i].get(1, n, j - w + 1, j);
            cnt[a[i][j]].up(i, 1);
            if (j > w) cnt[a[i][j - w]].up(i, -1);
        }
        tree[0].build(1, m);
        for(int i = h; i <= m; i++) {
            int x = tree[0].get(1, m, i - h + 1, i).first;
            if (!x) res++;
            else {
                if (2 * cnt[x].getsum(i - h + 1, i) <= h * w) res++;
            }
        }
    }
    cout << res;
}

