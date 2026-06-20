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
        bool flag = false;
        for(ll i=1; i<n; i++){
            if((a[i]%a[i-1])!=0) flag = false;
            if((b[i-1]|b[i])!=0) flag = false;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}