#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int t ; cin>>t ;
    while(t--)
    {
        int n ; cin>> n; 
        vector<int>a(n) ; 
        vector<int>f(n) ; 
        for(int i=0;i<n;i++)cin>>a[i] ; 
        sort(a.begin(),a.end()) ;
        a.resize(unique(a.begin(),a.end())-a.begin()) ; 
        n = a.size() ; 
        f[n-1] = 1 ;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]-(i==0?0:a[i-1])==1)
            {
                f[i] = 1-f[i+1]; 
            }
            else
            {       
                f[i] =1 ; 
            }
        }
        cout<<(f[0]==1?"Alice":"Bob")<<'\n';
    }  
}