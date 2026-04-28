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
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        sort(arr.begin(),arr.end());
        ll res = 0;
        for(ll i=0; i<n-2; i++){
            ll ans = arr[n-1] - arr[i] + arr[i+1] - arr[i];
            res = max(res, ans);
        }
        for(ll i=n-1; i>=2; i--){
            ll ans = abs(arr[i]-arr[0]) + abs(arr[i]-arr[i-1]);
            res = max(ans,res);
        }
        cout << res << "\n";
    }
}