	#include<bits/stdc++.h>
	using namespace std ;
	#define ll long long 
	#define TASK "text" 
	const int N = 1e5+5;  
	int n , L , R ; 
	ll s[N] , a[N]  ; 
	ll st[4*N] ; 
	void doc()
	{
		cin>> n >> L >> R  ; 
		for(int i= 1;i<=n;i++)cin>>a[i] , s[i] = s[i-1]+a[i] ; 
	}
	void build(int id , int l ,int r )
	{
		if(l==r)
		{
			st[id] = s[l] ; 
			return ; 
		}
		int mid = (l+r)/2 ; 
		build(id*2,l,mid) ; 
		build(id*2+1,mid+1,r) ; 
		st[id] = min(st[id*2],st[id*2+1]) ; 
	}
	ll get(int id ,int l ,int r  ,int t ,int p )
	{
		if(t<=l&&r<=p)return st[id] ; 
		if(r<t||p<l)return 1e17 ; 
		int mid =(l+r)/2 ;
		return min(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p))  ;		
	} 
	void xuly()
	{
		build(1,0,n) ;
		ll res = -1e17 ;  
		for(int i =1 ;i<=n;i++)
		{
			int l = i+1-R  ; 
			int r = i+1-L ; 
			res=max(res,s[i]-get(1,0,n,l-1,r-1)) ; 
		}
		cout<<res ; 
	}
	const int N =1e5 ; 
	int pa[N][20] ; 
	int pa[N][16] ;  
	signed main()
	{
		if(fopen(TASK".INP","r"))
		{
			freopen(TASK".INP","r",stdin) ; 
			freopen(TASK".OUT","w",stdout) ; 
		}
		doc() ;
		xuly() ; 
	}
	// i-j+1>=L  j <= i-L+1 
	// i-j+1<=R j >=i+1-R 