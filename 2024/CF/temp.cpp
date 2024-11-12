#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

struct student 
{
    int tuoi, name ; 
} ; 
student a[N] ; 
bool abc(student A , student B)
{
    if(A.tuoi==B.tuoi)return A.name<B.name ; 
    return A.tuoi < B.tuoi ; 
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    int n ; cin>> n ; 
    for(int i=1;i<=n;i++)cin>>a[i].tuoi>>a[i].name ;
    sort(a+1,a+n+1,abc) ;
    
}