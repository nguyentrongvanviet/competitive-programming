#include<bits/stdc++.h>
using namespace std;

#define TASK "OR"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define int long long 
#define FOR(i,a,b)  for(ll i= a;i<=b;i++)
#define FORD(i,a,b) for(ll i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =5e6+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  ,k , l , r ; 
int a[N] ;

void doc()
{
 	cin>>n >> k >> l>> r  	; 
 	FOR(i,1,n)cin>>a[i] ;    
}
ll f[205][450][205];
void sub1()
{
 	f[0][0][0]=1;
	FOR(i,1,n)
	{
		FOR(j,0,400)
		{
			f[i][0][0] =1 ;
			FOR(x,1,k)
			{
				f[i][j][x]+=f[i-1][j][x]  ;
				f[i][j][x]%=sm; 
				if(j|a[i]<=400-1)f[i][j|a[i]][x]+=f[i-1][j][x-1];
				if(j|a[i]<=400-1)f[i][j|a[i]][x]%=sm;
			}
		}
	}	
	ll res= 0 ; 
	FOR(i,l,min(400LL-1LL,r))
	{
		if(i%3!=0)continue;
		res+=f[n][i][k]%sm;
		res%=sm;  
	}
	cout<<res;
}
ll fac[N] ;
ll sl[25] ;  
ll binpow(ll a , int n )
{
	if(n==0)return 1 ; 
	ll b= binpow(a,n/2) ; 
	if(n&1)
	{
		return b*b%sm*a%sm; 
	}
	else 
	{
		return b*b%sm;
	}
}
ll tohop(ll n ,ll k  )
{
	if(n<k)return 0 ; 
	ll u =fac[n] ; 
	ll v= fac[k] ; 
	ll t= fac[n-k] ; 
	return u*binpow(v*t%sm,sm-2)%sm; 
}
void sub2()
{
	if(l%3!=0)
	{
		cout<<0  ;
		return ; 
	}
	FOR(i,1,n)
	{
		sl[(int)log2(a[i])]++;
	}
	fac[0] = 1 ; 
	FOR(i,1,(int)1e6)
	{
		fac[i] = fac[i-1]*i%sm; 
	}
	ll res=0 ; 
	int z= __builtin_popcount(l); 
	FOR(i,1,l)
	{
		if((i|l)==l)
		{
			int u =0 ;  
			for(int  j= 0 ;j<=20;j++)
			{
				if(i>>j&1)
				{
					u+=sl[j];
					u%=sm;
				}
			}
			int g = __builtin_popcount(i); 
			if((z-g)%2!=0)
			{
				res=(res-tohop(u,k)+sm)%sm;
			}	
			else 
			{
				res=(res+tohop(u,k))%sm;
			}
		}
	}
	cout<<res;
}
ll dp[5+(1<<21)];
ll dd[5+(1<<21)];
void sub4()
{
	fac[0] = 1 ; 
	FOR(i,1,(int)1e6)fac[i]=fac[i-1]*i%sm;
	FOR(i,1,n)
	{
		dp[a[i]]++ ;
	}
	FOR(j,0,20)
	{
		FOR(i,1,(1<<21)-1)
		{
			if(i>>j&1)
			{
				dp[i]+=dp[i^(1<<j)];
				// dp[i]%=sm; 
			}
		}
	}
	// int u = __builtin_popcountll(l) ; 
	// ll res=0 ; 
	// FOR(i,1,(1<<21)-1)
	// {
	// 	if((i|l)==l)
	// 	{
	// 		int v=  __builtin_popcountll(i) ; 
	// 		ll x =tohop(dp[i],k);
	// 		// if(x>sm)while(1);
	// 		// ll x= 0 ;
	// 		if((u-v)%2==0)
	// 		{
	// 			res+=x ; 
	// 			res%=sm ; 
	// 		}
	// 		else 
	// 		{
	// 			res-=x;
	// 			res+=sm; 
	// 			res%=sm;
	// 		}
	// 	}
	// }
	FOR(i,0,(1<<21)-1)
	{
		ll x = tohop(dp[i],k); 
		ll d = __builtin_popcount(i) ; 
		if(d&1)
		{
			dd[i]=x ;
		}
		else
		{
			dd[i]=-x;
			dd[i]+=sm; 
			dd[i]%=sm;
		}
	}
	FOR(j,0,20)
	{
		FOR(i,1,(1<<21)-1)
		{
			if(i>>j&1)
			{
				dd[i]+=dd[i^(1<<j)];
				dd[i]+=sm;  
				dd[i]%=sm; 
			}
		}
	}
	ll res=0 ; 
	FOR(i,l,r)
	{
		ll d= __builtin_popcount(i) ; 
		if(i%3==0)
		{
			if(d&1)
			{
				res+=dd[i] ; 
			}
			else 
			{
				res-=dd[i] ; 
			}
			res=(res+sm)%sm;
		}
	}
	cout<<res;
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
        // if(n<=2000&&l!=r)sub1();
        // else if(l==r)sub2();
        sub4();
    }
    return 0;
}
