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
    vi dp(n,0);
    dp[1] = abs(arr[0]-arr[1]);
    for(ll i=2; i<n; i++){
        dp[i] = dp[i-1] + abs(arr[i]-arr[i-1]);
        dp[i] = min(dp[i], dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout << dp[n-1];
}