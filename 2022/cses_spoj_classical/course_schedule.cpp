#include<bits/stdc++.h>
using namespace std ; 


#define TASK "course_schedule"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0)  ; cout.tie(0) ; 
#define ll long long 
#define FOR(i,a,b) for(int  i=a;i<=b;i++)
#define FORD(i,a,b)for(int i =a ;i>=b;i--)
#define pb push_back
#define pk pop_back 
#define pii pair<int,int> 
#define fi first 
#define se second 
#pragma GCC target("popcnt") 

const int N =2e5+5 , oo = 2e9 ; 
const ll inf = 1e17 , cs = 331  , sm= 1e9+7 ; 

int n , m; 
vector<int>g[N];
vector<int>res ; 
int bac[N] ;
void doc()
{
	cin>>n>>m ; 
	FOR(i,1,m)
	{
		int u , v; 
		cin>>u>>v ; 
		g[u].pb(v) ; 
		bac[v]++ ; 
	}
	queue<int>q;  
	FOR(i,1,n)
	{
		if(bac[i]==0)
		{
			q.push(i) ; 
		}
	}
	while(!q.empty())
	{
		int u= q.front() ; 
		q.pop() ; 
		res.pb(u);
		for(auto v: g[u])
		{
			bac[v]-- ; 
			if(bac[v]==0)
			{
				q.push(v) ; 
			}
		} 
	}
	if(res.size()!=n)
	{
		cout<<"IMPOSSIBLE";
	}
	else 
	{
		for(auto u : res)cout<<u<<" ";
	}
}
void xuly()
{

}
int main()
{
	fast
	if(fopen(TASK".INP","r"))
	{
		freopen(TASK".INP","r",stdin) ; 
		freopen(TASK".OUT","w",stdout) ; 
	}
	doc() ; 
	xuly() ; 
}