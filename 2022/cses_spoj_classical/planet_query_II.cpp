#include<bits/stdc++.h>
using namespace std; 
#define TASK "planet_query_II"

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
const int LO = 20 ; 
int n ,q ; 
int after[N] ;  
int pa[N][LO+3];
vector<int>g[N]; 
int dd[N] ; 
int d[N] ; 
int total= 0 ;
int tp[N] ;
pii pos[N]  ;
void bfs(int u  )
{
	d[u] =1 ;
	queue<int>q; 
	q.push(u);
	while(!q.empty())
	{
		int u  =q.front() ; 
		q.pop() ; 
		for(auto v : g[u]) 
		{
			d[v] = d[u]+1 ; 
			q.push(v) ;  
		}
	}
}

void doc()
{
 	cin>>n >>q ;
 	FOR(i,1,n)dd[i] =-2 ; 
 	FOR(i,1,n)
 	{
 		int u ; 
 		cin>>u ; 
 		after[i] = u ; 
 		pa[i][0] = u ;
 		g[u].pb(i);   
 	} 
 	int sl =0 ;
 	FOR(i,1,n)
 	{
 		int u=  i ; 
 		if(dd[u]!=-2)continue ;
 		vector<int>q; 
 		q.pb(u) ; 
 		while(dd[after[u]]==-2)
 		{
 			dd[u] =-3;  
 			u=after[u] ;
 			q.pb(u) ; 
 		}
 		bool cycle= 0  ;
 		int tmp = 0;
 		for(auto v : q)
 		{
 			if(v==after[u])
 			{
 				cycle= 1;  
 			}
 			if(cycle)
 			{
 				++tmp ;  
 				dd[v]=sl+1; 
 			}
 			else dd[v] =-1 ;
 		}
 		if(cycle)++sl;
 		for(int i= 0  ;i<q.size();i++)
 		{
 			int v= q[i] ; 
 			if(dd[v]>0)
 			{
 				pos[v] ={i+1,tmp};
 			}
 		}
 	}
 	FOR(u,1,n)
 	{
 		if(dd[u]==-1&&dd[after[u]]>=1)
 		{
 			bfs(u) ; 
 		}	
 	}
 	FOR(j,1,LO)
 	{
 		FOR(i,1,n)
 		{
 			pa[i][j] = pa[pa[i][j-1]][j-1] ; 
 		}
 	}
 	auto goup =[&](int u ,int dis)
 	{
 		FOR(j,0,LO)
 		{
 			if(dis>>j&1)
 			{
 				u=  pa[u][j] ; 
 			}
 		}
 		return u ;
 	};
 	FOR(i,1,q)
 	{
 		int u ,v ; 
 		cin>>u>>v; 
 		// cout<<goup(u,n) <<" "<<goup(v,n)<<"\n";
 		// cout<<dd[goup(u,n)]<<" "<<dd[goup(v,n)]<<"\n";
 		if(dd[goup(u,n)]!=dd[goup(v,n)])
 		{
 			cout<<-1<<'\n';   
 		}
 		else if(dd[u]>0&&dd[v]==-1)
 		{
 			cout<<-1<<'\n' ; 
 		}
 		else if(dd[u]==-1&&dd[v]==-1) 
 		{
 			int dif =d[u] -d[v] ; 
 			int nu = goup(u,dif);
  			if(nu!=v)
 			{
 				cout<<-1<<"\n";  
 			}
 			else 
 			{
 				cout<<dif<<"\n";
 			}
 		}	
 		else 
 		{
 			int x= d[u] ; 
 			u= goup(u,x) ;
 			int a=  pos[u].fi; 
 			int b =pos[v].fi;  
 			int c= pos[u].se; 
 			if(a<=b)
 			{
 				cout<<x+b-a<<"\n";
 			}
 			else 
 			{
 				cout<<x+c-a+b<<"\n";
 			}
 		}
 	}
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