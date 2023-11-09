// code for fun code for TTMD 
#include<bits/stdc++.h>
using namespace std;

#define TASK "beautarr"

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

const int N =5e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ;  

int n ; 
int a[N] ; 
ll res=0 ; 
map<int,int>sl;
void doc()
{
    cin>>n ; 
    FOR(i,1,n)cin>>a[i] ; 
}
void xuly()
{
	int l = 1; 
    FOR(i,1,n)
    {
    	sl[a[i]]++ ;  
    	while(sl[a[i]]>2)
    	{
    		sl[a[l]]--; 
    		++l; 
    	}
    	res+=((ll)i-l+1) ; 
    }
    cout<<res;	
}
int main()
{
    IOS();  
    doc(); 
    xuly();
}