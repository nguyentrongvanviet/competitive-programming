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
#define int long long 
struct bg 
{
    int l ; 
    int sl ; 
    bool operator<(const bg & x )const
    {
        return l<x.l ; 
    }
};  
int n ; 
ll fac[N] ; 
bg a[N] ; 
ll s[N];
void init()
{
    fac[0]=1 ; 
    for(int i =1; i<=(int)1e5;i++)
    {
        fac[i] = (fac[i-1]*i)%sm; 
    }
}

ll binpow(ll a , ll n )
{
    if(n==0)return 1;
    ll b = binpow(a,n/2) ;   
    if(n%2==0)
    {
        return b*b%sm ; 
    }
    else 
    {
        return b*b%sm*a%sm ; 
    }
}
ll C(int n , int k)
{
    if(n<k)return 0 ;
    return fac[n]*binpow(fac[k]*fac[n-k]%sm,sm-2)%sm;
}
int np1(int l , int r,int val)
{
    int ans=r+1; 
    while(l<=r)
    {
        int mid=(l+r)/2; 
        if(a[mid].l>val)
        {
            ans= mid; 
            r=mid-1 ; 
        }
        else 
        {
            l=mid+1; 
        }
    }
    return ans ; 
}
int np2(int l , int r , int val)
{
    int ans= 0 ;  
    while(l<=r)
    {
        int mid=(l+r)/2; 
        if(a[mid].l<val)
        {
            ans= mid; 
            l=mid+1 ; 
        }
        else 
        {
            r=mid-1; 
        }
    }
    return ans ;
}
void inp()
{
    cin>> n ;  
    for(int i= 1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].sl;   
    }   
    init();
    sort(a+1,a+n+1) ; 
    for(int i= 1;i<=n;i++)
    {
        s[i] = s[i-1]+a[i].sl;
    }
    ll res= 0 ; 
    for(int i = 3;i<=n;i++)
    {
        for(int j=2 ;j<=i-1;j++)
        {
            int pos = np1(1,j-1,a[i].l-a[j].l);
            if(pos==0)continue;
            res=(res+a[i].sl*a[j].sl%sm*(s[j-1]-s[pos-1]))%sm ;
        }
    }   
    for(int i = 1;i<=n;i++)
    {
        if(a[i].sl<2)continue ;
        res=(res+(C(a[i].sl,2)*s[i-1])%sm)%sm; 
        int pos = np2(i+1,n,a[i].l+a[i].l);
        if(pos==0)continue;
        res=(res+(s[pos]-s[i])*C(a[i].sl,2)%sm)%sm;
    }
    for(int i= 1;i<=n;i++)
    {
        res=(res+C(a[i].sl,3))%sm ; 
    }
    cout<<res; 
}   

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}