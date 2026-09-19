#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        // 0 - i kill
        // 1 - friend kills
        vector<vi> dp(n,vi(2));
        dp[0][1] = arr[0];
        dp[0][0] = 1e9;
        if(n==1){
            cout << dp[0][1] << "\n";
            continue;
        }
        dp[1][0] = dp[0][1];
        dp[1][1] = dp[0][1] + arr[1];
        for(ll i=2; i<n; i++){
            // i kill
            dp[i][0] = dp[i-1][1];
            dp[i][0] = min(dp[i][0], dp[i-2][1]);
            // friend kills 
            dp[i][1] = dp[i-1][0] + arr[i];
            dp[i][1] = min(dp[i][1], dp[i-2][0] + arr[i] + arr[i-1]); 
        }
        cout << min(dp[n-1][0],dp[n-1][1]) << "\n";
    }
}