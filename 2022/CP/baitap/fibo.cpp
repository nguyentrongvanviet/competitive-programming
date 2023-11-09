#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
 #define int long long  
 #define ll long long 
 const ll sm= 1e9+7 ; 
map<ll,ll>dd; 
ll n ; 
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (dd[n] = 1);
 
    // If fib(n) is already computed
    if (dd[n])
        return dd[n];
    int k = (n & 1)? (n+1)/2 : n/2;
    ll res = (n & 1)? ((fib(k)*fib(k)%sm + fib(k-1)*fib(k-1)%sm)%sm)
           : ((2*fib(k-1)%sm+ fib(k))*fib(k)%sm)%sm;
    return dd[n] =res; 
}
signed main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    cin>> n; 
    printf("%d ", fib(n));
    return 0;
}
