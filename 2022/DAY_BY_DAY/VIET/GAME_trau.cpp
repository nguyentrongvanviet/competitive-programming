#include<bits/stdc++.h>
#define fi "game.INP"
#define fo "game.ANS"
#define ll long long
#define pb push_back
#define FOR( i , a , b ) for( int i = a ; i <= int(b) ; i ++ )
#define FORN( i , a , b ) for( int i = a ; i < int(b)  ; i ++ )
#define FORG( i , a , b ) for( int i = a ; i >= int(b)  ; i-- )
using namespace std;
const ll oo = 1e18;
const int N= 1e6+5;

int n , k , a[N] , M;

void sub1()
{
	cin >> n >> k >> M;
	FOR( i , 1 , n) cin >> a[i];
	sort ( a + 1 , a + n + 1 );

	ll res = 0 ;
	FOR( i , 1 , n - 1)
	{
		int d = i + 1 , c = n ;
		while( d + 1 < c )
		{
			int g = ( d + c ) / 2;
			if ( a[g] - a[i] <= k ) d = g;
			else c = g;
		}
		if ( a[c] - a[i] <= k) res += c - i;
		else if (a[d] - a[i] <= k ) res += d - i;
	}
	cout << res <<'\n';
}
vector< int > bit1[N] , bit2[N] , sum1[N] , sum2[N];
void fake_get_down( int x , int y )
{
	for( int i = x ; i > 0 ; i -= i & -i ) bit1[i].pb(y),sum1[i].pb(0);
}
void fake_get_up( int x , int y )
{
	for( int i = x ; i <= 75000 ; i += i & -i )  bit2[i].pb(y),sum2[i].pb(0);
}
void fake_update_up( int x , int y )
{
	for( int i = x ; i <= 75000 ; i += i & -i ) bit1[i].pb(y),sum1[i].pb(0);
}
void fake_update_down( int x , int y )
{
	for( int i = x ; i >0 ; i -= i & -i )bit2[i].pb(y),sum2[i].pb(0);
}
int get_down( int x , int y )
{
	int ans = 0 ;
	for( int i = x ; i > 0 ; i -= i & -i )
	{
		int j = lower_bound( bit1[i].begin() , bit1[i].end() , y ) - bit1[i].begin() + 1;
		for( j ; j <= bit1[i].size() ; j += j & -j ) ans += sum1[i][j -1]; //, cout << i << " "<<j<<" "<<bit1[i][j-1]<<endl;;
	}
	return ans;
}
int get_up( int x , int y )
{
	int ans = 0 ;
	for( int i = x ; i <= 75000 ; i += i & -i )
	{
		int j = lower_bound( bit2[i].begin() , bit2[i].end() , y ) - bit2[i].begin() + 1;
		for( j ; j <= bit2[i].size() ; j += j & -j ) ans += sum2[i][j -1];
	}
	return ans;	
}
void update_up( int x , int y )
{
	for( int i = x ; i <= 75000 ; i += i & -i )
		{
			int j = lower_bound( bit1[i].begin() , bit1[i].end() , y ) - bit1[i].begin() + 1;
			for( j ; j > 0 ; j -= j & -j ) sum1[i][j - 1] += 1;
		}	
}
void update_down( int x , int y )
{
	for( int i = x ; i > 0 ; i -= i & -i )
		{
			int j = lower_bound( bit2[i].begin() , bit2[i].end() , y ) - bit2[i].begin() + 1;
			for( j ; j > 0 ; j -= j & -j ) sum2[i][j - 1] += 1;
		}
}
struct bg
{
	int x , y;
}b[N];
bool cmp( bg a , bg b )
{
	return a.x < b.x;
}
// void sub2_trau();
// {
// 	cin >> n >> k >> M;
// 	// if ( k >= 75000*2 )
// 	// {
// 	// 	ll res = (ll) n * ( n - 1 ) / 2;
// 	// 	cout << res <<'\n';
// 	// 	return;
// 	// }
// 	FOR( i , 1 , n ) cin >> b[i].x >> b[i].y;
// 	ll res = 0 ;	
// 	FOR( i , 1 , n )
// 	FOR( j , i + 1 , n ) if ( abs( b[i].x - b[j].x ) + abs( b[i].y - b[j].y ) <= k ) res++;
// 	cout << res;
// }
void sub2()
{
	cin >> n >> k >> M;
	// if ( k >= 75000*2 )
	// {
	// 	ll res = (ll) n * ( n - 1 ) / 2;
	// 	cout << res <<'\n';
	// 	return;
	// }
	FOR( i , 1 , n ) cin >> b[i].x >> b[i].y;
	// FOR( i , 1 , n ) cout << b[i].x << " "<<b[i].y<<'\n';
	sort( b + 1 , b + n + 1 , cmp );
	FOR( i , 1,  n )
	{
		int u = b[i].x , v = b[i].y;
		fake_get_down( v , k - ( u + v ) );
		fake_get_up( v + 1 , k - ( u - v ) );
		fake_update_up( v , k + v );
		fake_update_down( v  , k - v );
	}
	// cout << bit1[25].size()<<'\n';
	FOR( i , 0 , 150000 )
	{
		// if ( bit1[i].empty() ) continue;
		sort( bit1[i].begin() , bit1[i].end() );
		sort( bit2[i].begin() , bit2[i].end() );
	}
	ll res = 0 ;
	FOR( i , 1,  n )
	{
		int u = b[i].x , v = b[i].y;
		// cout << "Ac "<<k - ( u + v ) <<'\n';
		res += get_down( v , ( u + v ) - k);

		res += get_up( v + 1 ,  ( u - v ) - k );
		// cout << u + v <<'\n'; 
		update_up( v, u + v  );
		update_down( v, u - v );
		// cout << res << '\n';
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
		int b;
		cin >> b;
		if ( b == 1 )sub1();
		if ( b == 2 ) sub2();
	}

	return 0;
}