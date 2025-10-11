#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long x, xr = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x % 2) xr ^= (x - 1) / 2;
        }
        cout << (xr ? "Bob\n" : "Alice\n");
    }
}
