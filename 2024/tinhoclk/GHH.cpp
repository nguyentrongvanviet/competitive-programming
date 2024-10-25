#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    // Your code here
    int val; 
    cin>>val ;
    int sum = 0 ; 
    for(int i=1;i<=sqrt(val);i++)
    {
        if(val%i==0)
        {
            sum+=i ;
            if(val!=i*i)sum+=val/i ; 
        }
        if(sum>=2*val)return void(cout<<1<<'\n') ; 
    }
    return void(cout<<0<<'\n') ;
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}