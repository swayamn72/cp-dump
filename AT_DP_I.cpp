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
        vector<double> dp(n+1,0.0);
        dp[0] = 1.0;
        for(ll i=0; i<n; i++){
            double p = arr[i];
            for(ll j=i+1; j>=0; j--){
                double tails = dp[j]*(1.0-p);
                double heads = (j>0) ? dp[j-1]*p : 0.0;
                dp[j] = tails + heads;
            }
        }
        double res = 0.0;
        for(ll i=n/2+1; i<=n; i++){
            res += dp[i];
        }
        cout << fixed << setprecision(9) << res;
    }
} 