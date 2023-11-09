// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "lightball"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define vi vector<int> 
#define fi first 
#define se second
#define btpc(x) __builtin_popcount(x)   
#define all(a) a.begin(),a.end() 
void IOS()
{
    fast 
    srand(time(0)) ;
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
ll a[N] , b[N] , c[N] ; 
ll sq(ll a)
{
	return a*a ; 
}
ll tknp( ll val ,  ll b[] , ll c[] , int n , int m )
{
	int l =1 ; 
	int r= n ; 
	int x= -1 ; 
	while(l<=r)
	{
		int mid =(l+r)/2;
		if(b[mid]<=val)
		{
			x=mid ; 
			l=mid+1; 
		} 
		else
		{
			r=mid-1 ;
		}
	}
	int y=-1 ; 
	l = 1 ; 
	r=m ; 
	while(l<=r)
	{
		int mid =(l+r)/2 ; 
		if(c[mid]>=val)
		{
			y=mid ; 
			r=mid-1 ; 
		}
		else 
		{
			l=mid+1; 
		}
	}
	if(x!=-1&&y!=-1)
	{
		// cout<<b[x]<<" "<<c[y]<<endl;
		return sq(val-b[x])+sq(val-c[y])+sq(b[x]-c[y]) ;
	}
	return inf ;
}
void doc()
{
	int n , m, p ; 
 	cin>> n>>m>>p ;
 	FOR(i,1,n)cin>>a[i];
 	FOR(i,1,m)cin>>b[i] ; 
 	FOR(i,1,p)cin>>c[i] ;
 	sort(a+1,a+n+1);  
 	sort(b+1,b+m+1) ; 
 	sort(c+1,c+p+1); 
 	ll res= inf ; 
 	FOR(i,1,max({n,m,p}))
 	{
 		if(i<=n)res=min(res,tknp(a[i],b,c,m,p)); 
 		if(i<=n)res=min(res,tknp(a[i],c,b,p,m)) ; 
 		if(i<=p)res=min(res,tknp(c[i],a,b,n,m)) ; 
 		if(i<=p)res=min(res,tknp(c[i],b,a,m,n)) ; 
 		if(i<=m)res=min(res,tknp(b[i],a,c,n,p)) ; 
 		if(i<=m)res=min(res,tknp(b[i],c,a,p,n)) ; 
 	}
 	cout<<res;
}
void xuly()
{
    
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}