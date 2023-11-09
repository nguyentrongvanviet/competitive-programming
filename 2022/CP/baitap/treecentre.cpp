#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back 
#define pk pop_back 
#define pii pair<int,int> 

const int N= 2e5+5 ,oo = 1e9 ; 
const ll  inf = 1e17 , sm =1e9+7 ; 

ll n ; 
ll a[N] ; 
vector<int>g[N] ;
vector<int>res; 
vector<int>leaf;
vector<int>newleaf ;
vector<int> ctree()
{
	
	for(int i= 1;i<=n;i++)
	{
		if(a[i]==1)leaf.pb(i) ; 
	}
	int cnt=leaf.size();    
	while(cnt<n)
	{
		newleaf.clear() ; 
		for(int i = 0 ;i<leaf.size();i++)
		{
			int u = leaf[i] ; 
			for(int j = 0 ;j<g[u].size();j++)
			{
				int v= g[u][j];
				a[v]-- ; 
				if(a[v]==1)newleaf.pb(v);  
			}
		}
		cnt+=newleaf.size();
		leaf=newleaf; 
	}
	return leaf; 
}
void inp()
{
	cin>> n ; 
	for(int i= 1;i<=n-1;i++)
	{
		int u , v; 
		cin>>u>>v ;
		g[u].pb(v) ; 
		g[v].pb(u) ; 
		a[u]++;  
		a[v]++ ; 
	}
	if(n==1)
	{
		cout<<1<<"\n";
		return ;
	}
	res=ctree();
	cout<<res.size() <<"\n"; 
	sort(res.begin(),res.end()) ; 
	for(int i = 0;i<res.size();i++)cout<<res[i]<<" "; 
}
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	freopen("i.txt","r",stdin) ; 
	freopen("o.txt","w",stdout) ; 
	inp() ; 
}
