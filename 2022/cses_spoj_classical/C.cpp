#include<bits/stdc++.h>
using namespace std;

#define TASK "C"

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

const int N =104+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n ; 
set<int>res[N]; 
vector<int>g[N] ;
bool dd[N] ;
void dfs(int u)
{
	if(dd[u])return ; 
	dd[u] =1 ; 
	for(auto v: g[u])
	{
		dfs(v);  
		res[u].insert(res[v].begin(),res[v].end()); 
	}
}
void doc()
{
 	cin>> n  ;
 	FOR(i,1,n)
 	{
 		dd[i] = 0 ;
 		g[i].clear() ; 
 		res[i].clear() ;
 	}
 	FOR(i,1,n)
 	{
 		FOR(j,1,n)
 		{
 			char x ; cin>>x ; 
 			if(x=='1')
 			{
 				g[j].pb(i) ; 
 			}
 		}
 	}   
 	FOR(i,1,n)
 	{
 		res[i].insert(i) ; 
 	}
 	FOR(i,1,n)
 	{
 		if(dd[i]==0)dfs(i) ;
 	}
 	FOR(i,1,n)
 	{
 		cout<<res[i].size()<<" "; 
 		for(auto v : res[i])cout<<v<<" ";
 		cout<<"\n";
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
    cin>>t ; 
    while(t--)
    {
        doc();
    }
}