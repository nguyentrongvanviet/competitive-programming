#include<bits/stdc++.h>
using namespace std;

#define TASK "cpath"

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
#define int long long 
const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
struct E 
{
	int u, v , c;  
	bool operator <(const E&a )const
	{
		return c<a.c; 
	}
};
int n  , m , w , na , nb ; 
int pa[N] ;
E edge[3*N] ;
int sz1[N] , sz2[N] ; 
bool dd1[N] ,dd2[N] ;
ll res=0  ;
ll tmp ;
int goc(int u){return pa[u]==u? u : pa[u] =goc(pa[u]);} 
void  hop(int u ,int v )
{
	int chau = goc(u) ; 
	int chav = goc(v) ;
	if(chau==chav)return ; 
	tmp+=sz1[chau]*sz2[chav]+sz1[chav]*sz2[chau]; 
	pa[chau] =chav; 
	sz1[chav]+=sz1[chau] ; 
	sz2[chav]+=sz2[chau] ; 
}
ll tinh(ll w )
{
	FOR(i,1,n)
	{
		pa[i] = i ; 
		sz1[i] =sz2[i] = 0 ;
		if(dd1[i])sz1[i]=1 ; 
		if(dd2[i])sz2[i]=1 ; 
	}
	tmp =0  ; 
	FOR(i,1,m)
	{
		int u= edge[i].u ; 
		int v= edge[i].v;
		int c= edge[i].c ; 
		if(c>w)break;   
		hop(u,v) ; 
	}
	return tmp ;
}
void doc()
{
    cin>> n >>  m >> w >>na >>nb ; 
    FOR(i,1,m)
    {
    	int u ,v , c;  cin>>u>>v>>c ; 
    	edge[i] ={u,v,c} ; 
    }	
    sort(edge+1,edge+m+1);
    FOR(i,1,na)
    {
    	int u ; cin>>u; 
    	dd1[u]=1 ; 
    }
    FOR(i,1,nb)
    {
    	int u ; 
    	cin>> u; 
    	dd2[u] = 1 ;
    }
    ll x= tinh(w) ; 
    ll y = tinh(w-1) ; 
    cout<<x-y;
}

signed main()
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