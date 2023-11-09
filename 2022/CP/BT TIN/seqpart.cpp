#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =8e3+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

ll n , k ; 
ll a[N] , s[N] ; 
ll f[N] ,nf[N]  ;  
void tinh(ll l , ll r , ll optl , ll optr, ll k   )
{
    if(l>r) return ; 
    ll mid =(l+r)/2;
    pair<ll,ll> tmp{inf,-1} ; 
    for(ll i= optl ;i<=min(mid,optr);i++)
    {
        ll val  = f[i]+(s[mid]-s[i])*(mid-i);  
        if(tmp.X>val)
        {
            tmp.X=val ; 
            tmp.Y=i ; 
        }
    }
    nf[mid] = tmp.X ;
    tinh(l,mid-1,optl,tmp.Y,k); 
    tinh(mid+1,r,tmp.Y,optr,k); 
}
void inp()
{w
    cin>>n>>k  ; 
    for(ll i= 1;i<=n;i++)
    {
        cin>>a[i] ; 
        s[i]=s[i-1]+a[i] ; 
    }
    for(ll i= 1 ;i<=n;i++)
    {
        f[i]= s[i]*i ; 
    }
    for(ll j =2 ;j<=k;j++)
    {
        tinh(j,n,j-1,n,j);
        for(int i= 1;i<=n;i++)
        {
            f[i] =nf[i] ; 
        }
    }
    cout<<f[n]; 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}