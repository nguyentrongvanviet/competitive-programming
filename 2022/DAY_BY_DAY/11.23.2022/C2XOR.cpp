#include<bits/stdc++.h>
using namespace std;

#define TASK "C2XOR"

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
    int t = 1;
}

const int N =2e5+5 ,maxN=20 ,  oo = 2e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17  ; 

int n ; 
int a[N] , s[N] ; 
ll res =0 ;
map<int,pii>sl ;
void doc()
{cin>>n;
    FOR(i,1,n)cin>>a[i],s[i]=(s[i-1]^a[i]);
    sl[0]={1,1};
    FOR(i,2,n)
    {
    	if(sl.find(s[i])!=sl.end())
    	{
    		res+=i*(sl[s[i]].fi)-sl[s[i]].se;
    	}
    	sl[s[i-1]].fi++;
    	sl[s[i-1]].se+=i;
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