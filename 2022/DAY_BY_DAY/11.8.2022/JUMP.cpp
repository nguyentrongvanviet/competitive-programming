#include<bits/stdc++.h>
using namespace std;

#define TASK "JUMP"
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
const int N =1e3+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;


int BUFF(string x )
{
	int ans= 0 ; 
	for(int i= 0 ;i<x.size();i++)
	{
		ans=ans*10+x[i]-'0';
	}
	return ans ;
}
int n  , m , k  ;
int a[N] , b[N] ; 
ll f[N][N];
int x[N][N];
void doc()
{
    cin>>n>>m>>k;
    FOR(i,1,n)
    {
    	cin>>a[i] ;
    }
    FOR(i,1,m)
    {
    	cin>>b[i] ; 
    }
    FOR(i,1,n)
    {
    	FOR(j,1,m)
    	{
    		if(i==1&&j==1)
    		{
    			f[i][j] = 1 ; 
    		}
    		else 
    		{
    			FOR(ii,1,i-1)
    			{
    				if(x[ii][j]>=i-ii)
    				{
    					f[i][j]=(f[i][j]+f[ii][j])%sm;
    				}
    			}
    			FOR(jj,1,j-1)
    			{
    				if(x[i][jj]>=j-jj)
    				{
    					f[i][j] = (f[i][j]+f[i][jj])%sm;
    				}
    			}
    		}
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
        doc();
    }
    return 0;
}