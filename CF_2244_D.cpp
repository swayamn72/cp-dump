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
        ll n,m; cin >> n >> m;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi b(m); for(auto &x : b) cin >> x;
        sort(b.rbegin(),b.rend());
        vi pref(n); pref[0] = arr[0];
        for(ll i=1; i<n; i++) pref[i] = pref[i-1] + arr[i];
        bool flag = false;
        vector<bool> isflip(n,false);
        for(ll i=0; i<m; i++){
            ll idx = b[i]-1;
            ll val = pref[idx];

            ll idx2 = -1;
            if(i<m-1) idx2 = b[i+1]-1;
            if(idx2!=-1) val -= pref[idx2];
            if(flag){
                val = -val;
            }
            if(val<=0){
                flag = !flag;
                isflip[idx] = true;
            }
        }        
        // for(auto a : isflip) cout << a << " ";
        // cout << "\n";
        flag = false;
        for(ll i=n-1; i>=0; i--){
            if(isflip[i]){
                flag = !flag;
            }
            if(flag){
                arr[i] = -arr[i];
            }
        }
        cout << accumulate(arr.begin(),arr.end(),0LL) << "\n";
    }
}