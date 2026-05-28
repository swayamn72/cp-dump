#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vector<double> arr(n); for(auto &x : arr) cin >> x;
    vector<vector<double>> dp(n+1, vector<double>(n+1,0.0));
    dp[0][0] = 1.0;
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<=i; j++){
            if(j>0) dp[i][j] += dp[i-1][j-1] * (arr[i-1]);
            if(j<i) dp[i][j] += dp[i-1][j] * (1.0 - arr[i-1]);
        }
    }
    double res = 0.0;
    for(ll i=n/2+1; i<=n; i++){
        res += dp[n][i];
    }
    cout << setprecision(16) << res;
}