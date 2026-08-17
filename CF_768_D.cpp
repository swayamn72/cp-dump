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
        ll k,q; cin >> k >> q;
        ll days = 1e4;
        vector<vector<double>> dp(days+1,vector<double>(k+1,0.0));
        dp[0][0] = 1.0;
        for(ll i=1; i<=days; i++){
            for(ll j=1; j<=k; j++){
                double collected = j;
                double rem = k-collected;
                dp[i][j] += dp[i-1][j-1] * ((rem+1)/k);
                dp[i][j] += dp[i-1][j] * (collected/k);
            }
        }
        vi ans(1e3+5,0);
        ll p = 1;
        for(ll i=1; i<=days; i++){
            while(p<=1000 && dp[i][k]>=(p-1e-7)/2000.0){
                ans[p] = i;
                p++;
            }
        }
        while(q--){
            ll p; cin >> p;
            cout << ans[p] << "\n";
        }
    }
} 