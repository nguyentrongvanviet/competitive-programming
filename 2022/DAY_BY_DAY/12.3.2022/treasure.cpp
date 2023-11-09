// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "TREASURE"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long 
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define int long long 
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define pll pair<ll,ll> 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm1 = 1e9+7,sm2=398122239,cs=441,inf = 1e17  ;  

pll gethash(int l ,int r ,pll ha[] , pll mu[])
{
	return {(ha[r].fi-ha[l-1].fi*mu[r-l+1].fi+sm1*sm1)%sm1,(ha[r].se-ha[l-1].se*mu[r-l+1].se+sm2*sm2)%sm2};
}
int n ,m ;
int x[N] ,y[N] ;
vector<pii>value; 
map<pii,int>pos ; 
int  a[N] , b[N] ;
pll ha[N] , hb[N] ; 
pll mu[N] ; 
void doc()
{
    cin>> n >>m ; 
    FOR(i,1,n)cin>>x[i] ;
    FOR(i,1,n-1)
    {
    	value.pb({x[i]/__gcd(x[i],x[i+1]),x[i+1]/__gcd(x[i],x[i+1])});
    }
    FOR(i,1,m)cin>>y[i] ; 
    FOR(i,1,m-1)
    {
    	value.pb({y[i]/__gcd(y[i],y[i+1]),y[i+1]/__gcd(y[i],y[i+1])});
    }
}
bool check(int len)
{
	vector<pll>dd ;  
	FOR(i,1,m-len+1)
	{
		dd.pb(gethash(i,i+len-1,hb,mu)) ;   
	}
	sort(all(dd));
	FOR(i,1,n-len+1)
	{
		pll value = gethash(i,i+len-1,ha,mu);
		int x = lower_bound(dd.begin(),dd.end(),value)-dd.begin();
		if(x!=dd.size())
		{
			if(dd[x]==value)return 1; 
		}
	}
	return 0 ; 
}
int tknp()
{
	int l = 1; 
	int r = min(n,m) ;  
	int ans=0;
	while(l<=r)
	{
		int mid =(l+r)/2; 
		if(check(mid)) 
		{
			ans=mid;  
			l=mid+1; 
		}
		else 
		{
			r=mid-1;  
		}
	}
	return ans ; 
}
void xuly()
{
    // sort(all(value));
    // value.resize(unique(all(value))-value.begin());
    FOR(i,0,(int)value.size()-1)pos[{value[i].fi,value[i].se}]=i+1 ; 
    FOR(i,1,n-1)
    {
    	a[i] = pos[{x[i]/__gcd(x[i],x[i+1]),x[i+1]/__gcd(x[i],x[i+1])}];
    }
    FOR(i,1,m-1)
    {
    	b[i] = pos[{y[i]/__gcd(y[i],y[i+1]),y[i+1]/__gcd(y[i],y[i+1])}];
    }
    --n ; 
    --m ;
    mu[0] ={1,1} ;
    FOR(i,1,max(n,m))mu[i].fi = mu[i-1].fi*cs%sm1,mu[i].se=mu[i-1].se*cs%sm2;
    FOR(i,1,n)
    {
    	ha[i].fi = (ha[i-1].fi*cs+a[i])%sm1; 
    	ha[i].se = (ha[i-1].se*cs+a[i])%sm2;  
    }
    FOR(i,1,m)
    {
    	hb[i].fi = (hb[i-1].fi*cs+b[i])%sm1; 
    	hb[i].se = (hb[i-1].se*cs+b[i])%sm2;  
    }
    int res = tknp();
    cout<<res+1; 
}
 main()
{
    IOS();  
    doc(); 
    xuly();
    return 0 ;
}