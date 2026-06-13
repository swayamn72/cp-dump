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
        ll n,x,y; cin >> n >> x >> y;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi transfer(n);
        for(ll i=0; i<n; i++){
            transfer[i] = (arr[i]/x)*y;
        }        
        ll res = 0;
        ll sum = accumulate(transfer.begin(),transfer.end(),0LL);
        for(ll i=0; i<n; i++){
            res = max(res, sum-transfer[i]+arr[i]);
        }
        cout << res << "\n";
    }
}