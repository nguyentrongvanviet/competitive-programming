#include<bits/stdc++.h>
using namespace std;

#define TASK "VM08"
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()

const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n ,q;  
vector<int>g[N] ;
int a[N] ;  
int tt = 0 ;
int head[N]  , pos[N] ; 
int bit[N] ;
int sz[N] ,pa[N] ;
int node[N];
void doc(){
    cin>> n>> q; 
    for(int i=1 ;i<=n-1;i++)
    {
    	int u , v ; 
    	cin>>u>>v; 
    	g[u].pb(v) ; 
    	g[v].pb(u) ; 
    }
}	

void predfs(int u , int p )
{
	sz[u]=1; 
	if(g[u][0]==p)
	{
		swap(g[u][0],g[u][g[u].size()-1]);
	}
	for(int i= 0 ;i<g[u].size();i++)
	{
		int v =g[u][i];
		if(v==p)continue; 
		predfs(v,u);
		pa[v]=u;
		if(sz[v]>sz[g[u][0]])swap(g[u][0],g[u][i]);
		sz[u]+=sz[v] ;
	}
}
void HLD(int u , int p )
{
	++tt;
	pos[u]=tt;
	node[tt] = u;
	if(sz[u]==1)return;
	head[g[u][0]]=head[u]; 
	HLD(g[u][0],u);
	for(int i= 1 ;i<g[u].size();i++)
	{
		int v =g[u][i]; 	
		if(v!=p)
		{
			head[v]=v; 
			HLD(v,u);
		}
	}
}
void up(int idx,int val)
{
	for(int i = idx;i<=n;i+=i&-i)
	{
		bit[i]+=val;  
	}
}
int get(int idx)
{
	int ans= 0  ; 
	for(int i = idx;i;i-=i&-i)
	{
		ans+=bit[i]; 
	}
	return ans; 
}

int Sum(int l , int r)
{
	return get(r)-get(l-1);
}
int query(int u )
{
	int l = 0 ,r = 0 ;
	while(u)
	{
		int x=Sum(pos[head[u]],pos[u]);
		if(x>0)
		{
			l = pos[head[u]] ; 
			r = pos[u] ; 
		}
		u=pa[head[u]];
	}	
	if(l==0&&r==0)return -1 ; 
	int ans= 0 ; 
	int L= l ;
	while(l<=r)
	{
		int mid =(l+r)/2; 
		if(Sum(L,mid))
		{
			ans=mid  ;
			r=mid-1; 
		}
		else 
		{
			l=mid+1;
		}
	}
	return node[ans];
}
void xuly()
{
	predfs(1,0);
	head[1]=1 ;
	HLD(1,0);
	while(q--)
	{
		int t , u ; cin>>t>>u ; 
		if(t==0)
		{
			if(a[u])
			{
				a[u]=0 ; 
				up(pos[u],-1);
			}
			else 
			{
				a[u]=1;  
				up(pos[u],1);
			}
		}
		else 
		{
			cout<<query(u)<<"\n";
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
        xuly();
    }
    return 0;
}