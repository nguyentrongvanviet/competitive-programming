#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =2e3+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;

ll n , b ;

ll a[N] ;
ll f[N][N];
ll dd[N][N];
ll tinh(ll pos , ll s )
{
    if(dd[pos][s]==1)return f[pos][s];
    dd[pos][s]=1;
    if(pos==0)
    {
        return 1 ;
    }
    if(a[pos]==-1)
    {
        ll ma = min(b-s,pos-1);
        return f[pos][s]=(ma*tinh(pos-1,s+1)+tinh(pos-1,s))%MOD;
    }
    else
    {
        if(a[pos]>min(pos-1,b-s))return f[pos][s]= 0;
        return f[pos][s]=tinh(pos-1,s+(a[pos]!=0))%MOD;
    }
}
void inp()
{
    cin>>n>>b ;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<tinh(n,0);
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
   freopen("GRAPH.INP","r",stdin) ;
   freopen("GRAPH.OUT","w",stdout) ;
    inp() ;
}
