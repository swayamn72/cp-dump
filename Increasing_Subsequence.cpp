#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    set<ll> s; s.insert(arr[0]);
    for(ll i=1; i<n; i++){
        ll val = arr[i];
        auto it = s.lower_bound(val);
        if(it!=s.end()){
            s.erase(it);
        }
        s.insert(val);
    }
    cout << s.size();
}