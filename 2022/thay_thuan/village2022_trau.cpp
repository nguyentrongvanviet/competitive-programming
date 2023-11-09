#include<bits/stdc++.h>
using namespace std;

#define TASK "village2022"

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
        freopen(TASK".ANS","w",stdout); 
    }
    int t = 1;
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int n ; 
ll a[N] ;
int dd[N] ;
ll res= 0 ; 
vector<int>g[N]  ; 
void doc()
{
 	cin>> n; 
 	FOR(i,1,n)cin>>a[i] ; 
 	FOR(i,1,n)g[i].clear();
    FOR(i,1,n-1)
 	{
 		int u ,v ; 
 		cin>>u>>v; 
 		g[u].pb(v); 
 		g[v].pb(u);
 	}   
 	FOR(i,0,(1<<n)-1)
 	{
 		ll ans =0  ;
 		FOR(j,1,n)dd[j] = 0 ;
 		FOR(j,1,n)
 		{
 			if(i>>(j-1)&1)
 			{
 				dd[j] = 1; 
 				ans+=a[j]  ; 
 			}
 		}	
 		FOR(j,1,n)
 		{
 			if(dd[j])continue ;
 			for(auto v: g[j])
 			{
 				if(dd[v])
 				{
 					ans+=a[j]; 
 					break; 
 				}
 			}
 		}
 		res=max(res,ans);
 	}
 	cout<<res;
}
void xuly()
{
    
}
int main()
{
    IOS();  
    int t =1 ;
    cin>>t ; 
    while(t--)
    {
    	doc(); 
    	xuly();
    }
}