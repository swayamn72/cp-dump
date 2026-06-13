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
        ll n,l,r; cin >> n >> l >> r;
        l--; r--;
        vi pref(n);
        ll val = 127;
        for(ll i=0; i<n; i++){
            if(i==r) pref[i] = (l!=0 ? pref[l-1] : 0);
            else pref[i] = val++;
        }        
        vi arr(n); arr[0] = pref[0];
        for(ll i=1; i<n; i++) arr[i] = pref[i] ^ pref[i-1];
        for(auto a : arr) cout << a << " ";
        cout << "\n";
    }
}