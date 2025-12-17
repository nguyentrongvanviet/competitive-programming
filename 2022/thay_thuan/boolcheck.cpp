#include<bits/stdc++.h>
using namespace std;

#define TASK "SUMABS"

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

void solve()
{
    cin>>n >>s; 
    vector<int>q ;  
    FOR(i,1,n)
    {
        a.pb(i);
    }
    do
    {
        int res=0 ;
        for(int i= 0 ;i<a.size();i++)
        {
            res+=abs(a[i]-i-1);
        }
        if(res==s)
        {
            ans++;
        }
    }while(next_permutation(a.begin(),a.end()));
    cout<<ans;
}
int main()
{
    IOS();  
    solve();
    // doc();/ 
    // xuly();
}