#include<bits/stdc++.h>
using namespace std;

#define TASK "SFARM"
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
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n , m ;
vector<int>g[N] ; 
int pa[N] , dd[N] ; 
int a[N] ; 
int res[N];
int component = 0;
int goc(int u )
{
	return pa[u] ==u ? u : pa[u] =goc(pa[u]);
}
void doc()
{		
    cin>> n>>m; 
   	FOR(i,1,m)
   	{
   		int u , v ;  
   		cin>> u>> v; 
   		g[u].pb(v) ; 
   		g[v].pb(u) ;  
   	}
   	FOR(i,1,n)cin>>a[i] , pa[i]= i ; 
  	FORD(i,n,1)
  	{
  		component++; 
  		int u= a[i]  ; 
  		dd[u] = 1; 
  		for(int v : g[u])
  		{
  			if(dd[v])
  			{
  				int chau = goc(u) ; 
  				int chav = goc(v) ; 
  				if(chau==chav)continue ; 
  				pa[chau]=chav; 
  				component--;
  			}
  		}
  		if(component==1)
  		{
  			res[i] = 1;
  		}
  	}
  	FOR(i,1,n)
  	{
  		if(res[i])
  		{
  			cout<<"YES"<<'\n' ; 
  		}
  		else 
  		{
  			cout<<"NO"<<'\n';
  		}
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
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}