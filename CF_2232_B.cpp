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
        vi res(n); res[0] = arr[0];
        
        ll sum = arr[0];
        for(ll i=1; i<n; i++){
            ll ans = (sum+arr[i])/(i+1);
            res[i] = min(res[i-1],ans);
            sum += arr[i];
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}