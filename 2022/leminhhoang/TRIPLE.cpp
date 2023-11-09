#define taskname "TRIPLE"
#include<bits/stdc++.h>
using namespace std;
#define int long long 
using lli = long long;
const int maxN = 1e5;
const int maxD = 9;
const int MOD = 123456789;
using TBoard = int[maxN + 1][maxD + 1];

TBoard f, g;
int oldn;

/*
g[i][d] = số sinh ra từ chữ số d sau i bước % MOD
f[i][d] = 10^k % MOD, k số chữ số của g[i][d]
*/
void Init()
{
    for (int d = 0; d <= maxD; ++d)
    {
        f[0][d] = 10 % MOD;
        g[0][d] = d % MOD;
    }
    oldn = 0;
}

void CalFG(int newn)
{
    if (newn <= oldn) return;
    for (int i = oldn + 1; i <= newn; ++i)
        for (int d = 0; d <= maxD; ++d)
        {
            int newd = d * 3;
            int dh = newd / 10, dl = newd % 10;
            if (dh == 0)
            {
                f[i][d] = f[i - 1][dl];
                g[i][d] = g[i - 1][dl];
            }
            else
            {
                f[i][d] = lli(f[i - 1][dh]) * f[i - 1][dl] % MOD;
                g[i][d] = ((lli)g[i - 1][dh] * f[i - 1][dl] + g[i - 1][dl]) % MOD;
            }
        }
    oldn = newn;
}

int Solve(int k, int n)
{
    CalFG(n);
    int p;
    p = 1;
    while (lli(p) * 10 <= k) p *= 10;
    int res = 0;
    for (; p > 0; p /= 10)
    {
        int d = k / p;
        res = ((lli)res * f[n][d] + g[n][d]) % MOD;
        k %= p;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    lli ntests;
    cin >> ntests;
    Init();
    while (ntests-- > 0)
    {
        int n, k;
        cin >> k >> n;
        cout << Solve(k, n) << '\n';
    }
}
