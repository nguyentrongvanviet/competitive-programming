#include<bits/stdc++.h>
using namespace std;

#define TASK "gameshow"

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

const int N =5e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n  ; 
ll T ; 
ll a[N] ;
ll f[N][N];
void doc()
{	
    cin>>n >> T ; 
	FOR(i,1,n)cin>>a[i] ;
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			f[i][j] =-inf;
		}	
	}
	if(a[1]<0)
	{
		cout<<-1 ;
		return ;
	}
	f[1][1] = a[1] ;
	FOR(i,2,n-1)
	{
		FOR(j,1,i)
		{
			if(a[i]+f[i-1][j-1]>=0)
			{
				f[i][j] =max(f[i][j],f[i-1][j-1]+a[i]);
			}
			if(f[i-1][j]-T>=0)
			{
				f[i][j] =max(f[i][j],f[i-1][j]-T);
			}
			// cout<<f[i][j]<<" ";
		}
	}
	FOR(i,1,n-1)
	{
		if(f[n-1][i]+a[n]>=0)
		{
			cout<<i+1;
			return ;
		}
	}
	cout<<-1; 
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
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}