#include <bits/stdc++.h>
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"
#define N 100100
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

template <class Int>
inline void read(Int& x) {
  x = 0; char ch = getchar(); int f = 1;
  for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
  for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
  x *= f;
}

ll n;
int kase, p[3];

struct Edge {
  int to, nxt;
  Edge() {}
  Edge(const int& to, const int& nxt) : to(to), nxt(nxt) {}
} e[N << 1];
int tot, head[N];

inline void AddEdge(const int& u, const int& v) {
  e[tot] = Edge(v, head[u]), head[u] = tot++;
  e[tot] = Edge(u, head[v]), head[v] = tot++;
}

int dfn, fa[N], pre[N], sz[N];

inline void dfs(int u, int pa) {
  fa[u] = pa, pre[u] = ++dfn, sz[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == pa) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

int C[N];
inline void modify(int x) { for (; x <= n; x += x & (-x)) ++C[x]; }
inline int query(int x) { int ret = 0; for (; x; x -= x & (-x)) ret += C[x]; return ret; }

inline void init() {
  dfn = 0, tot = 1;
  memset(C, 0, sizeof(C));
  memset(head, 0, sizeof(head));
}

int main() {
	if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
  read(kase);
  while (kase--) {
      init(); read(n);
    for (int i = 0; i < 3; ++i) read(p[i]);
    for (int i = 1, u, v; i < n; ++i) {
      read(u), read(v);
      AddEdge(u, v);
    }
    dfs(1, 0);
    ll ret = 0;
    for (ll i = 1; i <= n; ++i) {
      modify(pre[i]);
      ll add = 0, tmp = 0;
      if (p[1] == 1) {
	add = (n - i) * (n - i - 1) / 2;
	for (int j = head[i]; j; j = e[j].nxt) {
	  int v = e[j].to;
	  if (v == fa[i]) continue;
	  ll small = query(pre[v] + sz[v] - 1) - query(pre[v] - 1);
	  small = sz[v] - small;
	  add -= small * (small - 1) / 2;
	  tmp += small;
	}
	tmp = n - i - tmp;
	add -= tmp * (tmp - 1) / 2;
      } else if (p[1] == 2) {
	ll _tmp = 0;
	add = (n - i) * (i - 1);
	for (int j = head[i]; j; j = e[j].nxt) {
	  int v = e[j].to;
	  if (v == fa[i]) continue;
	  ll small = query(pre[v] + sz[v] - 1) - query(pre[v] - 1);
	  ll big = sz[v] - small;
	  add -= small * big;
	  tmp += small, _tmp += big;
	}
	tmp = i - tmp - 1, _tmp = n - i - _tmp;
	add -= tmp * _tmp;
      } else {
	add = (i - 1) * (i - 2) / 2;
	for (int j = head[i]; j; j = e[j].nxt) {
	  int v = e[j].to;
	  if (v == fa[i]) continue;
	  ll small = query(pre[v] + sz[v] - 1) - query(pre[v] - 1);
	  add -= small * (small - 1) / 2;
	  tmp += small;
	}
	tmp = i - tmp - 1;
	add -= tmp * (tmp - 1) / 2;
      }
      ret += add;
    }
    printf("%lld\n", ret);
  }
  return 0;
}