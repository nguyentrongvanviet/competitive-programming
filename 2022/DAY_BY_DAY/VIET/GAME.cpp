#define TASK "GAME"
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
ll lcm(ll a, ll b){return a/gcd(a,b)*	b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =1e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int B , n ; 
int M ; 
int d ; 
void read()
{
	cin>> B>>n >> d >> M ; 
}
void sub1()
{		
	vi a(n+1,0) ; 
	FOR(i,1,n)cin>>a[i] ; 
	sort(a.begin()+1,a.begin()+n+1) ; 
	ll res=0 ; 	
	for(int i = 1 ;i<=n;i++)
	{
		res+=upper_bound(a.begin()+i+1,a.begin()+n+1,d+a[i])-a.begin()-i; 
	}
	cout<<res;
}
void sub2() 
{	
	ve<pii> a(n+1) ; 
	FOR(i,1,n)
	{
		cin>>a[i].fi>>a[i].se; 
	}
	ll res= 0 ;
	for(int i= 1;i<=n;i++)
	{
		for(int j= 1;j<=i-1;j++)
		{
			if(abs(a[i].fi-a[j].fi)+abs(a[i].se-a[j].se)<=d)res++ ;
		}
	}
	cout<<res;
}
void sub3() 
{

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
        if(B==1)sub1() ; 
        if(B==2)sub2() ; 
        if(B==3)sub3() ;
        // solve();
    }
}