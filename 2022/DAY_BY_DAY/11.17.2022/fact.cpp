#include<bits/stdc++.h>
using namespace std;

#define TASK "fact"

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

const int N =500+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n ; 
ll s[N] , c[N]  ; 
bool dd[N];
ll  ucln[N][N];
ll value[N][N];	
vector<int>g[N];
void dfs(int u , int root )
{
	dd[u] = 1;  
	for(auto v : g[u])
	{
		if(dd[v])continue ; 
		value[root][v] = value[root][u]+s[v];
		ucln[root][v] = __gcd((int)ucln[root][u],(int)c[v]);
		dfs(v,root) ;
	} 	
}
void doc()
{
   	cin>> n ; 
   	FOR(i,1,n)cin>>s[i] ; 
   	FOR(i,1,n)cin>>c[i] ; 
   	FOR(i,1,n-1)
   	{
   		int u ,v ;
   		cin>>u>>v ; 
   		g[u].pb(v) ; 
   		g[v].pb(u) ; 
   	}
   	FOR(i,1,n)
   	{
   		FOR(j,1,n)dd[j] = 0;
   		ucln[i][i]= c[i];
   		value[i][i]=s[i];
   		dfs(i,i);
   	}
   	ll res= -inf ; 
   	FOR(i,1,n)
   	{
   		FOR(j,i+1,n)
   		{
   			FOR(k,j+1,n)
   			{
   				if(__gcd(ucln[i][j],__gcd(ucln[j][k],ucln[k][i]))>1)
   				{
   					res=max(res,value[i][j]+value[j][k]+value[k][i]);
   				}
   			}
   		}
   	}
   	if(res==-inf)
   	{
   		cout<<"No Solution";
   	}
   	else 
   	{
   		cout<<res; 
   	}
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