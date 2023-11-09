#include<bits/stdc++.h>
using namespace std;

#define TASK "lisys"

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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n , m , s;  
void doc()
{
	cin>> n>>m>>s ; 
	vector<vector<int>>a(n+5,vector<int>(m+5,0));
	vector<vector<int>>x(n+5,vector<int>(m+5,0));
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			cin>>a[i][j] ;
		}
	}	   
	FOR(i,1,s)
	{
		int u  ; 
		cin>> u ; 
		if(u>n)
		{
			u-=n;
			x[1][u]++; 
			x[1][u+1]--;
		}
		else 
		{ 	
			x[u][1]++;
			x[u+1][1]--;
		}
	}
	int res=0 ;
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			x[i][j]+=x[i-1][j]+x[i][j-1]-x[i-1][j-1] ; 
			if((a[i][j]+x[i][j])%3==0)
			{
				res++;
			}
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
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}