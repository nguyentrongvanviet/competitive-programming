#include<bits/stdc++.h>
using namespace std;

#define TASK "FKAND"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
    }
    int t = 1;
}

const int N =100+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int n  , k ;
ll a[N] , s[N] ; 
bool f[N][N];
ll tmp =1 ;
ll mu[70] ; 
void doc()
{	
	cin>> n >> k; 
	FOR(i,1,61)tmp*=2;	
	tmp-=1;
	FOR(i,1,n)cin>>a[i],s[i] =s[i-1]+a[i];
	mu[0] = 1 ; 
	FOR(i,1,63)
	{
		mu[i] =mu[i-1]*2; 
	}
}
void sub1()
{
	ll res = 0 ; 
	FOR(tt,1,(1<<n)-1)
	{
		if(__builtin_popcountll(tt)!=k)continue ; 
		int la = 0 ;
		ll ans =tmp;
		// cout<<bitset	<6>(tt)<<endl;
		FOR(i,1,n)	
		{
			if(tt&mu[i-1])
			{
				ans=(ans&(s[i]-s[la]));
				la=i ; 
			}
		}
		if(la!=n)continue;
		res=max(res,ans);
	}
	cout<<res;		
}
int main()
{
    IOS();  
    doc(); 
    if(n<=20)sub1();
    // xuly();/
}