#include<bits/stdc++.h>
using namespace std;

#define TASK "NUMPRN"

#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#pragma GCC target("popcnt")
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
ll n ; 

void doc()
{
 	cin>> n;     
 	ll res= 0 ;
	if(n&1)
	{
		cout<<-1<<"\n";
		return; 
	} 	
	else
	{
		vector<ll>res;
		for(ll i= 1;i<=(ll)1e6;i++)
		{
			if(n%(i*(i+1))==0)
			{
				res.pb(i); 
			}
		}
		for(ll i=1;i<=(ll)1e6;i++)
		{
			if(n%i==0)
			{
				ll x= n/i ; 
				if(x<=(1e6*(1e6+1)))break;
				ll u  =sqrt(x) ; 
				if(n%(u*(u+1))==0)
				{
					res.pb(u);
				}
			}
		}	
		sort(res.begin(),res.end());
		for(int i= 0 ;i<res.size();i++)
		{
			cout<<res[i]<<" ";
		}cout<<"\n";
	}
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t = 1;
    cin>>t ; 
    while(t--)
    {
        doc();
    }
}