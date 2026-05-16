#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,k,h; cin >> n >> k >> h;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll minv = *min_element(arr.begin(),arr.end());
        ll res = min(h,minv+k);
        cout << res << "\n";
    }
}