// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "Maxdif"

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

struct DL
{
	int i , j ;
	int val ;
	bool operator <(const DL& a)const
	{
		return val<a.val; 
	} 
};
int n , k;  
int a[N] ; 
int la[N] , dd[N] ; 
vector<DL>q ; 
bool check(int val)
{
	FOR(i,1,n)dd[i] = 0,la[i] = 0   ;
	for(int i=0 ;i<q.size();i++)
	{
		if(q[i].val<=val)continue;
		dd[q[i].i]=1; 
		dd[q[i].j]=1 ; 
		// cout<<q[i].i<<" "<<q[i].j<<" "<<q[i].val<<endl;
	}
	la[n+1] = n ;
	FORD(i,n,1)
	{
		if(dd[i])
		{
			la[i] = i ;
		}
		else 
		{
			la[i] = la[i+1] ; 
		}
	}
	for(int i= 1 ;i<=n;i++)
	{
		if(dd[i]==1)
		{
			if(n-la[i+1]<=k)return 1 ; 
			break;  
		}
	}
	for(int i = 1;i<=n;i++)
	{
		if(dd[i]==1)
		{
			if(la[i+1]==i+1&&a[i+1]-a[i]>val)continue;
			int tmp = i-1+n-la[i+1] ;  
			if(tmp<=k)return 1;  
		}
	}
	return 0 ; 
}
void doc()
{
	cin>> n>>k;
	FOR(i,1,n)cin>>a[i] ; 
	int ma = -1 ; 
	sort(a+1,a+n+1) ;
	FOR(i,1,n-1)
	{
		ma=max(ma,a[i+1]-a[i]) ;
		q.pb({i,i+1,a[i+1]-a[i]}) ; 
	}
	int l = 0 ;
	int r =ma  ; 
	int ans = ma;
	while(l<=r)
	{
		int mid =(l+r)/2 ; 
		if(check(mid))
		{
			ans= mid ; 
			r=mid-1 ; 
		}
		else 
		{
			l=mid+1 ; 
		}
	}
	cout<<ans;  
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