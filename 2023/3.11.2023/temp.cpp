#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define ll long long
#define ii pair<ll,ll>
#define iii pair<pair<ll,ll>,int>
#define iil pair<ll,ll>
#define iiil pair<ll,pair<ll,ll>>
#define oo 1e18
#define check(n) (prime[n>>6]&(1<<((n&63)>>1)))
#define set(n) prime[n>>6]|=(1<<((n&63)>>1))
using namespace std;
const int N=1e5+5;
const ll Mod=1e9+7;
const ll MOD=13141702292180207;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};

iii a[N],b[N];
int n;
set<int> res;
void slove()
{
    cin >> n; ll ma=0;
    bool ok=false;
    for (int i=1;i<=n;i++) cin >> a[i].F.S >> a[i].F.F,b[i]=a[i],a[i].F.S*=(-1), a[i].S=i;
    a[0].F.F=0; a[0].F.S; a[n+1].F.F=a[n].F.F+1;
    sort(a+1,a+1+n);
    ll l,r,u,v;
    int vt,tv;
    for (int i=1;i<=n;i++)
    {
        if (a[i].F.F==0)
        {
            if (a[i+1].F.F==0) continue;
            ok=true;
            res.insert(a[i].S);
            l=-a[i].F.S;
            r=a[i].F.F;
            u=l; v=r;
            vt=a[i].S;
            break;
        }
        l=-a[i].F.S;
        r=a[i].F.F;
        u=-a[i].F.S;
        v=a[i].F.F;
        vt=a[i].S;
        res.insert(a[i].S);
        break;
    }
    tv=vt; ll li,ri;
    for (int i=1;i<n;i++)
    {
        tv++;
        if (tv>n) tv-=n;
        if (b[tv].F.F==0) continue;
        li=b[tv].F.S;
        ri=b[tv].F.F;
        if (li*r<l*ri)
        {
            l=li;
            r=ri;
            res.insert(tv);
        }
    }
    for (int i=1;i<n;i++)
    {
        vt--;
        if (vt<1) vt+=n;
        if (b[vt].F.F==0) continue;
        li=b[vt].F.S;
        ri=b[vt].F.F;
        if (li*v>u*ri)
        {
            u=li;
            v=ri;
            res.insert(vt);
        }
    }

    cout << res.size() << '\n';
    for (int i: res) cout << i << ' ';

}
int main()
{
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int T=1;
    while(T--) slove();
