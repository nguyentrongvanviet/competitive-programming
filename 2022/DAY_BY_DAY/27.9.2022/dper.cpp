#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define X first 
#define Y second
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 76213,cs=330 ,inf = 1e17;

ll  n ;  
ll fac[N] ; 
ll binpow(ll a , ll n )
{
    if(n==0)return 1; 
    ll b = binpow(a,n/2) ; 
    if(n&1)
    {
        return b*b%sm*a%sm ;
    }
    else 
    {
        return b*b%sm; 
    }
}
ll C(int n  , int  k )
{
    if(n<k)return 0 ;  
    return fac[n]*binpow(fac[k]*fac[n-k]%sm,sm-2)%sm;
}
void inp()
{
    cin>> n ; 
    fac[0]=1; 
    for(int i= 1;i<=n;i++)
    {
        fac[i]=(fac[i-1]*i)%sm ; 
    }
    ll res= fac[n]; 
    for(int i= 1;i<=n;i++)
    {
        ll ans =(C(n,i)*fac[n-i]%sm*(i%2==1?-1:1));
        res=(res-C(n,i)*fac[n-i]%sm*(i%2==1?1:-1)+sm)%sm;  
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