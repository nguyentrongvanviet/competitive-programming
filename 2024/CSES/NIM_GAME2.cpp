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
        int n; cin>> n; 
        int res = 0 ; 
        for(int i=1;i<=n;i++)
        {
            int val; cin>>val ;
            val%=4 ; 
            res^=val; 
        }   
        if(res)cout<<"first";
        else cout<<"second"; 
        cout<<'\n';
    }
}