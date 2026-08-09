#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi pref = arr;
        for(ll i=0; i<n; i++){
            pref[i] += i;
        } 
        vi suff = arr;
        for(ll i=0; i<n; i++){
            suff[i] += (n-i-1);
        }
        // for(auto a : pref) cout << a << " ";
        // cout << "\n";     
        // for(auto a : suff) cout << a << " ";
        // cout << "\n";  
        
        vi leftindex(n), rightindex(n);
        ll temp = 0;
        for(ll i=1; i<n; i++){
            leftindex[i] = temp;
            if(pref[i]>pref[temp]) temp = i;
        }
        temp = n-1;
        for(ll i=n-2; i>=0; i--){
            rightindex[i] = temp;
            if(suff[i]>suff[temp]) temp = i;
        }
        ll res = 0;
        for(ll i=1; i<n-1; i++){
            ll idx1 = leftindex[i];
            ll idx2 = rightindex[i];
            ll ans = arr[i] + arr[idx1] + arr[idx2] - (idx2-idx1);
            res = max(res,ans);
        }
        cout << res << "\n";
    }
}