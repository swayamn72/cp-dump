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
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vi> v(n,vi(4));
        for(auto &a : v){
            cin >> a[0] >> a[1] >> a[2] >> a[3];
        }
        ll w = 1;
        vector<vector<pair<ll,ll>>> endsat(m+1);
        for(auto a : v){
            ll p = a[2], q = a[3];
            ll probnot = ((q-p)%mod * modinv(q,mod)) % mod;
            w = (w*probnot)%mod;
            ll wt = (p%mod*modinv(q-p,mod)) % mod;
            endsat[a[1]].push_back({a[0],wt});
        }
        vi dp(m+1,0);
        dp[0] = 1;
        for(ll i=1; i<=m; i++){
            for(auto &[l,wt] : endsat[i]){
                dp[i] = (dp[i]+dp[l-1]*wt)%mod;
            }
        }
        ll res = (dp[m]*w)%mod;
        cout << res;
    }
} 