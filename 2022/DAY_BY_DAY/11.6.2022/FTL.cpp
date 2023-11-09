#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const long long INF64 = 1e18;

int main() {
	vector<int> ps(2);
	vector<long long> ts(2);
	int h, s;
	forn(i, 2) scanf("%d%lld", &ps[i], &ts[i]);
	scanf("%d%d", &h, &s);
	long long ans = INF64;
	vector<long long> dp(h + 1, INF64);
	dp[0] = 0;
	forn(i, h) 
	for (int j = 1; j <= h - i; ++j) 
	forn(k, 2){
		int ni = min((long long)h, i + j * (ps[k] - s) + j * ts[k] / ts[k ^ 1] * (ps[k ^ 1] - s));
		if (ni == h)
			ans = min(ans, dp[i] + j * ts[k]);
		if (j * ts[k] >= ts[k ^ 1]){
			ni = min((long long)h, i + (j - 1) * (ps[k] - s) + (j * ts[k] / ts[k ^ 1] - 1) * (ps[k ^ 1] - s) + (ps[0] + ps[1] - s));
			dp[ni] = min(dp[ni], dp[i] + j * ts[k]);
		}
	}
	ans = min(ans, dp[h]);
	printf("%lld\n", ans);
}