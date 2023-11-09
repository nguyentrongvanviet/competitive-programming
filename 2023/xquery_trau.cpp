// Author: Nguyen Quoc Phu Dep Trai    

#define TASK "xquery"
#include<bits/stdc++.h>
using namespace std; 

bool multitest = false;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define db long double
#define mp make_pair
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin())
#define str string 
#define fi first 
#define se second  
#define pb push_back 
#define pk pop_back 
#define pt pop_front
#define pf push_front
#define el '\n'
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define fd(i,a,b) for(int i=(a);i>=(b);i--)
#define FORN(i,a,b) for(int i=(a);i<(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a) 
#define btctz(a) __builtin_ctz(a) // bit 1 MIN
#define btclz(a) __builtin_clz(a)  // bit 1 MAX
#define print(a) for(auto  v : a )cout<<v<<" ";cout<<'\n';
#define            tct  template<typename T>
#define BIT(x,i) ((x>>i)&1)
#define MASK(x) (1<<(x))
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){f(i,1,n)cout<<a[i]<<" ";cout<<el;}
const ll INF=(ll)1e18 + 7LL;
const int N =1e5+5, maxN=20, oo = 2e9, CH = 26 , size = 1e3 +5;
const ll sm = 1e9+7, base=311, inf = 1e18 , MOD=1e9+7 , LG=18;
const db PI = acos(-1), eps = 1e-9 ;
int xx[] = {0,0,0,-1,1}; 
int yy[] = {0,-1,1,0,0};

// end template and solution


multiset<ll>save;
ll tr[N*LG][2],sl[N*LG],mask[N*LG][LG+1],q,node=1,tmp=0;

void read()
{
    
}
void add(ll val){
    ll r=1; val=val^tmp;
    fd(i,LG,0){
        ll v=val>>i&1;
        if(!tr[r][v]) tr[r][v]=++node;
        r=tr[r][v];
        f(msk,0,LG) mask[r][msk]+=BIT(val,msk);
        sl[r]++;
    }
}
void trieerase(ll val){
    ll r=1; val=val^tmp;
    fd(i,LG,0){
        ll v=val>>i&1;
        r=tr[r][v];
        f(msk,0,LG) if(mask[r][msk]>0) mask[r][msk]-=BIT(val,msk);
        if(sl[r]>0) sl[r]--;
    }
}
ll get(ll val){
    ll r=1; ll res=0;
    fd(i,LG,0){
        ll pre=tmp>>i&1;
        if(r==0) return res;
        if(sl[tr[r][pre]]>=val){
            r=tr[r][pre];
        }
        else {
            val-=sl[tr[r][pre]];
            if(pre) res+=(1<<i)*min(val,(sl[tr[r][pre^1]]-mask[tr[r][pre^1]][i]));
            else res+=(1<<i)*min(val,mask[tr[r][pre^1]][i]);
            fd(msk,i-1,0){
                ll v=tmp>>msk&1;
                if(v) res+=(1<<msk)*(sl[tr[r][pre]]-mask[tr[r][pre]][msk]);
                else res+=(1<<msk)*mask[tr[r][pre]][msk];
            }
            r=tr[r][pre^1];
        }
    }
    return res;
}
void solve()
{
    cin>>q;
    f(i,1,q){
        ll type,u;
        cin>>type>>u;
        if(type==0){
            add(u);
            save.insert((u^tmp));
        }
        else if(type==1){
            if(save.count(u^tmp)==0) continue;
            trieerase(u);
            save.erase(save.find(u^tmp));
        }
        else if(type==2){
            tmp^=u;
        }
        else {
            cout<<get(u)<<el;
        }
    }
}

signed main()    
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(TASK".INP", "r"))
    {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".ANS", "w", stdout);
    }
    fast;
    ll test =1; 
  //  cin>>test;
   while(test--)
    {
        read(); 
        solve();
    }
    cerr << "\nTime: " << clock() << "ms\n";
}