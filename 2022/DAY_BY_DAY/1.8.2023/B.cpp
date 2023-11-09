#include<bits/stdc++.h>
#define ll long long
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define pb push_back
#define For( i , a , b ) for( int i = a ; i <= b ; i ++ )
#define ForN( i , a , b ) for( int i = a ; i < b ; i ++ )
#define ForG( i , a , b ) for( int i = a ; i >= b ; i-- )
using namespace std;
const ll oo = 1e18;
const int N= 50+5;

int n ,a[N][N] , ok[N*N];
int xx[] = { 0 , 1 , -1 , 0 };
int yy[] = { 1 , 0  , 0 , -1};
void read()
{
	cin >> n ;
}
struct DL
{
	int x , y;
};
bool in(int x, int y )
{
	return 1<=x&&x<=n&&1<=y&&y<=n;
}
void solve()
{
	For( i , 1 , n)
	For( j , 1 , n ) a[i][j] = 0 ;
	For( i , 1 , n * n ) ok[i] = 0 ;
	queue< DL > q;
	a[1][1] = 1;
	ok[1] = 1;
	int val = n * n -1 ; q.push({1,1});
	while(!q.empty())
	{
		int x = q.front().x;int y = q.front().y;q.pop();
		int bruh = 0 ;
		For( i , 0 , 4-1 )
		{
			int u = x + xx[i];
			int v = y + yy[i];
			if (in(u,v) && a[u][v] == 0 )
			{
				if( a[x][y] - val >= 1 && ok[ a[x][y] - val ] == 0 )
				{
					a[u][v] = a[x][y] - val;
					q.push({ u , v });
					val--;
					ok[ a[u][v] ] = 1;
					bruh = 1;
				}
				else if ( a[x][y] + val <= n * n && ok[ a[x][y] + val] == 0 )
				{
					a[u][v] = a[x][y] + val;
					q.push({ u , v });
					val--;
					ok[ a[u][v] ] = 1;
					bruh =1;
				}
				if(bruh==1)break;
			}
		}
	}
	For( i , 1 , n )For( j , 1 , n )
	{
		if ( a[i][j] == 0)
		{
			For( k , 1 , n * n )
			if ( ok[k] == 0 )
			{
				ok[k] = 1;
				a[i][j] = k;
				break;
			}
		}
	}
	For( i , 1 , n )
	{
		For( j , 1 , n ) cout << a[i][j] <<" ";cout<<endl;
	}
}
signed main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int test;
	cin>>test;
	while(test--)
	{
		read();
		solve();
	}
}