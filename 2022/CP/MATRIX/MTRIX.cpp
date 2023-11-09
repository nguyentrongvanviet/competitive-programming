#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =2, INF =1e17 , C= 330  , MOD =111539786 ;
struct MT
{
    ll n , m ;
    ll x[N][N];
};
MT mul(MT a , MT b)
{
    MT tmp;
    tmp.n = a.n ;
    tmp.m =b.m;
    ll l= a.m;
    for(ll i =0;i<tmp.n;i++)
    {
        for(ll j= 0 ;j<tmp.m;j++)
        {
            tmp.x[i][j]=0;
            for(ll t= 0 ; t<l;t++)
            {
                tmp.x[i][j]+=(a.x[i][t]*b.x[t][j])%MOD;
            }
        }
    }
    return tmp ;
}
MT pow(MT a , ll p )
{
    if(p==1)return a;
    MT c =pow(a,p/2);
    if(p&1)
    {
        return mul(mul(c,c),a);
    }else
    {
        MT res =mul(c,c);
        return res;
    }
}
void inp()
{
    ll n ;
    ll u[2][2]={1,1,1,0};
    MT ans;
    ans.n=2 ;
    ans.m=2 ;
    for(ll i =0  ;i<2;i++)
    {
        for(ll j= 0 ;j<2;j++)
        {
            ans.x[i][j]=u[i][j];
        }
    }
    cin>> n ;
    if(n==1){cout<<1;return;}
    MT res= pow(ans,n-1);
    cout<<(res.x[0][0]+res.x[0][1])%MOD;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin ) ;
//    freopen("o.txt","w",stdout) ;
    ll t ;
    cin>>t;
    while(t--)
    {
        inp();
        cout<<"\n";
    }
}
/*
1 2 0
3 0 1
2 3 1
*/
