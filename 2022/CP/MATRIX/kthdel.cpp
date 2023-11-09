#include<bits/stdc++.h>

#define TASK "kdel"
const bool multitest = true; 

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));; 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b
using namespace std;


void IOS()
{

}
const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
ll k ;
ll a[N] ; 
ll res=0  ;
void read()
{
    cin>> n >> k; 
    FORN(i,0,n)cin>>a[i] ; 
}
ll sl(ll value)
{
	ll ans =0 ;
	FORN(msk,1,(1<<n))
	{
		ll val = 1; 
		FORN(i,0,n)
		{
			if(msk>>i&1)
			{
				val=lcm(val,a[i]);
			}
		}
		if(btpc(msk)&1)ans+=value/val;
		else ans-=value/val;
	}
	// cout<<value-ans<<endl;
	return value-ans; 
}
void process()
{
	res=0 ;
	ll  l= 1; 
	ll r= inf; 
	while(l<=r)
	{
		ll mid=(l+r)/2 ;
		if(sl(mid)>=k)
		{
			res=mid; 
			r=mid-1;  
		}
		else
		{
			l=mid+1;
		}
	} 	
}
void print()
{
	cout<<res<<'\n';
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
    
}