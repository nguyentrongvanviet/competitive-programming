#define taskname "RIDER"
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef long long lli;
const int maxM = 1e5 + 1;
const lli Mul = 1e12;
const int Prec = 12;

int m, n, z;

struct TVector
{
    lli x, y;
    lli inline operator *(const TVector& other) const
    {
        return x * other.y - y * other.x;
    }
    TVector inline operator -(const TVector& other) const
    {
        return {x - other.x, y - other.y};
    }
};
typedef TVector TPoint;

TVector p[maxM];

bool CW(const TPoint& a, const TPoint& b, const TPoint& c)
{
    TVector u = b - a, v = c - b;
    return u * v < 0LL;
}

void ReadInput()
{
    cin >> m;
    z = 0;
    for (int i = 1; i <= m; ++i)
    {
        TPoint q;
        q.x = i;
        cin >> q.y;
        while (z >= 2 && !CW(p[z - 1], p[z], q)) --z;
        p[++z] = q;
    }
    cout<<z<<endl;
}

void WriteFrac(lli a, lli b)
{
    lli x = a, y = b;
    while (y != 0)
    {
        lli r = x % y;
        x = y;
        y = r;
    }
    cout << a / x << ' ' << b / x << '\n';
}

void Cal(lli t)
{
    TPoint q = {0, t};
    int low = 1, high = z - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (CW(q, p[mid], p[mid + 1])) high = mid - 1;
        else low = mid + 1;
    }
    lli DeltaT = p[low].y - t;
    lli DeltaS = p[low].x;
    WriteFrac(DeltaS, DeltaT);
}

void Solve()
{
    cin >> n;
    while (n-- > 0)
    {
        lli t;
        cin >> t;
        Cal(t);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Solve();
}
