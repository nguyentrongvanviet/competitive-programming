#define TASK "F_837"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0),srand(time(0));
#define ll long long 
#define db long double
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
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';

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

const int N =2e5+5,maxN=20,oo = 2e9,CH = 26,LO = 18;
const ll sm = 1e9+7,cs=330, inf = 1e17 ;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};
ll rd(ll l , ll r )
{
    return l+1LL*rand()*rand()%(r-l+1);
}
struct Node
{
    int l = 0 , r = 0 ; 
    ll s = 0 ;   
}; 
int n , q, m  ; 
int a[N] ; 
vi value; 
unordered_map<int,int> ps; 
int node =1; 
Node T[N*22] ;
int H[N] ;
ll id[N] ; 
void read()
{
    cin>> n ;
    FOR(i,1,n)cin>>a[i],value.pb(a[i]) ;

    sort(all(value)) ; 
    value.resize(unique(all(value))-value.begin()) ; 
    m = value.size() ;   
    FOR(i,1,m) ps[value[i-1]] = i ; 
    FOR(i,1,n)a[i] = ps[a[i]] , id[a[i]] =rd(1,inf) ;  
}
int up(int pre , int val , int h )
{
    ++node; 
    int cur =node; 
    T[cur].s =(T[pre].s^id[val]);
    if(h==-1)return cur ; 
    if(val>>h&1)
    {   
        T[cur].r = T[pre].r ;
        T[cur].l = up(T[pre].l,val,h-1);
    }
    else
    {
        T[cur].l = T[pre].l ; 
        T[cur].r = up(T[pre].r,val,h-1);
    }
    return cur ; 
}
int get(int l , int r , int val , int h)
{
    if(T[l].s==T[r].s)return 0; 
    if(h==-1)
    {
        return val; 
    }  
    int ans=0 ; 
    if(T[r].r) ans=get(T[l].r,T[r].r,val,h-1); 
    if(ans)return ans;  
    return get(T[l].l,T[r].l,val^(1<<h),h-1);
}
void solve()
{   
    H[0] = 1 ;
    FOR(i,1,n)H[i] = up(H[i-1],a[i],LO);
    cin>>q ;
    int ans= 0 ; 
    while(q--)
    {
        int l  , r ; cin>>l>>r ; 
        l = ans^l ;  
        // l = max(l,1) ; 
        // l=min(n,l) ;  
        r = ans^r ;
        // r=max(r,1) ; 
        // r=min(n,r) ; 
        ans=  get(H[l-1],H[r],0,LO) ; 
        if(ans==0)cout<<0<<el; 
        else
        {
            cout<<value[ans-1]<<el; 
            ans= value[ans-1];
        }
    }
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