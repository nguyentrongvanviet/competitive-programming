#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
ll a[N] ;
ll s[N]; 
ll mi[N] ;
ll f[N] , g[N]; 
void inp()
{
    cin>> n ; 
    f[0] =-inf; 
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i] ;
        f[i] =-inf;
        g[i]=-inf;   
        s[i]= s[i-1]+a[i] ; 
    }   
    mi[0] = 0 ;  
    mi[1] = s[1]; 
    mi[2]=s[2];  
    for(int i= 3 ;i<=n-2;i++)
    {
        f[i] = s[i]-mi[i%3];
        mi[i%3] = min(mi[i%3],s[i]);
        f[i] = max(f[i],f[i-1]);
    }
    mi[(n+1)%3] = 0 ; 
    mi[n%3]=a[n];
    mi[(n+2)%3]=s[n]-s[n-2] ; 
    g[n+1]= -inf;
    for(int i=n-2;i>=4;i--)
    {
        g[i] = s[n]-s[i-1]-mi[i%3] ;
        mi[i%3] = min(mi[i%3],s[n]-s[i-1]); 
        g[i] = max(g[i],g[i+1]);
    }
    ll res= -inf ; 
    for(int i= 3;i<=n-3;i++)
    {
        res=max(res,f[i]+g[i+1]) ; 
    }
    cout<<res; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}