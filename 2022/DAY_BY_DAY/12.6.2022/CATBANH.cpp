#define TASK "text"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
#define int long long 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =500+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , k;  
ll a[N][N] ; 
ll c[N][N]  , s[N][N] ; 
ll get(int u , int v, int x , int y  )
{
	return s[x][y]-s[x][v-1]-s[u-1][y]+s[u-1][v-1]; 
}
void read()
{
	cin>> n  >> k; 
	++k ;
	FOR(i,1,n)FOR(j,1,n)cin>>a[i][j] ; 
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			s[i][j] =s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];  
			c[i][j] = c[i-1][j-1]+a[i][j];  
		}
	}
	ll tmp = 0 ; 
	ll res= -inf ; 
	FOR(i,1,n-k+1)
	{
		if(i==1)FOR(j,1,k)tmp+=get(j,1,j,j); 
		else tmp+=get(i+k-1,1,i+k-1,k)-c[i-1+k-1][k];
		ll tmp1= tmp ; 
		res=max(res,tmp1) ; 
		FOR(j,2,n-k+1)
		{

			tmp1=tmp1-get(i,j-1,i+k-1,j-1)+c[i+k-1][j+k-1]-c[i-1][j-1];
			// cout<<i<<" "<<j<<" "<<tmp1<<el;
			res=max(res,tmp1);
		}
	}
	cout<<res;
}

void solve()
{

}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}