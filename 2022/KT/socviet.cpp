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

struct bg 
{
    ll t , p  ; 
};
int m , n , k ;  
bg a[N] ; 
ll b[N] ; 
int check(ll val)
{
    for(int i= 1 ;i<=m;i++)
    {
        if(a[i].t<=val)
        {
            b[i] =1 +(val-a[i].t)/a[i].p ; 
        } 
        else 
        {
            b[i]= 0 ;  
        }
    }
    sort(b+1,b+m+1,greater<ll>()) ; 
    ll s= 0 ; 
    for(int i =1 ;i<=n;i++)
    {
        s+=b[i];
        if(s>=k)return 1 ;  
    }
    return 0 ; 
}
void tknp()
{
    ll  l = 0 ; 
    ll r = inf ; 
    ll ans = 0 ;
    while(l<=r)
    {
        ll mid =(l+r)/2 ; 
        if(check(mid))
        {
            r=mid-1  ;
            ans= mid ; 
        }
        else 
        {
            l=mid+1; 
        }
    }
    cout<<ans;
}
void inp()
{
    cin>> m >> n >> k; 
    for(int i =1 ;i<=m;i++)
    {
        cin>>a[i].t ; 
    }   
    for(int i= 1; i<=m;i++)
    {
        cin>>a[i].p; 
    }
    tknp() ; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}