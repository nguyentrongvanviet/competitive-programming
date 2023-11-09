/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
// 1900 dp on tree 
#include<bits/stdc++.h>
using namespace std;

#define TASK "path_in_the_tree"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}
const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ,m ;  ;
ll a[N];
unordered_map<int,ll>f[N] ;
vi g[N]; 
void doc()
{
    cin>> n >> m; 
    FOR(i,2,n)
    {		
    	int u ;
    	cin>>u ; 
    	g[u].pb(i) ;
    }
    FOR(i,1,n)cin>>a[i] ; 
}	
ll dfs(int u , int k )
{
	if(f[u].find(k)!=f[u].end())return f[u][k] ;
	int sz = g[u].size(); 
	ll ans  = a[u]*k; 	
	if(sz==0)
	{
		f[u][k] = ans ;  
		return f[u][k] ;
	}
	if(k%sz==0)
	{
		for(auto v  : g[u])
		{
			ans+=dfs(v,k/sz) ;
		}
	}
	else 
	{
		int nk = k/sz;   
		vector<ll>value ; 
		for(auto v : g[u])
		{
			ll x= dfs(v,nk) ;
			ll y= dfs(v,nk+1) ; 
			ans+=x;  
			value.pb(y-x) ; 
		}
		sort(all(value),greater<ll>());
		FORN(i,0,k-nk*sz)
		{
			ans+=value[i] ; 
		}
	}
	return f[u][k]=ans;  
}
void xuly()
{
   	cout<<dfs(1,m)<<'\n'; 
}
void clear()
{
	FOR(i,1,n)
	{
		g[i].clear() ; 
		f[i].clear() ;
	}
}
main()
{
    IOS();
    int test ;
    cin>>test;
    while(test--)
    {
    	doc(); 
    	xuly();
    	clear();
    }
}