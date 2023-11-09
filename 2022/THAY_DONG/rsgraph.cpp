#include<bits/stdc++.h>

#define TASK "rsgraph"
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
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n  ,m; 
ll fac[N] ; 
ll pw(ll a, ll n)
{
	if(n==0)return 1;   
	ll b= pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;  
	else return b*b%sm ;
}
ll C(int n , int k)
{
	if(n<k)return 0 ; 
	ll tu =fac[n] ; 
	ll mau = fac[k]*fac[n-k]%sm; 
	return tu*pw(mau,sm-2)%sm;
}	
vi q[N]; 
vi g[N]; 
int d[N] ;
int ma= 0 ; 
void read()
{
    cin>> n >>m ;


    q[0].pb(1) ; 
    FOR(i,2,n)
    {
    	cin>>d[i] ;  
    	ma=max(ma,d[i]);
    	q[d[i]].pb(i);
    }
    FOR(i,1,m)
    {
    	int u ,v ; 
    	cin>>u>>v; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ;
    }
    fac[0] = 1; 
    FOR(i,1,n)fac[i] = fac[i-1]*i%sm;  
}
void process()
{
	ll res=1;
	int s= 1 ; 
	int tr =1 ;  
	FOR(i,1,ma)
	{
		if(q[i].size()==0)
		{
			cout<<0 ; 
			return ; 
		}
		int cnt= 0 ;
		int c=0  ; 
		ll tmp = 1;     
		for(auto u : q[i])
		{
			int x=0 ; 
			for(auto  v :g[u])
			{
				if(d[v]==d[u])
				{
					cnt++;
				} 
				else if(d[u]-d[v]>1) 
				{	
					cout<<0 ;
					return ; 
				}	
				else if(d[v]+1==d[u])
				{
					++x ; 
				}
			}
			if(x==0)tmp=tmp*(pw(2,tr)-1)%sm;
			else tmp*pw(2,tr-x)%sm;
		}
		int sz= q[i].size() ;
		int g= C(sz,2)-cnt;
		// cout<<pw(2,g)<<" "<<g<<endl;
		res = res*pw(2,g)%sm*tmp%sm;
		tr=q[i].size();
		res%=sm;
	}
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