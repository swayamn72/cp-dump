#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi c(n); for(auto &x : c) cin >> x;
        vi dp(n,0LL);
        dp[0] = c[0];
        ll res = dp[0];
        for(ll i=1; i<n; i++){
            dp[i] = c[i];
            ll maxv = 0LL;
            for(ll j=i-1; j>=0; j--){
                if(arr[j]<=arr[i]) maxv = max(maxv,dp[j]);
            }
            dp[i] += maxv;
            res = max(res,dp[i]);
        }        
        cout << accumulate(c.begin(),c.end(),0LL) - res << "\n";
    }
}