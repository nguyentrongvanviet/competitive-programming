#define taskname "READER"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lli;
const int maxN = 1e5 + 1;
const int maxM = 1e5 + 1;
int n, m;
lli q[maxN];

struct TVector
{
    lli x, y;
    TVector operator -(const TVector& other) const
    {
        return {x - other.x, y - other.y};
    }
    lli operator *(const TVector& other) const
    {
        return x * other.y - y * other.x;
    }
};

typedef TVector TPoint;
TPoint a[maxN], b[maxN];
int nb;

inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + c - '0';
    return res;
}

void WriteInt(lli x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Enter()
{
    n = ReadInt(); m = ReadInt();
    q[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int t = ReadInt();
        q[i] = q[i - 1] + t;
        a[i] = {q[i - 1], q[i]};
    }
}

inline bool CW(const TPoint& a, const TPoint& b, const TPoint& c)
{
    return (b - a) * (c - b) < 0;
}

void FindConvexHull()
{
    nb = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (nb > 1 && !CW(b[nb - 1], b[nb], a[i])) --nb;
        b[++nb] = a[i];
    }
}

lli WaitTime(const TVector& u)
{
    int low = 2, high = nb;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        TVector v = b[middle] - b[middle - 1];
        if (u * v >= 0) low = middle + 1;
        else high = middle - 1;
    }
    // cout<<high<<" "<<u*b[high]<<endl;
    return u * b[high];
}

void Solve()
{
    // cout<<nb<<endl;
    // for(int i = 1;i<=nb;i++)cout<<b[i].x<<" "<<b[i].y<<endl;
    lli res = 0;
    int PrevC, C;
    C = PrevC = ReadInt();
    for (int i = 2; i <= m; ++i)
    {
        C = ReadInt();
        res += WaitTime({PrevC, C});
        PrevC = C;
    }
    res += q[n] * C;
    WriteInt(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".ANS", "w", stdout);
    Enter();
    FindConvexHull();
    Solve();
}
