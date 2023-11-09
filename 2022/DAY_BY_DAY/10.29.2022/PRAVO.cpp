#include<bits/stdc++.h>
using namespace std;

#define TASK "PRAVO"

#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b) for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i = b;i>=a;i--)
#define pii pair<int,int>
#define x first 
#define y second  
#define fi first 
#define se second  
#define all(a) a.begin(),a.end()
const int N =1500+5 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
pii a[N] ; 
map<pii,int>cnt; 
void doc()
{
	cin>> n ;
	for(int i=1 ;i<=n;i++)cin>>a[i].fi>>a[i].se; 
	ll res= 0 ;
 	for(int i=1;i<=n;i++)
 	{
 		cnt.clear();
 		for(int j= 1;j<=n;j++)
 		{
 			if(j==i)continue ; 
 			int u = a[j].x-a[i].x ; 
 			int v= a[j].y-a[i].y ; 
 			int c= __gcd(abs(u),abs(v));
 			u/=c; 
 			v/=c; 
 			if(u<0)
 			{
 				u=-u ; 
 				v=-v ;
 			}
 			else if(u==0&&v<0)
 			{
 				v=-v ;
 			}
 			int nu = v ; 
			int nv = -u ; 
			if(nu<0)
			{
				nu=-nu ; 
				nv=-nv ; 
			}
			else if(nu==0&&nv<0)
			{
				nv=-nv;
			}
 			if(cnt.find({nu,nv})!=cnt.end())
 			{	
  				res+=cnt[{nu,nv}];
 			}
 			cnt[{u,v}]++;
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