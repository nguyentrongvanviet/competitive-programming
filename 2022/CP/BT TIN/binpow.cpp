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


ll binpow(ll a , ll n , ll mod )
{
    if(n==0)return 1 ;
    ll b = binpow(a,n/2,mod);  
    if(n%2==1)
    {
        return (b*b)%mod*a%mod;
    }
    else 
    {
        return b*b%mod ; 
    }
}   
void inp()
{
    ll x, y , n ; 
    cin>>x>>y>> n; 
    cout<<binpow(x,y,n)<<"\n"; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int test ; 
    cin>>test ;
    while(test--)
    {
        inp() ; 
    }
    int u  ; 
    cin>>u  ; 
    return 0;
}