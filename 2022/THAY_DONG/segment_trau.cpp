#include<bits/stdc++.h>
using namespace std;

#define TASK "segment"
#define faster ios_base :: sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0)
#define For(i,l,r) for(int i=(int)l ; i<=(int)r ; i++)
#define Forn(i,r,l) for(int i=(int)r ; i>=(int)l ; i--)
#define all(v) v.begin(),v.end()
#define pb push_back
#define fi first
#define se second

typedef pair<long long,long long> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;

const int base=311, inf=2e9, N=3005 ;
const long long sm=1e9+7, oo=1e18;

ll w, h, n, area;
bool dd[N][N], wall[N][N][4];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool inside(ll x, ll y)
{
    return 1 <= x && x <= w && 1 <= y && y <= h;
}
void DFS(int i, int j)
{
    if (dd[i][j]) return;
    dd[i][j] = 1;
    area++;

    For(k, 0, 3)
    {
        if (wall[i][j][k])continue;
        int u = i + dx[k], v = j + dy[k];
        if (!inside(u, v)) continue;
        DFS(u, v);
    }
}
int main()
{
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".ANS","w",stdout);
    }
    faster;
    
    cin >> w >> h;
    cin >> n;
    For(i, 1, n)
    {
        ll x, y, u, v;
        cin >> x >> y >> u >> v;
        if (x == u)
        {
            For(j, min(y, v) + 1, max(y, v))
            {
                if (!inside(x, j)) continue;
                wall[x][j][1] = 1;
                wall[x + 1][j][3] = 1;
            }
        }
        if (y == v)
        {
            For(j, min(x, u) + 1, max(x, u))
            {
                if (!inside(j, y)) continue;
                wall[j][y][0] = 1;
                wall[j][y + 1][2] = 1;
            }
        }
    }

    vector<ll> sol;
    For(i, 1, w)For(j, 1, h)
    if (!dd[i][j])
    {
        area = 0;
        DFS(i, j);
        sol.pb(area);
    }

    sort(all(sol), greater<ll>());
    for(ll i : sol) cout << i << '\n';
    
    return 0;
}