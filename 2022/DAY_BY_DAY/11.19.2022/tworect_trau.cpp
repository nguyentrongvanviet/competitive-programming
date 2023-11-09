#include<bits/stdc++.h>
using namespace std;

#define TASK "tworect"

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

const int N =1e3+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n  , m ; 
int f[N][N] ;
int s[N][N] ; 
int a[N][N]  , ma[N][N] ;
int sum(int u ,int v, int i , int j )
{
	return s[i][j] -s[i][v-1]-s[u-1][j]+s[u-1][v-1];
}
void doc()
{
    cin>>n >> m; 
    int t= 0 ; 
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		cin>>a[i][j] ;
    		t+= (a[i][j]==0);
    		s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1] +a[i][j] ; 
    	}
    }
    if(t<2)
    {
    	cout<<0 ; 
    	return ;
    }
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		f[i][j] = max(f[i-1][j],f[i][j-1]); 
    		if(a[i][j]==0)
    		{
    			FOR(u,1,i)
    			{
    				FOR(v,1,j)
    				{
    					if(sum(u,v,i,j)==0)
    					{
    						f[i][j] = max(f[i][j],(i-u+1)*(j-v+1));
    					}
    				}
    			}
    		}
    	}	
    }
    FORD(i,n,1)
    {
    	FORD(j,m,1)
    	{
    		ma[i][j] = max(ma[i+1][j],ma[i][j+1]); 
    		if(a[i][j]==0)
    		{
    			FOR(u,i,n)
    			{
    				FOR(v,j,m)
    				{
    					if(sum(i,j,u,v)==0)
    					{
    						ma[i][j] = max(ma[i][j],(u-i+1)*(v-j+1));
    					}
    				}
    			}
    		}
    	}	
    }
    int res=0  ;
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		res=max(res,f[i][j]+max(ma[i+1][1],ma[1][j+1]));
    	}
    }
    cout<<res;
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}