#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int test ; cin>>test ;
    while(test--)
    {
        int n; cin>>n;
        int sum_xor= 0 ;
        for(int i=1;i<=n;i++)
        {
            int val; cin>>val ;
            if(i%2==0)sum_xor^=val; 
        }
        if(sum_xor)cout<<"first"<<'\n';
        else cout<<"second"<<'\n';
    }
}