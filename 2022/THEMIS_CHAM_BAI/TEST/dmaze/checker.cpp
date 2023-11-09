#include <iostream>
#include <fstream>
using namespace std;

ifstream inp, sol, out;

int A[3072][3072];
int n, m, k;
int p, q, a, b, c;

bool CheckCell(int x)
{
    int i = (x - 1) % m + 1;
    int j = (x - 1) / m + 1;
    if (i < 1 or i > m or j < 1 or j > n)
    {
        cout << "0.3" << endl;
        cerr << "translate:partial" << endl; // out of range
        return false;
    }
    if (A[i][j] == 1)
    {
        cout << "0.3" << endl;
        cerr << "translate:partial" << endl; // forbidden cell
        return false;
    }
    return true;
}

bool CheckLast(int x, int lsol)
{
    int last;
    for (int i = 1; i <= lsol; ++ i)
    {
        sol >> last;
    }
    if (x != last)
    {
        cout << "0.3" << endl;
        cerr << "translate:partial" << endl; // wrong last cell
        return false;
    }
    return true;
}

bool CheckLength(int lout, int lsol)
{
    if (lout == -1)
    {
        if (lsol == -1)
        {
            cout << "1.0" << endl;
            cerr << "translate:success" << endl; // there is not a path
        }
        else
        {
            cout << "0.0" << endl;
            cerr << "translate:wrong" << endl; // there is a path
        }
        return false;
    }
    if (lout != lsol)
    {
        cout << "0.0" << endl;
        cerr << "translate:wrong" << endl; // wrong length
        return false;
    }
    return true;
}

bool CheckOut(bool fl = true)
{
    if (out.fail())
    {
        if (!fl)
        {
            cout << "0.0" << endl;
            cerr << "translate:wrong" << endl; // missing length
        }
        else
        {
            cout << "0.3" << endl;
            cerr << "translate:partial" << endl; // missing next cell
        }
        return false;
    }
    return true;
}

int main(int argc, char * argv[])
{
    inp.open(argv[1]);
    sol.open(argv[2]);
    out.open(argv[3]);

    int x, y;
    inp >> m >> n >> k;
    inp >> p >> q >> a >> b >> c;

    for (int i = 1; i <= p; ++ i)
    {
        x = (q - 1) % m + 1;
        y = (q - 1) / m + 1;
        A[x][y] = 1;
        q = ((long long)(q) * a + b) % c + 1;
    }

    int lout, lsol;
    out >> lout;
    sol >> lsol;

    if (!CheckOut(0) or !CheckLength(lout, lsol)) return 0;

    int v1, v2;
    out >> v1;
    if (!CheckOut() or !CheckCell(v1)) return 0;

    for (int i = 1; i < lout; ++ i)
    {
        out >> v2;
        if (!CheckOut() or !CheckCell(v2)) return 0;
        if (v2 - v1 != 1 and v2 - v1 != m and v2 - v1 != m + 1)
        {
            cout << "0.3" << endl;
            cerr << "translate:partial" << endl; // wrong path
            return 0;
        }
        v1 = v2;
    }

    if (!CheckLast(v1, lsol)) return 0;

    cout << "1.0" << endl;
    cerr << "translate:success" << endl; // okay

    return 0;
}
