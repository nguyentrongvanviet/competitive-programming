// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "mimimum_LCM"

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
#define gcd(a,b) __gcd(a,b) 
#define lcm(a,b) (ll)a*b/__gcd(a,b) 
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

void doc()
{
	cin>> n;   
	vi div; 
	FOR(i,1,sqrt(n))
	{
		if(n%i==0)
		{
			div.pb(i) ;
			if(n/i!=i)div.pb(n/i);
		}
	}
	ll res= oo ; 
	int x , y ; 
	for(auto uoc: div)
	{
		if(uoc==n)continue; 
		if(res>lcm(uoc,(n-uoc)))
		{
			res = lcm(uoc,(n-uoc)) ; cout
			x= uoc; 
			y= n-uoc; 
		} 	
	}
	cout<<x<<" "<<y<<'\n';
}
void xuly()
{
    
}
int main()
{
    IOS(); 
    int test; 
    cin>>test ;
    while(test--)
    {
    	doc(); 
    	xuly();
    } 
    return 0 ;
}