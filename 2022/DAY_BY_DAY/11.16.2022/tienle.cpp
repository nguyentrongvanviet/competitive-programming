#include<bits/stdc++.h>
using namespace std;

#define TASK "SUMDIV"

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

const int N =1e6+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

int nt[N] ; 
void snt()
{
	for(ll i = 2 ;i<=(ll)1e6;i++)
	{
		if(nt[i]==0)
		{
			nt[i] = i ; 
			for(ll j=  i*i ;j<=(ll)1e6;j+=i)
			{
				nt[j] = i ;  
			}
		}
	}
}
void doc()
{	
	snt();
	int n , k ;  
	cin>> n>> k;
	int res=0 ;
	FOR(i,1,n)
	{
		if(nt[i]==i&&i>k)
		{
			if(nt[i-k]==i-k)
			{
				res++;
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