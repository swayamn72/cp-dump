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
    ll maxv = arr[0];
    ll res = 0;
    for(ll i=1; i<n; i++){
        res = max(res,maxv-arr[i]);
        maxv = max(maxv,arr[i]);
    }
    cout << res;
}