#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    vi random(1e6+5); 
    for(ll i=0; i<1e6+5; i++) random[i] = rng();

    ll t; cin >> t;
    while(t--){
        ll n,q; cin >> n >> q;
        vi arr(n); for(auto &x : arr) cin >> x;
        
        vi randomsum(n+1);
        randomsum[0] = 0; 
        for(ll i=1; i<=n; i++) randomsum[i] = randomsum[i-1]^random[arr[i-1]];

        vi xorsum(n+1); 
        xorsum[0] = 0; 
        for(ll i=1; i<=n; i++) xorsum[i] = xorsum[i-1]^arr[i-1];

        while(q--){
            ll l,r; cin >> l >> r;
            ll val1 = xorsum[r]^xorsum[l-1];
            ll val2 = randomsum[r]^randomsum[l-1];
            if(val1==0 && val2==0) cout << "YES";
            else cout << "NO";
            cout << "\n";
        }
    }
}