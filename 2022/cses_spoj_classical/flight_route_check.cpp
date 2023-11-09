#include<bits/stdc++.h>
using namespace std;

#define TASK "flight_route_check"

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
int n  ,m  ;
int tplt = 0 , tt =0 ; 
int low[N] , id[N] ;
vector<int>g[N]  ; 
int tp[N] ;  
stack<int>st ;  
void dfs(int u)
{
	low[u] = id[u]= ++tt; 
	st.push(u) ;  
	for(auto v: g[u])
	{
		if(tp[v])continue; 
		if(id[v])
		{
			low[u]=min(low[u],id[v]);
		}
		else 
		{
			dfs(v); 
			low[u]=min(low[u],low[v]);
		}
	}
	if(low[u]==id[u])
	{
		int t  ;
		++tplt;
		do
		{
			t=st.top();  
			st.pop() ;
			tp[t] =tplt ;  
		}while(t!=u);
	}
}
void doc()
{
 	cin>> n >> m ;
 	FOR(i,1,m)
 	{
 		int u, v ; cin>>u>>v ; 
 		g[u].pb(v) ; 
 	}   
 	FOR(i,1,n){if(id[i]==0)dfs(i);}
 	if(tplt==1)
 	{
 		cout<<"YES" ;
 	}
 	else 
 	{
 		cout<<"NO"<<"\n";
 		int x, y; 
 		FOR(i,1,n)
 		{
 			if(tp[i] ==1 )
 			{
 				x=i  ;
 			}
 			else 
 			{
 				y= i ; 
 			}
 		}
 		cout<<x<<" "<<y ;
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