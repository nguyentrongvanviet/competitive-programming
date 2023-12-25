/*************************************
*    author: marvinthang             *
*    created: 22.12.2023 09:35:08    *
*************************************/

#include <bits/stdc++.h>

using namespace std;

#define                  fi  first
#define                  se  second
#define                left  ___left
#define               right  ___right
#define                TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define             MASK(i)  (1LL << (i))
#define           BIT(x, i)  ((x) >> (i) & 1)
#define  __builtin_popcount  __builtin_popcountll
#define              ALL(v)  (v).begin(), (v).end()
#define           REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)
#define          REPD(i, n)  for (int i = (n); i-- > 0; )
#define        FOR(i, a, b)  for (int i = (a), _b = (b); i < _b; ++i) 
#define       FORD(i, b, a)  for (int i = (b), _a = (a); --i >= _a; ) 
#define       FORE(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i) 
#define      FORDE(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i) 
#define        scan_op(...)  istream & operator >> (istream &in, __VA_ARGS__ &u)
#define       print_op(...)  ostream & operator << (ostream &out, const __VA_ARGS__ &u)
#ifdef LOCAL
    #include "debug.h"
#else
    #define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
    #define DB(...) 23
    #define db(...) 23
    #define debug(...) 23
#endif

template <class U, class V> scan_op(pair <U, V>)  { return in >> u.first >> u.second; }
template <class T> scan_op(vector <T>)  { for (size_t i = 0; i < u.size(); ++i) in >> u[i]; return in; }
template <class U, class V> print_op(pair <U, V>)  { return out << '(' << u.first << ", " << u.second << ')'; }
template <size_t i, class T> ostream & print_tuple_utils(ostream &out, const T &tup) { if constexpr(i == tuple_size<T>::value) return out << ")";  else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); }
template <class ...U> print_op(tuple<U...>) { return print_tuple_utils<0, tuple<U...>>(out, u); }
template <class Con, class = decltype(begin(declval<Con>()))> typename enable_if <!is_same<Con, string>::value, ostream&>::type operator << (ostream &out, const Con &con) { out << '{'; for (__typeof(con.begin()) it = con.begin(); it != con.end(); ++it) out << (it == con.begin() ? "" : ", ") << *it; return out << '}'; }

// end of template

const int LOG = 19;

struct Node {
	int child[2];
	int cnt;
	Node(int l = -1, int r = -1, int c = 0) {
		child[0] = l; child[1] = r; cnt = c;
	}
};

vector <Node> nodes;

int newNode() {
	nodes.push_back(Node());
	return (int) nodes.size() - 1;
}

int newNode(int l, int r, int cnt) {
	nodes.push_back(Node(l, r, cnt));
	return (int) nodes.size() - 1;
}

int idx[LOG + 1];
int update(int cur, int x) {
	idx[LOG] = cur;
	REPD(i, LOG) {
		if (idx[i + 1] == -1) idx[i] = -1;
		else idx[i] = nodes[idx[i + 1]].child[BIT(x, i)];
	}
	REP(i, LOG + 1) {
		if (idx[i] == -1) idx[i] = newNode();
		else idx[i] = newNode(nodes[idx[i]].child[0], nodes[idx[i]].child[1], nodes[idx[i]].cnt);
		++nodes[idx[i]].cnt;
		if (i) nodes[idx[i]].child[BIT(x, i - 1)] = idx[i - 1];
	}
	return idx[LOG];
}

void process(void) {
	int n, q; cin >> n >> q;
	nodes.reserve((n + q) * (LOG + 1));
	vector <int> versions {-1};
	REP(i, n) {
		int x; cin >> x;
		versions.push_back(update(versions.back(), x));
	}
	int cur_xor = 0;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int x; cin >> x;
			versions.push_back(update(versions.back(), x ^ cur_xor));
		} else if (op == 2) {
			versions.pop_back();
		} else if (op == 3) {
			int x; cin >> x;
			cur_xor ^= x;
		} else if (op == 4) {
			int l, r, x; cin >> l >> r >> x; --l;
			int res = 0;
			int cur_r = versions[r], cur_l = versions[l];
			x ^= cur_xor;
			REPD(i, LOG) {
				int v = !BIT(x, i);
				int cr = nodes[cur_r].child[v], cl = cur_l == -1 ? -1 : nodes[cur_l].child[v];
				if (cr != -1 && nodes[cr].cnt - (cl == -1 ? 0 : nodes[cl].cnt) > 0) {
					cur_r = cr;
					cur_l = cl;
					res ^= MASK(i);
				} else {
					cur_r = nodes[cur_r].child[!v];
					cur_l = cur_l == -1 ? -1 : nodes[cur_l].child[!v];
				}
			}
			cout << res << '\n';
		} else if (op == 5) {
			int l, r, x; cin >> l >> r >> x; --l;
			int res = 0;
			int cur_r = versions[r], cur_l = versions[l];
			REPD(i, LOG) {
				int v = BIT(cur_xor, i);
				if (BIT(x, i)) {
					int cr = nodes[cur_r].child[v], cl = cur_l == -1 ? -1 : nodes[cur_l].child[v];
					if (cr != -1) res += nodes[cr].cnt - (cl == -1 ? 0 : nodes[cl].cnt);
					v = !v;
				}
				cur_r = nodes[cur_r].child[v];
				cur_l = cur_l == -1 ? -1 : nodes[cur_l].child[v];
				if (cur_r == -1) break;
			}
			if (cur_r != -1) res += nodes[cur_r].cnt - (cur_l == -1 ? 0 : nodes[cur_l].cnt);
			cout << res << '\n';
		} else if (op == 6) {
			int l, r, k; cin >> l >> r >> k; --l;
			int res = 0;
			int cur_r = versions[r], cur_l = versions[l];
			REPD(i, LOG) {
				int v = BIT(cur_xor, i);
				int cr = nodes[cur_r].child[v], cl = cur_l == -1 ? -1 : nodes[cur_l].child[v];
				int cnt = cr == -1 ? 0 : nodes[cr].cnt - (cl == -1 ? 0 : nodes[cl].cnt);
				if (cnt < k) {
					k -= cnt;
					v = !v;
					res ^= MASK(i);
				}
				cur_r = nodes[cur_r].child[v];
				cur_l = cur_l == -1 ? -1 : nodes[cur_l].child[v];
			}
			cout << res << '\n';
		}
	}	
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); // cout.tie(nullptr);
	file("LQUERY");
	// int t; cin >> t; while (t--)
	process();
	// cerr << "Time elapsed: " << TIME << " s.\n";
	return (0^0);
}