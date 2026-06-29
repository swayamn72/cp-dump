#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(n==1){
            cout << 0 << "\n";
            continue;
        }        
        ll xorsum = 0;
        for(auto a : arr) xorsum ^= a;
        if(xorsum==0){
            cout << 1 << "\n";
            continue;
        }
        // cout << xorsum << "\n";
        ll res = 0;
        for(ll i=0; i<n; i++){
            if((xorsum^arr[i]) <= arr[i]) res++;
        }
        cout << res << "\n";
    }
}