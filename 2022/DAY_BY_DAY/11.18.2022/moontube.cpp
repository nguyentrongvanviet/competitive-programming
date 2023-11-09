#include<bits/stdc++.h>
using namespace std;

#define TASK "moontube"

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
struct E
{
	int u , v, c; 
	E(){} 
	E(int _u ,int _v ,int _c){u=_u;v=_v;c=_c;}
	bool operator <(const E & a )const
	{
		return c>a.c ; 
	}
}; 
struct Q 
{
	int u ,  c, id ; 
	bool operator < (const Q &a)const
	{
		return c>a.c ; 
	}
};
int n  ,  q ; 
int pa[N] , sz[N] ;
E edge[N] ;  
Q query[N*10]; 
int res[N] ; 
int goc(int u )
{	
	return pa[u]==u ? u : pa[u]=goc(pa[u]) ; 
}
void hop(int u , int v )
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return ;  
	pa[chau] = chav ; 
	sz[chav]+=sz[chau];
}
void doc()
{
	cin>>n >>q; 
	FOR(i,1,n-1)
	{
		int u , v,  c ; 
		cin>>u>>v>>c ; 
		edge[i] = {u,v,c};  
	}   
	FOR(i,1,n)pa[i] =i , sz[i] = 1; 
	FOR(i,1,q)
	{
		cin>>query[i].c>>query[i].u ; 
		query[i].id =i ;  
	} 
	sort(edge +1,edge+n) ; 
	sort(query+1,query+q+1) ;
	int it = 1 ;
	FOR(i,1,q)
	{
		int u = query[i].u ; 
		int c= query[i].c;  
		while(edge[it].c>=c&&it<=n-1)
		{
			// cout<<edge[it].c<<" ";
			hop(edge[it].u,edge[it].v) ; 
			++it ; 
		}
	// /	cout<<query[i].id<<" A "<<"\n";
		res[query[i].id]=sz[goc(u)]-1;
	}
	cout<<"\n";
	FOR(i,1,q)cout<<res[i]<<"\n";
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