#define TASK "pair"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"
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
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int B , n , D  , M ; 
void read()
{
	cin>>B>>n>>D>>M ; 
}
pii a[N]; 
void sub2()
{
	FOR(i,1,n)
	{
		cin>>a[i].fi>>a[i].se; 
	}
	ll ans = 0 ; 
	for(int i= 1;i<=n;i++)
	{
		for(int j =i+1;j<=n;j++)
		{
			if(abs(a[i].fi-a[j].fi)+abs(a[i].se-a[j].se)<=D)ans++ ; 
		}
	}
	cout<<ans;
}
struct pt 
{
	int x ,y,z; 
};
void sub3()
{
	ve<pt>a(n+1);
	FOR(i,1,n)
	{
		cin>>a[i].x>>a[i].y>>a[i].z ;
	}
	int res = 0 ;
	for(int i= 1;i<=n;i++)
	{
		for(int j = i+1;j<=n;j++)
		{
			if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+abs(a[i].z-a[j].z)<=D)
			{
				// cout<<i<<" "<<j<<el;
				res++ ;
			}
		}
	}
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
        if(B==2)sub2() ; 
        else sub3() ;
    }
}