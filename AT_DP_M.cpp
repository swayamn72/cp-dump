#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        // 1d dp
        vi arr(n); for(auto &x : arr) cin >> x;
        vi dp(k+1,0);
        dp[0] = 1;
        for(ll i=0; i<n; i++){
            vi pref(k+1,0);
            pref[0] = dp[0];
            for(ll j=1; j<=k; j++){
                pref[j] = (pref[j-1]+dp[j])%mod;
            }
            vi next(k+1,0);
            for(ll j=0; j<=k; j++){
                ll left = j-arr[i]-1;
                ll tosubtract = (left>=0 ? pref[left] : 0);
                next[j] = (pref[j]-tosubtract+mod)%mod;
            }
            dp = next;
        }
        cout << dp[k];
        // 2d dp
        // vi arr(n+1); 
        // for(ll i=1; i<=n; i++) cin >> arr[i];
        // vector<vi> dp(n+1,vi(k+1,0));
        // dp[0][0] = 1;

        // // upto i children
        // for(ll i=1; i<=n; i++){
        //     vi pref(k+1,0);
        //     pref[0] = dp[i-1][0];
        //     for(ll j=1; j<=k; j++) pref[j] = (pref[j-1] + dp[i-1][j])%mod;

        //     // j - candies
        //     // dp[i][j] - no. of ways to distribute j candies among i children
        //     for(ll j=0; j<=k; j++){
        //         ll left = j-arr[i]-1;
        //         ll tosubtract = (left>=0 ? pref[left] : 0); 
        //         dp[i][j] = (pref[j]-tosubtract+mod)%mod;
        //     }
        // }
        // cout << dp[n][k];
        
    }
}