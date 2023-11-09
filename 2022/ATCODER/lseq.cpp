#define TASK "lseq"
#include<bits/stdc++.h>
using namespace std; 

bool multitest =  false ;
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);  srand(time(0)) ;
#define ll long long 
#define db long double
#define int long long
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
#define btpc(a) __builtin_popcount(a)
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
const int N =1e6+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;
const db PI = acos(-1)  , eps = 1e-9;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
ll s[N] ; 
ll a[N]  ; 
vi q ;
void read()
{
	cin>> n ;
	int cnt= 0 ; 
	FOR(i,1,n)
	{
		int val ; cin>>val; 
		if(val!=0)
		{
			q.pb(val) ;
			++cnt;  
		}
	}
	int x= n-cnt;  
	sort(all(q)) ; 
	q.resize(unique(all(q))-q.begin()) ; 
	n =q.size() ; 
	FOR(i,1,n)a[i] =q[i-1];
	FOR(i,1,n)
	{
		s[i] = s[i-1]+a[i]-a[i-1]-1; 
		s[1] = 0 ;
	}
	if(n==0)
	{
		cout<<x; 
		return ; 
	}
	int j=  1; 
	ll res = 1+x;  
	FOR(i,2,n)
	{
		while(s[i]-s[j]>x)j++;
		res=max(res,s[i]-s[j]+(i-j+1)+x-(s[i]-s[j])) ;
	}
	cout<<res;
}
void solve()
{

}
signed main()
{
    IOS() ; 
    int test =1 ; 
    if(multitest)cin>>test;
    while(test--)
    {
        read() ; 
        solve() ;
    }
}