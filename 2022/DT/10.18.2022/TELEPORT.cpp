#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

struct ke
{
	int v ; 
	ll w ; 
};
int n  , m , p  , l  ,  k ; 
vector<ke>g[N] ; 
void input()
{
    cin>> n >> m >>p >> l>> k ; 
    for(int i=1;i<=m;i++)
    {
    	int u , v  ; 
    	ll w; 
    	cin>>u>>v>> w;  
    	g[u].pb({v,w});
    	g[v].pb({u,w});
    }
}
struct bg0 
{
	int u ;  
	ll val ; 
};
struct cmp
{
	bool operator()(bg0 a , bg0 b)
	{
		return a.val>b.val ;
	}
};
ll f[N]  ;  
int dd[N];
void sub0()
{
	priority_queue<bg0,vector<bg0>,cmp> q; 
	for(int i =1;i<=n;i++)
	{
		f[i] =inf ; 
	}
	f[1] = 0 ; 
	q.push({1,0}); 
	while(!q.empty())
	{
		int u = q.top().u ; 
		q.pop() ; 
		if(dd[u])continue ; 
		dd[u]= 1 ; 
		for(int i= 0 ;i<g[u].size();i++)
		{
			int v =g[u][i].v;
			ll w=g[u][i].w;
			if(dd[v])continue ;
			if(f[v]>f[u]+w)
			{
				f[v]=f[u]+w; 
				q.push({v,f[u]+w});
			}
		}
	}
	cout<<f[n]; 
}
struct bg1
{
	int u ; 
	ll val; 
	int k ;  
};
struct cmp1
{
	bool operator()(bg1 a , bg1 b)
	{
		return a.val>b.val; 
	}
};
vector<int>g2[N] ;
void sub1()
{
	vector<vector<int>>d(n+1,vector<int>(n+1,oo));
	for(int i= 1;i<=n;i++)
	{
		d[i][i]=0;
		for(int j= 0 ;j<g[i].size();j++)
		{
			d[i][g[i][j].v]=1;
		}
	}
	for(int k =1;k<=n;k++)
	{
		for(int i= 1;i<=n;i++)
		{
			for(int j=1 ;j<=n;j++)
			{
				if(d[i][j]>d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	for(int i=1 ;i<=n;i++)
	{
		for(int j=1 ;j<=n;j++)
		{
			if(d[i][j]>1&&d[i][j]<=l)
			{
				g2[i].pb(j);
			}
		}
	}
	priority_queue<bg1,vector<bg1>,cmp1>q; 
	vector<vector<ll>>f(n+1,vector<ll>(k+1,inf));
	vector<vector<int>>dd(n+1,vector<int>(k+1,0));
	f[1][0]=0;
	q.push({1,0,0});
	ll res=inf ; 
	while(!q.empty())
	{
		int u =q.top().u ; 
		int nk  = q.top().k ;
		if(u==n)
		{
			cout<<f[u][nk]<<"\n";
			return ; 
		}
		q.pop() ; 
		if(dd[u][nk])continue ; 
		dd[u][nk]=1;
		for(int i= 0 ;i<g[u].size();i++)
		{
			int v= g[u][i].v;  
			ll w= g[u][i].w;  
			if(dd[v][nk])continue;
			if(f[v][nk]>f[u][nk]+w)
			{
				f[v][nk]=f[u][nk]+w;
				q.push({v,f[v][nk],nk});
			}
		}
		if(nk==k)continue;
		for(int i= 0;i<g2[u].size();i++)
		{
			int v=g2[u][i]; 
			if(dd[v][nk+1])continue ; 
			if(f[v][nk+1]>f[u][nk]+p)
			{
				f[v][nk+1]=f[u][nk]+p;
				q.push({v,f[v][nk+1],nk+1});
			}
		}
	}
}
struct bgfull
{
	int u ; 
	ll val ; 
	int k ,  l ;  
};
struct cmpfull{
	bool operator()(bgfull a , bgfull b )
	{
		return a.val>b.val ;
	} 
};

void subfull()
{
	priority_queue<bgfull,vector<bgfull>,cmpfull>q  ; 
	vector<vector<vector<ll>>>f(n+1,vector<vector<ll>>(k+1,vector<ll>(l+1,inf)));
	vector<vector<vector<ll>>>dd(n+1,vector<vector<ll>>(k+1,vector<ll>(l+1,0)));
	f[1][0][0]= 0 ;
	q.push({1,f[1][0][0],0,0});
	while(!q.empty())
	{
		int u = q.top().u ; 
		int nk = q.top().k ; 
		int nl = q.top().l ; 
		if(u==n)
		{
			cout<<f[u][nk][nl];
			return ; 
		}
		q.pop();			
		if(dd[u][nk][nl])continue ;
		dd[u][nk][nl]=1;
		for(int i= 0 ;i<g[u].size();i++)
		{
			int v= g[u][i].v; 
			int w= g[u][i].w;
			if(nl==0)
			{
				if(dd[v][nk][nl]==0&&f[v][nk][nl]>f[u][nk][nl]+w)
				{
					f[v][nk][nl]=f[u][nk][nl]+w;		
					q.push({v,f[v][nk][nl],nk,0});
				}
				if(nk<k&&nl<l&&dd[v][nk+1][nl+1]==0&&f[v][nk+1][nl+1]>f[u][nk][nl]+p)
					{
						f[v][nk+1][nl+1]=f[u][nk][nl]+p;
						q.push({v,f[v][nk+1][nl+1],nk+1,1});
					}
			} 
			else 
			{
				if(dd[u][nk][0]==0&&f[u][nk][0]>f[u][nk][nl])
				{
					f[u][nk][0]=f[u][nk][nl];
					q.push({u,f[u][nk][0],nk,0});
				}
				if(nl<l)
				{
					if(dd[v][nk][nl+1]==0&&f[v][nk][nl+1]>f[u][nk][nl])
					{
						f[v][nk][nl+1]=f[u][nk][nl];
						q.push({v,f[v][nk][nl+1],nk,nl+1});
					}
				}
			}
		}
	}
}
void output()	
{
	if(k==0)sub0();
	else subfull();
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}