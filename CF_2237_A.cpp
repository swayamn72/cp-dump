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
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                if(arr[j]>arr[i]){
                    arr[j] = arr[i];
                    break;
                }
            }
        }
        cout << accumulate(arr.begin(),arr.end(),0LL) << "\n";
    }
}