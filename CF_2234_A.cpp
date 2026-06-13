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
        sort(arr.rbegin(),arr.rend());
        ll val = arr[0] % arr[1];
        bool flag = true;
        for(ll i=2; i<n; i++){
            if(arr[i]!=(arr[i-2]%arr[i-1])){
                flag = false;
                break;
            }
        }        
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        cout << arr[0] << " " << arr[1] << "\n";
    }
}