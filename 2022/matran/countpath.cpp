#define TASK "countpath"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define db long double
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
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORN(i,a,b) for(int i= a ;i<b;i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a);
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define el '\n' 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(a%b,a);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
    void IOS()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct MT 
{
	int n , m ; 
	ve<ve<ll>>mt ; 
	void resize(int _n , int _m )
	{
		n = _n;  
		m = _m;
		mt.resize(n+1); 
		FOR(i,0,n)mt[i]=ve<ll>(m+1,0);
	}
};
MT mul(MT a, MT b )
{
	int n = a.n ; 
	int m = b.m ;
	MT ans ;
	ans.resize(n,m) ;
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			ll tmp = 0 ; 
			for(int t= 0;t<=a.m;t++)
			{
				tmp+=a.mt[i][t]*b.mt[t][j]%sm;
				tmp%=sm;
			}
			ans.mt[i][j] = tmp; 
		}
	}
	return ans;
}
MT pw(MT a,int n )
{
	if(n==1)return a;  
	MT b =pw(a,n/2);
	if(n&1)return mul(a,mul(b,b)); 
	return mul(b,b);
}
int n , m , k ;
void read()
{
	cin>> n >>m>>k; 
	MT D; D.resize(1,n);
	MT G  ;G.resize(n,n);
	FOR(i,1,n)D.mt[0][i] = 1 ; 
	FOR(i,1,m)
	{
		int u ,v ; 
		cin>>u>>v;  
		G.mt[u][v] =1 ; 
	}
	MT ans = mul(D,pw(G,k));
	ll res=0 ; 
	for(int i= 1 ;i<=n;i++)res+=ans.mt[0][i],res%=sm;
	cout<<res;
}
void solve()
{

}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
    }
}