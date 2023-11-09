#include<bits/stdc++.h>
using namespace std;

#define TASK "MUAQUA"

#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define vii vector<int> 
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
#define pll pair<ll,ll>
const int N =2e5+5 ,  oo = INT_MAX ;
const ll sm = 1e9+7,cs=330 ,inf = LLONG_MAX;

int n   ; 
ll p  ;
pll a[N] ;
bool cmp(pll a, pll b)
{
	return a.fi+a.se<b.fi+b.se;
}
void doc()
{
 	cin>> n>> p ;
 	for(int i =1 ;i<=n;i++)
 	{
 		cin>>a[i].fi>>a[i].se; 
 	}
 	sort(a+1,a+n+1,cmp);
 	ll s= 0 ; 
 	ll ma= -inf ;
 	int en =0 ; 
 	for(int i=1 ;i<=n;i++)
 	{	
 		if(s+a[i].fi+a[i].se>p)
 		{
 			en= i-1; 
 			break ; 
 		}
 		s+=a[i].fi+a[i].se ; 
 		ma=max(ma,a[i].fi);
 		if(i==n)
 		{
 			cout<<n; 
 			return ; 
 		}
 	}   
 	ll mi = inf ;
 	for(int i=en+1;i<=n;i++)
 	{
 		mi =min(a[i].fi/2+a[i].se,mi) ;
 	}	
 	if(mi+s<=p||s-ma/2+a[en+1].fi+a[en+1].se<=p)
 	{
 		cout<<en+1; 
 	}
 	else 
 	{
 		cout<<en;
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
    }
    return 0;
}