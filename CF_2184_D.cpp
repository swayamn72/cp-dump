#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll ncr(int n, int r) {
    if(r<0 || r>n) return 0;
    ll res = 1;
    for(int i=1; i<=r; i++){
        res = res*(n-i+1)/i;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        ll total = 64 - __builtin_clzll(n);
        ll res = 0;
        for(ll i=1; i<total; i++){
            ll onbits = k+2-i;
            if(onbits>i) continue;
            ll extraones = max(0LL, onbits-1);
            for(ll j=extraones; j<=i-1; j++){
                res += ncr(i-1,j);
            }
        }
        if(total>k) res++;
        cout << res << "\n";
    }
}
// rep + on - 1 = k+1;
// on = k + 2 - rep;