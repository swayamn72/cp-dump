#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll k; cin >> k;    
        vector<vector<ll>> dp(k+1,vi(3,0));
        // 0 - s 
        // 1 - t
        // 2 - tt
        dp[1][0] = 1; dp[1][1] = 1;
        for(ll i=2; i<=k; i++){
            dp[i][0] = (dp[i-1][1] + dp[i-1][2])%mod;
            dp[i][1] = dp[i-1][0];
            dp[i][2] = dp[i-1][1];
        }
        ll res = (dp[k][0] + dp[k][1] + dp[k][2])%mod;
        cout << res << "\n";
    }
} 