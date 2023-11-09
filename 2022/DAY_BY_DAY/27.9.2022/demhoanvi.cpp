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

ll n ; 
ll binpow(ll a , ll n )
{
    if(n==0)return 1 ; 
    ll b = binpow(a,n/2); 
    if(n&1)
    {
        return b*b%sm*a%sm; 
    }
    else 
    {
        return b*b%sm;  
    }
}
void inp()
{
    cin>> n; 
    if(n<=2)cout<<0<<"\n";
    else cout<<(binpow(2,n-1)-2+sm)%sm<<"\n"; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout);
    int test ;
    cin>>test ; 
    while(test--)inp();
    return 0;
}