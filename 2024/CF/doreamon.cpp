#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int a = 5  , b = 12 ;
    a*=++b-a ; 
    cout<<a++<<" "<<--b<<endl;
    // a=41 b=12
    // 11-(41-11)    
    b-=a++ - --b ;
    cout<<b++<<" "<<a<<endl;
}
// 41 12 
// 41 
// 42 
// 104 5 
// 2 a = 7 x
// 
