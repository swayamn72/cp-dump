#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vi a(n); for(auto &x : a) cin >> x;
    vi b(n); for(auto &x : b) cin >> x;
    map<ll,ll> mp;
    bool flag = true;
    for(ll i=0; i<n; i++){
        mp[a[i]] = i+1;
    }
    for(ll i=0; i<n; i++){
        if(mp[i+1]!=b[i]){
            flag = false; break;
        }
    }
    cout << (flag ? "Yes" : "No");
}