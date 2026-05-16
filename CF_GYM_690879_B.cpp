#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        set<ll> s; for(auto a : arr) s.insert(a);
        ll res = 1;
        while(s.find(res)!=s.end()) res*=2;
        cout << res << "\n";
    }
}