#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
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
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define mp make_pair 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout) ;
    }
}
const int N = 2e5+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 998244353; 
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
int a[N] ; 
void read()
{
	cin>> n  ; 
	FOR(i,1,n)cin>>a[i]; 
}
const int D = 90000;
ll pre[N] ; 
ll cur[N] ; 
void solve()
{
	pre[a[2]+D]= 1; 
	for(int i =2 ;i<=n-1;i++)
	{
		cur[a[i+1]+D]+=pre[D];
		for(int j=-D;j<=D;j++)
		{
			if(j==0)continue;
			// if(pre[j+D])cout<<j<<" ";
			cur[a[i+1]-j+D]+=pre[j+D];
			cur[a[i+1]-j+D]%=sm;

			cur[a[i+1]+j+D]+=pre[j+D];
			cur[a[i+1]+j+D]%=sm;
		}
		// cout<<el;
		for(int j= -D ;j<=D;j++)
		{
			pre[j+D]  = cur[j+D];
			// if(pre[j+D])cout<<j<<" "<<pre[j+D]<<el;
			cur[j+D] = 0 ;
		}
		// cout<<el;
	}	
	ll res= 0 ; 
	FOR(i,0,180000)res+=pre[i] ,res%=sm; 
	cout<<res;
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