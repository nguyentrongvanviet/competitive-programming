#include<bits/stdc++.h>
using namespace std;

#define TASK "NOVEL"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int n  , k ; 
ll a[N] ; 


bool check(ll val)
{
	int used =1; 
	ll s = 0  ; 
	for(int i= 1 ;i<=n;i++)
	{
		if(a[i]>val)
		{
			return 0 ;
		}
		s+=a[i] ; 
		if(s>val)
		{
			s=a[i] ; 
			used++ ;
		}
		if(used>k)return 0 ;
	}
	return 1 ; 	
}
void doc()
{
	cin>> n >>k;
	FOR(i,1,n)cin>>a[i]; 
	ll l = 0 ;
	ll r= inf ; 
	ll res= 0 ; 
	while(l<=r)
	{
		ll mid =(l+r)>>1  ;
		if(check(mid))
		{
			r=mid-1; 
			res=mid ; 
		}
		else 
		{
			l=mid+1; 
		}
	}    
	cout<<res;
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
    }
    return 0;
}