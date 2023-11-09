#define TASK "stacks"
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
        freopen(TASK".OUT","r",stdin) ;
        freopen(TASK".INP","w",stdout) ;
    }
}
ll rd(ll l , ll r )
{
	return l+1LL*rand()*rand()%(r-l+1);
}
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int a[N]; 
int n ;
stack<int>st[N] ; 
queue<int>q[N] ; 
void read()
{
	ofstream cout(TASK".INP") ;
	n= rd(2,2);
	cout<<n<<el ; 
	for(int i= 1;i<=pow(2,n);i++)
	{
		a[i]= i ;
	} 
	random_shuffle(a+1,a+(int)pow(2,n)+1) ;  
	for(int i= 1;i<=pow(2,n);i++)
	{
		cout<<a[i]<<" "; 
		if(i&1)q[i].push(a[i]) ;
		else st[i].push(a[i]) ; 
	}
	cout.close() ; 	
	// system(TASK".exe") ; 
}

void check()
{
	
}

signed main()
{
	srand(time(0)) ; 
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        check() ;
    }
}