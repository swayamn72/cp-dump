#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi a(n), b(n), c(n);
    for(ll i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vi> dp(3, vi(n));
    dp[0][0] = a[0]; dp[1][0] = b[0]; dp[2][0] = c[0];
    for(ll i=1; i<n; i++){
        dp[0][i] = max(dp[1][i-1],dp[2][i-1]) + a[i];
        dp[1][i] = max(dp[0][i-1],dp[2][i-1]) + b[i];
        dp[2][i] = max(dp[0][i-1],dp[1][i-1]) + c[i];
    }
    cout << max({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
}