#include<bits/stdc++.h>
using namespace std;

#define TASK "BDT2"

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
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

ll n ,k ; 
void doc()
{
	cin>>n>> k; 
	ll x = (2*n+k-k*k)/(2*k) ;
	ll res=1 ; 
	if(x<=0)
	{
		cout<<-1<<"\n";
		return ; 		
	}
	// cout<<x<<endl;	
	for(ll i= 1 ;i <=k-1;i++)
	{
		res = (res*((x*x%sm-x+sm)%sm))%sm;
		n-=x ; 
		++x; 
	}
	res=res*n%sm*(n-1)%sm;	
	cout<<res<<"\n";
}
void xuly()
{	
   
}
int main()
{
    IOS(); 
    int test ; 
    cin>>test ;
    while(test--)
    {
    	doc(); 
    	xuly();
    } 
    
}