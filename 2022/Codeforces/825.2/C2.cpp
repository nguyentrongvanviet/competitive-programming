#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr, left_most, right_most, right_second_most;
void get_bound() {
    // left_most[i] represents the leftmost point such that subarray arr[left_most[i]:i] is good
    left_most.resize(n + 1);
    // right_most[i] represents the rightmost point such that subarray arr[i:right_most[i]] is good
    right_most.resize(n + 1);
    // right_second_most[i] is similar with right_most[i]
    // but when you start from i, and go right, you have one chance to skip bad point.
    right_second_most.resize(n + 1);
    for (int l = 1, r = 1, r2 = 1; l <= n; l++) {
        while (r <= n and arr[r] - r >= 1 - l) {
            left_most[r] = l;
            r++;
        }
        right_most[l] = r - 1;
        r2 = max(r2, min(r + 1, n + 1));
        while (r2 <= n and arr[r2] - r2 >= 1 - l) {
            r2++;
        }
        right_second_most[l] = r2 - 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    get_bound();
    // S1: presum of contributions of all points
    // S2: presum of contributions of all points, if each of them has one skip chance.
    std::vector<long long> S1(n + 1);
    std::vector<long long> S2(n + 1);
    for (int i = 1; i <= n; i++) S1[i] = S1[i - 1] + (right_most[i] - i + 1);
    for (int i = 1; i <= n; i++) S2[i] = S2[i - 1] + (right_second_most[i] - i + 1);
    long long total = S1.back();
    for(int i= 1;i<=n;i++)cout<<right_most[i]<<" ";cout<<"\n";
    int m;  
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        if (x == arr[p]) {
            cout << total << '\n';
        } else if (x < arr[p]) {
            int now_left_most = max(left_most[p], p - x + 1);
            if (now_left_most == left_most[p]) {
                cout << total << '\n';
                continue;
            }
            // now_left_most > left_most[p]
            // we can cut off contributions from left_most[p] to now_left_most-1.
            // but, they are not cut off completely. they can still reach p-1.
            long long cut_off = S1[now_left_most - 1] - S1[left_most[p] - 1];
            long long remain = (long long)((p - now_left_most) + (p - left_most[p] + 1)) * (now_left_most - left_most[p]) / 2;
            cout << total - cut_off + remain << '\n';
        } else {
            int now_left_most = max(int(lower_bound(right_most.begin() + 1, right_most.end(), p - 1) - right_most.begin() - 1) + 1, p - x + 1);
            if (now_left_most == left_most[p]){
                cout << total << '\n';
                continue;
            }
            // now_left_most < left_most[p]
            // this is the time to use skip chance!
            // for all those points that stuck at p, they can skip p and reach right_second_most
            long long old_sum = S1[left_most[p] - 1] - S1[now_left_most - 1];
            long long now_sum = S2[left_most[p] - 1] - S2[now_left_most - 1];
            cout<<old_sum<<" "<<now_sum<<"\n";
            cout << total - old_sum + now_sum << '\n';
        }
    }
}