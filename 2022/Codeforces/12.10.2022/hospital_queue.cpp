// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "hospital_queue"

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

const int N =2e3+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , m;  
int a[N] ; 
vi g[N] ;
int b[N] ;  
void doc()
{
	cin>>n>> m; ; 
	FOR(i,1,n)cin>>a[i]; 
	FOR(i,1,m)
	{
		int u ,v ; 
		cin>>u>>v ; 
		g[v].pb(u) ; 
	}
	FOR(i,1,n)
	{
		FOR(j,1,n)b[j] =0 ;
		FOR(j,1,n)for(auto v :g[j])b[v]++; 
		priority_queue<pii>q;  	
		FOR(v,1,n)if(v!=i&&!b[v])q.push({a[v],v});  
		FORD(pos,n,1)
		{
			if(q.empty()||q.top().fi<pos)
			{
				cout<<pos<<" "; 
				break; 
			}
			int u  =  q.top().se ; 
			q.pop() ;	
			for(auto v : g[u])
			{
				b[v]--; 
				if(v!=i&&!b[v])
				{
					q.push({a[v],v}) ;
				}
			}
		}
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