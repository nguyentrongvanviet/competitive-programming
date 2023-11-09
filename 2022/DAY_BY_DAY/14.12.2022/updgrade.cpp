/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "updgrade"

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

struct BG 
{
	int u ; 
	bool used ;
	ll w ; 
};
struct ke 
{
	int v,  w;  
};
struct cmp
{
	bool operator()(BG a , BG b)
	{
		return a.w > b.w; 
	}
};
int n  ,m , q; 
vector<ke>g[N] ; 
ll d[N][2] ; 
bool dd[N][2] ; 
void dij(int s ,int t ,ll f[][2] )
{
	FOR(i,1,n)f[i][0]=f[i][1] = inf , dd[i][0] = dd[i][1] = 0  ;
	priority_queue<BG,vector<BG>,cmp>q ;
	f[s][0]=0; 
	q.push({s,0,f[s][0]}); 
	while(!q.empty())
	{
		int u= q.top().u ;
		bool used = q.top().used;
		ll w= q.top().w; 
		q.pop() ;
		if(dd[u][used])continue ; 
		dd[u][used] =1; 
		for(auto it : g[u])
		{
			int v= it.v; 
			int w= it.w;  
			if(used==0)
			{
				if(f[v][0]>f[u][0]+w)q.push({v,0,f[v][0]=f[u][0]+w});
				if(f[v][1]>f[u][0]) q.push({v,1,f[v][1]=f[u][0]}); 
			}	
			else 
			{
				if(f[v][1]>f[u][1]+w)q.push({v,1,f[v][1]=f[u][1]+w});
			}
		}
	}
}
void doc()
{
    cin>> n >> m >>q ;
    FOR(i,1,m)
    {
    	int u ,v ,w ; 
    	cin>>u>>v>>w; 
    	g[u].pb({v,w}); 
    }
    dij(1,n,d);
    while(q--)
    {
    	int s ,t; 
    	cin>>s>>t;  
    	cout<<min(d[s][0],d[s][1]+t)<<"\n";
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