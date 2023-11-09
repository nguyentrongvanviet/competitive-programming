/*
DOANHONGBAO
1505
*/
#define TASK "smeX"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ans"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 0;
 
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
#define int ll
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 2e3+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 998244353; 
const db PI = acos(-1), e = 1e-9;
int n;
int a[N],f[N][N];
void doc()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		a[i] = x;
	}
	for(int i=0;i<=n;i++) 
	{
		f[0][i] = 1;
	}
	ll res = 0;
	for(int i=1;i<=n;i++)
	{
		set<int> s;
		for(int J=0;J<=100;J++) s.insert(J);
		for(int t = i;t>=1;t--)
		{
			if(s.find(a[t]) != s.end()) s.erase(s.find(a[t]));
			int u = *s.begin(); 
				f[i][u] = (f[i][u] + f[t-1][u])%sm;
		}
	}
	for(int i=0;i<=100;i++) res = (res + f[n][i])%sm;
	cout<<res;
	cerr<<res<<el;
}

void xuly()
{

}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        xuly() ; 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}