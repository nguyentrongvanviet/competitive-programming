// Cao Quang Hung
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<long long , long long>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define FOR(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define dem(x) __builtin_popcount(x)
#define Mask(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define ln '\n'
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
///mt19937 rnd(time(0));

const int INF = 1e9 , mod = 1e9 + 7;

template <class T1, class T2>
inline T1 mul(T1& x, const T2 &k){ return x = (1LL * x * k) % mod; }

template <class T1 , class T2>
inline T1 pw(T1 x, T2 k){T1 res = 1; for (; k ; k >>= 1){ if (k & 1) mul(res, x); mul(x, x); } return res;}

template <class T>
inline bool minimize(T &x, const T &y){ if (x > y){x = y; return 1;} return 0; }

template <class T>
inline bool maximize(T &x, const T &y){ if (x < y){x = y; return 1;} return 0; }

template <class T>
inline void add(T &x , const T &y){ if ((x += y) >= mod) x -= mod; }

template <class T>
inline T product (const T &x , const T &y) { return 1LL * x * y % mod; }

#define PROB "iii"
void file(){
    // if(fopen(PROB".inp", "r")){
    //     freopen(PROB".inp","r",stdin);
    //     freopen(PROB".out","w",stdout);
    // }
}
void sinh_(){
//    srand(time(0));
//    freopen(PROB".inp" , "w" , stdout);
//    int n;
}



typedef long long ll;
typedef double db;
const int N = 80000 + 5;
const int M = 350000 + 5;

int numNode = 0;
int n, m, subtask;
int num[N], low[N], timeDfs;
int scc, idx[N], s[N], sz[N];
vector<int> Scc[N];
pii edge[M], ans[M];
bool used[M];
vi adj[N], g[N];
ll Res, Ans;

struct tree_edge{
    int u, v, id;
    tree_edge(int _u = 0, int _v = 0, int _id = 0) {
        u = _u, v = _v, id = _id;
    }
} TreeEdge[M];
int numTreeEdge;
 
int Oth(int x, int id) {
    return x ^ TreeEdge[id].u ^ TreeEdge[id].v;
}
int other(int x, int id) {
    return x ^ edge[id].first ^ edge[id].second;
}

void readip(){
    cin >> n >> m;
    REP(i, 1, n) adj[i].clear(), g[i].clear(), num[i] = low[i] = 0;
    REP(i, 1, m) {
        cin >> edge[i].first >> edge[i].se;
        adj[edge[i].first].eb(i);
        adj[edge[i].second].eb(i);
        ans[i] = edge[i];
        used[i] = 0;
    }
    numNode = 0;
    timeDfs = 0;
    scc = 0;
    Ans = Res = 0;
    numTreeEdge = 0;
}

vector<int> st;
void dfs(int u) {
    ++numNode;
    st.pb(u);
    num[u] = low[u] = ++timeDfs;
    for (int id : adj[u]) {
        if (used[id]) continue;
        used[id] = true;

        int v = other(u, id);
        ans[id] = mp(u, v);
        if (num[v]) minimize(low[u], num[v]);
        else {
            dfs(v);
            minimize(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        ++scc;
        Scc[scc].clear();
        int x(-1);
        int cnt(0);
        do {
            ++cnt;
            x = st.back();
            Scc[scc].pb(x);
            idx[x] = scc;
            st.pop_back();
        } while(x != u);

        Ans += 1LL * cnt * (cnt - 1);
        s[scc] = cnt;
    }
}
 

#define IN 0
#define OUT 1

void FINDANS(int u, int p, int dir) {
    for (int id : g[u]) {
        int v = Oth(u, id);
        if (v == p) continue;

        int ID = TreeEdge[id].id;
        ans[ID] = edge[ID];

        if (dir == IN) {
            if (idx[ans[ID].first] != v)
                swap(ans[ID].first, ans[ID].second);
        }
        else {
            if (idx[ans[ID].first] == v)
                swap(ans[ID].first, ans[ID].second);
        }
        FINDANS(v, u, dir);
    }
}



void prepare(int root) {
    st.clear();
    REP(i, 1, scc) {
        Scc[i].clear();
        g[i].clear();
    }
    numNode = 0;
    numTreeEdge = timeDfs = scc = 0;
    Res = 0;
    dfs(root);

    REP(i, 1, scc) {
        for (int u : Scc[i])
        for (int id : adj[u]) {
            int v = other(u, id);
            if (idx[v] > i) {
                TreeEdge[++numTreeEdge] = tree_edge(i, idx[v], id);
                g[i].eb(numTreeEdge);
                g[idx[v]].eb(numTreeEdge);
            }
        }
    }
}


void dfs1(int u, int p) {
    sz[u] = s[u];
    for (int id : g[u]) {
        int v = Oth(u, id);
        if (v == p) continue;
        dfs1(v, u);
        Res += 1LL * sz[v] * s[u];
        sz[u] += sz[v];
    }
}

int Find_centroid(int u, int p) {
    for (int id : g[u]) {
        int v = Oth(u, id);
        if (v == p) continue;
        if (sz[v] * 2 >= numNode)
            return Find_centroid(v, u);
    }
    return u;
}

void solve() {
    REP(xx, 1, n) if (!num[xx]) {
        prepare(xx);

        dfs1(1, -1);
        int root = Find_centroid(1, -1);

        Res = 0;
        dfs1(root, -1);

        vector<int> f;
        vpii G;
        for (int id : g[root]) {
            int v = Oth(root, id);
            f.eb(sz[v]);
        }
        sort(ALL(f));

        FOR(i, f.size()) {
            int j = i;
            while(j < f.size() && f[i] == f[j]) ++j; --j;
            int cnt = j - i + 1;
            int x = 1;
            while(x <= cnt) {
                G.eb(x * f[i], f[i]);
                cnt -= x;
                x <<= 1;
            }
            if (cnt) G.eb(cnt * f[i], f[i]);
            i = j;
        }

        int Sz = G.size();
        vector<vector<bool>> dp(Sz + 2, vector<bool> ((numNode - s[root] + 1) / 2 + 2 , 0));
        vector<vector<bool>> ok(Sz + 2, vector<bool> ((numNode - s[root] + 1) / 2 + 2 , 0));

        dp[0][0] = 1;
        REP(i, 1, Sz) {
            REP(j, 0, (numNode - s[root] + 1) / 2) {
                if (dp[i - 1][j]) ok[i][j] = 0, dp[i][j] = 1;
                else if (j >= G[i - 1].fi && dp[i - 1][j - G[i - 1].fi])
                    ok[i][j] = dp[i][j] = 1;
            }
        }

        int x = 0;
        REPD(i, (numNode - s[root] + 1) / 2, 0) if (dp[Sz][i]) {
            x = i;
            break;
        }
        
        Res += 1LL * x * (numNode - s[root] - x);
        Ans += Res;

        vector<int> cntSize(numNode + 2, 0);
        REPD(i, Sz, 1) {
            if (ok[i][x]) {
                cntSize[G[i - 1].se] += G[i - 1].fi / G[i - 1].se;
                x -= G[i - 1].fi;
            }
        }


        for (int id : g[root]) {
            int v = Oth(root, id);
            if (cntSize[sz[v]] > 0) {

                FINDANS(v, root, IN);
                int ID = TreeEdge[id].id;
                ans[ID] = edge[ID];

                if (idx[ans[ID].first] != v)
                    swap(ans[ID].first, ans[ID].second);

                --cntSize[sz[v]];
            }
            else {

                FINDANS(v, root, OUT);
                int ID = TreeEdge[id].id;
                ans[ID] = edge[ID];
                if (idx[ans[ID].first] == v)
                    swap(ans[ID].first, ans[ID].second);
            }
        }

    }
    cout << Ans << ' ';
}

int main(){
    sinh_();
    io_faster
    file();
    int t = 1;
    // cin >> subtask >> t;
    REP(T, 1, t) {
        readip();
        solve();
        if (T < t) cout << ln;
    }
}