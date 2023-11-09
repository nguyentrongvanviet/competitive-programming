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
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) , EPS = 1e-9 ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n ; 
ll f[N]; 
ll value[N] ; 
ll a[N] , sl[N] ; 
void doc()
{
	cin>> n;  
	FOR(i,1,n)cin>>value[i] ; 
	sort(value+1,value+n+1) ; 
}

void xuly()
{
	int it =1 ; 
	int tmp = 0 ; 
	while(it<=n)
	{
		a[++tmp] = value[it] ; 
		int j= it ; 
		while(value[j]==value[it])
		{
			sl[value[it]]++ ;
			j++ ;
		}
		it = j ; 
	}
	n =tmp ; 
	for(int i= 1;i<=n;i++)
	{
		if(a[i]==a[i-1]+1)f[i] = max(f[i-1],f[max(0,i-2)]+sl[a[i]]*a[i]);
		else f[i] = sl[a[i]]*a[i]+f[i-1];
	}
	cout<<f[n]<<el;
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        doc(); 
        xuly();
    }
}