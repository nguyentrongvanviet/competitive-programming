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
int f[N] , d[N] ; 
int a[N] ; 
int  np1(int val ,int x[])
{
    ll l =1 ; 
    ll r= n ; 
    int ans ; 
    while(l<=r)
    {
        int mid =(l+r)/2; 
        if(x[mid]>=val) 
        {
            ans =mid ; 
            r=mid-1; 
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;  
}
int x[N],y[N] ; 
int np2(int val ) 
{
    int l =1 ; 
    int r= n ; 
    int ans ;
    while(l<=r)
    {
        int mid =(l+r)/2; 
        if(y[mid]<=val)
        {
            ans=mid ;
            r=mid-1;  
        }
        else 
        {
            l=mid+1;  
        }
    }
    return ans ; 
}
void inp()
{
    cin>>n ; 
    for(int i= 1;i<=n;i++)
    {
        x[i] =oo ;
        y[i] =oo ;
    }
    for(int i =1 ;i<=n;i++)cin>>a[i] ; 
    for(int i =1 ;i<=n;i++)
    {
        int pos =np1(a[i],x) ; 
        x[pos]=a[i];  
        f[i] =pos;
    }   
    for(int i = n ;i>=1;i--)
    {
        int pos =np1(a[i],y); 
        y[pos]=a[i]; 
        d[i]=pos;
    }
    int res =0  ; 
    for(int i= 1;i<=n;i++)
    {
        res =max(res,d[i]+f[i]-1) ; 
    }
    cout<<res ; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}