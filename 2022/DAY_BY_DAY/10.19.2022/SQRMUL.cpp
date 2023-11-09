#include<bits/stdc++.h>
using namespace std;

#define TASK "SQRMUL"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =1e6+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;


ll  sl[N] ;
ll value[N] ;
int n; 
ll a[N] ; 
void init()
{
	FOR(i,1,(int)1e6)
	{
		sl[i]=0 ; 
	}
}
ll binpow(ll a,  ll n )
{
	if(n==0)return 1 ; 
	ll b = binpow(a,n/2) ;
	if(n&1)
	{
		return b*b%sm*a; 
	}
	return b*b%sm;
}
void pt(ll a )
{
	ll x =2 ; 
	while(x*x<=a)
	{ 
		ll tmp= 0 ;
		while(a%x==0)
		{
			tmp++;
			a/=x; 
		}
		sl[x]=max(sl[x],tmp);
		++x;
	}
	if(a)
	{
		sl[a]=max(sl[a],1LL);
	}
}
void doc()
{
	cin>> n ; 
	FOR(i,1,n)cin>>a[i] ; 
	FOR(i,1,n)
	{
		pt(a[i]);
	}
	ll ans= 1 ; 
	FOR(i,2,n)
	{
		if(sl[i]%2==0)
		{
			ans=ans*binpow(i,sl[i])%sm;
		}
		else 
		{
			ans=ans*binpow(i,sl[i]+1)%sm;
		}
	}
	cout<<ans<<"\n";
}		

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    cin>>t ; 
    while(t--)
    {
    	init();
        doc();
    }
}