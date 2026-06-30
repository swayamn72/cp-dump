// sos template
// vector<int> dp(1 << N, 0);
// for (int mask = 0; mask < (1 << N); mask++) {
//     dp[mask] = initial_value[mask];
// }
// for (int i = 0; i < N; i++) {
//     for (int mask = (1 << N) - 1; mask >= 0; mask--) {
//         if (mask & (1 << i)) {
//             // TYPE A: Subsequence/Subset Propagation (What you used)
//             if (dp[mask] != 0) dp[mask ^ (1 << i)] = dp[mask];
//             // TYPE B: Summing Over Subsets (Counting problems)
//             // dp[mask] += dp[mask ^ (1 << i)];
//         }
//     }
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    
    vi dp(1LL<<22,-1);
    for(ll i=0; i<n; i++){
        dp[arr[i]] = arr[i];    
    }
    for(ll i=0; i<22; i++){
        for(ll mask = 0; mask < (1LL<<22); mask++){
            if(mask & (1<<i)){
                if(dp[mask^(1LL<<i)]!=-1){
                    dp[mask] = dp[mask ^ (1<<i)];
                }
            }
        }
    }
    vi res(n,-1);
    for(ll i=0; i<n; i++){
        ll complement = arr[i] ^ ((1LL<<22)-1);
        res[i] = dp[complement];
    }
    for(auto a : res) cout << a << " ";
}