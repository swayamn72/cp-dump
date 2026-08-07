#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> arr(n); for(auto &x : arr) cin >> x;
    ll res = *max_element(arr.begin(),arr.end());
    vi pref(n); pref[0] = arr[0];
    for(ll i=1; i<n; i++) pref[i] = pref[i-1] + arr[i];
    ll minv = 0;
    for(ll i=0; i<n; i++){
        res = max(res, pref[i]-minv);
        minv = min(minv,pref[i]);
    }
    cout << res;
}