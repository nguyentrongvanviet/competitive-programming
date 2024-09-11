#include<bits/stdc++.h>
using namespace std ; 

const int N = 1e6+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 
int n; 
int a[N] ; 
long long f[N][3] ;
long long shoot(int pos ,int bullet)
{
    if(pos>n)return 0 ; 

    long long &val = f[pos][bullet] ;
    if(val!=-1)return val;  
    val=shoot(pos+1,2) ; 
    if(bullet)
    {
        val = max(val,shoot(pos+1,bullet-1)+a[pos]);
    }
    return val;  
}
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n;
    for(int i=1;i<=n;i++)cin>>a[i] ;
    memset(f,-1,sizeof(f)) ;  
    cout<<shoot(1,2) ; 
}