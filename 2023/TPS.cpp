//it's the hiensumi
#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
// #define int long long
#define base 1000000+5
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct bg{
	int val;
	int head = 0;
};
int n, c[21][21], m;
bg f[(1<<20) + 1][21];
// vector <int> adj[21];
// gọi f[x][i] là cp ít nhất khi đi được k đỉnh và đỉnh cuối cùng là đỉnh thứ i
// k số bit 1(x)
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> m;
	// fod(i,1,n) fod(j,1,n) c[i][j] = 2e9;
	memset(c, 0x3f, sizeof c);
	int THENUMBER = c[0][0];
	fod(i,1,m){
		int u, v, w; cin >> u >> v >> w;
		c[u][v] = w;
	}
	int tt = (1 << n) - 1;
	fod(x,0,tt) fod(i,1,n) f[x][i].val = 2e9;
	// f[1][0] = 1e18;
	fod(x,0,tt) {
		int k = __builtin_popcount(x);
		if(k == 1) fod(i,1,n) f[x][i].val = 0;
	}
	fod(x,0,tt) fod(i,1,n) if((x & (1 << (i-1)))){
		int k = __builtin_popcount(x);
		fod(j,1,n) if((x & (1 << (j-1))) == 0 and c[i][j] != THENUMBER) {
			int p = (x xor (1 << (j-1)));
			if(f[p][j].val > c[i][j] + f[x][i].val){
				if(f[p][j].head == 0){
					if(f[x][i].head == 0) f[p][j].head = i;
					else f[p][j].head = f[x][i].head;
				}else{
					f[p][j].head = f[x][i].head;
				}
				f[p][j].val = c[i][j] + f[x][i].val;
			}
		}
	}
	int res = 2e9;
	fod(i,1,n){
	    if(c[i][f[tt][i].head] != THENUMBER) res = min(res, f[tt][i].val + c[i][f[tt][i].head]);
		// cout << i << " " << f[tt][i].val << " " << f[tt][i].head << endl;
	}
	cout << res;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Sit down and code\n";
	return 0;
}