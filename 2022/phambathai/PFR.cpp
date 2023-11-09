#include<bits/stdc++.h>

#define TASK "PFR"
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
const int N =1e5+5 , maxN=20 , oo = 2e9, CH = 26 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
int ne[N] ,go[N];
vi g[N];
int ma= 0 ;
ll res= 0 ;
int dd[N] ;
vi Len_CT ;  
void read()
{
    cin>> n;
    FOR(i,1,n)cin>>ne[i],g[ne[i]].pb(i) ; 
}
int tmp = 0 ;
void dfs(int u ,int p ,int h )
{
	dd[u] = 1; 
	tmp=max(tmp,h) ;
	for(auto v: g[u])if(dd[v]!=2&&v!=p)
	{
		dfs(v,u,h+1);
	}
}
ll pw(ll a, ll n)
{
	if(n==0)return 1;   
	ll b= pw(a,n/2); 
	if(n&1)return b*b%sm*a%sm;  
	else return b*b%sm ;
}
int sl[N];
int nt[N] ;
void sieve()
{
	for(ll i = 2  ;i<=N-1;i++)
	{
		if(!nt[i])
		{
			nt[i]=i;
			for(ll j =i*i;j<=N-1;j+=i)
			{
				nt[j] = i ;
			}
		}
	}
} 
void pt(int d)
{
	while(d!=1)
	{
		int x= nt[d] ; 
		int tmp  = 0 ;
		while(d%x==0)
		{
			++tmp ; 
			d/=x;
		}
		sl[x]=max(sl[x],tmp); 
	}
}
void process()
{
	FOR(i,1,n)
	{
		if(dd[i])continue ;
		int u = i; 
		while(!dd[u])
		{
			dd[u]=1;
			int v=ne[u] ; 
			go[v]= u ; 
			u= ne[u];
		}
		dd[u]=2;
		int cur = u ; 
		vi CT ; 
		CT.pb(cur) ; 
		cur=go[cur] ;
		while(cur!=u)
		{
			CT.pb(cur);
			dd[cur]=2 ; 
			cur = go[cur] ;
		}
		Len_CT.pb(CT.size()) ;
		for(auto u : CT)
		{
			for(auto v  : g[u])
			{
				if(dd[v]!=2)
				{
					tmp = 0 ;
					dfs(v,0,1) ;
				}
				ma=max(ma,tmp) ;
			}
		}
	}	
}
void print()
{
	sieve();
	for(auto x: Len_CT)
	{
		pt(x) ;
	}
	ll res=1 ; 
	FOR(i,1,(int)1e5)res=res*pw((ll)i,sl[i])%sm;
    cout<<(res+ma)%sm; 
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