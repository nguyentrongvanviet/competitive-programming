#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
#define pii pair<int,int>
#define fi first 
#define se second
#define all(a) a.begin(),a.end()
#define sz(a) (ll)a.size()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17; 
struct edge 
{
    int u , v , w;  
    bool operator <(const edge& a  )const 
    {
        return w<a.w; 
    }
};
int n ; 
vector<int>a;
vector<edge>q;
int pa[N];
int max_val;  
void inp()
{
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    sort(a.begin(),a.end());
 
    a.resize(unique(a.begin(),a.end()) - a.begin());
    
    max_val = a.back();
    n = a.size();
}

void init()
{
    for(int i =0 ;i<n;i++)
    {
        pa[i] =  i ;
    }
}
void build()
{
    for(int i = 0; i < n - 1; ++i) {
        for(int j = a[i]; j <= max_val; j += a[i]) {
            int k = lower_bound(a.begin() + i + 1, a.end(), j) - a.begin();
            if(k >= n) continue;
            if(a[k] - j > a[ i]) continue;
            q.push_back({i, k, a[k] - j});
        }
    }
}
ll res=0 ;  
ll goc(int u )
{
    return (pa[u]==u?u:pa[u]=goc(pa[u])) ;
}   
void hop(int u , int v ,int w )
{
    int chau=goc(u) ; 
    int chav=goc(v) ; 
    if(chau==chav)return ;
    res+=w;  
    pa[chau]=chav; 
}
void solve()
{
    sort(q.begin(),q.end()) ; 
    for(int i= 0 ;i<q.size();i++)
    {
        int  u =q[i].u ; 
        int v =q[i].v ;  
        hop(u,v,q[i].w) ;       
    }
    cout<<res ; 
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    // freopen("i.txt","r",stdin); 
    // freopen("o.txt","w",stdout); 
    int t ; 
    t = 1; 
    while(t--)
    {
        inp(); 
        build(); 
        init(); 
        solve() ; 
    }
    return 0;
}