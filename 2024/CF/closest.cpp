#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+5 ; 
int a[N] ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    int test ;cin>>test ;
    while(test--)
    {
        int n; cin>> n; 
        for(int i=1;i<=n;i++)cin>>a[i] ; 
        if(n>2)
        {
            cout<<"NO"<<'\n' ; 
        }   
        else
        {
            if(a[1]+1==a[2])cout<<"NO"<<'\n' ;
            else cout<<"YES"<<'\n' ;
        }
    }
}