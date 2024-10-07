#include<bits/stdc++.h>
using namespace std ; 

const int N = 1e6+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 

int n , k ; 
int a[N] ; 
int f[N] ; 
signed main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k; 
    for(int i=1;i<=k;i++)cin>>a[i] ;     
    f[0] = 0 ; 
    for(int i=1;i<=n;i++)
    {
        for(int j =1;j<=k;j++)if(i>=a[j])
        {
            if(f[i-a[j]]==0)
            {
                f[i] = 1; 
                break ; 
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<(f[i]?"W":"L");
}
