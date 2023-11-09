#define TASK "C"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll unsigned long long 
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
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
ll  mu[100]; 
void read()
{
	ll n , x ; 
	cin>>n>>x; 
	// cout<<bitset<64>(n)<<" "<<bitset<64>(x)<<el;
	if(n==x)return void(cout<<n<<el); 
	ll nho = 0 ; 
	ll res = 0 ;
	for(int i= 63 ;i>=0;i--)
	{	
		if((n>>i&1)&&(x>>i&1)==0)
		{	
			ll val = n ; 
			for(int j= i;j>=0;j--)
			{
				if(val>>j&1)val-=(mu[j]);
			}
			val+=mu[i+1];
			// cout<<bitset<64>(val)<<el;	
			// cout<<val<<el;	
			if((n&val)!=x)return void(cout<<-1<<el) ; 
			else return void(cout<<val<<el);
		}
		else if((n>>i&1)==0&&(x>>i&1))
		{
			return void(cout<<-1<<el);
		}
	}	
}	

void solve()
{

}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    mu[0] =1 ; 
    FOR(i,1,63)mu[i]=mu[i-1]*2; 
    while(test--)
    {
        read(); 
        solve();
    }
}