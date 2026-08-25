#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
ll mulmod(ll a, ll b, ll mod) {
    return (ll)(a * b % mod);
}
ll binexp(ll a, ll b, ll mod) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = mulmod(res,a,mod);
        a = mulmod(a,a,mod);
        b>>=1;
    }
    return res;
}
ll modinv(ll a, ll mod){
    return binexp(a,mod-2,mod);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll inv100 = modinv(100,mod);
    
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,p; cin >> n >> p;
        ll pby100 = (p*inv100)%mod;
        ll pmby100 = ((100-p)*inv100)%mod;
        vi dp(n+1,0);
        dp[1] = 1;
        for(ll i=2; i<=n; i++){
            dp[i] = 1+((pby100 * dp[i-2])%mod + (pmby100 * dp[i-1])%mod)%mod;
        }
        cout << dp[n];
    }
} 