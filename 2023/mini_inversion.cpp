#include <bits/stdc++.h>

using namespace std;

#define type(x) __typeof((x).begin())
#define foreach(it, x) for(type(x) it = (x).begin(); it != (x).end(); it++)

typedef long long ll;
typedef pair < int, int > ii;

const int inf = 1e9 + 333;
const ll linf = 1e18 + 333;

const int N = 5e5 + 5;

int n, a[N], w[N], add[N << 2];
pair < int, ii > qu[N << 1];
ii lu[N], rd[N], t[N << 2];
vector < int > canlu, canrd;

void init(int x, int l, int r) {
    if(l == r) {
        t[x] = ii(0, l);
        return;
    }
    int m = l + r >> 1;
    init(x + x, l, m);
    init(x + x + 1, m + 1, r);
    t[x] = max(t[x + x], t[x + x + 1]);
}

void up(int x, int l, int r, int x1, int x2, int k) {
    if(x2 < l or r < x1)
        return;
    if(x1 <= l and r <= x2) {
        t[x].first += k;
        add[x] += k;
        return;
    }
    int m = l + r >> 1;
    up(x + x, l, m, x1, x2, k);
    up(x + x + 1, m + 1, r, x1, x2, k);
    t[x] = max(t[x + x], t[x + x + 1]);
    t[x].first += add[x];
}

int main() {

    scanf("%d", &n);

    bool flag = 0;

    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        flag |= a[i] != i;
        w[a[i]] = i;
    }

    if(!flag) {
        puts("Cool Array");
        return 0;
    }

    int mx = 0;

    for(int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        if(mx == a[i])
            canlu.push_back(a[i]);
        int ind = lower_bound(canlu.begin(), canlu.end(), a[i]) - canlu.begin();
        lu[i] = ii(ind, canlu.size() - 1);
        if(lu[i].first > lu[i].second)
            lu[i].first = -1;
    }

    int mn = inf;

    for(int i = n; i >= 1; i--) {
        mn = min(mn, a[i]);
        if(mn == a[i])
            canrd.push_back(-a[i]);
        int ind = lower_bound(canrd.begin(), canrd.end(), -a[i]) - canrd.begin();
        rd[i] = ii(ind, canrd.size() - 1);
        if(rd[i].first > rd[i].second)
            rd[i].first = -1;
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        if(lu[i].first != -1 and rd[i].first != -1) {
            qu[cnt++] = make_pair(lu[i].first, ii(rd[i].first, rd[i].second));
            qu[cnt++] = make_pair(lu[i].second + 1, ii(rd[i].first - inf, rd[i].second - inf));
        }
    }

    pair < int, ii > ans = make_pair(-1, ii(0, 0));

    sort(qu, qu + cnt);

    int bef = -1;

    init(1, 0, n - 1);

    for(int it = 0; it < cnt; it++) {
        int i = qu[it].first;
        int x = qu[it].second.first;
        int y = qu[it].second.second;
        int k = x < 0 ? -1 : 1;
        if(k == -1) {
            x += inf;
            y += inf;
        }
        up(1, 0, n - 1, x, y, k);
        if(k == 1 and t[1].first >= ans.first) {
            pair < int, ii > res = make_pair(t[1].first, ii(w[canlu[i]], w[-canrd[t[1].second]]));
            if(res.first > ans.first or (res.first == ans.first and res.second < ans.second))
                ans = res;
        }
    }

    printf("%d %d\n", ans.second.first, ans.second.second);

    return 0;

}