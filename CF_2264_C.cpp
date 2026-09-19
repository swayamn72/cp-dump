#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
ll binexp(ll a, ll b) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll modinv(ll a){
    return binexp(a, mod-2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi fact(2e5+5);
    fact[0] = fact[1] = 1;
    for(ll i=2; i<2e5+5; i++) fact[i] = (fact[i-1]*i)%mod;

    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        vi suff(n+1);
        for(ll i=n-1; i>=0; i--){
            suff[i] = (suff[i+1]+arr[i])%mod;
        }        
        ll res = 0;
        for(ll i=0; i<n-1; i++){
            ll choices = n-i-1;
            ll w = (fact[n-1]*modinv(choices))%mod;
            ll sum = suff[i+1];
            ll self = (choices*arr[i])%mod;
            ll val = (sum-self+mod)%mod;
            ll ans = (w*val)%mod;
            res = (res+ans)%mod;
        }
        cout << res << "\n";
    }
} 