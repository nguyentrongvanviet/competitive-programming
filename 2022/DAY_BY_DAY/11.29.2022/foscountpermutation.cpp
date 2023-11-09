#include<bits/stdc++.h>
using namespace std;

#define TASK "foscountpermutation"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}
#define ll long long 
const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
int a[N]  ; 
vector<int>g[N]  ;
int c[N] ;
int f[N] , sz[N] ; 
int fac[N] ; 
int cong(int a, int b)
{
	return ((ll)a+(ll)b)%sm;
} 
int nhan(int a , int b)
{
	return (ll)a*(ll)b%sm ; 
}
int pw(int a , int n )
{
	if(n==0)return 1;  
	int b = pw(a,n/2) ; 
	if(n&1)return nhan(nhan(b,b),a) ; 
	return nhan(b,b) ;
}

int C(int k , int n )
{	
	ll tu = fac[n] ; 
	ll mau = nhan(fac[k],fac[n-k]);
	return nhan(tu,pw(mau,sm-2));
}
void doc()
{	
    cin>>n ; 
    fac[0] = 1;  
   	FOR(i,1,n)
   	{
   		fac[i] =  nhan(fac[i-1],i) ; 
   	}
   	FOR(i,1,n)
   	{
   		cin>>a[i] ;  
   	}
   	stack<int>st ; 
   	FORD(i,n,1)
   	{
   		while(!st.empty()&&a[st.top()]<a[i])st.pop();  
   		if(st.empty())
   		{
   			c[i] = n+1;  
   		}
   		else 
   		{
   			c[i] = st.top() ; 
   		}
   		st.push(i) ; 
   	}
   	FORD(i,n,1)
   	{ 
   		g[c[i]].pb(i);
   	}
}
void dfs(int u , int p)
{
	f[u] =1 ; 
	for(int i =0;i<g[u].size();i++)
	{
		int v = g[u][i] ; 
		if(v==p)continue ; 
		dfs(v,u); 
		sz[u]+=sz[v] ; 
		f[u]=nhan(C(sz[v]-1,sz[u]-1),nhan(f[u],f[v]));
		// if(u==n+1)cout<<f[u]<<" ";
	}
	sz[u]++;
}
void xuly()
{
    dfs(n+1,0) ; 
    cout<<f[n+1];
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}