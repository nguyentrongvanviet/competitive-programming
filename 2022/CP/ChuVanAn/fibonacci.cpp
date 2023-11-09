#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
#define pk pop_back
// #define int long long
#define int unsigned long long 
#define pii pair<int,int>
#define fi first 
#define se second
#define _sz(a) (int)a.size() 
#define all(a) a.begin(),a.end()
const int N =2e5+5 ,  oo = 1e9 ;
const ll sm = 1e9+7,cs=330 ,inf = 1e17;

int n ; 
void input()
{
 	cin>>n ;    
}
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = (p.first * (2 * p.second +sm-p.first))%sm;
    int d = ((p.first * p.first)%sm + (p.second * p.second)%sm)%sm;
    if (n & 1)
        return {d%sm, (c + d)%sm};
    else
        return {c%sm, d%sm};
}

void output()
{
    cout<<fib(n).fi%sm;
}
 main()
{
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    freopen("i.txt","r",stdin); 
    freopen("o.txt","w",stdout); 
    int t ; 
    t=1;
    // cin>>t;
    while(t--)
    {
        input();
        output(); 
    }
    return 0;
}