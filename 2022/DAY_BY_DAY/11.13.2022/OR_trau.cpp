#include<bits/stdc++.h>
using namespace std;

#define TASK ""
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

int n ; 
int a[N] ; 
void doc()
{
    cin>> n; 
    FOR(i,1,n)cin>>a[i] ; 
    FOR(i,1,(1<<n)-1)
    {
    	int bit =0  ; 
    	for(int j= 0 ;j<n;j++)
    	{
    		if(i>>j&1)
    		{
    			bit&=a[j+1];
    		}
    	}
    	if(l<=bit&&r<=bit)
    	{}
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
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}