#include<bits/stdc++.h>
using namespace std;

#define TASK "LPATH2"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =3e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

struct ke 
{
	int v  ; 
	ll w; 
} ; 
int n , m ;
vector<ke>g[N] ; 
int exist[N];  
int d[N];
ll f[N] ; 
int s , t ;
void dfs(int u )
{
	if(u==t)
	{
		exist[u] = 1 ;
		f[u] = 0 ;
		return ; 
	}
	if(d[u])return ;  
	for(int i= 0 ; i<g[u].size();i++)
	{
		int v= g[u][i].v ;
		ll w= g[u][i].w;
		dfs(v) ;
		if(exist[v]==0)continue;
		exist[u] =1 ; 
		f[u]=max(f[u],f[v]+w);
	}
	d[u] =1 ;  
}  
void doc()
{
    cin>> n>> m ; 
    cin>>s>>t; 
    for(int i=1 ;i<=n;i++)f[i]=-inf;
    for(int i=1 ;i<=m;i++)
    {
    	int u ,v ;  ll c;  
    	cin>>u>>v >>c ; 
    	g[u].pb({v,c}) ;
    }
   	dfs(s); 
   	ll res=f[s];
   	if(res==-inf)
   	{
   		cout<<-1; 
   	}
   	else 
   	{
   		cout<<res;
   	}
}	

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
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
    }
    return 0;
}