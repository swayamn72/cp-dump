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
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        set<ll> s;
        for(auto a : arr) s.insert(a);
        if(s.size() > k){
            cout << -1 << "\n";
            continue;
        }        
        ll val = 1;
        while(s.size()<k){
            if(!s.count(val)){
                s.insert(val);
            } 
            val++;
        }
        cout << n*k << "\n";
        for(ll i=0; i<n; i++) for(auto a : s) cout << a << " ";
        cout << "\n";
    }
}