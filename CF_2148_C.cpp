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
        ll n,m; cin >> n >> m;
        vi a(n), b(n);
        for(ll i=0; i<n; i++) cin >> a[i] >> b[i];
        ll cur = 0;
        ll res = 0;
        ll prev = 0;
        for(ll i=0; i<n; i++){ 
            ll diff = a[i] - prev;
            if(b[i]==cur){
                if(diff%2==0) res += diff;
                else res += max(0LL,diff-1);
            }else{
                if(diff%2==0) res += max(0LL,diff-1);
                else res += (diff);
            }
            cur = b[i];
            prev = a[i];
        }
        res += (m-a[n-1]);
        cout << res << "\n";
    }
}
// 0 _ _ _ 0 
// 0 _ _ 0
// 0 _ _ _ 1 
// 0 _ _ 1