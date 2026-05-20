#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1; 
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi pref(n); pref[0] = arr[0]; for(ll i=1; i<n; i++) pref[i] = arr[i] + pref[i-1];
        sort(arr.begin(),arr.end());
        vi pref2(n); pref2[0] = arr[0]; for(ll i=1; i<n; i++) pref2[i] = arr[i] + pref2[i-1];    
        ll q; cin >> q;
        while(q--){
            ll type; cin >> type;
            if(type==1){
                ll l,r; cin >> l >> r;
                if(l==1){
                    cout << pref[r-1] << "\n";
                }else{
                    cout << pref[r-1] - pref[l-2] << "\n";
                }
            }else{
                ll l,r; cin >> l >> r;
                if(l==1){
                    cout << pref2[r-1] << "\n";
                }else{
                    cout << pref2[r-1] - pref2[l-2] << "\n";
                }
            }
        }    
    }
}
