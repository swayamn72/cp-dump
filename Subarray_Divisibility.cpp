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
    vi pref(n); pref[0] = arr[0];
    vi freq(n,0); freq[0] = 1;
    for(ll i=1; i<n; i++){
        pref[i] = pref[i-1] + arr[i];
    }
    ll res = 0;
    for(ll i=0; i<n; i++){
        ll rem = ((pref[i]%n)+n)%n;
        res += freq[rem];
        freq[rem]++;
    }
    cout << res;
}