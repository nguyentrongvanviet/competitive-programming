// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "DP_3"
#define int long long 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
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

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct ke
{
	int v, c ; 
}; 
int n ; 
vector<ke>g[N] ; 
int dd[N] ,sz[N] ; 
ll res=0 ; 
int f[2][2] ; 
void doc()
{
	cin>> n; 
	FOR(i,1,n-1)
	{
		int u ,v ,c ; 
		cin>>u>>v>>c; 
		g[u].pb({v,c}) ;
		g[v].pb({u,c}) ;
	}    
}
void predfs(int u , int p)
{
	sz[u]=1 ; 
	for(auto it: g[u])
	{
		int v = it.v;  
		if(dd[v]||v==p)continue ; 
		predfs(v,u) ; 
		sz[u]+=sz[v];  
	}
}
int centroid(int u , int  p , int n )
{
	for(auto it : g[u])
	{
		int v= it.v ; 
		if(dd[v]||v==p)continue; 
		if(sz[v]>n/2)
		{
			return centroid(v,u,n) ; 
		}
	}
	return u ; 
}

int d[2][2] ;
void dfs_11_10(int u , int p , int khong )
{
	if(khong==0)d[1][1]++;
	else d[1][0]++;
	for(auto it : g[u])
	{
		int v = it.v; 
		int c= it.c;  
		if(v==p||dd[v])continue ; 
		if(khong)
		{
			if(c==0)dfs_11_10(v,u,khong);
		}
		else 
		{
			if(c==1)dfs_11_10(v,u,khong) ; 
			else if(c==0)dfs_11_10(v,u,1);
		}
	}
}
void dfs_00_01(int u ,int p , int mot)
{
	if(mot==0)d[0][0]++;
	else d[0][1]++;
	for(auto it : g[u])
	{
		int v =it.v; 
		int c= it.c; 
		if(v==p||dd[v])continue; 
		if(mot)
		{
			if(c==1)dfs_00_01(v,u,mot) ;
		}
		else 
		{
			if(c==1)dfs_00_01(v,u,1) ; 
			else if(c==0) dfs_00_01(v,u,0);
		}
	}
}
// centroid decomposition 

void solve(int u , int p )
{
	dd[u] =1 ; 
	ll value =0 ;
	memset(f,0,sizeof(f)) ;
	for(auto it : g[u])
	{
		memset(d,0,sizeof(d)) ;
		int  v= it.v ; 
		int c= it.c;  
		if(dd[v]||v==p)continue;
		if(c==1)dfs_11_10(v,u,0);
		else dfs_00_01(v,u,0); 
		if(c==1)
		{
			value+=(d[1][1]*f[1][1]) ; // 1 thuan chung
			value+=(d[1][0]*f[1][1]) ;

			value+=(d[1][1]*f[1][0]);
			value+=(d[1][1]*f[0][0]);
			value+=(d[1][1]*f[1][1]);
		}
		else if(c==0)
		{
			value+=(d[0][0]*f[0][0]);// 0 thuan chung
			value+=(d[0][0]*f[0][1]); 
			value+=(d[0][0]*f[1][1]);	

			value+=(d[0][0]*f[0][0]);
			value+=(d[0][1]*f[0][0]);  
		}
		FOR(i,0,1)FOR(j,0,1)f[i][j]+=d[i][j] ;
	}
	value+=2*f[1][1]+2*f[0][0]+f[0][1]+f[1][0];
	res+=value; 
	// cout<<u<<" "<<value<<endl;
	for(auto it :g[u])
	{
		int v = it.v;
		if(v==p||dd[v])continue ; 
		predfs(v,u);
		solve(centroid(v,u,sz[v]),u);
	}
}	
void xuly()
{
    predfs(1,0) ; 
    // res=2*(n-1);
   	solve(centroid(1,0,n),0) ;
   	cout<<res;
}
signed main()
{
    IOS();  
    doc(); 
    xuly();
}