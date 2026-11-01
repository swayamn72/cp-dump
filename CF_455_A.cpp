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
        ll n; cin >> n;
        vi cnt(1e5+1,0);
        for(ll i=0; i<n; i++){
            ll x; cin >> x;
            cnt[x]++;
        }
        vi dp(1e5+1,0);
        dp[0] = 0;
        dp[1] = cnt[1];
        for(ll i=2; i<=1e5; i++){
            dp[i] = max(dp[i-1],dp[i-2]+cnt[i]*i);
        }
        cout << dp[1e5];
    }
}