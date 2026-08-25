#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
ll mulmod(ll a, ll b) {
    return (ll)(a * b % mod);
}
ll binexp(ll a, ll b) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = mulmod(res,a);
        a = mulmod(a,a);
        b>>=1;
    }
    return res;
}
ll modinv(ll a){
    return binexp(a,mod-2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n-1); for(auto &x : arr) cin >> x;
        // dp[x] = expected value to reach from x 
        vi dp(n+2,0);
        vi suff(n+2,0);
        for(ll i=n-1; i>=1; i--){
            ll ai = arr[i-1];
            ll idx = i+ai;
            ll inv = modinv(ai);

            ll sum = (suff[i+1]-suff[idx+1]+mod)%mod;
            ll num = (sum+1+ai)%mod;
            dp[i] = (num*inv)%mod;
            suff[i] = (suff[i+1] + dp[i])%mod;
        }
        cout << dp[1];
    }
} 