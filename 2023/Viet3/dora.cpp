#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Triplet
{
public:
    ll x,y, gcd;
};

Triplet extendedEuclidAlgo(ll a, ll b)
{
    if(b==0)
    {
        Triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    Triplet small = extendedEuclidAlgo(b,a%b);
    Triplet ans;
    ans.gcd = small.gcd;
    ans.x = small.y;
    ans.y = small.x - ((a/b)*small.y);
    return ans;
}

ll MMI(ll a, ll b)
{
    ll ans = extendedEuclidAlgo(a, b).x;
    return (ans%b+b)%b;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,d;
        cin>>a>>b>>d;
        ll g = __gcd(a,b);
        if(d%g)
        {
            cout<<0<<endl;
            continue;
        }
        // if(d==0)
        // {
        //     cout<<1<<endl;
        //     continue;
        // }
        a/=g;
        b/=g;
        d/=g;
        
        ll y1 = ((d%a) * MMI(b, a))%a;
        ll firstvalue = d/b;
        if(d < y1*b)
        {
            cout<<0<<endl;
            continue;
        }
        
        ll ans = ((firstvalue - y1)/a)+1;
        cout<<ans<<endl;
        
    }
    return 0;
}