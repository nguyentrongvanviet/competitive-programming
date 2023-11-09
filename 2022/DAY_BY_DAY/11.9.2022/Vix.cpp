#include<bits/stdc++.h>
using namespace std;

#define TASK "VIx"
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

vector<int> pt (int n )
{
	vector<int>div; 
	int uoc  = 2;  
	while(uoc*uoc<=n)
	{
		bool ok = 0 ;
		while(n%uoc==0)
		{
			n/=uoc ;
			ok =1 ; 
		}
		if(ok==1)div.pb(uoc);
		uoc++;
	}
	if(n!=1)
	{						
		div.pb(n) ; 
	}
	return div; 
}
int n ;  
void doc()
{
    cin>> n; 
    nvector<int> uoc = pt(n);  
    for(int i =0  ;i<uoc.size();i++)cout<<uoc[i]<< " ";
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