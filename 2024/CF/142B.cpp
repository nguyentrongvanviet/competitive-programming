#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n , m ;cin>> n>> m; 
    if(n==1||m==1)
    {
    }
    int res1 = 0 , res2 = 0 ; 
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        if((i+j)%2==0)res1++;
        else res2++ ; 
    }
    cout<<max(res2,res1) ; 
}