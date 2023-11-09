#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5 , INF =1e17 , C= 330  , MOD = 1e9+7 ;

ll n ;
ll inp(ll x , ll y )
{
    if(x==y )return 0 ;
    if(y-x>x)
    {
        return 1 ;
    }

}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin ) ;
    freopen("o.txt","w",stdout) ;
    string s  ;
    while(1)
    {
        ll x, y ;
        cin>>x>>y;
        if(x==0&&y==0)return 0;
        if(x>y)swap(x,y);
        cout<<(solve(x,y)==1? "T":"S")<<"\n";
    }
}
