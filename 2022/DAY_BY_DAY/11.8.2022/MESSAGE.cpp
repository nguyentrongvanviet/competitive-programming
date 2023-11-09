	#include<bits/stdc++.h>
	using namespace std;

	#define TASK "MESSAGE"
	#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
	#define ll long long
	#define pb push_back
	#define pk pop_back
	#define FOR(i,a,b)  for(int i= a;i<=b;i++)
	#define FORD(i,a,b) for(int i= a;i>=b;i--)
	#define pii pair<int,int>
	#define fi first 
	#define se second  
	#pragma CPP target("popcnt")
	const int N =2e5+5 ,  oo = 2e9 ; 
	const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

	struct pt 
	{
		ll x,  y; 
	};
	ll dis(pt a, pt b)
	{
		return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	}

	struct ke
	{
		int v; 
		ll w; 
	};
	struct E
	{
		int u ,v , x; 
	};
	int n ; 
	pt a[N] ; 
	int dd[N] ; 
	vector<ke>g[N] ;
	vector<E>edge ;
	void doc()
	{
	    cin>> n;  
	    FOR(i,1,n)cin>>a[i].x>>a[i].y; 
	}
	int cnt =0 ; 
	void dfs(int u , ll c )
	{
		dd[u] =1 ; 
		cnt++ ;
		FOR(i,0,g[u].size()-1)
		{
			int v= g[u][i].v ;
			ll w =g[u][i].w;  
			if(dd[v]||w>c)continue ;
			dfs(v,c);
		}
	}
	void xuly()
	{
		FOR(i,1,n)
		{
			FOR(j,i+1,n)
			{
				g[i].pb({j,dis(a[i],a[j])}) ; 
				g[j].pb({i,dis(a[i],a[j])}) ; 
			}
		}
		ll l =  0 ; 
		ll r = inf ; 
		ll ans =0 ; 
		while(l<=r)
		{
			ll mid =(l+r)/2 ;
			FOR(i,1,n)dd[i]= 0 ; 
			cnt =0  ;
			dfs(1,mid) ; 
			if(cnt==n)
			{
				ans=mid ;
				r=mid-1; 
			}
			else
			{
				l=mid+1;
			}
		}
		cout<<ans;
	}

	int main()
	{
	    fast 
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