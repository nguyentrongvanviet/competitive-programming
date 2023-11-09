#include<bits/stdc++.h>
using namespace std;

#define TASK "ROBOT5"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =200+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  , m ; 
int nt[N] ;
ll f[N][N];
int a[N][N];
void snt()
{
	nt[0] = -1; 
	nt[1] = -1;
	for(ll i=2 ;i<=200;i++)
	{
		if(nt[i]==0)
		{
			nt[i] =i ;  
			for(ll j= i*i;j<=200;j+=i)
			{
				nt[j] = i ;
			}
		}
	}
}
void doc()
{
    cin>> n>>m; 
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j]; 
    FOR(i,1,n)FOR(j,1,m)
    {
    	if(i==1&&j==1)
    	{
    		f[i][j]=1 ; 
    	}
    	else 
    	{
    		int val  =abs(a[i][j]-a[i-1][j]); 
    		if(nt[val]==val)f[i][j] +=f[i-1][j] ; 
    		val =abs(a[i][j]-a[i][j-1]);
    		if(nt[val]==val)f[i][j]+=f[i][j-1];
    		f[i][j]%=sm;
    	}
    }
    cout<<f[n][m];
}	
int main()
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
    	snt();
        doc();
    }
    return 0;
}