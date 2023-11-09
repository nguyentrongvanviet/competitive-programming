#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ans[100005], t[100005];

void solve() 
{
    int n;
    vector<int> ldk, dk;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        bool ty; int ti;
        cin >> ty >> t[i];
        if (ty) ldk.pb(i); 
        else dk.pb(i); 
    }

    bool ok = true;

    for (int i = 1; i < n/2; i++) 
    {
        if (t[ldk[i]] != t[ldk[i-1]])
        {
            ok = false; break;
        }
    }

    if (ok)
    {
        cout << "-1"; return;
    }

    ok = true;

    for (int i = 1; i < n/2; i++) 
    {
        if (t[dk[i]] != t[dk[i-1]])
        {
            ok = false; break;
        }
    }

    if (ok)
    {
    cout << "-1"; return;
    }

    for (int i = 0; i < n/2; i++)
    {
        while(true)
        {
            int id = rng()%(n/2 - i);
            if (t[dk[id]] != ldk[i] && t[ldk[i]] != dk[id])
            {
                ans[i + 1] = dk[id];
                swap(dk[id], dk[n/2 - i - 1]); dk.pop_back();
                break;
                }
            }
            cout << ldk[i] << " ";
        }
    cout << "\n";

for (int i = 1; i <= n/2; i++) cout << ans[i] << " ";

}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}