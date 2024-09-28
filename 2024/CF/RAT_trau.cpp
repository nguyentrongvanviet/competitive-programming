#include <bits/stdc++.h>
using namespace std;

#define popcount(n) (__builtin_popcountll((n)))
#define clz(n) (__builtin_clzll((n)))
#define ctz(n) (__builtin_ctzll((n)))
#define lg(n) (63 - __builtin_clzll((n)))
#define BIT(n, i) (((n) >> (i)) & 1ll)
#define MASK(i) (1ll << (i))
#define FLIP(n, i) ((n) ^ (1ll << (i)))
#define ON(n, i) ((n) | MASK(i))
#define OFF(n, i) ((n) & ~MASK(i))

#define Int __int128
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long long, int> pli;
typedef pair<int, long long> pil;
typedef vector<pair<int, int>> vii;
typedef vector<pair<long long, long long>> vll;
typedef vector<pair<long long, int>> vli;
typedef vector<pair<int, long long>> vil;

template <class T1, class T2>
bool maximize(T1 &x, T2 y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
template <class T1, class T2>
bool minimize(T1 &x, T2 y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template <class T>
void remove_duplicate(vector<T> &ve) {
    sort (ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
}

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <class T> T random(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}
template <class T> T random(T r) {
    return rng() % r;
}

const int N = 100 + 5;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;

int n;
int is_cave[N], can_go[N][N], dist[N][N];
int ans[N][N];
vector<int> caves, adj[N];

void solve(int x, int y) {
    // cerr << "solving " << x << ' ' << y << ' ';

    vector<int> X, Y;
    for (auto _x : adj[x]) X.emplace_back(_x);
    for (auto _y : adj[y]) for (auto __y : adj[_y]) Y.emplace_back(__y);

    if (X.empty() && Y.empty()) {
        ans[x][y] = -1;
        return;
    }

    if (X.empty()) X.emplace_back(x);
    if (Y.empty()) Y.emplace_back(y);

    for (auto _x : X) {
        bool flag = true;
        for (auto _y : Y) if (ans[_x][_y] != -1) {
            flag = false;
            break;
        }

        if (flag) {
            ans[x][y] = -1;
            return;
        }
    }

    int ma = -1;
    for (auto _x : X) {
        int mi = inf;
        for (auto _y : Y) if (ans[_x][_y] != -1) minimize(mi, ans[_x][_y]);
        if (mi < inf) maximize(ma, 1 + mi);
        else return;
    }
    ans[x][y] = ma;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    #define taskname "text"
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".ans", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> is_cave[i];
        if (is_cave[i]) caves.emplace_back(i);
    }

    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        cin >> can_go[i][j];
        if (can_go[i][j]) adj[i].emplace_back(j);
    }

    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        if (can_go[i][j]) dist[i][j] = 1;
        else dist[i][j] = inf;
    }

    for (int i = 1; i <= n; ++i) dist[i][i] = 0;
    for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            minimize(dist[i][j], dist[i][k] + dist[k][j]);
    }

    memset(ans, 0x3f, sizeof ans);
    for (int i = 1; i <= n; ++i) ans[i][i] = 0;
    for (auto cave : caves) for (int i = 1; i <= n; ++i) ans[cave][i] = -1;

    for (int _ = 0; _ < n; ++_) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
            if (ans[i][j] > inf) ++cnt, solve(i, j);
        }
        if (cnt == 0) break;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // cout << ans[i][j] << ' ';
            // assert(ans[i][j] <= n);
            cout << (ans[i][j] > inf ? -1 : ans[i][j]) << ' ';
        }
        cout << '\n';
    }
    cerr << '\n'; return 0;
}