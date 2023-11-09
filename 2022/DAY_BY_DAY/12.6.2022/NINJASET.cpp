// Cao Quang Hung
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<long long , long long>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define FOR(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define dem(x) __builtin_popcount(x)
#define Mask(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define ln '\n'
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937 rnd(time(0));

const int INF = 1e9 , mod = 1e9 + 7;

template <class T1, class T2>
inline T1 mul(T1& x, const T2 &k){ return x = (1LL * x * k) % mod; }

template <class T1 , class T2>
inline T1 pw(T1 x, T2 k){T1 res = 1; for (; k ; k >>= 1){ if (k & 1) mul(res, x); mul(x, x); } return res;}

template <class T>
inline bool minimize(T &x, const T &y){ if (x > y){x = y; return 1;} return 0; }

template <class T>
inline bool maximize(T &x, const T &y){ if (x < y){x = y; return 1;} return 0; }

template <class T>
inline void add(T &x , const T &y){ if ((x += y) >= mod) x -= mod; }

template <class T>
inline T product (const T &x , const T &y) { return 1LL * x * y % mod; }
#define PROB "NINJASET"
void file(){
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp","r",stdin);
        freopen(PROB".out","w",stdout);
    }
}
void sinh_(){
//    srand(time(0));
//    freopen(PROB".inp" , "w" , stdout);
//    int n;
}
typedef long long ll;
const int N = 2e5 + 5;
multiset<int> s[N];
int n , val[N], root;
vi adj[N];
void readip(){
    cin >> n;
    REP(i, 1, n){
        cin >> val[i];
        int p; cin >> p;
        if (!p) root = i;
        else adj[p].eb(i);
    }
}
void dfs_tree(int u){
    for (int &v : adj[u]){
        dfs_tree(v);
        if (SZ(s[u]) < SZ(s[v]))
            s[u].swap(s[v]);
        s[u].insert(ALL(s[v]));
        s[v].clear();
    }
    if (s[u].empty()) s[u].emplace(val[u]);
    else{
        auto it = s[u].lower_bound(val[u]);
        if (it == s[u].end()) s[u].emplace(val[u]);
        else{
            s[u].erase(it);
            s[u].emplace(val[u]);
        }
    }
}
void solve(){
    dfs_tree(root);
    cout << SZ(s[root])<<endl;
    for(auto v : s[root])cout<<v<<" ";
}

int main(){
    sinh_();
    io_faster
    file();
    int t = 1;
//    cin >> t;
    while (t--){
        readip();
        solve();
    }
}
