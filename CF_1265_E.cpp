#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 998244353;
ll binexp(ll a, ll b, ll mod) {
    ll res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll modinverse(ll n){
    return binexp(n,mod-2,mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi p(n); for(auto &x : p) cin >> x;
        ll e = 0;
        ll inv100 = modinverse(100);
        for(ll i=0; i<n; i++){
            ll pinv = modinverse(p[i]);
            e++;
            e = (e*100)%mod;
            e = (e*pinv)%mod;
        }
        cout << e;
    }
} 