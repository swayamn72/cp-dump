#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    string s; cin >> s;
    ll n = s.size();
    vi dp(n+1,0);
    for(ll i=1; i<n; i++){
        dp[i] = dp[i-1];
        if(s[i-1]==s[i]) dp[i]++;
    }
    dp[n] = dp[n-1];
    // for(auto a : dp) cout << a << " ";
    cout << "\n";
    ll m; cin >> m;
    while(m--){
        ll l,r; cin >> l >> r;
        cout << dp[r-1] - dp[l-1] << "\n";
    }
}