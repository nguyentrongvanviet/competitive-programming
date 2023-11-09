#define TASK "D"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
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
const int N =3e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n;  
int a[N] ; 
int nt[N] ; 
vi g[N] ;
vi D[N] ;
void snt()
{
	for(ll i= 2 ;i<=550;i++)
	{
		if(nt[i]==0)
		{
			nt[i] = i ; 	
			for(ll j = i*i;j<=(ll)3e5;j+=i)
			{
				nt[j] = i; 
			}
		}
	}
	for(ll i = 2;i<=(ll)3e5;i++)
	{
		if(nt[i] ==0  )nt[i] = i ;
	}
}
void read()
{
	cin>> n ; 
	FOR(i,1,n)cin>>a[i]  ;
}	
void pt(int a, int idx)
{
	while(a!=1)
	{
		int x = nt[a] ;
		g[x].pb(idx) ;  
		D[idx].pb(x);
		while(a%x==0)a/=x ;
	}
}
vi  bfs(int s , int t )
{
	queue<int>q ;
	ve<int>pre(n+1,0) ; 
	ve<int>used(N+1,0) ;
	pre[s] = -1; 
	q.push(s); 
	while(!q.empty())
	{
		int u =q.front() ; q.pop() ; 
		for(auto uoc: D[u])
		{
			if(used[uoc])continue ;
			used[uoc] =1; 
			for(auto v : g[uoc])
			{
				if(pre[v]==0)
				{
					pre[v] = u  ; 
					q.push(v);
				}
			}
		}
	}
	return pre; 
}
void solve()
{
	FOR(i,1,n)pt(a[i],i) ; 
	int s , t; 
	cin>>s>>t ;
	vi pre = bfs(s,t) ; 
	if(pre[t]==0)return void(cout<<-1);
	vi res; 
	while(t!=-1)
	{
		res.pb(t) ; 
		t=pre[t] ; 
	} 
	reverse(all(res)) ;
	cout<<res.size()<<el; 
	for(auto u : res)cout<<u<<" ";
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
    	snt() ; 
        read(); 
        solve();
    }
}