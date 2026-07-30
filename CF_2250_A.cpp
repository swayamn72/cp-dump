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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        if(n%2){
            cout << "NO" << "\n";
            continue;
        }       
        ll left = arr[0], right = arr[1];
        for(ll i=2; i<n; i+=2){
            left = min(left,arr[i]);
            right = max(right,arr[i+1]);
        }
        if(right<left-1){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}