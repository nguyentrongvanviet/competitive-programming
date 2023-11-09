#include<bits/stdc++.h>
#define REP(i,a,n) for(int i=a;i<=n;++i)
using namespace std;
 
const int N = 402;
int n,m,a[N][N],f[N][N],pre[N][N*N];
 
int main() {
	scanf("%d%d", &n, &m);
	REP(i,1,n) REP(j,1,m) scanf("%d",a[i]+j);
	int ans = 0;
	REP(i,1,n) REP(d,1,m) {
		for (int l=1,r=d; r<=m; ++l,++r) {
			if (l==r) f[l][l]=max(f[l][l],pre[l][a[i][l]]);
			else if (a[i][l]==a[i][r]) f[l][r] = i;
			else {
				f[l][r]=max({f[l][r],f[l][r-1],f[l+1][r],pre[r][a[i][l]],pre[l][a[i][r]]});
			}
			ans = max(ans, (i-f[l][r])*(r-l+1));
		}
		REP(j,1,m) pre[j][a[i][j]]=i;
	}
	printf("%d\n", ans);
}















