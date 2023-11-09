#include<bits/stdc++.h>

#define TASK "APL"
const bool multitest = false; 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int h1 , h2 , n ; 
ll fac[N];
void read()
{
	cin>>h1>>h2>>n ; 
}
ll pw(ll a, ll n)
{
	if(n==0)return 1;   
	ll b= pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;  
	else return b*b%sm ;
}
ll C(int n , int k)
{
	ll tu = fac[n] ; 
	ll mau =fac[n-k]*fac[k]%sm ; 
	return tu*pw(mau,sm-2)%sm; 
}
ll tinh(int h1, int h2 , int n )
{
	if(h1<h2)swap(h1,h2) ; 
	int a = (n+h1-h2)/2; 
	int b=n-a; 
	if((n+h1-h2)%2!=0||b<0)return 0; 
	return C(n,a);
}
void process()
{		
    fac[0] =1 ; 
    FOR(i,1,N-1)fac[i] = fac[i-1]*i%sm; 
  	ll res= 0; 
  	FOR(i,0,n)
  	{
  		res+= C(n,i)*(tinh(h1,h2,n-i)-tinh(h1,-2-h2,n-i)+sm)%sm;
  		cout<<C(n,i)<<" "<<tinh(h1,h2,n-i)<<" "<<tinh(h1,-2-h2,n-i)<<endl;
  		res%=sm;
  	}
  	cout<<res;
}
void print()
{
    
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
}