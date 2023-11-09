#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
#define int long long 
const int N =5e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n   ; 
ll m  ; 
ll f[N][N] ; 
ll a[N]  ;
ll b[N] ;  
ll x[N]  ; 
int np(ll val )
{
    int l = 1 ;
    int r = n ; 
    int ans ; 
    while(l<=r)
    {
        int mid=(l+r)/2; 
        if(x[mid]>=val)
        {
            ans= mid ; 
            r=mid-1 ; 
        }
        else 
        {
            l=mid+1 ;
        }
    }
    return ans;  
}
void inp()
{
    cin>> n  >>  m;  
    if(n>500)
    {
        vector<int>a(n+1,0); 
        for(int i=1 ;i<=n;i++)
        {
            cin>>a[i] ; 
            x[i] = oo ;
        }
        int res= 0 ;
        for(int  i=1 ;i<=n;i++)
        {
            int pos =np(a[i]) ;
            x[pos] =a[i];
            res=max(res,pos) ;   
        }
        cout<<res ;  
        return ; 
    }
    for(int i =1; i<=n;i++)
    {
        cin>>a[i] ;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j] =inf; 
        }
    }
    int res= 0 ; 
    for(int i =1 ;i<=n;i++)
    {
        if(a[i]<=m)
        {
            f[i][1] =a[i] ; 
            res=max(res,(ll)1);
        }
        for(int j=1 ;j<=i-1;j++)
        {
            if(a[j]<a[i])
            {
                for(int t =2 ;t<=i;t++)
                {
                    if(f[j][t-1]!=inf&&f[j][t-1]+a[i]<=m)
                    {
                        res=max(res,t) ; 
                        f[i][t]=min(f[i][t],f[j][t-1]+a[i]); 
                    }
                }
            }
        }
    }   
    cout<<res ; 
}
 signed  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}