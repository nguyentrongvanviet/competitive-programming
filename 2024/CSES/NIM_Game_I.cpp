#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

int a[N] ; 
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int test  ; cin>>test ;
    while(test--)
    {
        int n; cin>> n; 
        for(int i=1;i<=n;i++)cin>>a[i] ; 
        int sum = 0 ;
        for(int i=1;i<=n;i++)
        {   
            sum^=a[i] ; 
        }
        cout<<(sum==0?"second":"first")<<'\n' ; 
    }
}