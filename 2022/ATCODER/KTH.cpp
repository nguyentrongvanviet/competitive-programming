#define TASK "KTH"
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
const int N =40+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
ll n  , k ; 
ll f[N] ; 
char tim(ll n , ll k)
{
	if(n==1)return 'a'; 
	if(n==2)return 'b';
	if(n==3)return 'c';
	ll x = f[n-1] ; 
	ll y = f[n-2] ; 
	ll z = f[n-3] ;
	if(x>=k)
	{	
		return tim(n-1,k);
	}
	else if(x+y>=k)
 	{
 		return tim(n-2,k-x);
	}
	else if(x+y+z>=k)return tim(n-3,k-x-y);
	cout<<"CON CAC DE SAI ";
	return '!';
}
void read()
{
	cin>>n>>k;
	++n;
	f[1]=f[2]=f[3]= 1 ; 
	FOR(i,4,36)f[i] = f[i-1]+f[i-2]+f[i-3];
	cout<<tim(n,k);
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