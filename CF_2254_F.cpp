#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        ll xorsum = 0;
        for(auto x : b) xorsum ^= x;
        bool flag = true;
        for(ll i=0; i<n; i++){
            if(a[i]==b[i]) continue;
            ll val = xorsum ^ b[i];
            ll temp = a[i]^val;
        }

        cout << (flag ? "YES" : "NO") << "\n";
    }
}