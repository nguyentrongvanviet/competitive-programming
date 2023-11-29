
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
        X eps = 1e-9;
        if (x > y + eps) {x = y; return 1;}
        return 0;
    }

template <class X, class Y>
    bool maximize(X &x, const Y &y)
    {
        X eps = 1e-9;
        if (x + eps < y) {x = y; return 1;}
        return 0;
    }

using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
const int M = 1e6 + 5;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
const ll oo = 2e18;
const double eps = 1e-1;
const long double pi = 2*acos(0.0);

int n, q;
ll a[N];

void Input(void)
{
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];
}

ll sign(ll x)
{
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

namespace sub1
{
    void solve(void)
    {    

        while (q--)
        {
            char type;
            cin >> type;
            if (type == '+')
            {
                int l, r, v;
                cin >> l >> r >> v;
                for (int i = l; i <= r; i ++) a[i] += v;
            }
            else
                if (type == '*')
                {
                    int l, r;
                    cin >> l >> r;
                    for (int i = l; i <= r; i ++) a[i] *= -1;
                }
                else
                {
                    int l, r;
                    cin >> l >> r;
                    int len = 1;
                    ll cur = 0;
                    ll ans = 1;
                    for (int i = l + 1; i <= r; i ++)
                    {
                        if (cur == 0)
                        {
                            if (a[i] - a[i - 1] == 0) len = 1;
                            else cur = a[i] - a[i - 1], len ++;
                        }
                        else
                        {
                            if (sign(cur) * sign(a[i] - a[i - 1]) != -1) 
                            {
                                len = 1;
                                if (a[i] - a[i - 1] != 0)  cur = a[i] - a[i - 1], len ++;
                                else cur = 0;
                            }
                            else 
                            {
                                len ++;
                                cur = a[i] - a[i - 1];
                            }
                        }
                        ans += len;
                    }
                    cout << ans << '\n';
                }
        }
    }
}

void solve(void)
{
    if (n <= 5000 && q <= 5000)
    {
        sub1::solve();
    }
}

int main()
{
std::ios_base::sync_with_stdio(0); cin.tie(0);
freopen("text.inp", "r", stdin);
freopen("text.ans", "w", stdout);
    int test = 1;
    //cin >> test;
    while (test --)
    {
        Input();
        solve();
    }
    return 0;
}