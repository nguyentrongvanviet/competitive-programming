#include<bits/stdc++.h>
using namespace std;

#define TASK "PREDICTION"

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
        freopen(TASK".ANS","w",stdout); 
    }
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n , k ;
void doc()
{
	cin>>n>>k ; 
	FOR(i,1,n)
	{
		if(n%i==0)
		{
			k--;
		}
		if(k==0)
		{
			cout<<i<<"\n";
			return ;
		}
	}    
	cout<<-1 <<"\n";
	return ;  
}	
void xuly()
{
    
}
int main()
{
    IOS();  
    int test ;
    cin>>test ;

    while(test--)doc(); 
    xuly();
}