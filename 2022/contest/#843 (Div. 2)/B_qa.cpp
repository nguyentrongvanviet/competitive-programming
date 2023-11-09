#include<bits/stdc++.h>
#define fi "text.INP"
#define fo "text.OUT"
#define ll long long
#define pb push_back
#define For( i , a , b ) for( int i = a ; i <= b ; i ++ )
#define ForN( i , a , b ) for( int i = a ; i < b ; i ++ )
#define ForG( i , a , b ) for( int i = a ; i >= b ; i-- )
using namespace std;
const int N= 1e6+5;

int n ;
vector< int > a[N];
void read(){
	
	unordered_map< int , int > dem;
	For( i , 1 , n )a[i].clear() ;
	cin >> n ;
	int ok = 0 ;
	For( i , 1 , n )
	{
		int k ;
		cin >> k ;
		For( j , 1 , k )
		{
			int x;
			cin >> x;
			dem[x]++;
			a[i].pb(x);
		}
	}
	For( i , 1 , n )
	{
		int ok = 1 ;
		for( int v : a[i] ) if( dem[v] == 1 ) ok = 0; 
		if ( ok == 1 )
		{
			cout<<"YES"<<'\n';
			return;
		}
	}
	cout<<"NO"<<'\n';
}
int main()
{
	// freopen( fi, "r" , stdin );
	// freopen( fo, "w" , stdout );

	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		read();
	}

	return 0;
}