#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t = 1; 
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;

        vi pref(n); pref[0] = arr[0];
        for(ll i=1; i<n; i++) pref[i] = gcd(pref[i-1],arr[i]);

        vi suff(n); suff[n-1] = arr[n-1];
        for(ll i=n-2; i>=0; i--) suff[i] = gcd(suff[i+1],arr[i]);

        ll res = pref[n-1];
        for(ll i=1; i<n-1; i++){
            res += min(pref[i],suff[i]);
        }
        cout << res << "\n";
    }
}