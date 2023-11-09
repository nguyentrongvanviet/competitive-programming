#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
const ll N =1e5+5  ,INF = 1e17 , C = 330  , MOD = 1e9+7 ;

struct bg
{
    ll b;
    ll u ;
};
struct cmp
{
    bool operator()(bg  a, bg b)
    {
        return a.b<b.b;
    }
};
set<pii>s;
ll n;
void inp()
{
    cin>> n;
    for(ll i=1;i<=n;i++)
    {
        ll b ;
        cin>>b ;
        s.insert({b,i});
    }
    while(!s.empty())
    {
        set <pii>::iterator it1  = s.begin();
        set <pii>:: iterator it2 = s.end();
        --it2;
        ll u =(*it1).second;
        ll v =(*it2).second ;
        ll b = (*it2).first;
        --b;
        cout<<u<<" "<<v<<endl;
        s.erase(it1);
        s.erase(it2);
        if(b>0)s.insert({b,v});
    }
}
int main()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
//    freopen("i.txt","r",stdin) ;
//    freopen("o.txt","w",stdout) ;
    inp() ;
}
