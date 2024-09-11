#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std ; 

const int N = 3e5+5 , oo = 1e9+5 ; 
const long long inf = 1e17+5 , sm = 1e9+7 ; 
int n; 
int a[N] ; 
int dd[N] ; 
signed main()
{
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

    int test ; 
    cin>>test ; 
    while(test--)
    {
        cin>> n ;
        for(int i=1;i<=n;i++)cin>>a[i] ; 
        long long res=0 ; 
        for(int i=1;i<=n;i++)res+=a[i] ;    
        int ma = 0 ; 
        for(int i=1;i<=n;i++)
        {
            dd[a[i]]++ ; 
            if(dd[a[i]]==2)ma=max(ma,a[i]) ;
            a[i] = ma ; 
        }
        for(int i=1;i<=n;i++)dd[i]=0;
        ma = 0 ;
        for(int i=1;i<=n;i++)
        {
            res+=a[i] ; 
            dd[a[i]]++ ; 
            if(dd[a[i]]==2)ma=max(ma,a[i]) ;
            a[i] = ma ; 
        }
        for(int i=1;i<=n;i++)dd[i]=0;
        for(int i=1;i<=n;i++)
        {
            res+=1ll*a[i]*(n-i+1) ; 
        }
        cout<<res<<'\n'; 
    }
    return 0 ;
}
// 00123344566