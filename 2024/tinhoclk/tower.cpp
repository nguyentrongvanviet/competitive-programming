#include<bits/stdc++.h>
using namespace std ;

signed main()
{
    int test ;cin>>test ; 
    while(test--)
    {
        long long val; cin>>val;  
        long long delta = 1+8*val;
        long long b = sqrt(delta)  ; 
        if(b*b==delta && (-1+b)%2==0)
        {
            cout<<"YES"<<'\n';
        }
        else 
        {
            cout<<"NO"<<'\n' ;
        }
    }
}