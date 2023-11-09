#include<bits/stdc++.h>
using namespace std;

#define TASK "PFTREE"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".ANS","w",stdout); 
    }
    int t = 1;
}

const int N =1e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 
int n  ,q ;
ll res=0 , t = 0 ;
vector<int>g[N] ; 
vector<int>s[N] ;
void doc()
{
    cin>> n >>q ; 
    FOR(i,1,n-1)
    {
    	int u ,v ; 
    	cin>>u>>v ; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}
void merge(vector<int>&a , vector<int>&b)
{ 
	for(auto v: b)
	{
		a.pb(v) ;
	}
}
void dfs(int u , int p)
{
	s[u].pb(0);
	vector<int>tmp ; 
	for(int i= 0  ;i<(int)g[u].size();i++)
	{
		int v= g[u][i] ; 
		if(v==p)continue ; 
		dfs(v,u);
		merge(tmp,s[v]); 
	}
	for(auto x:tmp)
	{
		s[u].pb(x+1);
	}
	sort(s[u].begin(),s[u].end());
}
ll pw(ll a, ll n)
{
	if(n==0)return 1;  
	ll b= pw(a,n/2) ; 
	if(n&1)
	{
		return b*b%sm*a%sm;  
	}
	else
	{
		return b*b%sm; 
	}
}
ll query(int u)
{
	ll ans= 0 ;
	for(int i= 0 ;i<s[u].size();i++)
	{
		ans=(ans+s[u][i]*pw(t,i)%sm)%sm;		
	}
	return ans ; 
}
void xuly()
{
    dfs(1,0) ;
    ll s= 0 ; 
    FOR(i,1,q)
    {
    	int a , b ;
    	cin>>a>>b;  	
    	int u=1+(a+s)%n; 
    	t=1+(b+s)%(ll)1e9;
    	// cout<<u<<" "<<t<<endl; 
    	res=query(u) ;
    	s+=res;
    	cout<<res<<"\n";
    }
    // cout<<8<<"\n"<<9<<"\n"<<0<<endl;
}
signed main()
{
    IOS();  
    doc(); 
    xuly();
}