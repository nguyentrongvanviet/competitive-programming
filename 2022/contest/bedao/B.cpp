#define TASK "B"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = true ;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
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

const int N =1e6+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n , a[N] ; 
stack<int>_2 ,_0,_3  ; 
void read()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ; 
}

bool check()
{
	if(_2.size()<2||_0.size()<1||_3.size()<1)return 0 ;
	int v =_2.top();
	_2.pop() ; 
	int u= _2.top() ; 
	_2.push(v);
	int x=  _0.top() ; 
	int y = _3.top() ; 
	if(u+1==x&&x+1==v&&v+1==y)
	{
		_2.pop() ; 
		_2.pop() ; 
		_0.pop() ; 
		_3.pop() ;
		return 1;  
	}
	return 0 ; 
}
void solve()
{
	while(_2.size())_2.pop() ; 
	while(_0.size())_0.pop() ;
	while(_3.size())_3.pop() ; 
	int ans = 0 ;
	FOR(i,1,n)
	{
		if(a[i]==2)_2.push(i-ans*4) ; 
		else if(a[i]==0)_0.push(i-ans*4) ; 
		else _3.push(i-ans*4);
		if(check())
		{
			ans++; 
		}
	}
	if(ans==0)
	{
		cout<<":("<<el; 
	}
	else if(ans%2==1)cout<<"Bedao"<<el; 
	else cout<<"Bemai"<<el;
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