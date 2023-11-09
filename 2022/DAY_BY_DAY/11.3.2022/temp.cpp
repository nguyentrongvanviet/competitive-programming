#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int MAXN = (int)5e5+228;
bitset <50005> dp[50005];
bool have[MAXN];
int n, m;
vector < int > g[MAXN], gr[MAXN];
int type[MAXN], from[MAXN], go[MAXN], sz, wh[MAXN];
vector < int > ts;
bool used[MAXN];
vector < int > cmps[MAXN];
vector < pair < int, int > > edge;
void dfs(int x) {
    used[x] = 1;
    for(auto &to : g[x]) if(!used[to])
        dfs(to);
    ts.pb(x);
}
void dfs1(int x) {
    used[x] = 1;
    wh[x] = sz;
    cmps[sz].pb(x);
    for(auto &to : gr[x]) if(!used[to])
        dfs1(to);
}
bool res[MAXN];
int main() {
    freopen("Epath.inp", "r", stdin);
    freopen("Epath.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=m;++i) {
        int x, y; cin >> x >> y;
        edge.pb(mp(x,y));
        g[x].pb(y);
        gr[y].pb(x);
    }
    int q; cin >> q;
    for(int i=1;i<=q;++i) {
        cin >> type[i] >> from[i] >> go[i];
        if(type[i] == 1) {
            n++;
            if(go[i]) {
                edge.pb(mp(n,from[i]));
                g[n].pb(from[i]);
                gr[from[i]].pb(n);
            } else {
                edge.pb(mp(from[i],n));
                g[from[i]].pb(n);
                gr[n].pb(from[i]);
            }
        }
    }
    for(int i=1;i<=n;++i) if(!used[i]) dfs(i);
    reverse(ts.begin(),ts.end());
    memset(used,0,sizeof used);
    for(auto &to : ts) {
        if(!used[to]) {
            sz++;
            dfs1(to);
        }
    }
    for(int i=1;i<=n;++i) g[i].clear();
    for(auto &to : edge) {
        if(wh[to.first] != wh[to.second]) g[wh[to.first]].pb(wh[to.second]);
    }
    memset(used,0,sizeof used);
    for(int i=1;i<=sz;++i) {
        if(!used[i]) {
            dfs(i);
        }
    }
    for(auto &to : ts) {
        dp[to].set(to,1);
        for(auto &it : g[to]) dp[to] |= dp[it];
    }
    for(int i=q;i>=1;--i) {
        if(type[i] == 1) {
            n--;
        } else {
            if(go[i] > n || from[i] > n) continue;
            res[i] = dp[wh[from[i]]].test(wh[go[i]]);
        }
    }
    for(int i=1;i<=q;++i) {
        if(type[i] == 1) continue;
        if(res[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}