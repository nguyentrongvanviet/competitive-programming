#define TASK "wall"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
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
const int N = 5e3+5, oo = 2e9, CH = 26, LO = 20; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , k ; 
int a[N] ; 
int mi[N][N];
int f[N][N];
int pre[N] ;
void read()
{
	unordered_map<int,int>pos;
	cin>> n >> k; 
	FOR(i,1,n)
	{
		cin>>a[i] ; 
		if(pos.count(a[i]))pre[i]= pos[a[i]] ; 
		else pre[i] = 0; 
		pos[a[i]] = i ;
	}
	for(int i= 0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			mi[i][j] = oo ; 
			f[i][j] = oo ; 
		}
	}
	f[0][0]=0 ; 
	mi[0][0]=0 ; 
	for(int j= 0;j<=k;j++)
	{
		for(int i= 1;i<=n;i++)	
		{
			f[i][j] = f[pre[i]][j]+i-pre[i]-1;
			if(j)f[i][j] = min(f[i][j],mi[i-1][j-1]+i);
			mi[i][j] = min(mi[i-1][j],f[i][j]-i-1);
		}
	}
	int res=oo ; 
	for(int i= 1;i<=n;i++)
	{
		for(int j= 0 ;j<=k;j++)
		{
			f[i][k] = min(f[i][k] ,f[i][j]) ; 
		}
		res=min(res,f[i][k]+(n-i));
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
    }
}