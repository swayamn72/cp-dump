#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,x; cin >> n >> x;
    vi arr(n); for(auto &x : arr) cin >> x;
    map<ll,ll> mp; mp[0] = 1;
    ll res = 0;
    ll pref = 0;
    for(ll i=0; i<n; i++){
        pref += arr[i];
        ll need = pref - x;
        res += mp[need];
        mp[pref]++;
    }
    cout << res;
}