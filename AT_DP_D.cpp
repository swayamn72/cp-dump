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

    vector<vi> dp(n+1,vi(wt+1,0));
    for(ll i=1; i<=n; i++){
        ll val = v[i-1], weight = w[i-1];
        for(ll j=1; j<=wt; j++){
            dp[i][j] = dp[i-1][j];
            if(j-weight>=0){
                dp[i][j] = max(dp[i][j],dp[i-1][j-weight]+val);
            }
        }
    }
    cout << dp[n][wt];
}