// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "DP_1"

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
int a[N] ; 
int mal[N] , mar[N];  
int sl[N] ;
void doc()
{
    cin>> n;  
    FOR(i,1,n)cin>>a[i]; 
    FOR(i,1,n)
    {
    	mal[i] = mal[i-1]; 
    	vi div; 
    	for(int uoc= 1 ;uoc<=(int)sqrt(a[i]);uoc++)
    	{
    		if(a[i]%uoc==0)
    		{
    			div.pb(uoc);
    			if(a[i]/uoc!=uoc)
    			{
    				div.pb(a[i]/uoc) ; 
    			}
    		}
    	}
    	for(auto uoc : div)
    	{
    		if(sl[uoc])
    		{
    			mal[i] = max(mal[i],uoc);
    		}
    	}
    	for(auto uoc : div)
    	{
    		sl[uoc]++; 
    	}
    }		
   	FOR(i,1,(int)1e5)sl[i] = 0 ;
    FORD(i,n,1)
    {
    	mar[i] = mar[i+1]; 
    	vi div; 
    	for(int uoc= 1 ;uoc<=(int)sqrt(a[i]);uoc++)
    	{
    		if(a[i]%uoc==0)
    		{
    			div.pb(uoc);
    			if(a[i]/uoc!=uoc)
    			{
    				div.pb(a[i]/uoc) ; 
    			}
    		}
    	}
    	for(auto uoc : div)
    	{
    		if(sl[uoc])
    		{
    			mar[i] = max(mar[i],uoc);
    		}
    	}
    	for(auto uoc : div)
    	{
    		sl[uoc]++; 
    	}
    }
    int res= 0 ;
    for(int i=2 ;i<=n-2;i++)
    {
    	res=max(res,mal[i]+mar[i+1]); 
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