#include<bits/stdc++.h>
using namespace std;

#define TASK "ICBUS"
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
const int N =5e3+1 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

struct bg
{
	int u ; 
	ll val;  
	int cl ; 
}; 
struct cmp
{
	bool operator()(bg a,  bg b )
	{
		return a.val>b.val ;
	}
}; 
int n , m ;
int a[N],  f[N][10001] ,dd[N][10001] ; 
int d[N] ;
vector<int>g[N] ; 
void doc()
{
 	cin>> n>>  m ; 
 	FOR(i,1,n)cin>>a[i]>>d[i] ; 
 	FOR(i,1,m)
 	{
 		int u ,v ; cin>>u>>v ; 
 		g[u].pb(v) ; 
 		g[v].pb(u) ; 
 	}
}
void xuly()
{
	priority_queue<bg,vector<bg>,cmp>q;
	FOR(i,1,n)FOR(j,0,n)f[i][j]=oo ; 
	f[1][0]= 0 ; 
	q.push({1,0,0}) ; 
	while(!q.empty())
	{
		int u= q.top().u ; 
		ll val = q.top().val; 
		int cl = q.top().cl; 
		q.pop(); 
		if(dd[u][cl])continue ; 
		dd[u][cl]=1 ;
		FOR(i,0,g[u].size()-1)
		{
			int v =g[u][i] ;
			if(cl)
			{
				if(dd[v][cl-1])continue ;
				if(f[v][cl-1]>f[u][cl])
				{
					f[v][cl-1] = f[u][cl] ;
					q.push({v,f[v][cl-1],cl-1 });
				}
				if(f[v][0]>f[u][cl])
				{
					f[v][0] = f[u][cl] ; 
					q.push({v,f[v][0],0});
				}
			}
			else 
			{
				if(f[u][d[u]]>f[u][0]+a[u])
				{
					f[u][d[u]] = f[u][0] +a[u] ;
					q.push({u,f[u][d[u]],d[u]}); 
				}	
			}
		}
	} 
	int res= oo ;
	for(int i= 0;i<=n;i++)
	{
		res=min(res,f[n][i]);
	}
	cout<<res;
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
        xuly(); 
    }
    return 0;
}