#include<bits/stdc++.h>
using namespace std;

#define TASK "inversion"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(ll i= a;i<=b;i++)
#define FORD(i,a,b) for(ll i= a;i>=b;i--)
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

const int N =1e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n  ; 
ll m ; 
ll mu[N] ; 
ll res= 0 ;
int lazy[8*N];  
int st[8*N]; 
void build(int id,  int l , int r )
{
	lazy[id]=lazy[id*2]=lazy[id*2+1]=0;
	if(l==r)
	{
		st[id] = l-1;  
		return ; 
	}
	int mid =(l+r)>>1; 
	build(id*2,l,mid) ; 
	build(id*2+1,mid+1,r) ;
	st[id] =max(st[id*2],st[id*2+1]);
}
void dolazy(int id )
{
	st[id]+=lazy[id] ;
	lazy[id*2]+=lazy[id]; 
	lazy[id*2+1]+=lazy[id] ; 
	lazy[id]=0 ; 
}
void up(int id , int l ,int r,int t , int p ,int val)
{
	if(lazy[id])dolazy(id);
	if(r<t||p<l)return ;
	if(t<=l&&r<=p)
	{
		lazy[id]+=val; 
		dolazy(id) ; 
		return ; 
	}
	int mid =(l+r)/2; 
	up(id*2,l,mid,t,p,val) ; 
	up(id*2+1,mid+1,r,t,p,val) ; 
	st[id]=max(st[id*2],st[id*2+1]) ; 
}
pii get(int id , int l , int r , ll val )
{
	if(lazy[id])dolazy(id);
	if(l==r)
	{
		return {l,st[id]}; 
	}
	int mid = (l+r)/2; 
	dolazy(id*2) ; 
	dolazy(id*2+1);
	if(st[id*2]>=val)
	{
		return get(id*2,l,mid,val); 
	}
	else if(st[id*2+1]>=val)
	{
		return get(id*2+1,mid+1,r,val) ; 
	}
	return {0,0};
}

void doc()
{
 	cin>>n>>m ;
 	mu[0]=1;  
 	FOR(i,1,n-1)mu[i]=mu[i-1]*2%sm;
  	build(1,1,n);
  	ll res=0  ;
 	FOR(i,1,n)
 	{
 		ll val = 1LL*(n-i)*(n-i-1)/2; 
 		pii x=get(1,1,n,m-val);
 		if(x.fi==0)
 		{
 			cout<<-1<<"\n";
 			return ; 
 		}
 		else 
 		{	
 			m-=x.se;

 			up(1,1,n,x.fi+1,n,-1);
 			up(1,1,n,x.fi,x.fi,-oo);
 			cout<<x.fi<<" ";		
 			res+=(x.fi*mu[i-1]); 
 			res%=sm ; 
 		}
 	}
 	cout<<res<<"\n";
}
void xuly()
{
    
}
main()
{
    IOS();  
    int test; 
    cin>>test ; 
    while(test--)
    {
    	doc(); 
  		xuly();
    }
    
}