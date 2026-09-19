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
        vector<vi> dp(n,vi(n,0));
        for(ll i=0; i<n; i++){
            dp[i][i] = arr[i];
        }
        for(ll len=2; len<=n; len++){
            for(ll i=0; i<=n-len; i++){
                ll l = i, r = i+len-1;
                ll takeleft = arr[l] - dp[l+1][r];
                ll takeright = arr[r] - dp[l][r-1];
                dp[l][r] = max(takeleft,takeright);
            }
        }
        cout << dp[0][n-1];
    }
} 