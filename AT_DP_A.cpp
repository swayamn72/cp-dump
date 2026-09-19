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
        vi arr(n); for(auto &x : arr) cin >> x;
        vi dp(n); dp[0] = 0;
        dp[1] = abs(arr[1]-arr[0]);
        for(ll i=2; i<n; i++){
            dp[i] = min(dp[i-1]+abs(arr[i-1]-arr[i]), dp[i-2]+abs(arr[i-2]-arr[i]));
        }
        cout << dp[n-1];
    }
} 