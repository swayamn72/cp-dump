#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tc=1; 
    // cin >> t;
    while(tc--){
        ll n,t; double p; cin >> n >> p >> t;
        vector<vector<double>> dp(t+1, vector<double>(n+1,0.0));
        dp[0][0] = 1.0;
        for(ll i=1; i<=t; i++){
            for(ll j=0; j<=n; j++){
                if(j==n){
                    dp[i][j] += dp[i-1][j]*1.0;
                    dp[i][j] += dp[i-1][j-1]*p;
                }else{
                    dp[i][j] += dp[i-1][j] * (1.0-p);
                    if(j>0) dp[i][j] += dp[i-1][j-1]*p;
                }
            }
        }
        double res = 0.0;
        for(ll i=0; i<=n; i++){
            res += (dp[t][i]*i);
        }
        cout << fixed << setprecision(9) << res;
    }
} 