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
    cin >> t;
    vector<vi> dp(1e6+1,vi(2));
    dp[0][0] = 1; dp[0][1] = 1;
    for(ll i=1; i<=1e6; i++){
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])%mod;
    }    
    while(t--){
        ll n; cin >> n; 
        ll res = (dp[n-1][0]+dp[n-1][1])%mod;
        cout << res << "\n";
    }
} 