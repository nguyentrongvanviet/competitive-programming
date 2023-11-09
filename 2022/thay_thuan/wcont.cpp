#include<bits/stdc++.h>
using namespace std;

#define TASK "wcont"

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
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n  , q; 
int ma= 0 ;
int sl[N] ; 
vector<int>g[N];
int h[N] ;
void doc()
{
	cin>>n >>q; 
	FOR(i,1,n-1)
	{
		int u ,v ; 
		cin>>u>>v ;
		g[u].pb(v) ;
		g[v].pb(u) ; 
	}
	FOR(i,1,q)
	
			int x;  cin>>x; 
	}
}
void dfs(int u , int p )
{
	ma=max(ma,h[u]);
	sl[h[u]]++;
	for(auto v: g[u])
	{
		if(v==p)continue ; 
		h[v]=h[u]+1;
		dfs(v,u);
	}
}
void xuly()
{
	ma=0 ; 
	dfs(1,0);
	int res= 0 ;
	int s= 0 ; 
	FOR(i,0,ma)
	{
		if(s+sl[i]>q)
		{
			break ;
		}
		else 
		{
			s+=sl[i];
			res+=sl[i];
		}
	}
	cout<<res<<"\n";
}
void init()
{
	FOR(i,0,n)
	{
		g[i].clear() ; 
		sl[i]= 0 ;
		h[i] = 0 ;
	}
}
int main()
{
	IOS();
	int test ;
	cin>>test;
	while(test--)
	{
		doc();
		xuly();
		init();
	}
}