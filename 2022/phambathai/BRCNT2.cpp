#include<bits/stdc++.h>
#define fi "text.INP"
#define fo "text.OUT"
#define ll long long
#define pb push_back
#define int ll
#define FOR( i , a , b ) for( int i = a ; i <= b ; i ++ )
#define FORN( i , a , b ) for( int i = a ; i < b ; i ++ )
#define FORG( i , a , b ) for( int i = a ; i >= b ; i-- )
using namespace std;
const ll oo = 1e18;
const int N= 2e7+5;

int n , k , a[N];
ll  po[N] , b , sm = 1e9 + 7 , gt[N];
void add(ll &a, ll b)
{
	a += b;
	if ( a >= sm ) a -= sm;
}

void doc(){
	cin >> n ;
	FOR ( i , 1 , n )
	{
		char x ;
		cin >> x;
		if ( x == '(' ) a[i] = 1;
		if ( x == '[' ) a[i] = 2;
		if ( x == '{' ) a[i] = 3;
		if ( x == ')' ) a[i] = 4;
		if ( x == ']' ) a[i] = 5;
		if ( x == '}' ) a[i] = 6;
	}
}
ll PO( ll x , ll y )
{
	if ( y == 0 ) return 1;
	if ( y == 1 ) return x;
	ll mid = PO ( x , y / 2 );
	if ( y % 2 == 0 ) return mid * mid % sm;
	return mid * mid % sm * x % sm;
}
ll C( ll k , ll n )
{
	ll tu = gt[n];
	ll mau = gt[k] * gt[ n - k ] % sm;
	return tu * PO ( mau , sm - 2 ) % sm;
}

ll  calc ( ll h1 , ll h2 , ll  n )
{
	ll kc = abs ( h1 - h2);
	
	ll a = ( kc + n ) / 2;
	ll b = n - a;
	if ( ( kc + n ) % 2 != 0 || a < 0 || b <0 ) return 0;
	return C( b , n );
}
ll tinh ( ll i , ll s  )
{
	int len = n - i + 1 ;
	return ( calc ( s , 0 , len ) - calc ( s , -2 , len ) + sm ) %sm;
}
void xuly()
{
	gt[0] = 1;
	FOR( i , 1 , n ) gt[i] = gt[i - 1 ] * i % sm;
	int s = 0 ;
	ll res = 0;
	po[0] = 1;
	FOR ( i , 1 , n ) po[i] = po[ i - 1 ] * 3 % sm;
	FOR( i , 1 , n  )
	{
		ll v = min ( 4ll , a[i] );
		int news = s + 1 ;
		if  ( ( n - i - news ) % 2 == 0 && n - i - news >= 0 )
		add( res,   po[ ( n - i - news ) / 2] * tinh ( i + 1 , news  ) %sm * ( v - 1));
		
		if ( a[i] <= 3 ) s ++ ;
		else s--;
	}
	res = ( res + 1 ) % sm;
	cout <<res;
}
 main()
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
	}

	return 0;
}