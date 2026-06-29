#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,d; cin >> n >> d;
        vi arr(n); for(auto &x : arr) cin >> x;
        for(ll i=0; i<n; i++) arr.push_back(arr[i]);
        vi pref(2*n,0);
        pref[0] = arr[0];
        for(ll i=1; i<2*n; i++) pref[i] = pref[i-1] + arr[i];
        vi suff(2*n,0);
        suff[2*n-1] = arr[2*n-1];
        for(ll i=2*n-2; i>=0; i--) suff[i] = suff[i+1] + arr[i];
        // for(auto a : pref) cout << a << " ";
        // cout << "\n";
        // for(auto a : suff) cout << a << " ";
        // cout << "\n";
        ll res = 0;
        for(ll i=0; i<n; i++){
            ll idx = i;
            if(i-d<0) idx+=n;
            ll val = arr[i];
            ll leftindex = idx-d;
            ll rightindex = idx+d;
            
            
            ll range = pref[rightindex] - (leftindex>0 ? pref[leftindex-1] : 0);
            ll neighbor = range - val;
            ll ans = 2*d*val - neighbor;
            
            if(ans>0) res += ans;
        }    
        cout << res << "\n";
    }
}