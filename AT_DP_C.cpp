#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(ll i=0; i<n; i++){
        cin >> a[i]; cin >> b[i]; cin >> c[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(3,0));
    dp[0][0] = a[0]; dp[0][1] = b[0]; dp[0][2] = c[0];
    for(int i=1; i<n; i++){
        dp[i][0] = a[i] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0],dp[i-1][1]);
    }
    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}