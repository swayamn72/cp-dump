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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<double> arr(n); for(auto &x : arr) cin >> x;
        vector<vector<double>> dp(n+1,vector<double>(n+1,0.0));
        dp[0][0] = 1.0;
        for(ll i=1; i<=n; i++){
            for(ll j=0; j<=i; j++){
                // curr coin is tails
                dp[i][j] = dp[i-1][j] * (1.0 - arr[i-1]);
                if(j>0){
                    dp[i][j] += dp[i-1][j-1] * arr[i-1];
                } 
            }
        }
        double res = 0.0;
        for(ll i=n/2+1; i<=n; i++){
            res += dp[n][i];
        }
        cout << fixed << setprecision(9) << res;
    }
} 