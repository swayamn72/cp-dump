#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,k; cin >> n >> k;
    vi arr(n); for(auto &x : arr) cin >> x;
    vi dp(n,LLONG_MAX);
    dp[0] = 0;
    for(ll i=1; i<n; i++){
        for(ll j=i-1; j>=max(0LL,i-k); j--){
            dp[i] = min(dp[i],dp[j]+abs(arr[i]-arr[j]));
        }
    }
    cout << dp[n-1];
}