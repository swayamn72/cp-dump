#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q,k; cin >> q >> k;
    ll n = 1e5+5;
    vi dp(n,1);
    for(ll i=1; i<k; i++) dp[i] = 1;
    for(ll i=k; i<n; i++){
        dp[i] = (dp[i-1] + dp[i-k])%mod; 
    }
    vi pref(n);
    pref[0] = dp[0];
    for(ll i=1; i<n; i++){
        pref[i] = (pref[i-1]+dp[i])%mod;
    }
    while(q--){
        ll l,r; cin >> l >> r;
        cout << (pref[r]-pref[l-1]+mod)%mod << "\n";
    }
}