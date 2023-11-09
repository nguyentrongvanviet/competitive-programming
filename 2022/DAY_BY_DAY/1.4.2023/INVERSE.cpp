#define TASK "INVERSE"
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
const int N =5e2+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

int n , m ; 
int a[N][N] ; 
int A[N][N] ;
int b[N][N] ;
void read()
{
	cin>>n>> m;
	FOR(i,1,n)FOR(j,1,m)
	{
		char x ; cin>>x ;
		a[i][j] = x-'0' ;
	}  
	FOR(i,1,n)FOR(j,1,m)
	{
		char x ; cin>>x ;  
		b[i][j] = x-'0' ; 
	}
}
bool ok1 = 0 ; 
vi check()
{
	vi ans;  
	FOR(i,1,n)FOR(j,1,m)A[i][j]=a[i][j];
	FOR(j,1,m)
	{
		if(A[1][j]!=b[1][j])
		{
			ans.pb(-j);
			FOR(i,1,n)
			{
				A[i][j]=1-a[i][j];
			}
		}
	}
	FOR(i,2,n)
	{
		if(A[i][1]!=b[i][1])
		{
			ans.pb(i);
			FOR(j,1,m)
			{
				A[i][j] = 1-A[i][j]; 
			}
		}
		FOR(j,1,m)if(A[i][j]!=b[i][j])
		{	
			ok1 =0 ; 
			return ans; 
		}
	}	
	return ans;  
}
void solve()
{
	bool ok = 0 ; 
	ok1= 1 ; 
	vi res; 		
	vi tmp1= check() ; 
	if(ok1)
	{
		ok =1; 
		res=tmp1;  
	}
	ok1= 1; 
	FOR(i,1,m)a[1][i]=1-a[1][i];
	tmp1 =check() ; 
	if(ok1)
	{
		tmp1.pb(1);
		if(ok==0||tmp1.size()<res.size())
		{
			ok= 1 ;  
			res=tmp1;  
		}
	}
	if(ok==0)return void(cout<<-1); 
	cout<<res.size()<<el;  
	for(auto x:res)cout<<x<<" ";
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