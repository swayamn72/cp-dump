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
        vector<ll> suff(n); suff[n-1] = arr[n-1];
        for(ll i=n-2; i>=0; i--) suff[i] = suff[i+1] + arr[i];
        // for(auto a : suff) cout << a << " ";
        // cout << "\n";
        ll res = arr[0];
        ll val = 1;
        for(ll i=1; i<n; i++){
            if(suff[i]>0) val++;
            res += (val*arr[i]);
        }
        cout << res << "\n";
    }
}