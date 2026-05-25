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
        vi arr2 = arr;
        if(is_sorted(arr.begin(),arr.end())){
            cout << "YES" << "\n";
            continue; 
        }
        ll temp = 0;
        for(ll i=1; i<n; i++){
            if(arr[i]<arr[i-1]){
                temp = max(temp, arr[i-1]-arr[i]);
                arr[i]+=temp;
            }
        }
        for(ll i=1; i<n; i++){
            if(arr2[i]<arr2[i-1]) arr2[i]+=temp;
        }
        if(is_sorted(arr2.begin(),arr2.end())){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}