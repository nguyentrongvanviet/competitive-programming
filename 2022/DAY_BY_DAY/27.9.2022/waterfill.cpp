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
ll k ; 
ll a[N] ; 
bool check1(ll val)
{
    ll du =0 ;  
    for(int i= 1;i<=n;i++)
    {
        if(du+val*k>=a[i])
        {
            du =du+val*k-a[i];  
            if(du>(ll)1e15)
            {
                du= 1e15 ;
            } 
            if(i==n)return 1;  
        }
        else 
        {
            du =  0 ; 
        }
    }
    return 0 ; 
}
bool check2(ll val)
{
    ll du =0 ;  
    for(int i= 1;i<=n;i++)
    {
        if(du>= a[i]-val*k)
        {
            du =du+(val*k-a[i]);
            if(du>(ll)1e15)
            {
                du= 1e15 ;
            }  
        }
        else 
        {
            return 0 ; 
        }
    }
    return 1; 
}
ll np1()
{   
    ll l = 0 ; 
    ll  r= (ll)1e9 ; 
    ll ans ; 
    while(l<=r)
    {
        ll mid=(l+r)/2; 
        if(check1(mid))
        {
            ans= mid ; 
            r=mid-1; 
        }
        else 
        {
            l=mid+1; 
        }
    }
    return ans;  
}
ll np2()
{
    ll l = 0 ; 
    ll  r= (ll)1e9 ; 
    ll ans ; 
    while(l<=r)
    {
        ll mid=(l+r)/2; 
        if(check2(mid))
        {
            ans= mid ; 
            r=mid-1; 
        }
        else 
        {
            l=mid+1; 
        }
    }
    return ans;  
}

void inp()
{
    cin>> n>> k ; 
    for(int i=1 ;i<=n;i++)
    {
        cin>>a[i] ; 
    }
    ll x = np1() ; 
    ll y= np2() ; 
    cout<<x<<" "<<y ; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    inp();
    return 0;
}