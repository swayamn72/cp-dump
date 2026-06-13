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
        vi arr(n); for(auto &x : arr) cin >> x;
        vi res(n);
        for(ll i=0; i<n; i++){
            vi ans(n,LLONG_MAX); ans[i] = 0;
            ll j = (i+1)%n; ll prev = arr[i];
            while(j!=i){
                ans[j] = min(ans[j],prev);
                prev = max(prev,arr[j]);
                j++; j%=n;
            }
            j = (i-1+n)%n;
            prev = arr[j];
            while(j!=i){
                ans[j] = min(ans[j],prev);
                j=(j-1+n)%n;
                prev = max(prev,arr[j]);
            }
            ll val = 0;
            for(auto a : ans) val += a;
            res[i] = val;
        }        
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}