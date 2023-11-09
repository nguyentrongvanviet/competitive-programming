#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e6+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;
const ll M= 24;
ll n ;
ll a[N];
ll f[1<<24];
void inp()
{
    cin>> n ;
    memset(f,-1,sizeof f );
    for(ll i =1 ;i<=n;i++)
    {
        cin>>a[i] ;
        f[a[i]]=a[i];
    }
    for(ll i=0 ;i<M;i++)
    {
        for(ll j = 0 ; j<(1<<M);j++)
        {
            if((1<<i)&j)
            {
                f[j]=max(f[j],f[j^(1<<i)]);
            }
//            cout<<f[j]<<endl;
        }
    }
    for(ll i= 1;i<=n;i++)
    {
        cout<<f[((1<<M)-1)^a[i]]<<" ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
