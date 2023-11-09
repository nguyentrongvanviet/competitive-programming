#include<bits/stdc++.h>
#define fi "D.INP"
#define fo "D.ANS"
#define ll long long
#define pb push_back
#define FOR( i , a , b ) for( int i = a ; i <= b ; i ++ )
#define FORN( i , a , b ) for( int i = a ; i < b ; i ++ )
#define FORG( i , a , b ) for( int i = a ; i >= b ; i-- )
using namespace std;
const ll oo = 1e18;
const int N= 1e6+5;

int t[ 8 *N][4] , d[ 8*N ]  , n , q  , b[N];
char s[N];
int ch( char c )
{
	if ( c == 'N' ) return 0;
	if ( c == 'E' ) return 1;
	if ( c == 'S' ) return 2;
	return 3;
}
void update1( int k , int l, int r , int u , int v , int val)
{

		FOR( j , 0 , 3 ) b[j] = t[k][j];
		FOR( j , 0 , 3) t[k][j] = b[( j - d[k] + 4) % 4 ];
		d[ 2 * k ] = ( d[2 * k] + d[k] )% 4;
		d[ 2 * k + 1 ] = ( d[ 2 * k + 1] + d[k] ) % 4;
		d[k] = 0;
	if ( r < u || v < l ) return;
	if ( u <= l && r <= v )
	{
		FOR( j , 0 ,3 ) t[k][j] = 0 ;
		t[k][val]++;
		return;
	}
	int mid = ( l + r ) / 2;
	update1( 2 * k , l , mid , u , v ,val );
	update1( 2 * k + 1 , mid + 1 , r , u , v, val );
	FOR( j , 0 , 3 ) t[k][j] = t[ 2 * k][j] + t[ 2 * k + 1 ][j];
}
void update2( int k , int l , int r , int u , int v , int val )
{
		FOR( j , 0 , 3 ) b[j] = t[k][j];
		FOR( j , 0 , 3) t[k][j] = b[( j - d[k] + 4) % 4 ];
		d[ 2 * k ] = ( d[2 * k] + d[k] )% 4;
		d[ 2 * k + 1 ] = ( d[ 2 * k + 1] + d[k] ) % 4;
		d[k] = 0;
	if ( r < u || v < l ) return;
	if ( u <= l && r <= v )
	{
		FOR( j , 0 , 3 ) b[j] = t[k][j];
		FOR( j , 0 , 3) t[k][j] = b[( j - val + 4) % 4 ];
		d[ 2 * k ] = ( d[ 2 * k ] + val ) % 4;
		d[ 2 * k + 1 ] = ( d[ 2 * k + 1] + val ) % 4;
		return;
	}
	int mid = ( l + r ) / 2 ;
	update2( 2 * k , l , mid , u , v , val );
	update2( 2 * k + 1 , mid +1 , r , u , v, val );
	FOR( j , 0 , 3 ) t[k][j] = t[ 2 * k][j] + t[ 2 * k + 1 ][j];
}

void doc(){
	cin >> n >> q;
	FOR( i , 1,  n ) cin >> s[i];
	FOR( i , 1 , n ) update1( 1 , 1 , n ,  i , i , ch(s[i]) );
	int res = 0 ;
	FOR( i , 1 , q )
	{
		int k;
		cin >> k;
		if ( k == 1 )
		{
			int id ; char c ;
			cin >> id >> c ;
			s[id] = ch(c);
			update1( 1 , 1 , n  , id , id , ch(c) );
		}else
		{
			int l , r , val;
			cin >> l >> r >> val;
			val = val % 4;
			update2( 1 , 1 , n , l , r , val );
		}
		if ( t[1][0] == t[1][2] && t[1][1] == t[1][3] ) res++;
		// else cout<<0<<endl;
	}
	cout <<res;
}

int main()
{
	freopen( fi, "r" , stdin );
	freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int t;
	// cin>>t;
	t= 1;
	while(t--)
	{
		doc();
	}

	return 0;
}