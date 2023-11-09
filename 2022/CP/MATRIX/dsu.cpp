#include<bits/stdc++.h>

#define TASK "union"
const bool multitest = false; 

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));; 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++)
#define pii pair<int,int>
#define vi vector<int>
#define ve vector
#define str string  
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;

const int N =2e5+5 ,maxN=20 ,  oo = 2e9,CH = 26  ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

struct DSU
 {
 	vi pa; 
 	void init(int n )
 	{
 		pa.resize(n+1) ; 
 		FOR(i,1,n)pa[i] = i; 
 	}
 	int goc(int u )
 	{
 		return pa[u] ==u  ? u : pa[u] =goc(pa[u]) ;
 	}
 	void hop(int u , int v)
 	{
 		int chau = goc(u) ; 
 		int chav = goc(v) ; 
 		if(chau== chav)return;  
 		pa[chau] = chav ;  
 	}
}dsu ;  
int n ; 

void read()
{
    cin>> n; 
}
void process()
{
    
}
void print()
{
    
}
signed main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout); 
    }
    int test = 1;  
    if(multitest)cin>>test; 
    while(test--)
    {
        read() ; 
        process();
        print() ; 
    }
    
}