#include<bits/stdc++.h>

#define TASK "booksort2"
const bool multitest = false; 
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0), srand(time(0));
#pragma GCC target("popcnt")
#define ll long long 
#define db long double  
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define vi vector<int>
#define ve vector 
#define str string 
#define pll pair<ll,ll>
#define fi first 
#define se second
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define FORN(i,a,b) for(int i= a;i<b;i++) 
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  a/gcd(a,b)*b 
using namespace std;
const int N =2e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
struct DL
{
	ll val;  
	int pos ; 
	bool operator<(const DL&a)const
	{
		return val<a.val;  
	}
};
int n ; 
DL a[N] ;
ll mi1 = inf , mi2 =inf ;
void read()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i].val , a[i].pos=  i,mi1=min(mi1,a[i].val);  
}
vi g[N] ;
int dd[N] ;
ll tmp  , k  ;
void dfs(int u )
{
	++k;
	dd[u] =1 ;  
	tmp+=a[u].val;
	mi2 = min(mi2,a[u].val);
	for(auto v: g[u])
	{
		if(dd[v]==0)dfs(v);  
	}
}
void process()
{
	sort(a+1,a+n+1) ; 
 	FOR(i,1,n)
 	{
 		g[a[i].pos].pb(i);
 	}   
 	ll res=0 ; 
 	FOR(i,1,n)
 	{
 		if(dd[i])continue ; 
 		k = 0 ;
 		tmp =0 ; 	
 		mi2 = inf;
 		dfs(i) ; 
 		if(k>1)res+=min(2*(mi1+mi2)+mi1*(k-1)+tmp-mi2,mi2*(k-1)+tmp-mi2); 
 	}
 	// if(res==0)while(1);
 	cout<<res;
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