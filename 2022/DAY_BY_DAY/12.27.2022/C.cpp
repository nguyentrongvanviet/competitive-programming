#define TASK "C"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  true;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define int long long 
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
const int N =5e6+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n ;
int a[N] ,  s[N] ; 
vi q ;
ll sl[2*N];
void read()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i],s[i]=(s[i-1]^a[i]);
	// for(int i= 1 ;i<=n;i++)for(int j = i;j<=n;j++)cout<<(s[j]^s[i-1])<<el;
	ll res= 0 ;
	FOR(i,1,n)
	{
		sl[s[i-1]]++;
		for(auto x : q)
		{
			res+=sl[s[i]^x]; 
		}
	}
	FOR(i,0,n)sl[s[i]]=0;
	cout<<n*(n+1)/2-res<<el;
}
void solve()
{

}
signed main()
{
    IOS() ; 
    int test =1 ; 
    FOR(i,0,520)q.pb(i*i); 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
    }
}