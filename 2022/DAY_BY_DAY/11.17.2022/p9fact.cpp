#include<bits/stdc++.h>
using namespace std;

#define TASK "p9fact"

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

const int N =1e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n ; 
int nt[N*10];
vector<int>snt;
set<int>dinh[N*10];
vector<int>g[N]; 
void thieve()
{
	for(ll i= 2 ;i<=(ll)1e6;i++)
	{
		if(nt[i]==0)
		{
			nt[i] = i ;
			snt.pb(i);
			for(ll j= i*i;j<=(ll)1e6;j+=i)
			{
				nt[j]=i;
			}
		}
	}
}
ll a[N] ; 
ll f[N][4] ; 
bool dd[N] ;
void doc()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ;
	FOR(i,1,n)
	{
		int x;
		cin>>x; 
		while(nt[x])
		{
			int u=  nt[x] ; 
			while(x%u==0)
			{
				x/=u; 
			}
			dinh[u].insert(i); 
		}
	}
	for(int i= 1;i<=n-1;i++)
	{
		int u ,v ; cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
	}
}
ll res=-inf ;
void dfs(int u, int p ,int uoc )
{
	dd[u] = 1;
	f[u][1]=2*a[u] ; 
	ll ma1= -inf ; 
	ll ma2= -inf ; 
	// cout<<u<<"\n";
	ll aa = -inf ; 
	ll bb = -inf ; 
	multiset<int>s ;
	for(int v :g[u])
	{
		if(v==p||dinh[uoc].find(v)==dinh[uoc].end())continue ;
		dfs(v,u,uoc);
		if(aa!=-inf&&f[v][2]!=-inf)
		{
			f[u][3] =max(f[u][3],2*a[u]+aa+f[v][2]); 
		}
		s.insert(f[v][1]);
		if(s.size()>3)
		{
			s.erase(s.find(*s.begin()));
		}
		if(bb!=-inf&&f[v][1]!=-inf)
		{
			f[u][3] =max(f[u][3],2*a[u]+bb+f[v][1]);
		}
		aa=max(aa,f[v][1]) ;
		bb=max(bb,f[v][2]);
		if(f[v][1]!=-inf)f[u][1]= max(f[u][1],f[v][1]+2*a[u]);
		if(f[v][2]!=-inf)f[u][2]=max(f[u][2],f[v][2]+2*a[u]);
		if(f[v][1]>=ma1)
		{	
			ma2= ma1; 
			ma1=f[v][1];
		}
		else if(f[v][1]>ma2)
		{
			ma2=f[v][1]; 
		}
		if(f[v][2]!=-inf)f[u][3] =max(f[u][3],f[v][2]+2*a[u]);
	}
	if(ma1!=-inf&&ma2!=-inf)f[u][2] =max(f[u][2],ma1+ma2+a[u]*3);
	if(ma1!=-inf)f[u][2] =max(f[u][2],ma1+a[u]*3);
	if(ma1!=-inf&&ma2!=-inf)
	{
		f[u][3]=max(f[u][3],ma1+ma2+3*a[u]);
	}
	if(s.size()==3)
	{
		ll tmp = 0 ;
		for(auto v :s)
		{
			tmp+=v; 
		}
		f[u][3]=max(f[u][3],3*a[u]+tmp);
	}
	// cout<<u<<" "<<f[u][1]<<" "<<f[u][2]<<" "<<f[u][3]<<"\n";
	res=max(res,f[u][3]);
}
void xuly()
{ 
	for(auto x :snt) 
	{
		for(auto u : dinh[x])
		{
			dd[u] = 0 ;
			// cout<<u<<" ";
			for(int i =1 ;i<=3;i++)f[u][i]=-inf; 
		}	
		for(auto u : dinh[x])
		{
			if(dd[u]==0)
			{
				dfs(u,0,x) ; 
			}
		}
	}	
	if(res==-inf)
	{
		cout<<"No Solution"; 
	}
	else 
	{
		cout<<res;
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
    thieve() ; 
    doc() ; 
    xuly();
}