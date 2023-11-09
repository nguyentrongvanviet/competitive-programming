include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 5000 + 7;

int n, m;
int a[3];
vector<int> g[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, 3) scanf("%d", &a[i]);
	forn(i, n)
		g[i].clear();
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		g[u].pb(v);
	}
	return true;
}

int tot0, tot1;
int clr[N];
vector<vector<int>> vts[2];
bool ok;

void dfs(int v){
	tot0 += clr[v] == 0;
	tot1 += clr[v] == 1;
	vts[clr[v]].back().pb(v);
	for (auto u : g[v]){
		if (clr[u] == -1){
			clr[u] = clr[v] ^ 1;
			dfs(u);
		}
		else if (clr[u] == clr[v]){
			ok = false;
		}
	}
}

int dp[N][N];
int res[N];

void solve() {
	vector<pt> siz;
	memset(clr, -1, sizeof(clr));
	vts[0].clear();
	vts[1].clear();
	forn(i, n) if (clr[i] == -1){
		tot0 = tot1 = 0;
		clr[i] = 0;
		ok = true;
		vts[0].pb(vector<int>());
		vts[1].pb(vector<int>());
		dfs(i);
		if (!ok){
			puts("NO");
			return;
		}
		siz.pb(mp(tot0, tot1));
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	forn(i, sz(siz)) forn(j, N) if (dp[i][j] != -1){
		dp[i + 1][j + siz[i].x] = 0;
		dp[i + 1][j + siz[i].y] = 1;
	}

	if (dp[sz(siz)][a[1]] == -1){
		puts("NO");
		return;
	}

	puts("YES");
	memset(res, -1, sizeof(res));
	int cur = a[1];
	for (int i = sz(siz); i > 0; --i){
		for (auto it : vts[dp[i][cur]][i - 1])
			res[it] = 2;
		cur -= sz(vts[dp[i][cur]][i - 1]);
	}

	forn(i, n) if (res[i] == -1){
		if (a[0] > 0){
			res[i] = 1;
			--a[0];
		}
		else{
			res[i] = 3;
			--a[2];
		}
	}

	forn(i, n) printf("%d", res[i]);
	puts("");
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int tt = clock();

#endif

	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {
		solve();

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}
