#include<bits/stdc++.h>
#define fi "DREAMING.INP"
#define fo "DREAMING.ANS"
#define ll long long
#define pb push_back
#define FOR( i , a , b ) for( int i = a ; i <= b ; i ++ )
#define FORN( i , a , b ) for( int i = a ; i < b ; i ++ )
#define FORG( i , a , b ) for( int i = a ; i >= b ; i-- )
using namespace std;
const int oo = 1e9;
const int N= 1e6+5;

int n , m , l , f[N] , dp[N] , dd[N] , f_max , dp_max , ok;
struct bg{
	int x , w;
};
vector< int > tmp;
vector<bg>g[N] ;

void doc(){
	cin >> n >> m >> l;
	FOR( i , 1 , m )
	{
		int x , y , w;
		cin >> x >> y >> w;
		g[x].pb({ y , w });
		g[y].pb({ x , w });
	}
}
void dfs_in( int u , int cha )
{
	if(ok == 0 )tmp.pb(u);
	dd[u] = 1;
	f[u] = 0 ;
	FORN( j , 0 , g[u].size() )
	{
		int v = g[u][j].x , cost = g[u][j].w ;
		if ( v == cha ) continue;
		dfs_in( v , u );
		f_max = max ( f_max , f[u] + cost + f[v] );
		f[u] = max ( f[u] , cost + f[v] );
	}
}
void dfs_out( int u , int cha , int val )
{
	dp[u] = max ( f[u] , val );
	dp_max = min ( dp_max , dp[u] );
	int s1 = val , s2 = 0; 
	FORN( j , 0 , g[u].size() )
	{
		int v = g[u][j].x , cost = g[u][j].w;
		if ( v == cha ) continue;
		if ( s1 <= f[v] + cost ) s2 = s1 , s1 = f[v] + cost;
		else if( s2 < f[v] + cost ) s2 = f[v] + cost;
	}
	FORN( j , 0 , g[u].size() )
	{
		int v = g[u][j].x , cost = g[u][j].w;
		if ( v == cha ) continue;
		int gt;
		if ( f[v] + cost == s1 ) gt = s2;
		else gt = s1;
		dfs_out( v , u , gt + cost );
	}
}
void xuly()
{
	int res = 0 ;
	vector< int > a;
	FOR( i , 0 , n - 1)
	{
		if ( dd[i] == 0 )
		{
			f_max = 0 ;
			dp_max = oo ;
			dfs_in( i , 0 );
			dfs_out( i , 0 , 0 );
			a.pb( dp_max );
			res = max ( res , f_max );
			// cout << i <<" "<<f_max<<" "<<dp_max<<endl;
		}
	}
	sort( a.begin() , a.end() , greater<int>() );
	// cout << a.size() <<'\n';
	// cout << m <<'\n';
	if ( a.size() >= 2 )
	{
		res = max ( res , a[0] + a[1] + l);
		if ( a.size() >= 3 ) res = max ( res , a[1] + a[2] + 2 * l );
	}
	cout << res;
}
void sub1()
{
	int res = 0 ;
	vector< int > a;
	FOR( i , 0 , n - 1)
	{
		if ( dd[i] == 0 )
		{
			tmp.clear();
			f_max = 0 ;
			dp_max = oo ;
			ok = 0;
			dfs_in( i , 0 );
			ok = 1;
			// dfs_out( i , 0 , 0 );
			// a.pb( dp_max );
			for( int x : tmp )
			{
				dfs_in( x , 0 );
				dp_max = min ( dp_max , f[x] );
			}
			// cout<<i<<" "<<f_max<<" "<<dp_max<<endl;
			res = max ( res , f_max );
			a.pb( dp_max );
		}
	}
	// cout << res << endl;
	// cout << a.size() << endl;
	sort( a.begin() , a.end() , greater<int>() );
	if ( a.size() >= 2 )
	{
		res = max ( res , a[0] + a[1] + l);
		if ( a.size() >= 3 ) res = max ( res , a[1] + a[2] + 2 * l );
	}
	cout << res;	
}
int main()
{
	freopen( fi, "r" , stdin );
	freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int t;
	// cin>>t;
	t = 1;
	while(t--)
	{
		doc();
		xuly();
		// sub1();
	}

	return 0;
}
