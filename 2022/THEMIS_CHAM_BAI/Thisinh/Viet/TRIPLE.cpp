#define TASK "TRIPLE"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  true ;
#define fast     ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long  
#define pll pair<ll,ll>
#define fi first 
#define se second
#define str string 
#define FOR(i,a,b) for(int i =a ;i<=b;i++)
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(a%b,a);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
    void IOS()
    {
        fast 
        if(fopen(TASK".INP","r")) freopen(TASK".INP","r",stdin) , freopen(TASK".OUT","w",stdout);
    }
const int N =1e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 123456789,cs=330 ,inf = 1e17;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int k , n ; 
bool dd[N][10];
pll f[N][10]  ; 
void read()
{
	cin>> k >>  n ; 
}
pll truoc , sau ; 
void tinh(int k , int n )
{
	if(dd[n][k]!=0 ){return ; }
	dd[n][k] = 1; 
	if(n==0){f[n][k] = {k,10};return ;}  	
	pll tmp={-1,-1}; 
	k*=3; 
	if(k>=10)
	{
		tinh(k%10,n-1) ;
		tinh(k/10,n-1) ;
		sau =f[n-1][k%10]; 

		truoc = f[n-1][k/10];
		ll val  = (truoc.fi*sau.se%sm+sau.fi)%sm ;
		ll mu = (truoc.se*sau.se)%sm; 
		tmp  = { val , mu} ;
	}
	else if(k<=10) tinh(k,n-1),tmp=f[n-1][k]; 
	k/=3;
	f[n][k]=  tmp ; 
}
void solve()
{
	ll res =0 ;  
	ll l  = 1 ; 
	pll T ; 
	while(k>0)
	{
		tinh(k%10,n) ; 
		T=f[n][k%10];
		res= (T.fi*l%sm +res)%sm ; 
		l = (l*T.se)%sm; 
		k/=10;
	}
	cout<<res<<el;
}
signed main()
{
    IOS() ; 
    int test =1 ;
  	if(multitest)cin>>test ; 
    while(test--)
    {
        read() ; 
        solve() ; 
    }
}