#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back

const ll N =1e5+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;


map<vector<ll>,ll>m;
void inp()
{
    ll a, b , c ;
    while(cin>>a>>b>>c)
    {
        ++m[{a,b,c}];
        if(m[{a,b,c}]==2)
        {
            cout<<a<<" "<<b<< " "<<c<<endl;
            return ;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("o.txt","r",stdin) ;
    freopen("i.txt","w",stdout) ;
    inp() ;
}
