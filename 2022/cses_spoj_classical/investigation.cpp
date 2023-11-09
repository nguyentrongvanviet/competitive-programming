#include<bits/stdc++.h>
using namespace std;

#define TASK "investigation"

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
struct ke 
{
	int v; 
	ll c ;
}; 
struct DL
{	
	int u ; 
	ll val;  
};
struct cmp
{
	bool operator()(DL a , DL b)
	{
		return a.val>b.val;
	}
};
int n , m ; 
bool dd[N] ; 
vector<ke>g[N] ;
ll f1[N] , d1[N] ;
int mi1[N] , ma1[N] ; 
void dij(int s , ll f[] ,ll d[N],int mi[],int ma[] )
{
	priority_queue<DL,vector<DL>,cmp>q;
	FOR(i,1,n)
	{
		f[i] = inf ;
		dd[i] = 0 ; 
		d[i] = 0 ; 
	}
	q.push({s,f[s]=0});
	d[s] = 1 ; 
	mi[s] =0  ;
	ma[s] = 0 ; 
	while(!q.empty())
	{

		int u = q.top().u ;
		q.pop() ;
		if(dd[u])continue ; 
		dd[u] =1 ; 
		for(auto it: g[u])
		{
			int v = it.v ; 
			ll c =it.c ;
			if(dd[v])continue ; 
			if(f[v]>f[u]+c)
			{
				mi[v] =mi[u]+1; 
				ma[v] =ma[u]+1; 
				d[v]= d[u] ;
				q.push({v,f[v]=f[u]+c});
			}
			else if(f[v]==f[u]+c)
			{
				mi[v] =min(mi[v],mi[u]+1);  
				ma[v] =max(ma[v],ma[u]+1);
				d[v]+=d[u];
				d[v]%=sm;  
			}
		}
	}
} 
void doc()
{
 	cin>>n>>m ; 
 	FOR(i,1,m)
 	{
 		int u ,v  ; 
 		ll cp ; 
 		cin>>u>>v>>cp ; 
 		g[u].pb({v,cp}); 
 	}   
 	dij(1,f1,d1,mi1,ma1);
 	cout<<f1[n]<<" "<<d1[n]<<" "<<mi1[n]<<" "<<ma1[n];
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