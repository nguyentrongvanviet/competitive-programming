#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {

    string s ; cin>>s ;
    s.resize(unique(s.begin(),s.end())-s.begin()) ; 
    cout<<s<<endl;
    // Write your solution here
}

int main() {
    fastio;
    int t = 1 ; 
    while (t--) {
        solve();
    }
    return 0;
}