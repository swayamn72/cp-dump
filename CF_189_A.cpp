#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,a,b,c; cin >> n >> a >> b >> c;
    vi dp(n+1,LLONG_MIN);
    dp[0] = 0;
    for(ll i=1; i<=n; i++){
        if(i>=a && (dp[i-a]!=LLONG_MIN)) dp[i] = max(dp[i],dp[i-a]+1);
        if(i>=b && (dp[i-b]!=LLONG_MIN)) dp[i] = max(dp[i],dp[i-b]+1);
        if(i>=c && (dp[i-c]!=LLONG_MIN)) dp[i] = max(dp[i],dp[i-c]+1);
    }
    cout << dp[n];
}