#include<bits/stdc++.h>
using namespace std;

#define TASK "Moocast"
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

struct E 
{
	int u ,v ; 
	ll w ; 
	bool operator <(const E& a)const
	{
		return w<a.w; 
	}
};
struct pt
{
	int x , y;  
};
ll sq(ll a){return a*a;}
int n ; 
pt a[N] ;
ll res=0 ; 
int pa[N]  ;
vector<E>edge; 
ll dis(pt a, pt b)
{
	return sq(a.x-b.x)+sq(a.y-b.y);
}
int goc(int u)
{
	return pa[u]==u? u : pa[u]=goc(pa[u]);
}
void doc()
{
 	cin>> n; 
 	FOR(i,1,n)
 	{
 		cin>>a[i].x>>a[i].y;  
 		pa[i]= i ; 
 	}   
 	FOR(i,1,n)
 	{
 		FOR(j,i+1,n)
 		{
 			edge.pb({i,j,dis(a[i],a[j])});
 		}
 	}
 	sort(edge.begin(),edge.end()); 
 	int component =  n ;
 	FOR(i,0,edge.size()-1)
 	{
 		int u= edge[i].u ; 
 		int v= edge[i].v ;
 		int chau=  goc(u) ;  
 		int chav= goc(v) ; 
 		if(chau==chav)continue ; 
 		pa[chav]=chau;
 		component--; 
 		if(component==1)
 		{
 			cout<<edge[i].w;
 			return ; 
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
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}