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
    sort(arr.rbegin(),arr.rend());
    vi pref(n); pref[0] = arr[0]; for(ll i=1; i<n; i++) pref[i] = gcd(pref[i-1],arr[i]);
    // for(auto a : pref) cout << a << " "; cout << "\n";
    vi suff(n); suff[n-1] = arr[n-1]; for(ll i=n-2; i>=0; i--) suff[i] = gcd(suff[i+1],arr[i]);
    // for(auto a : suff) cout << a << " ";
    if(n==2){
        cout << max(arr[0],arr[1]);
        return 0;
    }
    ll res = 1;
    for(ll i=0; i<n-2; i++){
        res = max(res,gcd(pref[i],suff[i+2]));
    }
    res = max({res,suff[1],pref[n-2]});
    cout << res;
}