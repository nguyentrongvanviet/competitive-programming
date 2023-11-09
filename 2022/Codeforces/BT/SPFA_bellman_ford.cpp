// code for fun code for TTMD 
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
	int v ; 
	ll w;  
} ; 
struct G
{
	int n , m; 
	vector<ke>g[N] ; 
	bool inq[N] ; 
	ll f[N] ; 
	void add(int u ,  int v,ll w)
	{
		g[u].pb(v);  
	}
	ll bellman_ford(int s )
	{
		queue<int>q;  
		FOR(i,1,n)
		{
			f[i] = -inf ; 
		}
		f[s]= 0 ; 
		q.push(s) ; 
		while(!q.empty())
		{
			int u= q.front() ; 
			q.pop() ; 
			inq[u] = 0;
			for(auto it :g[u])
			{
				int v = it.v; 
				int c = it.c;
				if(f[v]>f[u]+c)
				{
					f[v]=f[u]+c ; 
					if(inq[v]==0)q.push(v),inq[v]=1 ;
				}
			}
		}
	}
}graph ; 
int n ;  
vector<int>g[N] ; 
void doc()
{
   	cin>>n>>m ; 
   	FOR(i,1,u)
   	{
   		int u ,v ; 
   		ll w  ; 
   		cin>>u>>v>> w ; 
   		graph.add(u,v,w) ; 
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