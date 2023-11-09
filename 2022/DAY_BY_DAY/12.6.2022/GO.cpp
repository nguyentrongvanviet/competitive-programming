#define TASK "GO"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = true;
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
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n;  
int a[N] ; 	
int pa[N] ;
void read()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ;
}
int goc(int u )
{
	return pa[u]==u ? u : pa[u]=goc(pa[u]) ;
}
void solve()
{	
	pa[1] =1;
	FOR(i,2,n)
	{
		if(i%2==0)
		{
			int u = goc(i-1);
			if(a[u]!=a[i])
			{
				if(u>1)
				{
					int v= goc(u-1) ;
					pa[u] = v; 
				} 
				else
				{
					a[u] = a[i] ; 
				}
			}
			pa[i] = pa[i-1];
		}
		else
		{
			int g= goc(i-1);
			if(a[g]==a[i])pa[i]=g ; 
			else pa[i] = i ;
		}
	}
	int c= 0 ; 
	int u = n ; 
	int res= 0 ; 
	while(u)	
	{
		int x = goc(u);
		if(a[x]==0)res+=(u-x+1);
		u=x-1; 
	}
	cout<<res<<el;
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