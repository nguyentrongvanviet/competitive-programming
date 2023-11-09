#define TASK "CIRCLE"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';

ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}

const int N =1e6+5, maxN=20, oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
int dd[N]  ,ne[N]  ; 
int deg[N] ;
void read()
{	
	cin>>n; 
	FOR(i,1,n)
	{
		cin>>ne[i] ; 
		deg[ne[i]]++ ; 
	}
}		

void solve()
{
	ve<pii>q; 
	FOR(i,1,n)if(deg[i]==0)
	{
		int u = i ; 
		int st=u  ;  
		while(dd[ne[u]]==0)
		{
			dd[u] =1 ; 
	 		u=ne[u] ; 
		}
		dd[u] =1 ;
		q.pb({st,u});
	}
	for(int i= 1;i<=n;i++)if(dd[i]==0)
	{
		int u= i ; 
		int st = u ;
		while(dd[ne[u]]==0)
		{
			dd[u] =1 ; 
			u=ne[u] ; 
		}
		dd[u] = 1 ; 
		q.pb({st,u}); 
	}
	if(q.size()==1)
	{
		if(ne[q[0].se]==q[0].fi)
		{
			cout<<0 ; 
		}
		else
		{
			cout<<1<<el;
			cout<<q[0].se<<" "<<q[0].fi;
		}
		return ; 
	}
	cout<<q.size()<<el;
	for(int i= 0 ;i<q.size()-1;i++)
	{
		cout<<q[i].se<<" "<<q[i+1].fi<<el;
	}
	cout<<q.back().se<<" "<<q[0].fi<<el;
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}