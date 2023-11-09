#include<bits/stdc++.h>
using namespace std;
int n, t;
long long ans = 0;
priority_queue<int> Q;
int main() {
	freopen("i.txt","r",stdin) ; 
	freopen("o.txt","w",stdout) ; 
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        Q.push(t);
        ans += Q.top() - t;
        Q.pop(); Q.push(t);
    }
    cout<<ans;
    return 0;
}