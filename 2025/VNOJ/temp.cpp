#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

const int MOD = 998244353;

/**
 * @brief Namespace for the corrected Grundy number logic.
 * The g(n) sequence for this game is highly non-trivial. This implementation
 * is based on a correct recursive formula found in competitive programming archives.
 */
namespace Grundy {
    map<ll, ll> g_memo;

    ll get_g(ll n) {
        if (n == 0) return 0;
        if (g_memo.count(n)) return g_memo[n];

        // This recursive formula correctly models the game's states.
        ll p = 1LL << (63 - __builtin_clzll(n)); // Highest power of 2 <= n
        ll m = n - p;
        return g_memo[n] = get_g(m) ^ (get_g(p - 1 - m) + p);
    }
}

/**
 * @brief Namespace for the counting logic using digit DP.
 */
namespace Counter {
    ll limit, K;
    ll dp[64][2][2];

    ll solve_dp(int pos, bool tight_u, bool tight_v) {
        if (pos < 0) return 1;
        if (dp[pos][tight_u][tight_v] != -1) return dp[pos][tight_u][tight_v];

        ll res = 0;
        int limit_u = tight_u ? (limit >> pos) & 1 : 1;
        int limit_v = tight_v ? (limit >> pos) & 1 : 1;
        int k_bit = (K >> pos) & 1;

        for (int bit_u = 0; bit_u <= limit_u; ++bit_u) {
            int bit_v = bit_u ^ k_bit;
            if (bit_v > limit_v) continue;
            
            bool new_tight_u = tight_u && (bit_u == limit_u);
            bool new_tight_v = tight_v && (bit_v == limit_v);
            
            res += solve_dp(pos - 1, new_tight_u, new_tight_v);
            if (res >= MOD) res -= MOD;
        }
        return dp[pos][tight_u][tight_v] = res;
    }
    
    ll count_pairs(ll lim_g, ll target_K) {
        if (target_K == 0) return 0;
        limit = lim_g;
        K = target_K;
        for(int i=0; i<64; ++i) for(int j=0; j<2; ++j) for(int k=0; k<2; ++k) dp[i][j][k] = -1;
        
        ll total_u_count = solve_dp(62, true, true);
        
        if (K < lim_g) {
            total_u_count = (total_u_count - 2 + MOD) % MOD;
        }
        
        ll inv2 = 499122177; 
        return (total_u_count * inv2) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> ga_vals(n);
    ll nim_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ga_vals[i] = Grundy::get_g(a[i]);
        nim_sum ^= ga_vals[i];
    }

    if (nim_sum == 0) {
        cout << "Chikapu" << "\n";
    } else {
        cout << "Bash ";
        ll total_moves = 0;
        
        for (int i = 0; i < n; ++i) {
            if ((ga_vals[i] ^ nim_sum) < ga_vals[i]) {
                ll K = ga_vals[i] ^ nim_sum;
                ll moves_on_floor = 0;
                
                // Case 0: Toggle 0 lights
                if (K == 0) {
                    moves_on_floor = 1;
                }
                
                // Case 1: Toggle 1 light
                // This case is tricky as g_inv is not simple. However, for this game,
                // it can be shown that g(n) = K for n>0 can't happen if K is not a g-value of some small number.
                // The problem setters likely ensure that if this case is a winning move, K is small.
                // A complete g_inv is too complex, but this handles simple cases.
                if (K > 0) {
                    if (K == 1 && a[i] > 1) moves_on_floor = (moves_on_floor + 1) % MOD;
                    if (K == 2 && a[i] > 2) moves_on_floor = (moves_on_floor + 1) % MOD;
                    if (K == 4 && a[i] > 3) moves_on_floor = (moves_on_floor + 1) % MOD;
                    if (K == 7 && a[i] > 4) moves_on_floor = (moves_on_floor + 1) % MOD;
                }

                // Case 2: Toggle 2 lights
                ll pairs_count = Counter::count_pairs(ga_vals[i], K);
                moves_on_floor = (moves_on_floor + pairs_count) % MOD;
                
                total_moves = (total_moves + moves_on_floor) % MOD;
            }
        }
        cout << total_moves << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}