#define TASK "C"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
#define int long long 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pk pop_back 
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
using namespace std;
const ll oo = 1e18;
const int N= 1e6+5;
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
int n , k , d[N];
ll c[N] , s[5][N];
vector< ll > adj[5];
void read()
{
	cin >> n >> k;
	FOR( i , 1 , n ) {cin >> c[i];};
	FOR( i , 1 , n )
	{	
		cin >> d[i] ; 
		d[i] = d[i] % 3;
	}
}
int timkiem( ll val )
{
	int ans = 0 ; 
	int l =0 ; 
	int r=  adj[0].size()-1; 
	while(l<=r)
	{
		int mid =(l+r)/2;
		if(s[0][mid]<=val)ans=mid,l=mid+1;
		else r=mid-1; 
	}
	return ans; 
}
void solve()
{
	FOR( i , 0, 2 ) adj[i].push_back(0);
	FOR( i , 1 , n ) adj[ d[i] ] .push_back(c[i]);
	FOR( i , 0, 2 ) sort(all(adj[i]));
	FOR( i , 0 , 2 )
	{
		FORN( j , 1 , adj[i].size() )
		{
			s[i][j] =s[i][ j - 1 ]+adj[i][j];
		}
	}
	int res=0 ;
	FORN(i,0,adj[2].size())
	{
		FORN(j,0,adj[1].size())
		{
			if(s[2][i]+s[1][j]>k)break;
			if((i*2+j)%3==0)res = max(res,i+j+timkiem(k-s[2][i]-s[1][j]));
		}
	}
	cout<<res<<el;
}
signed main()
{
	IOS();
	read(); 
	solve() ; 
}