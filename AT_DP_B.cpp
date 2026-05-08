#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k; cin >> n >> k;
    vector<ll> arr(n); for(auto &x : arr) cin >> x;
    vector<ll> dp(n, LLONG_MAX);
    dp[0] = 0;
    dp[1] = abs(arr[1]-arr[0]);
    for(ll i=2; i<n; i++){
        ll limit = max(0LL,i-k);
        for(ll j=limit; j<i; j++){
            dp[i] = min(dp[i],dp[j]+abs(arr[i]-arr[j]));
        }
    }
    cout << dp[n-1];
}