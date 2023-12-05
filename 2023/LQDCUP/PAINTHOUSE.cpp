#include <bits/stdc++.h>

#define MASK(i) (1LL << (i))
#define BIT(x, y) (((x) >> (y)) & 1)
#define sz(v) ((ll) (v).size())
#define all(v) (v).begin(), (v).end()
#define uni(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define F first
#define S second
#define pii(x, y) make_pair(x, y)
#define __builtin_popcount __builtin_popcountll
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define lg(x) (63 - __builtin_clz(x))

template <class X, class Y>
    bool minimize(X &x, const Y &y)
    {
        if (x > y) {x = y; return 1;}
        return 0;
    }

template <class X, class Y>
    bool maximize(X &x, const Y &y)
    {
        if (x < y) {x = y; return 1;}
        return 0;
    }

using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int M = 6e5;
const int mod = 998244353;
const int INF = 1e9 + 7;
const ll oo = 2e18;
const double eps = 1e-1;
const long double pi = 2*acos(0.0);

int n, a[N];

void Input(void)
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
}

void add(int &x, int y)
{
    x += y;
    if (x >= mod) x -= mod;
}

void sub(int &x, int y)
{
    x -= y;
    if (x < 0) x += mod;
}

namespace sub1
{
    int dp[105][105];
    void solve(void)
    {
        memset(dp, 0, sizeof dp);
        for (int j = 1; j <= a[1]; j ++) dp[1][j] = 1;
        for (int i = 2; i <= n; i ++)
            for (int p = 1; p <= a[i - 1]; p ++)
                for (int j = 1; j <= a[i]; j ++)
                    if (p != j) add(dp[i][j], dp[i - 1][p]);
        int ans = 0;
        for (int j = 1; j <= a[n]; j ++) add(ans, dp[n][j]);
        cout << ans;
    }
}

namespace sub3
{
    vector<int> vi;
    int dp[2005][2005];
    void solve(void)
    {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i ++) vi.push_back(a[i]);
        vi.push_back(0);
        uni(vi);
        for (int i = 1; i <= n; i ++) a[i] = lower_bound(all(vi), a[i]) - vi.begin();
        int m = sz(vi) - 1;
        for (int i = 1; i <= a[1]; i ++) dp[1][i] = 1;
        for (int i = 2; i <= n; i ++)
        {
            int sum = 0;
            for (int j = 1; j <= m; j ++) add(sum, 1LL * dp[i - 1][j] * (vi[j] - vi[j - 1]) % mod);
            for (int j = 1; j <= a[i]; j ++) dp[i][j] = (sum - dp[i - 1][j] + mod) % mod;
        }
        int ans = 0;
        for (int j = 1; j <= a[n]; j ++) add(ans, 1LL * dp[n][j] * (vi[j] - vi[j - 1]) % mod);
        cout << ans;
        return ;
    }
}

namespace sub5
{
    int dp[N][2], L[N], sum[N][2];
    int get(int l, int r, int id)
    {
        return (sum[r][id] - (l == 0 ? 0 : sum[l - 1][id]) + mod) % mod;
    }
    void solve(void)
    {
        stack<int> st;
        for (int i = 1; i <= n; i ++)
        {
            while (sz(st) && a[st.top()] > a[i]) st.pop();
            if (sz(st)) L[i] = st.top();
            st.push(i);
        }
        memset(dp, 0, sizeof dp);
        memset(sum, 0, sizeof sum);
        dp[1][1] = a[1];
        sum[1][1] = a[1];
        for (int i = 2; i <= n; i ++)
        {
            for (int j = 0; j < 2; j ++)
            {
                dp[i][j] = dp[L[i]][j];
                add(dp[i][j], 1LL * get(L[i], i - 1, 1 - j) * a[i] % mod);
                if (L[i] == 0 && j == 1) add(dp[i][j], a[i]);
                sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
            }
        }
        cout << (dp[n][n % 2] - dp[n][1 - n % 2] + mod) % mod;
    }
}

void solve(void)
{
    if (n <= 100 && *max_element(a + 1, a + 1 + n) <= 100)
    {
        sub1::solve();
        return ;
    }
    if (n <= 2000)
    {
        sub3::solve();
        return ;
    }
    sub5::solve();
}

int main()
{
    std::ios_base::sync_with_stdio(0); cin.tie(0);
freopen("PAINTHOUSE.inp", "r", stdin);
freopen("PAINTHOUSE.out", "w", stdout);
    int test = 1;
    //cin >> test;
    while (test --)
    {
        Input();
        solve();
    }
    return 0;
}
