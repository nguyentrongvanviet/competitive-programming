/*
DOANHONGBAO
1505
*/
#define TASK "MSEQ"
#define INPUT TASK".INP" 
#define OUTPUT TASK".ANS"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 0;
 
#define ll long long 
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
#define int ll
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 2e5+5, oo = 2e9, LO = 17; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;

int n;
int a[N];

void doc()
{
    cin>>n;
    FOR(i,1,n) cin>>a[i];
}

int f[N];
namespace sub1
{
    void xuly()
    {
        FOR(i,1,n) f[i] = inf;
        FOR(i,1,n)
        {
            int sum = 0;
            FOR(j,i,n) 
            {
                sum += (a[j] != j - i + 1);
                mini(f[j],f[i - 1] + sum);      
            }
        }
        cout<<f[n];
    }
}
namespace subfull
{
    int st[N * 4];
    int lazy[N * 4];
    vi line[N];
    void dolazy(int id,int l,int r)
    {
        if(lazy[id] == inf) return;
        int t = lazy[id];
        lazy[id] = inf;
        mini(st[id] , t);
        if(l == r) return;
        mini(lazy[id*2],t);
        mini(lazy[id*2+1],t);
    }
    void up(int id,int l,int r,int d,int c,int val)
    {
        dolazy(id,l,r);
        if(l > c || r < d) return ;
        if(d<=l&&r<=c)
        {
            mini(lazy[id],val);
            dolazy(id,l,r);
            return;
        }
        int mid = (l+r)/2;
        up(id*2,l,mid,d,c,val);
        up(id*2+1,mid+1,r,d,c,val);
        st[id] = min(st[id*2],st[id*2+1]);
    }
    int get(int id,int l,int r,int pos)
    {
        dolazy(id,l,r);
        if(l > pos || r < pos) return inf;
        if(l == r) return st[id];
        int mid = (l+r)/2;
        return min(get(id*2,l,mid,pos),get(id*2+1,mid+1,r,pos));
    }
    void xuly()
    {
        FOR(i,1,n * 4) lazy[i] = inf;
        FOR(i,1,n) 
        {   
            int l = - (a[i] - i - 1);
            if(l < 1) continue;
            if(l > i) continue;
            int r = i;
            line[l].pb(r);
        }
        up(1,0,n,0,0,0);
        FOR(i,1,n) 
        {
            if(line[i].empty()) continue;
            sort(all(line[i]));
            int val = get(1,0,n,i - 1) + i - 1;
            int pre = line[i][0];
            FOR(j,1,line[i].size() - 1)
            {
                int pos = line[i][j];
                up(1,0,n,pre,pos,val - i + 1 - (j));
                pre = pos;
            }
            up(1,0,n,pre,n,val - i + 1 - line[i].size());
        }
        cout<<get(1,0,n,n) + n;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    FOR(i,1,test)
    {
        doc() ; 
        if(n <= 3000) sub1::xuly();
        else subfull::xuly(); 
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}