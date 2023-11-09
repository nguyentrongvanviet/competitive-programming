#include<bits/stdc++.h>
using namespace  std ;
#define ll long long
const ll N= 3e6+5 ;
int dd[N];
int n , k ;
void inp()
{
    cin>> n ;
    cin>> k ;
    for(ll i=1;i<=n;i++)
    {
        dd[i] = 1;
    }
    for(ll i=n+1;i<=2*n;i++)
    {
        dd[i] = 2;
    }
    ll res=n;
    for(ll i=1;i<=k;i++)
    {
        ll u ,v;
        cin>>u>>v ;
        if(u>v)swap(u,v);
        swap(dd[u],dd[v]);
        if(dd[u]==dd[v]||v<=n||(v>n&&u>n)||u==v)
        {
            cout<<res<<'\n';
        }
        else
        {
            if(dd[v]==1)
            {
                cout<<--res<<'\n';
            }
            else
            {
                cout<<++res<<'\n';
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    freopen("i.txt","r",stdin) ;
    freopen("o.txt","w",stdout) ;
    inp();

}
