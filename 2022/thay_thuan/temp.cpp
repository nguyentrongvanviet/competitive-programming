#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;

#define fi first
#define se second
#define left BAO
#define right ANH
#define pb push_back
#define pf push_front
#define mp make_pair
#define ins insert
#define btpc __builtin_popcount
#define btclz __builtin_clz

#define sz(x) (int)(x.size());
#define all(x) x.begin(), x.end()
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y)
        {
            x = y;
            return true;
        }
        return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }

const int MOD = 1e9 + 7; //998244353

template<class X, class Y>
	void add(X &x, const Y &y) {
		x = (x + y);
		if(x >= MOD) x -= MOD;
	}

template<class X, class Y> 
	void sub(X &x, const Y &y) {
		x = (x - y);
		if(x < 0) x += MOD;
	}

/* Author : Le Ngoc Bao Anh, 12A5, LQD High School for Gifted Student*/

const ll INF = 1e9;
const int N = 1e5 + 10;

int v[N];

void BaoJiaoPisu() {
	int n, q; cin >> n >> q;

	int ans = 0;
	set<int> one;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		ans += btpc(v[i]);
		if(btpc(v[i]) & 1) one.ins(i);
	}	

	while(q--) {
		int id, x; cin >> id >> x;
		ans -= btpc(v[id]);
		if(btpc(v[id]) & 1) one.erase(id);
		v[id] = x;
		ans += btpc(v[id]);
		if(btpc(v[id]) & 1) one.ins(id);

		if(ans % 2 == 0) {
			cout << n << ' ';
		} else {
			auto iter = one.begin();
			int res = 0;
			maximize(res, n - (*iter) - 1);
			iter = one.end(); iter = prev(iter);
			maximize(res, (*iter)); 
			cout << res << ' ';
		}
	}

	cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #else 
    //online
    #endif

    int tc = 1, ddd = 0;
    cin >> tc;
    while(tc--) {
        //ddd++;
        //cout << "Case #" << ddd << ": ";
        BaoJiaoPisu();
    }
}
