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
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        ll res = 0;
        bool flag = true;
        for(ll i=0; i<n; i++){
            if(a[i]<=b[i]) continue;
            bool found = false;
            ll idx;
            for(ll j=i+1; j<n; j++){
                if(a[j]<=b[i]){
                    found = true;
                    idx = j;
                    break;
                }
            }
            if(!found){
                flag = false;
                break;
            }
            ll val = a[idx];
            res += (idx-i);
            for(ll k=idx; k>i; k--){
                a[k] = a[k-1];
            }
            a[i] = val;
        }        
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        cout << res << "\n";
    }
}