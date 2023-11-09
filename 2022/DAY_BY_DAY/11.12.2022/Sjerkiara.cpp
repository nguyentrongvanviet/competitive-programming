#include<bits/stdc++.h>
using namespace std;

#define TASK "Sjerkiara"
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
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n ; 
int a[N] ; 
int ma[N] , pa[N] ;
int goc(int u )
{
	return pa[u] == u  ? u : pa[u]=goc(pa[u]); 
}
struct E 
{
	int u , v;
	bool operator <(const E&x)const
	{
		return max(a[u],a[v])<max(a[x.u],a[x.v]);
	}  
};
E edge[N];
void doc()
{
 	cin>>n ; 
 	FOR(i,1,n)
 	{
 		cin>>a[i] ; 
 	}   
 	FOR(i,1,n-1)
 	{
 		int u ,v ;  
 		cin>>u>>v ; 
 		edge[i]={u,v}; 
 	}
 	FOR(i,1,n)
 	{
 		pa[i] = i ; 
 		ma[i] = a[i];
 	}
 	sort(edge+1,edge+n) ; 
 	ll res = 0 ;
 	FOR(i,1,n-1)
 	{
 		int u= edge[i].u ; 
 		int v = edge[i].v ; 
 		int chau = goc(u) ; 
 		int chav = goc(v) ; 
 		res+=ma[chau]+ma[chav] ;
 		pa[chau] = chav; 
 		ma[chav]  =max(ma[chau],ma[chav]); 
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
    }
    return 0;
}