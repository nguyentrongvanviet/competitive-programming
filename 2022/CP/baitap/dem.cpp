#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 
#define X first 
#define Y second 
#define int long long 
const int N =1000+5 , oo = 1e9 ; 
const ll inf = 1e17 , cs = 330 , sm = 1e9+7 ; 
int lowbit(int val )
{
	return val&-val;
}
int n, m,q, a[N][N], B[N][N][4];
void inp()
{
	cin>> n>> m >> q; 
	for(int  i=1 ;i<=n;i++)
	{
		for(int  j=1 ;j<=m;j++)
		{
			cin>>a[i][j] ; 	
		}	
	}	
		
}

void upd(int x, int y, int v) {
  for(int i = x ; i <= n ; i += lowbit(i)) {
    for(int j = y ; j <= m ; j += lowbit(j)) {
      B[i][j][0] += v;
      B[i][j][1] += x * v;
      B[i][j][2] += y * v;
      B[i][j][3] += x * y * v;
    }
  }
}
int qry(int x, int y) {
  int ans = 0;
  for(int i = x ; i > 0 ; i -= lowbit(i)) {
    for(int j = y ; j > 0 ; j -= lowbit(j)) {
      ans += (x + 1) * (y + 1) * B[i][j][0] - (y + 1) * B[i][j][1] - (x + 1) * B[i][j][2] + B[i][j][3];
    }
  }
  return ans;
}
void update(int x1, int y1, int x2, int y2, int v) {
  upd(x1, y1, v);
  upd(x1, y2 + 1, -v);
  upd(x2 + 1, y1, -v);
  upd(x2 + 1, y2 + 1, v);
}
int query(int x1, int y1, int x2, int y2) {
  return qry(x2, y2) - qry(x1 - 1, y2) - qry(x2, y1 - 1) + qry(x1 - 1, y1 - 1);
}
void init() {
  for(int i = 1 ; i <= n ; ++i) {
    for(int j = 1 ; j <= m ; ++j) {
      upd(i, j, a[i][j]);
    }
  }
}
void solve()
{
	for(int  i=1 ;i<=q;i++)
	{
		int t , x , y , u , v ; 
		cin>>t>>x>>y>>u>>v ; 
		if(t==1)
		{
			int val ; 
			cin>>val; 
			update(x,y,u,v,val);
		}
		else 
		{
			cout<<query(x,y,u,v)<<"\n";
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ;  
	freopen("o.txt","w",stdout) ; 
	int t = 1; 
	while(t--)
	{ 
		inp() ; 
		init();	
		solve() ; 
	}
}
