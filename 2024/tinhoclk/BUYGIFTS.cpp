#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n , m; cin>> n >> m;
    vector<int>a ;  
    for(int i=1;i<=n;i++)
    {
        int val; cin>>val;
        a.push_back(val) ;  
    }    
    sort(a.begin(),a.end()) ; 
    int res = 1e9 ; 
    for(int i = m-1;i<n;i++)
    {
        res=min(res,a[i]-a[i-m+1]) ; 
    }
    cout<<res ;
    return 0 ; 
}