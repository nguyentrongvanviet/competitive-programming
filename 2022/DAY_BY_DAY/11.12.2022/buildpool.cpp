#include<bits/stdc++.h>
using namespace std;

#define TASK "buildpool"
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

struct DL
{
	ll h ; 
	ll id ; 
	bool operator <(const DL& a)const
	{
		return h>a.h ;
	}
};
int n ; 
DL a[N] ; 
void doc()
{
 	cin>> n;
 	for(int i= 1 ;i<=n;i++)cin>>a[i].h ,a[i].id= i ; 
 	sort(a+1,a+n+1); 
 	ll mi= n+1; 
 	ll ma= -1; 
 	ll res= -inf ;
 	FOR(i,1,n)
 	{
 		res=max({res,a[i].h*(a[i].id-mi-1),a[i].h*(ma-a[i].id-1)});
 		mi =min(mi,a[i].id) ; 
 		ma=max(ma,a[i].id) ;
 	}
 	cout<<res;
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
    }
    return 0;
}