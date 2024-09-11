#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

int a[N] ; 
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n , K ; 
    cin>> n >> K ;
    K=2*K+2 ;  
    for(int i=1;i<=n;i++)cin>>a[i] ;  
    multiset<int>s ; 
    for(int i=1;i<=K;i++)
    {
        s.insert(a[i]) ; 
    }
    int res=*s.rbegin()+ *next(s.rbegin());  
    for(int i=K+1;i<=n;i++)
    {
        s.erase(s.find(a[i-K]))  ; 
        s.insert(a[i]) ; 
        res = max(res,*s.rbegin()+ *next(s.rbegin()));
    }
    cout<<res ; 
}