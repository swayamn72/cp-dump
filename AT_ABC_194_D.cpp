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
        vector<double> dp(n+1,0.0);
        for(ll i=n-1; i>=1; i--){
            dp[i] = (double)n/(double)(n-i);
            dp[i] += dp[i+1];
        }
        cout << fixed << setprecision(6) << dp[1];
    }
} 