#include<bits/stdc++.h>
using namespace std;

#define TASK ""

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
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

struct ke
{
	int v , w; 
};
vector<ke>g[N] ;
vector<int>value ;
int n  ,q ;
void dfs(int u ,int p,int g  )
{	

}
void doc()
{
    cin>> q ; 
    n= 1 ; 
    FOR(i,1,q)
    {
    	string t ;
    	cin>>t ; 
    	if(t[0]=='A')
    	{
    		int u , v; 
    		cin>>u>> v; 
    		++ n ;
    		g[u].pb({n,v}); 
    		// g[n].pb({u,v});
    	}
    	else 
    	{
    		int u ,v ; 
    		cin>>u>>v;
    		value.clear() ; 
    		dfs(v,0);
    	}
    }
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}