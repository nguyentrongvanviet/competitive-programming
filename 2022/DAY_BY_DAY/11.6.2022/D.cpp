#include<bits/stdc++.h>
using namespace std;

#define TASK "D"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 998244353,cs=330 ,inf = 1e17 ;

int n  ; 
ll m ;
ll a[N]  ; 
ll f[N] ; 
vector<ll> phantich(ll n )
{
	vector<ll>ans ;
	ll x =2; 
	while(x*x<=n)
	{
		bool ok = 0 ;
		while(n%x==0)
		{
			ok =1 ;
			n/=x; 
		}
		if(ok)ans.pb(x) ; 
		++x;
	}
	if(n!=1)
	{
		ans.pb(n);
	}
	return ans ;
}
void doc()
{
    cin>>n>> m;  
    for(int i= 1;i<=n;i++)cin>>a[i] ;  
}
void xuly()
{	
	for(int i=1 ;i<=n-1;i++)
	{
		if(a[i]%a[i+1]!=0)
		{
			cout<< 0<<"\n";
			return ;
		}
	}
	vector<ll>fac = phantich(a[1]) ; 
	f[1] = 1; 
	for(int i=2;i<=n;i++)
	{
		vector<ll>uoc ; 
		ll x= a[i-1]/a[i]; 
		for(int j=0  ;j<fac.size();j++)
		{
			if(x%fac[j]==0)
			{
				uoc.pb(fac[j]) ; 
			}
		}
		ll k = (ll)uoc.size();
		ll ans=  0 ; 
		for(ll bit = 1;bit<(1<<k);bit++)
		{
			ll u =1 ; 
			ll sl = __builtin_popcount(bit) ; 
			for(int j = 0 ;j<k;j++)
			{
				if(bit>>j&1)
				{
					u*=uoc[j] ; 
				}
			}
			if(sl&1)
			{
				ans+=m/a[i]/u;
			}
			else 
			{
				ans-=m/a[i]/u;
			}
			ans=(ans+sm)%sm;
		}
		ans= (m/a[i]-ans+sm)%sm; 
		f[i] =f[i-1]*ans%sm;
	}
	cout<<f[n]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    cin>>t;
    while(t--)
    {
        doc();
        xuly();
    }
    return 0;
}