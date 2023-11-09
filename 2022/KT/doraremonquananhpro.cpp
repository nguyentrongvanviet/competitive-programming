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
const int N=1e6+5;

int n , m , k ,num[N],low[N],cha[N],dd[N],s[N],tp[N],a[N],h[N],ma,id=0,stplt = 0;
struct bg{
	int x ,y ;
}c[N];
stack<int> st;
vector<int> g[N] , b[N];
int bit[N];
ll res = 0;
int base = 1;
void doc(){
	cin >> n >> m >> k;
	int x ,y ;
	FOR ( i , 1 , m ) cin >> x >> y , g[x].pb(i) , g[y].pb(i) , c[i] = { x, y };
}
void dfs( int u )
{
 	num[u] = low[u] = ++id; st.push(u);
 	FORN( j , 0 , g[u].size() )
 	{
 		int id = g[u][j];
 		int v;
 		if ( c[id].x == u ) v = c[id].y ; else v = c[id].x;
 		if ( dd[v] == 1 ) continue;
 		if ( cha[u] == id ) continue;
 		if ( num[v] > 0 )
 		{
 			low[u] = min ( low[u] , num[v] );
 		}else
 		{
 			cha[v] = id ;
 			dfs( v);
 			low[u] = min ( low[u] , low[v] );
 		}
 	}
 	if ( num[u] == low[u] )
 	{
 		int x ;
 		stplt++;
 		do{
 			x = st.top();st.pop();
 			dd[x] = 1;
 			tp[x] = stplt;
 			a[stplt] ++ ;
 		}while ( x != u );
 	}
}
void DFS ( int  u, int cha )
{
	s[u] = 1;
	for ( int v : b[u] )
	{
		if ( dd[v] == 1 || v == cha ) continue;
		DFS( v , u );
		s[u] += s[v];
	}
}
int centriod( int u , int cha , int  n)
{
	for ( int v : b[u])
	{
		if ( dd[v] == 1 || v == cha ) continue;
		if ( s[v] > n / 2 ) return centriod( v , u , n );
	}
	return u ;
}
void update( int x , int val )
{
	for ( int i = x ; i > 0 ; i -= i & -i ) bit[i] += val;
}
int get ( int x )
{
	int ans = 0 ; 
	for ( int i = x ; i <= ma ; i += i & -i ) ans += bit[i];
	return ans;
}
void dfs1 ( int u , int cha )
{
	if ( k - h[u] <= ma)
	{
		res += (ll ) a[u] * get( max( 0,  k - h[u] ) + base );
	}
	for ( int v : b[u] )
	{
		if ( dd[v] == 1 || v == cha ) continue;
		h[v] = h[u] + 1;
		dfs1( v , u );
	}
}
void dfs2( int u , int cha )
{
	update( h[u] + base , a[u] );
	for ( int v : b[u] )
	{
		if ( dd[v] == 1 || v == cha ) continue;
		h[v] = h[u] + 1;
		dfs2( v , u );
	}	
}


void tinh ( int u )
{
	dd[u] = 1;
	DFS( u , 0 );
	ma = s[u] + base;
	update( 0  + base , a[u] );
	h[u] = 0;
	FORN ( j , 0 , b[u].size() )
	{
		int v = b[u][j];
		if ( dd[v] == 1 ) continue;
		h[v] = h[u] + 1 ;
		dfs1( v , u );
		dfs2( v , u );
	}
	FOR ( i , 0 , ma  ) bit[i] = 0;
	for ( int v : b[u] )
	{
		if ( dd[v] == 1 ) continue;
		tinh ( centriod( v , u , s[v] ) );
	}
	
}
void xuly()
{
	FOR ( i ,1 , n ) if ( num[i] == 0 )dfs(i);
	FOR ( i ,1 , m )
	{
		int r1 = tp[ c[i].x ] , r2 = tp[ c[i].y ];
		if ( r1 != r2 )
		{
			b[r1].pb(r2);
			b[r2].pb(r1);
		}
	}
	FOR ( i ,1 , stplt ) dd[i] = 0;
	FOR ( i , 1 , stplt )
	{
		if ( dd[i] == 1 ) continue;
		DFS( i , 0 );
		tinh ( centriod( i , 0,  s[i] ) );
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
	}

	return 0;
}