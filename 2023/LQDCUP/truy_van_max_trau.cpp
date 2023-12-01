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
const int N = 1e5 + 5;
const int M = 6e5;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;
const ll oo = 2e18;
const double eps = 1e-1;
const long double pi = 2*acos(0.0);
const int block = 320;

struct line
{
    ll a, b;
    line (ll _a = 0, ll _b = 0)
    {
        a = _a, b = _b;
    }
    ll eval(ll x)
    {
        return a * x + b;
    }
};

bool bad(const line &l1, const line &l2, const line &l3)
{
    return (long double) (l3.b - l1.b) * (l1.a - l2.a) <= (long double) (l2.b - l1.b) * (l1.a - l3.a);
}

struct convexhull
{
    deque<line> st;
    void add(const line &x)
    {
        while (sz(st) >= 2 && bad(st[sz(st) - 2], st.back(), x)) st.pop_back();
        st.push_back(x);
    }
    ll query(ll x)
    {
        while (sz(st) >= 2 && st[0].eval(x) <= st[1].eval(x)) st.pop_front();
        return st[0].eval(x);
    }
} A[block];

int n, q;
ll a[102405], lz[block], val[block];

void Input(void)
{
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
}

void build(int i)
{
    A[i].st.clear();
    for (int j = i * block; j < (i + 1) * block; j ++) A[i].add(line(j, a[j]));
}

ll get_trau(int l, int r)
{
    ll res = 0;
    for (int i = l; i <= r; i ++) maximize(res, a[i] + i * lz[i / block] + val[i / block]);
    return res;
}

ll get_block(int l, int r)
{
    ll res = 0;
    for (int i = l; i <= r; i ++) maximize(res, A[i].query(lz[i]) + val[i]);
    return res;
}

ll get(int l, int r)
{
    int BL = (l + block - 1) / block, BR = r / block;
    if (BL >= BR) return get_trau(l, r);
    ll res = get_block(BL, BR - 1);
    if (l < BL * block) maximize(res, get_trau(l, BL * block - 1));
    maximize(res, get_trau(BR * block, r));
    return res;
}

void update_trau(int l, int r, ll x, ll y)
{
    for (int i = l; i <= r; i ++) a[i] += x + i * y;
    build(l / block);
    if (l / block != r / block) build(r / block);
}

void update_block(int l, int r, ll x, ll y)
{
    for (int i = l; i <= r; i ++) 
    {
        val[i] += x;
        lz[i] += y;
    }
}

void update(int l, int r, ll x, ll y)
{
    int BL = (l + block - 1) / block, BR = r / block;
    if (BL >= BR) 
    {
        update_trau(l, r, x, y);
        return ;
    }
    update_block(BL, BR - 1, x, y);
    if (l < BL * block) update_trau(l, BL * block - 1, x, y);
    update_trau(BR * block, r, x, y);
}


void solve(void)
{
    for (int i = 0; i < block; i ++) build(i);
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1) 
        {
            int l, r;
            cin >> l >> r;
            l --, r --;
            cout << get(l, r) << '\n';
        }
        else
        {
            int l, r;
            ll x, y;
            cin >> l >> r >> x >> y;
            l --, r --;
            update(l, r, x - y * l, y);
        }
    }
}

int main()
{
std::ios_base::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    if(fopen("text.INP","r"))
    {
        freopen("text.INP","r",stdin) ; 
        freopen("text.ANS","w",stdout) ;   
    }
    //cin >> test;
    while (test --)
    {
        Input();
        solve();
    }
    return 0;
}