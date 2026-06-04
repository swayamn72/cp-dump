#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vi a(n); for(auto &x : a) cin >> x;
    vi b(n); for(auto &x : b) cin >> x;
    ll m; cin >> m;
    vi c(m); for(auto &x : c) cin >> x;
    vi d(m); for(auto &x : d) cin >> x;
    bool flag = true;
    map<ll,ll> mp1, mp2;
    for(ll i=0; i<n; i++) mp1[a[i]] = b[i];
    for(ll i=0; i<m; i++) mp2[c[i]] = d[i];

    for(auto a : mp2){
        if(!mp1.count(a.first) || mp1[a.first]<mp2[a.first]){
            flag = false;
            break;
        }
        mp1[a.first] -= mp2[a.first];
    }
    if(!flag){
        cout << 0 << "\n";
        return 0;
    }
    ll res = 1;
    for(auto a : mp1){
        if(a.second>0){
            res *= 2;
            res %= mod;
        }
    }
    cout << res;
}