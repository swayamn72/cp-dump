#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,s; cin >> n >> s;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi minarr(n);
        for(ll i=0; i<n; i++) minarr[i] = min(s,arr[i]);

        vector<vector<ll>> dp(2, vector<ll>(n,0));
        dp[0][1] = minarr[1]*arr[0];
        dp[1][1] = (arr[1]-minarr[1])*arr[0];

        for(ll i=2; i<n-1; i++){
            dp[0][i] = min(dp[0][i-1] + (arr[i-1]-minarr[i-1])*minarr[i], dp[1][i-1] + (minarr[i-1])*minarr[i]);
            dp[1][i] = min(dp[0][i-1] + (arr[i-1]-minarr[i-1])*(arr[i]-minarr[i]), dp[1][i-1] + (minarr[i-1])*(arr[i]-minarr[i]));
        }
        ll res = dp[0][n-2] + arr[n-1]*(arr[n-2]-minarr[n-2]);
        res = min(res, dp[1][n-2] + arr[n-1]*minarr[n-2]);

        cout << res << "\n";
    }
}