#define TASK "text"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
ll sq(ll a){return a*a;}  
ll gcd(ll a, ll b){return b ==0 ? a: gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS()
{
    fast 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin) ;
        freopen(TASK".OUT","w",stdout) ;
    }
}
const int N =2e5+5 ,  oo = 2e9, CH = 26 ;
const ll sm = 1e9+7, cs=330, inf = 1e17 ;
const db PI = acos(-1) ; 
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
int n ; 
struct DL
{
    ll val;  
    int l , r;  
};
DL a[N] ; 
ll f[N]  ; 
ll st[4*N] ; 
void read()
{
    cin>> n;  
    FOR(i,1,n)cin>>a[i].val,a[i].val+=a[i-1].val; 
    FOR(i,2,n)cin>>a[i].l>>a[i].r;  
}
void up(int id , int l , int r, int t , int p , ll val)
{
    if(t<=l&&r<=p)
    {
        st[id] = val; 
        return ; 
    }
    if(r<t||p<l)return ; 
    int mid =(l+r)/2; 
    up(id*2,l,mid,t,p,val) ; 
    up(id*2+1,mid+1,r,t,p,val) ; 
    st[id]=min(st[id*2],st[id*2+1]) ; 
}
ll get(int id , int l , int r , int t , int p )
{
    if(r<t||p<l)return inf ;
    if(t<=l&&r<=p)return st[id]; 
    int mid =(l+r)/2; 
    return min(get(id*2,l,mid,t,p),get(id*2+1,mid+1,r,t,p)) ; 
}
void solve()
{
    f[1]  = 0 ;
    up(1,1,n,1,1,0); 
    FOR(i,2,n)
    {
        f[i] = get(1,1,n,a[i].l,a[i].r)+a[i].val ;
        up(1,1,n,i,i,f[i]-a[i-1].val); 
    }
    FOR(i,1,n)cout<<f[i]<<" "; 
}

signed main()
{
    IOS();
    int test =1;
    if(multitest)cin>>test;
    while(test--)
    {
        read(); 
        solve();
    }
}