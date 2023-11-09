#include<bits/stdc++.h>
using namespace std;

#define TASK "POWK"

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

int n ; 

void doc()
{
    cin>>n ; 
    FOR(i,1,n)
    {
    	ll x; 
    	cin>>x;
    	if(x%4==0)cout<<x/4+1<<" "<<x/4-1<<"\n";
    	if(x%4==1)cout<<x/2+1<<" "<<x/2<<"\n";
    	if(x%4==2)cout<<"impossible"<<"\n"; 
    	if(x%4==3)cout<<x/2+1<<" "<<x/2<<"\n";
    }
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