#include<bits/stdc++.h>
#define fi "text.INP"
#define fo "text.OUT"
#define ll long long
#define pb push_back
#define FOR(i,a,b) for( int i=a;i<=b;i++)
#define FORN(i,a,b) for( int i=a;i<b;i++)
#define FORG(i,a,b) for( int i=a;i>=b;i--)
using namespace std;
const ll oo=1e16;
const int N=2e3+5;

int n ;
ll a[N] , f[N][N] , ma[N][N] , mi[N][N];

void doc(){
	cin >> n ;
	FOR ( i , 1 , n ) cin >> a[i];
}
void xuly()
{
	sort ( a + 1 , a + n + 1 );
	FOR ( i , 1 , n ) f[i][i] = 0 , ma[i][i] = a[i] , mi[i][i] = a[i];
	FOR ( j , 2 , n )
	FORG( i , j - 1 , 1 ){
		ma[i][j] = max ( ma[i][ j - 1 ] , a[j] );
		mi[i][j] = min ( mi[i][ j - 1 ] , a[j] );
		f[i][j] = min ( f[i + 1 ][j] , f[i][ j - 1 ] ) + ma[i][j] - mi[i][j];
	}
	cout << f[1][n];
}
int main()
{
	// freopen( fi, "r" , stdin );
	// freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int t;
	//cin>>t;
	t = 1;
	while(t--)
	{
		doc();
		xuly();
	}

	return 0;
}