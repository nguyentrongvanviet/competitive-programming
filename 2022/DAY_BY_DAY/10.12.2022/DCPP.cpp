/* 
author : Nguyen Trong Van Viet
class 11T2 Le Khiet High school 
Nick name : Billyisme
My life have changed so much since I met you. 
May be I am not the one who is suitable for you , I know how stupidly I am but please give me a chance I won't let you down. Believe me :( I hate the moment I lost you so much .
*/ 
#include<bits/stdc++.h>
using namespace std;

#define TASK "DCPP"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define int long long 
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

const int N =1e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct E 
{
	int u , v, c, w ;
};
int n , m; 
int deg[N];
int s, t ;
struct MAXFLOW
{
	vector<E> edge ; 
vi g[N] ;
int pre[N] ; 	
bool inq[N]  ; 
ll d[N] ;
void add(int u , int v, int c, int w )
{
	g[u].pb(edge.size()) ; 
	edge.pb({u,v,c,w}) ;	
	g[v].pb(edge.size()) ; 
	edge.pb({v,u,0,-w}) ;
}
bool ford(int s, int t )
{
	FOR(i,0,n+1)d[i] = inf ; 
	d[s]= 0 ; 

	queue<int>q ;
	inq[s] = 1; 
	q.push(s) ; 
	
	while(!q.empty())
	{
		int u= q.front() ; 
		inq[u] = 0 ; 
		q.pop() ; 
		for(auto it : g[u])
		{
			int u = edge[it].u ; 
			int v = edge[it].v ;  
			int c = edge[it].c ;
			int w = edge[it].w; 
			if(c>0&&d[v]>d[u]+w)
			{
				d[v]= d[u]+w ;
				if(!inq[v])
				{
					pre[v] = it;
					inq[v] =1 ; 
					q.push(v) ;
				}
			} 
		}
	}
	return d[t]!=inf ; 
}	
ll mcfl(int s ,int t )
{
	ll ans= 0;
	while(ford(s,t)	)
	{
		int mi = oo ; 
		for(int v = t ; v!=s ; v = edge[pre[v]].u )
		{
			int u = edge[pre[v]]. u ; 
			mi =min(mi,edge[pre[v]].c); 
		}
		ans+= mi*d[t];
		for(int v = t ; v!=s ; v = edge[pre[v]].u)
		{
			edge[pre[v]].c-=mi;
			edge[pre[v]^1].c+=mi; 
		}
	}
	return ans; 
}
}FL;
ll tmp = 0 ;
void doc()
{
	cin>> n >> m; 
	FOR(i,1,m)
	{
		int u ,v ,c ; 
		cin>>u>>v>>c;
		tmp+=c; 		
		deg[u]--; 
		deg[v]++;
		FL.add(u , v , oo, c );
	}
	s= 0 ; 
	t=n+1; 
	FOR(i,1,n)
	{
		if(deg[i]>0)
		{
			FL.add(s,i,abs(deg[i]),0);
		}
		else if(deg[i]<0)
		{
			FL.add(i,t,abs(deg[i]),0);
		}
	}

}
void xuly()	
{
	ll res = FL.mcfl(s,t) ;
	cout<<res+tmp; 
}
main()
{
	IOS();  
	doc(); 
	xuly();
}