#include<bits/stdc++.h>
using namespace std;

#define TASK "FKAND"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define int long long 
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
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
}

const int N =100+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int n  , k ;
ll a[N] ,s[N] ; 
int f[N][N];
ll mu[63];
void doc()
{	
	cin>> n >> k; 
	FOR(i,1,n)cin>>a[i],s[i] =s[i-1]+a[i]; 
	mu[0] = 1; 
	FOR(i,1,62)mu[i]=mu[i-1]*2; 
}
int check(ll val , int x )
{
	memset(f,0,sizeof(f)) ;
	FOR(i,1,n)
	{
		FOR(j,0,k)
		{
			f[i][j] = 0;
		}
	}
	ll tmp =(val|mu[x]); 
	FOR(i,1,n)
	{		
		if((s[i]&tmp)==tmp)
		{
			f[i][1] =1;
		}
	}
	FOR(j,2,k)
	{
		FOR(i,1,n)
		{
			FOR(ii,1,i-1)
			{
				if(((s[i]-s[ii])&tmp)==tmp)
				{
					f[i][j]|=f[ii][j-1];
				}
			}
		}
	}
	return (f[n][k]==1);
}
void xuly()
{
	ll res= 0  ;
	FORD(i,62,0)
	{		
		if(check(res,i)==1)
		{
			res|=mu[i] ; 
		}
	}
	cout<<res;
}
main()
{
    IOS();  
    doc(); 
    // if(n<=20)sub1();
    xuly();
}