#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll sum = accumulate(arr.begin(),arr.end(),0LL);
    if(sum%3!=0){
        cout << 0;
        return 0;
    }
    ll div = sum/3;
    vi pref(n);
    pref[0] = arr[0];
    ll countdiv = 0;
    ll res = 0;
    if(pref[0]==div) countdiv++;
    for(ll i=1; i<n; i++){
        pref[i] = pref[i-1] + arr[i];
        if(pref[i]==2*div && i!=n-1){
            res += countdiv;
        }
        if(pref[i]==div){
            countdiv++;
        }
    }
    cout << res;
}