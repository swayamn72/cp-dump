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
        vi c(n); for(auto &x : c) cin >> x;
        ll aways = 0, cways = 0;
        for(ll i=0; i<n; i++){
            ll start = i;
            bool flag = true;
            for(ll j=0; j<n; j++){
                if(a[start%n]>=b[j]) flag = false;
                start++;
            }
            if(flag) aways++;
        }
        for(ll i=0; i<n; i++){
            ll start = i;
            bool flag = true;
            for(ll j=0; j<n; j++){
                if(c[start%n]<=b[j]) flag = false;
                start++;
            }
            if(flag) cways++;
        }
        cout << aways*cways*n << "\n";
    }
}