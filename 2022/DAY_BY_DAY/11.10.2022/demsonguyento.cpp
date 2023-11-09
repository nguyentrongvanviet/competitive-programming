#include<bits/stdc++.h>
using namespace std;

#define TASK "demsonguyento"

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

const int N =2e6+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;
int n ; 
int nt[N] ;
int res= 0 ;
void doc()
{
    for(ll i =2 ;i<=(int)1e6;i++)
    {
    	if(nt[i]==0)
    	{
    		nt[i] = i ; 
    		cout<<i<<" ";
    		res++; 
    		for(ll j= i*i;j<=(int)1e6;j+=i)
    		{
    			nt[j] = i ;
    		}
    	}
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
    int t = 1;
    // cin>>t ; 
    while(t--)
    {
        doc();
    }
}