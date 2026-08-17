#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,wt; cin >> n >> wt;
    vi w(n), v(n);
    for(ll i=0; i<n; i++) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(n,vector<ll>(wt+1));

    for(ll i=w[0]; i<=wt; i++) dp[0][i] = v[0];
    for(ll i=1; i<n; i++){
        for(ll j=0; j<=wt; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=w[i]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    cout << dp[n-1][wt];
}