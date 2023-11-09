#define TASK "text"
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
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n ; 
vi g[N] ;
int en[N]; 
int T[N][CH] ; 
int node= 1 ; 
int h[N] ; 
int nnode= 0  ;
int res =0  ; 
int get(str s)
{
	int r= 1;  
	FORN(i,0,s.size())
	{
		int j= s[i]-'a'; 
		if(T[r][j]==0)
		{
			T[r][j]=++node; 
		}
		r=T[r][j] ;
	}
	if(en[r])return en[r] ; 
	return en[r] =++nnode; 
}
void dfs(int u   ,int p)
{
	res=max(res,h[u]+1); 
	for(auto v : g[u])
	{
		if(v==p)continue; 
		h[v] =h[u]+1 ; 
		dfs(v,u);
	}
}
void read()
{
	cin>> n; 
	int root = get("polycarp");
	FOR(i,1,n)
	{
		str s1, s2 ,s3 ;
		cin>>s1>>s3>>s2 ; 
		FORN(j,0,s1.size())
		{
			if(s1[j]<='Z')
			{
				s1[j] = (char)(s1[j]+32) ;
			}
		}
		FORN(j,0,s2.size())
		{
			if(s2[j]<='Z')
			{
				s2[j] = (char)(s2[j]+32) ; 
			}
		}
		int u = get(s1);
		int v = get(s2);
		g[v].pb(u) ;
	}
	dfs(root,0); 
	cout<<res;
}

void solve()
{	
	dfs(1,0) ; 
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