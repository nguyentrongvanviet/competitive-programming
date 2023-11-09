#define TASK "text"
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

void read()
{
	str s; cin>>s; 
	if(s[0]=='a')
	{
		for(int i=1 ;i<s.size()-1;i++)
		{
			if(s[i]=='b')
			{
				cout<<s.substr(0,i)<<" "<<s.substr(i,s.size()-i-1)<<" "<<s[s.size()-1]<<el;
				return ; 
			}
		}
		cout<<s.substr(0,s.size()-2)<<" "<<s.substr(s.size()-2,1)<<" "<<s[s.size()-1]<<el;
	}
	else
	{
		for(int i=1 ;i<s.size()-1;i++)
		{
			if(s[i]=='a')
			{	
				cout<<s.substr(0,i)<<" "<<s.substr(i,1)<<" "<<s.substr(i+1)<<el;
				return ; 
			}
		}
		cout<<s[0]<<" "<<s.substr(1,s.size()-2)<<" "<<s[s.size()-1]<<el;
		return ; 
	}
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