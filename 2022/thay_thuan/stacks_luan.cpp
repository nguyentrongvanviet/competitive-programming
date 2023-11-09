#include<bits/stdc++.h>
using namespace std;

#define TASK "stacks"
#define faster ios_base :: sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0)
#define For(i,l,r) for(int i=(int)l ; i<=(int)r ; i++)
#define Forn(i,r,l) for(int i=(int)r ; i>=(int)l ; i--)
#define all(v) v.begin(),v.end()
#define pb push_back
#define fi first
#define se second

typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;

const int base = 311, inf = 2e9, N = 50, M = (1 << 20) + 5;
const long long sm = 1e9 + 7, oo = 1e18;

ll n, a[M];
queue<int> q[N];
stack<int> s[N];

void solve(int i, int l, int r)
{
    if (i == 2 * n + 1) return;

    int mid = (l + r) >> 1;

    if (i % 2 == 1)
    {
        while (!q[i].empty())
        {
            int u = q[i].front();
            q[i].pop();
            if (u > mid)
            {
                s[i + 1].push(u);
                cout << i << " ";
            }
            else
            {
                q[i + 2].push(u);
                cout << i << " " << i + 1 << " ";
            }
        }
        solve(i + 2, l, mid);
        solve(i + 1, mid + 1, r);
    }
    if (i % 2 == 0)
    {
        while (!s[i].empty())
        {
            int u = s[i].top();
            s[i].pop();
            q[i + 1].push(u);
            cout << i << " ";
        }
        solve(i + 1, l, r);
    }
}
int main()
{
    if (fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }
    faster;

    cin >> n;
    ll m = (1 << n);
    For(i, 1, m) cin >> a[i];

    For(i, 1, m) q[1].push(a[i]);

    solve(1, 1, m);

    return 0;
}