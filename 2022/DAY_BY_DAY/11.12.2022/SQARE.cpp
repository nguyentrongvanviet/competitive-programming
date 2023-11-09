#include<bits/stdc++.h>
using namespace std;

#define TASK "dora"
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
#define ll long long
#define pb push_back
#define pk pop_back
#define FOR(i,a,b)  for(int i= a;i<=b;i++)
#define FORD(i,a,b) for(int i= a;i>=b;i--)
#define pii pair<int,int>
#define fi first 
#define se second  
#pragma CPP target("popcnt")
const int N =2e5+5 ,  oo = 2e9 ; 
const ll sm = 1e9+7,cs=330 ,inf = 1e17 ;

ll n ; 

vector<ll> pt (ll a)
{
    a = abs(a) ; 
    vector<ll>uoc ;
    uoc.pb(1);
    ll it = 2 ; 
    while(it*it<=a)
    {
        bool ok = 0 ; 
        while(a%it==0)
        {
            ok = 1; 
            a/=it ; 
        }
        if(ok)uoc.pb(it);
        ++it ;  
    }
    if(a!=1)uoc.pb(a);
    return uoc;
}
void doc()
{
    cin>> n;
    cout<<n<<endl;
    if(n>=0)
    {
        ll u =sqrt(n) ; 
        if(u*u==n)
        {
            cout<<u ; 
            return ; 
        }
    } 
    vector<ll>uoc=pt(n);
    ll res = inf ;
    FOR(i,0,uoc.size()-1)
    {
        ll y= uoc[i] ; 
        ll x= n/uoc[i]; 
        ll u= (x+y)%2 ;
        ll v= (x-y)%2;
        if(u==0&&v==0)
        {
            res=min(res,abs(x+y)/2);
        }
    } 
    if(res==inf)cout<<"none";
    else cout<<res;
}

int main()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin); 
        freopen(TASK".OUT","w",stdout); 
    }
    int t ; 
    t=1;
    //cin>>t;
    while(t--)
    {
        doc();
    }
    return 0;
}