#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define LOG 20
#define rboost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define en "\n"
#define getbit(i,j) ((i>>j)&1)
#define cnt_bit(x) __builtin_popcount(x)
using namespace std;
const ll N=1e5+5,mod=1e9+7;
const ll ll_lim=1e18+7;
const ll int_lim=1e9+7;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
int dx[5]{1,0,0,-1};
int dy[5]{0,1,-1,0};
int tc,n,m,a[N];
int  f[N];

void add(int &x, int y) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; }
bool maximize(ll & x, ll y) {if (x<y) {x=y;return 1;} return 0;}
bool minimize(ll & x, ll y) {if (x>y) {x=y;return 1;} return 0;}
bool inGrid(int r, int c)
{
    return (r >= 1 && r <= n && c >= 1 && c <= m) ? true : false;
}

ll spow(ll x,ll mu)
{
    if (mu==0) return(1);
    if (mu==1) return(x);
    ll k=spow(x,mu/2);
    if (mu%2==1) return((((k*k)%mod)*x)%mod);
    else return((k*k) % mod);
}

bool check(int l, int r)
{
    set<int> th;
    for (int i=l;i<=r;i++)
    {
        if (a[i]!=0) th.insert(a[i]);
    }

    if (th.size()==0) return 1;
    if (th.size()!=1) return 0;
    int p=*th.begin();
    if (r-l+1==p) return 1;
    return 0;
}

int32_t main()
{
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
    rboost
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];

    f[0]=1;

    for (int i=1;i<=n;i++)
    {
        for (int j=i;j>=1;j--)
        {
            if (check(j,i))
            {
                f[i]=(f[j-1]+f[i]);
            }
        }
    }
//    cout<<f[n]<<en;
    if (f[n]==1) cout<<"YES"<<en;
    else cout<<"NO"<<en;
}