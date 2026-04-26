#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    vi c(m); for(auto &x : c) cin >> x;
    vi a(n); vi b(n);
    map<ll,ll> mp;
    for(ll i=0; i<n; i++){
        cin >> a[i] >> b[i];
        mp[a[i]] += b[i]; 
    }
    ll res = 0;
    for(auto x : mp){
        ll ans = min(x.second, c[x.first-1]);
        res += ans;
    }
    cout << res << "\n";

}