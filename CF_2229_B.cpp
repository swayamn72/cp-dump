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
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        
        ll sum = 0;
        ll rem = -1;
        for(ll i=0; i<n; i++){
            ll minv = min(a[i],b[i]);
            ll maxv = max(a[i],b[i]);
            sum += maxv;
            rem = max(rem,minv);
        }
        cout << sum + rem << "\n";
    }
}