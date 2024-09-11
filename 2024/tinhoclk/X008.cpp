#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    string s; 
    cin>>s ;
    bool ok1 = 0 , ok2 = 0 ;
    for(auto c : s)
    {
        ok1|=(('a'<=c&&c<='z')||('A'<=c&&c<='Z')) ;
        ok2|=('0'<=c&&c<='9') ; 
    }
    if(s.size()>=5&&ok1&&ok2)cout<<s.size() ;
    else cout<<"Error!";
}