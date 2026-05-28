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
        if(arr[0]==n || arr[n-1]==1){
            cout << "No" << "\n";
            continue;
        }
        vi indexes(n+1);
        for(ll i=0; i<n; i++){
            indexes[arr[i]] = i;
        }
    }
}