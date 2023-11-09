#define TASK "text"
#include<bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(b);i<(int)(b);i++)
#define vi vector<int> 
#define ve vector 
#define ll long long 
#define pii pair<int,int> 
#define fi first 
#define se second 
#define el '\n' 
const int N = 1e5+5 , oo = 2e9 , LO = 17; 
const ll inf = 1e17 ; 
int n; 
int a[N] ; 
int H[N] ; 
int st[(int)2e7];
int L[(int)2e7] , R[(int)2e7] ;
int node = 0 ; 
int NE[N] ;
int up(int old ,int l, int r , int pos , int val)
{	
	int cur = ++node; 
	if(l==r&&l==pos)
	{
		st[cur] = val;  
		return cur;  
	}
	int mid =(l+r)/2 ;
	if(pos<=mid)
	{
		R[cur] = R[old] ; 
		L[cur] = up(L[old],l,mid,pos,val) ;
	}
	else
	{
		L[cur] = L[old] ;
		R[cur] = up(R[old],mid+1,r,pos,val) ;  		
	}
	st[cur] = st[L[cur]]+st[R[cur]] ;
	return cur ; 
}
int get(int id, int l, int r , int k)
{
	if(st[id]<=k)return r; 
	if(l==r)return 0 ; 
	int mid = (l+r)/2 ;
	int u =get(L[id],l,mid,k) ; 
	int d= k - st[L[id]] ;  
	if(d>=0)u=max(u,get(R[id],mid+1,r,d)) ; 
	return u ;
}
int res[N]; 
void doc()
{
	cin>> n; 
	FOR(i,1,n)cin>>a[i] ; 	
}
int solve(int k)
{
	int res= 0 ;
	
	for(int l = 1,ne;l<=n;l=ne+1)
	{
		res++ ;
		ne = get(H[l],1,n,k) ; 
	}
	return res ; 
}
void xuly()
{
	
	FORD(i,n,1)
	{	
		int u = NE[a[i]] ;
		if(u)
		{
			H[i] = up(H[i+1],1,n,u,0) ;
			H[i] = up(H[i],1,n,i,1) ;  
		} 
		else H[i] = up(H[i+1],1,n,i,1) ; 
		NE[a[i]] = i ;
	}	
	FOR(i,1,n)
	{
		res[i] =solve(i); 
	}
	FOR(i,1,n)cout<<res[i]<<" ";
}
signed main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
	if(fopen(TASK".INP","r"))
	{
		freopen(TASK".INP","r",stdin) ; 
		freopen(TASK".OUT","w",stdout) ; 
	}
	doc() ; 
	xuly() ;
	cerr<<el<<"Time "<<clock()<<"ms"<<el;
}
