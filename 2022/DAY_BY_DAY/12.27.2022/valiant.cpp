#define TASK "valiant"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  true ;
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
const int N =1e3+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , m; 
void read()
{
	cin>>n>> m;
	ve<ve<int>>a(n+5,ve<int>(m+5,0)) ; 
	ve<ve<int>>s(n+5,ve<int>(m+5,0)) ; 
	FOR(i,1,n)FOR(j,1,m)cin>>a[i][j] ;   
	int  l=2; 
	int r= min(n,m) ;
	int res=1; 
	while(l<=r)
	{
		int mid =(l+r)/2;
		FOR(i,1,n)FOR(j,1,m)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			if(a[i][j]>=mid)s[i][j]++;
		}
		bool ok = 0; 
		for(int i= 1 ;i<=n-mid+1&&ok==0;i++)for(int j= 1 ;j<=m-mid+1&&ok==0;j++)
		{
			int u= i+mid-1; 
			int v= j+mid-1;
			if(s[u][v]-s[i-1][v]-s[u][j-1]+s[i-1][j-1]==mid*mid)
			{
				res =mid ;
				l=mid+1; 
				ok  = 1 ; 
			}
		}
		if(ok)continue ;
		r=mid-1;
	}
	cout<<res<<el;
}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read();
    }
}