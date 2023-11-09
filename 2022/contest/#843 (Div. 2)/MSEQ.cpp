#define TASK "MSEQ"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
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
int n , k ; 
int a[N] ; 
void read(){
	cin>> n >> k;
	int res= 0 ;
	map<int,int>div;  
	FOR(i,1,n)
	{
		cin>>a[i]; 
		a[i] = abs(a[i]) ; 
		a[i]%=k; 
		if(a[i]==0)res=1 ; 
		else	
		{	
			div[a[i]]++ ; 
		} 
	}
	if(div.find(k/2)!=div.end()&&k/2+k/2==k)
	{
		div.erase(k/2);
		res++;
	}
	int tmp =0 ; 
	for(auto v : div)
	{
		int x= v.fi ; 
		int sl = v.se; 
		int u = k-x; 
		int sz= 0 ; 
		if(div.find(u)!=div.end())sz=div[u] ; 
		if(sz==sl)tmp+=sz; 
		else if(sl>sz)res+=sl; 	
	}
	res+=tmp/2; 
	cout<<res;
}

void solve()
{

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