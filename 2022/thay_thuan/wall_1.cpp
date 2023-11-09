#include <bits/stdc++.h>
#define fi "wall.INP"
#define fo "wall.OUT"
using namespace std;
const int N = 5005;	
#define FOR(i,a,b) for(int i=a;i<=b;i++)
int n, a[N], test, d;
int g[N][N], f[N][N];

void doc(){
	cin>>n>>d;
	for(int i=1; i<=n; i++)	cin>>a[i];
}

// goi f[i][j] = so phep bien doi it nhat khi den i va co j vi tri vi pham
// goi g[i][j] = so phep bien doi it nhat de bien i->j thanh cung do cao
void xuly(){
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			g[i][j] = 2e9;
			f[i][j] = 2e9;
		}
	for(int i= 1 ;i<=n;i++)
	{
		map<int,int>sl;
		priority_queue<int>q;
		for(int j= i ;j<=n;j++)
		{
			sl[a[j]]++;
			q.push(sl[a[j]]);
			g[i][j]=(j-i+1)-q.top();
		}
	}
	for(int i=1;i<=n;i++)f[i][0]=g[1][i];
	for(int j=1;j<=d;j++)
	{
		for(int i=1 ; i<=n; i++)
		{
			f[i][j] = g[1][i];
			FOR(k,1,i-1)
			{
				f[i][j] = min(f[i][j], f[k][j-1] + g[k+1][i]);
			}
			// cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
		}
	}
	cout<<f[n][d]<<"\n";
}

int main(){
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);
	ios_base :: sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);

	cin>>test;
	while(test--){
		doc();
		xuly();
	}
	return 0;
}