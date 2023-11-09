#include<bits/stdc++.h>
using namespace std;

#define TASK "road_reparation"

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
	int u ,v  ; 
	ll c ; 
	bool operator < (const E& a)const
	{
		return c<a.c; 
	}
};

int n , m ;
int pa[N] ;
E edge[N] ;
int goc(int u)
{
	return pa[u]==u?u:pa[u]=goc(pa[u]) ;
}
int hop(int u ,int v )
{
	int chau = goc(u) ; 
	int chav = goc(v) ; 
	if(chau==chav)return 0 ; 
	else 
	{
		pa[chau] = chav; 
		return 1 ; 
	}
}
ll res = 0 ;
void doc()
{
 	cin>>n>>m ;
 	FOR(i,1,n)pa[i]= i ; 
 	FOR(i,1,m)
 	{
 		int u ,v ;
 		ll c; 
 		cin>>u>>v>>c;  
 		edge[i]={u,v,c} ; 
 	}   
 	sort(edge+1,edge+m+1) ;
 	int canh = 0 ; 
 	FOR(i,1,m)
 	{
 		if(hop(edge[i].u,edge[i].v))
 		{
 			++canh;
 			res+=edge[i].c; 
 		}
 	}
 	if(canh!=n-1)
 	{
 		cout<<"IMPOSSIBLE" ;
 		return ;
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
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
 	   }
}